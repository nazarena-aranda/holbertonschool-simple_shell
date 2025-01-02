# Simple Shell Project

## Description
This project implements a simple UNIX command line interpreter (shell) that executes commands entered by the user. It supports:
- Execution of both internal and external commands.
- Tokenizing input commands.
- Searching for executable commands in the PATH.
- Basic commands such as `exit` and `env`.

The shell reads user input, tokenizes it, and executes the appropriate command using system calls like `fork`, `execve`, and `wait`. It continues running until terminated by the user.

---

## Features

- **Prompt:** Displays `#cisfun$` as the prompt for user interaction.
- **Command Execution:** Executes both built-in and external commands.
- **PATH Handling:** Searches for executables in the system PATH.
- **Built-in Commands:**
  - `exit`: Exits the shell.
  - `env`: Prints the current environment variables.
- **Error Handling:** Handles cases like invalid commands or EOF (`Ctrl+D`).

---

## Files

| File         | Description                                   |
|--------------|-----------------------------------------------|
| `shell.h`    | Header file with function declarations and includes. |
| `shell.c`    | Main function and the shell loop.             |
| `aux.c`      | Handles tokenization of input.               |
| `path.c`     | Searches for commands in the PATH.           |
| `execute.c`  | Executes commands (internal and external).    |
| `builtins.c` | Implements built-in commands like `exit` and `env`. |

---

## Flowchart

Below is a flowchart illustrating the workflow of the shell:

## Compilation
To compile the project, use the following command:
```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o shell
```

---

## Usage
To run the shell, execute:
```bash
./shell
```

### Example Usage:
```plaintext
#cisfun$ ls
AUTHORS  README.md  aux.c  builtins.c  execute.c  path.c  shell.c  shell.h

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

#cisfun$ exit
```

---

## Authors
- **Nazarena Aranda**
- **Emiliano Moreira**

---
