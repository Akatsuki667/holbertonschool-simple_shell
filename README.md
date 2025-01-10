# Recreating a C shell

This project involves recreating a minimalist C shell called **simple_shell**. It offers a simplified experience while exploring advanced concepts such as process management, system calls and environment variable manipulation.

---

## Features

- Execution of simple commands (e.g., `ls`, `pwd`, `echo`).
- Argument and option management (e.g., `ls -l`).
- Pipes (e.g., `command1 | command2`).
- Integrated commands (e.g., `exit`).
- Display environment variables with `printenv`.

---

## Project structure

Here's the list of files included in the project:

- **`simple_shell.c`**: Main entry point, containing the shell loop.
- **`simple_shell.h`**: Header file declaring function prototypes and constants.
- **`_getenv.c`**: Function for retrieving the value of an environment variable.
- **`printenv.c`** : Implementation of the `printenv` built-in command.
- **`_tokenize.c`** : Function for breaking down a command into tokens (arguments).
- **`check_for_exe_in_path.c`** : Checks for the presence of an executable in the PATH
- **`exec_cmd.c`** : Command execution management using `execve`.
- **`exit_handler.c`** : Management of the `exit` built-in command.
- **`free_cmd_vector.c`** : Free up memory used by command vectors.
- **`is_builtin.c`** : Detection and execution of built-in commands.
- **`man_1_simple_shell`** : Manual file explaining how to use the shell.
- **`AUTHORS`**: List of authors who have contributed to the project.

---

## Prerequisites

Before you start, make sure you have the following tools installed:

- A C compiler (e.g., `gcc`).
- UNIX-based operating system (e.g., Linux, macOS).
-**Style** : follows the betty style of coding (use `betty-style` and `betty-doc` for the code review)

---

## Installation and compilation
1. Clone the repository :
git clone https://github.com/Akatsuki667/holbertonschool-simple_shell.git
2. Acces to project : 
cd holbertonschool-simple_shell
3. Compile the source code :
`gcc` with options `-Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

## Eamples of use
Here are some examples of how to use the **simple_shell** :

### 1. Basics commands
1. #c_is_hell ls
2. #c_is_hell pwd
3. #c_is_hell echo "Hello,World!"
### 1.1 Results
1. AUTHORS                  exec_cmd.          man_1_simple_shell
   README.md                exit_handler.c     simple_shell.c
   _getenv.c                free_cmd_vector.c  simple_shell.h
   _printenv.c              hack               simple_shell_flowchart.drawio
   _tokenize.c              hsh
   check_for_exe_in_path.c
2. /Users/holbertonschool-simple_shell
3. "Hello,World!"
### 2 Pipes
echo ls | ./hsh
### 2.1 Result
   AUTHORS                  exec_cmd.          man_1_simple_shell
   README.md                exit_handler.c     simple_shell.c
   _getenv.c                free_cmd_vector.c  simple_shell.h
   _printenv.c              hack               simple_shell_flowchart.drawio
   _tokenize.c              hsh
   check_for_exe_in_path.c
   #c_is_hell
### 3. Display environment variables
env
### 3.1 Result
__CFBundleIdentifier=com.apple.Terminal
TMPDIR=/var/folders/8m/dn35twfj39jc37jbdtt99xdr0000gn/T/
XPC_FLAGS=0x0
TERM=xterm-256color
SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.GCYlykjPOu/Listeners
XPC_SERVICE_NAME=0
TERM_PROGRAM=Apple_Terminal
TERM_PROGRAM_VERSION=455
TERM_SESSION_ID=AB954261-B7DB-4620-8223-973CB49E7300
SHELL=/bin/zsh
HOME=/Users/altyt
LOGNAME=altyt
USER=altyt
PATH=/opt/homebrew/bin:/opt/homebrew/sbin:/usr/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/local/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/appleinternal/bin:/Library/Apple/usr/bin
SHLVL=1
PWD=/Users/altyt/Akatsuki667/holbertonschool-simple_shell
OLDPWD=/Users/altyt/Akatsuki667
HOMEBREW_PREFIX=/opt/homebrew
HOMEBREW_CELLAR=/opt/homebrew/Cellar
HOMEBREW_REPOSITORY=/opt/homebrew
INFOPATH=/opt/homebrew/share/info:
ZSH=/Users/altyt/.oh-my-zsh
PAGER=less
LESS=-R
LSCOLORS=Gxfxcxdxbxegedabagacad
LS_COLORS=di=1;36:ln=35:so=32:pi=33:ex=31:bd=34;46:cd=34;43:su=30;41:sg=30;46:tw=30;42:ow=30;43
LANG=fr_FR.UTF-8
_=/Users/altyt/Akatsuki667/holbertonschool-simple_shell/./hsh

---

## Man page `simple_shell`
[man_1_simple_shell](man_1_simple_shell)

---

## Flowchart
[simple_shell_flowchart.drawio](https://app.diagrams.net/#HAkatsuki667%2Fholbertonschool-simple_shell%2Fmain%2Fsimple[…]chart.drawio#%7B%22pageId%22%3A%2294cD6ZTa3Vw65mxtf7fP%22%7D)

---

## Contributors
This project was produced as part of the Holberton School program by :
- [Mitchell Julian](https://github.com/jmitchell35)
- [Teyant Alexandre](https://github.com/Akatsuki667)
