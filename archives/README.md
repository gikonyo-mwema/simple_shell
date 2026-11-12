# Archived shell modules

This directory contains an earlier, separate set of shell source files. It is
kept for reference and experimentation; it is **not** included when building
the current shell from the repository root. Its functions and declarations
overlap with the current implementation, so do not compile these files
together with the top-level `*.c` files.

The archived modules cover command input and parsing, environment handling,
built-ins, process execution, pipes, and redirection. The file links below
describe the role indicated by each module's code.

| Task or module | Source |
| --- | --- |
| Declare archived shell structures and functions | [shell.h](shell.h) |
| Read a command line from a file descriptor | [my_getline.c](my_getline.c) |
| Read commands and manage the input loop | [shell_getcommand.c](shell_getcommand.c) |
| Display the shell prompt | [shell_prompt.c](shell_prompt.c) |
| Parse command-line tokens | [shell_parsecommand.c](shell_parsecommand.c) |
| Find a command in the executable search path | [shell_location.c](shell_location.c) |
| Allocate and collect environment output | [shell_alloc_env.c](shell_alloc_env.c) |
| Dispatch shell built-ins | [shell_builtin.c](shell_builtin.c) |
| Set and unset environment variables | [my_unsetev.c](my_unsetev.c) |
| Exit the shell | [exit_built_in.c](exit_built_in.c) |
| Execute external commands in child processes | [shell_exec.c](shell_exec.c) |
| Create and execute a two-command pipe | [shell_pipe.c](shell_pipe.c) |
| Detect pipes and redirection and extract operands | [shell_pipe_redir_helper.c](shell_pipe_redir_helper.c) |
| Choose a redirection mode | [shell_redirection_direction.c](shell_redirection_direction.c) |
| Apply input or output redirection | [shell_redirections.c](shell_redirections.c) |
| Provide a small output helper | [shell_printf.c](shell_printf.c) |
