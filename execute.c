#include "main.h"

void cmd_exe(char **args){

    char *cmmd = NULL;

    if (args) {
        // grabbing the command from the args array
        cmmd = args[0];

        // checking if the command has been executed successfully else deiplay an error

        if(execve(cmmd, args, NULL) == -1){
            perror("Error");
        }
    }
}

