# Simple Shell Project

## Project Description

This project implements a basic command interpreter (shell) in UNIX that allows the execution of user-entered commands. The shell operates similarly to other shells, like Bash, but with limited functionality, focusing on understanding the internal workings of a command interpreter.

## Features

### Command Execution:

- Supports internal commands (*built-ins*) such as `exit` and `env`.
- Supports external commands executable within the `PATH`.

### Input Tokenization:

- Splits user input into tokens for processing.

### PATH Management:

- Searches for entered commands in the paths defined by the `PATH` environment variable.

### Error Handling:

- Informative messages for commands not found, permission errors, etc.

### Support for Interactive and Non-Interactive Modes:

- In interactive mode, displays the `#cisfun$` prompt.
- In non-interactive mode, reads from a script or pipe.

## Technical Requirements

- **System functions used:**
  - `fork`
  - `execve`
  - `wait`
  - `access`
  - `getline`
  - `isatty`
  - `perror`

## Program Flow

### Flowchart

The following flow describes how the shell operates:

![Flowchart](https://github.com/nazarena-aranda/Images/blob/main/Flowchart.png?raw=true)

## Files

| File         | Description                                                                    |
| ------------ | ------------------------------------------------------------------------------ |
| `shell.h`    | Header file containing function declarations and inclusions.                   |
| `shell.c`    | Contains the main function and the shell loop.                                 |
| `aux.c`      | Handles tokenization of user input.                                            |
| `path.c`     | Searches for commands in the `PATH`.                                           |
| `execute.c`  | Executes internal and external commands.                                       |
| `builtins.c` | Implements internal commands like `exit` and `env`.                            |

## Specifiers

- **Command `exit`:** Ends the shell execution.
- **Command `env`:** Prints the current environment variables.
- **External commands:** Are searched in the `PATH` and executed if found.

## Example Cases

### Executing an External Command:

```bash
#cisfun$ ls
AUTHORS  README.md  aux.c  builtins.c  execute.c  path.c  shell.c  shell.h
```

## Handling the `env` Command:

```bash
#cisfun$ env
LESSOPEN=| /usr/bin/lesspipe %s
USER=root
SSH_CLIENT=10.43.194.53 39476 22
SHLVL=1
LD_LIBRARY_PATH=/usr/lib/debug
MOTD_SHOWN=pam
HOME=/root
OLDPWD=/root
SSH_TTY=/dev/pts/0...
```

## Command Not Found:

```bash
#cisfun$ nonexistent
nonexistent: Command not found
```

## Using the `exit` Command:

```bash
#cisfun$ exit
```

## Non-Interactive Mode:

```bash
echo "ls -l" | ./hsh
```

## Compilation

To compile the project, run the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage

To execute the shell, use:

```bash
./hsh
```

### Interactive Mode:

The `#cisfun$` prompt will be visible for the user to enter commands.

### Non-Interactive Mode:

You can execute a script:

```bash
echo "ls" | ./hsh
```

## Authors

- **Nazarena Aranda**
- **Emiliano Moreira**
