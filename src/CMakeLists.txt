add_executable(strace_like
    main.c
    core/x86_64/trace64.c
    core/logging.c
    utils/args.c
    utils/check.c
)
