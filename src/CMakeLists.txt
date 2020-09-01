add_executable(strace_like
    main.c
    core/x86_64/trace64.c
    core/x86/trace.c
    core/logging.c
    utils/args.c
    utils/check.c
)
