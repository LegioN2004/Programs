# SHELL SCRIPTING

## Linux shell

A shell provides an environment to a user to execute commands and interact with the kernel.

**Types of shell**

- bash
- sh
- ksh
- tsh
- fish
- zsh

**How to check your shell type**

- `echo $0` = shows `-bash`/`bash`. It means that all the scripts made will be executed with this shell only.
- `echo $SHELL` = shows `/bin/bash`. Kindof shows the whole path to the shell
- `cat /etc/shells` = shows all the shells available on the machine

**What is shell scripting**
- Shell script consists of a set of commands to perform a task.
- All the commands execute sequentially.
- Some task like file manipulation, program execution, user interaction, automation of task, etc can be done as well.

It is useful in many cases, let's say we have 25 tasks to comeplete. Either we can do those one by one and whenever we need to do that again do those one by one again or we can write those in a file known as shell script and then we can execute those all at once and we can reuse that again and again whenver need be. So it just makes our life easier.

It is useful for scheduling and automation. It can run in some day at certain time and we won't even need to touch something.

Also we can make the file without using the .sh extension but it is recommended to use for intuitiveness.

## First shell program

```shell
#!/bin/bash

echo "hello world"
```

The above is the first shell program and it prints out hello world as intended. Here we have a few things to note:

- **SHEBANG**: It is used to tell the linux kernel what interpreter/shell to use to execute the shell script. There may be cases where the shell might be different and as such it is used to make sure that there are no compatibility issues. It works without this line but it is better to follow the standards.
- **echo "some message"**: It is used to print something in the terminal.
