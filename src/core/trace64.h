#ifndef _TRACE64_H
#define _TRACE64_H

#include <stdlib.h>
#include <stdio.h>

void tracex64(char *filename, char **argv);

static char *syscall_name[] = 
{
    "read",
    "write",
    "open",
    "close",
    "stat",
    "fstat",
    "lstat",
    "poll",
    "lseek",
    "mmap",
    "mprotect",
    "munmap",
    "brk",
    "rt_sigaction",
    "rt_sigprocmask",
    "rt_sigreturn",
    "ioctl", // 16...
    "pread64",
    "pwrite64",
    "readv",
    "writev",
    "access",
    "pipe",
    "select",
    "sched_yield"
    "mremap",
    "msync",
    "mincore",
    "madvise",
    "shmget",
    "shmat", // 30
    "shmctl",
    "dup",
    "dup2",
    "pause",
    "nanosleep",
    "getitimer",
    "alarm",
    "getpid",
    "senfile",
    "socket",
    "connect",
    "accept",
    "sendto",
    "recvfrom", // 45

};

#endif