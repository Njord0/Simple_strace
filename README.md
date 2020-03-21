# Simple_strace
Simple strace-like tool, created to understand how strace works and how ptrace syscall works.

## Installation
```bash
git clone https://github.com/Njord0/Simple_strace.git
cd Simple_strace
make
```

## Usage
To trace the execution of an executable: 
```bash
./tracer --binary 'filename'
```

To display usage:
```bash
./tracer --help
```
### To-do
* Add option to trace the execution of a program with the pid
* Add support for 32 bits elf binary
* Add support for some arm architecture
* Fetch the arguments for every syscalls
* Add the return value of syscalls(eax register)
