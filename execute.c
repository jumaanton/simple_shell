#include "main.h"

void cmd_exe(char **args){

    char *cmmd = NULL;

    char *path_cmd = NULL;

    if (args) {
        // grabbing the command from the args array
        cmmd = args[0];

        // getting the path of the command
        path_cmd = get_pathname(cmmd);

        // checking if the command has been executed successfully else deiplay an error

        if(execve(path_cmd, args, NULL) == -1){
            perror("Error");
        }
    }
}

