# Minishell

Minishell is a simple shell program developed as a project for the 42 school's curriculum. The aim of this project is to implement a basic shell program capable of executing basic commands and managing environment variables.

## Features
Minishell supports the following features:

*    Execution of basic commands (e.g., **ls, echo, pwd, cat, etc.**)
*    Basic redirections (e.g., **>, <, >>**)
*    Environment variables management (e.g., **export, unset**)
*    Basic signal handling (e.g., **ctrl+C, ctrl+D**)
*    Pipes ( **|** )
## Getting Started

To get started with Minishell, follow these steps:

1. Clone this repository to your local machine:
```bash
git clone https://github.com/jakobklocker/minishell_42.git
```
2. Navigate to the project directory:
```bash
cd minishell_42
```
3. Build the program:
```bash
make
```

4. Run the program:
```bash
./minishell
```

## Usage

Once you have launched the program, you can enter basic commands as you would in a regular shell. Minishell supports a number of built-in commands, such as echo, cd, pwd, export, unset, and env. To execute a command, simply enter it at the prompt and press enter:

```bash
$ echo Hello, World!
Hello, World!
```
Minishell also supports basic redirections. For example, to redirect the output of a command to a file, use the > operator:

```bash
$ echo Hello > hello.txt
```

This will create a new file called hello.txt and write the output of the echo command to it.

Pipes work as they do in the offical shell, creating one child process each pipe
```bash
$ cat file1.txt | sort
```