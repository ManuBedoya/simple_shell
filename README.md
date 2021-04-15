# Simple_shell. 💻

<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li> <a href="#how-to-compile">¿How to compile?</a></li>
    <li><a href="#getting-started">How is it used</a></li>
    <li><a href="#usage">Man Page</a></li>
    <li><a href="#roadmap">Flowchart</a></li>
    <li><a href="#contributing">Files</a></li>
    <li><a href="#Authors">Authors</a></li>
  </ol>
</details>

_In this repository you will find a copy about ***Shell*** with any function of the real shell_.

---
## Description
Holberton School Shell (hsh), is a simple program of the line commands. This simple shell recreates basic and some more complex functionalities to result in our own Shell. This shell si developed in the programming language c. This shell takes the keyboard commands and delivers them to the system to be executed. some built-in commands implement: exit, env, help, cd.

---
## ¿How to compile?

- _Run that command on your console where the project is located._

```
gcc -Wall -Werror -Wextra -pedantic -Wno-format *.c -o hsh && ./hsh
```
---

## ¿How is it used?

- These are some examples of how you can use it.

```c
~$./hsh
($) /bin/ls
text1.txt test script.sh
($) exit
~$
```
```c
~$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
```
```c
~$ cat test_ls_2
/bin/ls
/bin/ls
~$
~$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
~$
```
---
## 📖 - Man Page

* To see the _printf manual you must execute this command.

```
man ./man_1_simple_shell
```
---

## Flowchart simple_shell

* You can see the Flowchart in this link: <a href="https://miro.com/app/board/o9J_lJl4RUA=/">Flowchart</a>

---

## 🗃 - Files

No|Files|Description
:---:|:---|:---:
1|[README.md](./README.md)| It contains all the information about the project and all its content.
2|[AUTHORS](./AUTHORS)| names and emails of colaborators.
3|[_printf.c](./_printf.c)| Own printf.
4|[builtins.c](.builtins.c)| have the function of the buit.ins (exit and env)
5|[getCommand.c](./getCommand.c)| Search the address of a command.
6|[header.h](./header.h)| header of the _shell
7|[headerPrintf.h](./headerPrintf.h)| header of the _printf
8|[interactiveMode.c](./interactiveMode.c)| have the infinite loop and show the propmt
9|[myFunctions.c](./myFunctions.c)| have string own functions like _strcat _strcpy _strlen.
10|[putchar_func](./putchar_func)| function to print a character.
11|[simpleShell.c](./simpleShell.c)| It's the main of the program.
12|[tokenize.c](./tokenize.c)| It's where separate the arguments and execute the commands.

---

## Authors. <img src="https://image.flaticon.com/icons/png/512/25/25231.png" width="25" height="25">

- *Joel Silva* : [@DovaZk](https://github.com/DovaZk)
- *Manuel Bedoya* : [@ManuBedoya](https://github.com/ManuBedoya)
