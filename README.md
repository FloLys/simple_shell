# Simple Shell
**By Germán Izquierdo and Florencia Mestre, Holberton C17**

# What is
It's a prototype recreation of the *shell*, a program you access through any terminal which allows you to control and manage computer files and directories using different commands in the command line interface.

This *simple shell* implements the same type of command line and the calling of different commands with their corresponding flags but does not allow navigation, create or delete files/directories.

# How to use it
Enter the program by running its executable file, which opens the prompt and waits in an infinite loop for inputs of any type of text.

If it's text that is not a `command`, it outputs an "not found" error.

If it's a `command`, it searches the program in all possible directories specified in the environment variable *"PATH="*, when found, checks if exists in it, then executes it (example: `ls`). If it cannot be found, it's interpretated as plain text and outputs an "not found" error.

You can also type commands specifying the path of the directory you want to execute that command in (example: `/bin/ls`).

If you type `exit`, the loop ends and simple shell closes.

If you press `Ctrl+D`, prints an "exit" line before closing.

# Arguments
After recognizing the program that is always in the argument 0, the rest of the arguments are parsed and the program executes these arguments itself.
For example: 

     ls -l -s -a

Its equivalent `ls -lsa` works fine as well.

It can also take as an argument a full path directory to work on:

     ls /bin

This will list the contents of the `bin` directory. And `ls ../` will list the contents of its parent directory.

