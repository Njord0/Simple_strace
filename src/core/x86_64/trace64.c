#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/user.h>
#include <errno.h>
#include <unistd.h>

#include "trace64.h"

void tracex64(char *filename, char **argv)
{

    pid_t pid = fork();

    switch (pid) {
        case -1:
            fprintf(stderr, "Error happened while fork()...\n\n");
        case 0:
            ptrace(PTRACE_TRACEME, 0, 0, 0);
            execvp(filename, argv+1);
    }

    waitpid(pid, 0, 0);
    ptrace(PTRACE_SETOPTIONS, pid, 0, PTRACE_O_EXITKILL);

    for (;;)
    {

        if (ptrace(PTRACE_SYSCALL, pid, 0, 0) == -1)
        {
            fprintf(stderr, "Error on ptrace syscall...\n"); // First we catch syscall before execution
            exit(-1);
        }

        if (waitpid(pid, 0, 0) == -1)
        {
            fprintf(stderr, "Error...\n");
            exit(-1);
        }

        struct user_regs_struct regs;
        ptrace(PTRACE_GETREGS, pid, 0, &regs);

        if (regs.orig_rax < 335 )
        {
            char *name = syscall_name[regs.orig_rax];
            printf("%s()\n", name);
        }
        else{
            printf("%llx\n", regs.orig_rax); //
        }


        if (regs.orig_rax == 231)
            exit(-1); // exit_group syscall



        if (ptrace(PTRACE_SYSCALL, pid, 0, 0) == -1)
        {
            fprintf(stderr, "Error on ptrace syscall\n");
            exit(-1);
        }

        waitpid(pid, 0, 0);
    }

}
