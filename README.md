# Simple Shell

Simple Shell is a small Unix command interpreter written in C for the ALX
software engineering project. It reads commands interactively or from standard
input, runs external programs, and provides a handful of shell built-ins. The
current implementation is intentionally small; it is not a full POSIX shell.

## Repository guide

| Location | What it contains |
| --- | --- |
| [Current shell source](#current-shell) | The top-level implementation and its command-processing tasks |
| [archives/](archives/README.md) | Earlier shell modules and experiments, including pipes and redirection |
| [improved/](improved/README.md) | Notes about the improved snapshot directory |
| [AUTHORS](AUTHORS) | Project contributors |

Build and run the current implementation from the repository root. The
`archives/` modules are separate historical code and are not part of this
build.

## Build and run

Requirements: GCC and a Unix-like environment with the standard C library.

```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
./hsh
```

Commands can also be piped into the shell:

```sh
printf 'pwd\n' | ./hsh
```

The generated executable is named `hsh` and is ignored by Git.

## Current shell

The top-level C files make up the build above. Links below point to each source
module and summarize its role.

| Task | Source |
| --- | --- |
| Start the shell loop and coordinate input, parsing, and execution | [shell.c](shell.c) |
| Read a line and display a prompt when attached to a terminal | [read_input.c](read_input.c) |
| Split input into command and argument tokens | [parse_input.c](parse_input.c) |
| Route built-in commands to their handlers | [check_builtin.c](check_builtin.c) |
| Handle `env` and `exit` | [builtin.c](builtin.c) |
| Change the working directory | [cd_builtin.c](cd_builtin.c) |
| Set an environment variable | [setenv_builtin.c](setenv_builtin.c) |
| Remove an environment variable | [unsetenv_builtin.c](unsetenv_builtin.c) |
| Resolve commands using `PATH` | [find_executable.c](find_executable.c) |
| Dispatch commands and choose an executable path | [execute_command.c](execute_command.c) |
| Fork, execute an external program, and wait for it | [run_command.c](run_command.c) |
| Report errors | [error_handling.c](error_handling.c) |
| Release command input memory | [free_memory.c](free_memory.c) |
| Share declarations and constants across modules | [shell.h](shell.h) |

The current implementation handles basic commands and the built-ins listed
above. Pipes and I/O redirection appear only in the archived code; they are not
implemented by the top-level build.

## Project notes

- [archives/README.md](archives/README.md) describes the legacy modules one by
  one and explains their relationship to the current shell.
- [improved/README.md](improved/README.md) describes the contents of that
  directory.
- Generated executables, editor swap files, Node dependency directories, and
  local SQLite/database files are excluded in [.gitignore](.gitignore).

## Project guidelines

These are the main requirements from the original ALX project brief. They
describe the assignment; they are not a claim that every requirement has been
independently certified for the current code.

- Compile on the target Ubuntu environment with GCC and
  `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- End source files with a newline, use Betty style, include guards in headers,
  and keep each C file to no more than five functions.
- Avoid memory leaks and use system calls only when needed.
- Keep the root `README.md` and an `AUTHORS` file listing contributors.
- Match `/bin/sh` output and error behavior where specified by the assignment;
  error messages should identify the invoked program (`argv[0]`).
- Support both interactive use and commands read from standard input.

### Functions and system calls listed in the assignment

The original brief lists the following:

`access`, `chdir`, `close`, `closedir`, `execve`, `exit`, `_exit`, `fflush`,
`fork`, `free`, `getcwd`, `getline`, `getpid`, `isatty`, `kill`, `malloc`,
`open`, `opendir`, `perror`, `read`, `readdir`, `signal`, `stat`, `lstat`,
`fstat`, `strtok`, `wait`, `waitpid`, `wait3`, `wait4`, and `write`.

The brief shows the platform-specific `__xstat`, `__lxstat`, and `__fxstat`
names alongside `stat`, `lstat`, and `fstat`, respectively. Check the course
checker or the original project instructions for the authoritative rules for
your submission environment.

### Learning objectives

The project is intended to teach how a shell reads and parses commands, uses
`PATH` to locate programs, creates processes with `fork`, runs programs with
`execve`, waits for child processes, handles EOF, and works with process
environments. It also covers process IDs, system calls versus library
functions, and the history of Unix and its shell.
