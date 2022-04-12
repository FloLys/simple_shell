# Simple Shell
**By Germán Izquierdo and Florencia Mestre, Holberton C17**

# What is
It's a prototype recreation of the *shell*, a program you access through any terminal which allows you to control and manage computer files and directories using different commands in the command line interface.
This *simple shell* implements the same type of command line and the calling of different commands with their corresponding flags but does not allow navigation, create or delete files/directories.

# How to use it
Enter the program by running its executable file, which opens the prompt and waits in an infinite loop for inputs of any type of text. 
If it's text that is not a `command`, it outputs an "not found" error.
If it's a `command`, it searches the program in all possible directories specified in the environment variable *"PATH="*, when found, checks if exists in it, then executes it. If it cannot be found, it's interpretated as plain text and outputs an "not found" error.
You can also type commands specifying the routeo of the directory you want to execute that command in (example: `/bin/ls`).
If you type *exit*, the loop ends and simple shell closes.
If you press `Ctrl+D`, prints an "exit" line before closing.

##### IDENTIFIERS

     %c   Prints a character.

     %s   Prints an array of characters.

     %d   Prints a decimal number.

     %i   Prints an integer number.

     %ui  Prints an unsigned integer.

     %b   Prints a number in binary.

     %o   Prints a number in octal.

##### FILES
     /_printf.c
          Main file.
     /fn_sel.c
          Function pointer to identified module functions.
     /fn_unk.c
          Counter function for an unknown identifier.
     /fn_print.c
          Definition of functions for character, string and module.
     /_print_i.c
          Definition of function for integers and decimals.
     /_print_ui.c
          Definition of function for unsigned integers.
     /_pwr.c
          Function to raise x to the power of x.
     /_putchar.c
          Custom function of putchar() to print the chars of the string.

###### BUGS
     Incomplete.

###### AUTHOR
     Florencia Mestre and German Izquierdo<https://github.com/FloLys/simple_shell>
