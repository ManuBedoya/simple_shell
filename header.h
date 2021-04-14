#ifndef HEADER_H
#define HEADER_H
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

char *foundCommand(char *concatanated, int lenCommand);
int isBuiltIn(char *builtin, char **environ);
char *getCommand(char *command, char **environ, char *filename, int iterator);
void tokenize(char *line, char **environ, char *filename, int iterator);
void interactiveMode(char **environ, char *filename);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _printf(const char *format, ...);
#endif
