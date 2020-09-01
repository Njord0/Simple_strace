#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/user.h>
#include <errno.h>
#include <unistd.h>

#include "trace.h"
#include "../logging.h"

void tracex86(const char *filename, char **argv)
{
    pid_t pid = fork();

    switch (pid)
    {
        case -1:
            log_(L_ERROR, "Error happened while fork()...");
        case 0:
            ptrace(PTRACE_TRACEME, 0, 0, 0);
            execvp(filename, argv+1);
    }

    waitpid(pid, 0, 0);
    ptrace(PTRACE_SETOPTIONS, pid, 0, PTRACE_O_EXITKILL);

    for (;;)
    {

        if (ptrace(PTRACE_SYSCALL, pid, 0, 0) == -1)
            log_(L_ERROR, "Error on ptrace syscall...");
        if (waitpid(pid, 0, 0) == -1)
           log_(L_ERROR, "Error...");

        struct user_regs_struct regs;
        ptrace(PTRACE_GETREGS, pid, 0, &regs);

        if (regs.orig_rax < 335 )
        {
            char *name = sys86[regs.orig_rax];
            printf("%s()\n", name, regs.orig_rax);
        }
        else
            printf("%llx\n", regs.orig_rax); //



        if (regs.orig_rax == 252)
            exit(0); // exit_group syscall



        if (ptrace(PTRACE_SYSCALL, pid, 0, 0) == -1)
            log_(L_ERROR, "Syscall error...");

        waitpid(pid, 0, 0);
    }
}
