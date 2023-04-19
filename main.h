# include<stdlib.h> // for the malloc() func
# include <string.h> // for the strtok() func
#include <stdio.h> // for the printf() func
#include <unistd.h> // for the execve() func
#include <sys/stat.h> // for the stat() func
#include <sys/types.h> // for the stat() func

// function to execute the commands
void cmd_exe(char **args);
char *get_pathname(char *args);

