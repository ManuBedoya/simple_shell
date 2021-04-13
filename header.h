#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

char *foundCommand(char *concatanated, int lenCommand);
int isBuiltIn(char *builtin);
char *getCommand(char *command);
void tokenize(char *line);
void interactiveMode(void);
void non_interactive(void);
#endif
