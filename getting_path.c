#include "main.h"

// to get the path of the command we are trying to execute we need to use the PATH variable

//variable to store the path

char *get_pathname(char *args){
    // calling path1 and path2 as a copy of path
    char *path, *path2;

    // grabbing the path from the environment variable
    path = getenv("PATH");

    if (path) {
       
        // making a copy of the path
        path2 = strdup(path);

        //getting the length of the command
        int len = strlen(args);

        // splitting path copy into tokens
        char *token = strtok(path2, ":");

        // variable to store the stat of the file
        struct stat st;

        // looping through to get the path
        while (token != NULL){
             

            int dir_len = strlen(token);

            //variable storing the path
            char *pathname = malloc(sizeof(char) * (dir_len + len + 2));

            // copying the path into the pathname variable
            strcpy(pathname, token);

            strcat(pathname, "/");

            strcat(pathname, args);

            strcat(pathname, "\0");

            // checking if the file exists
            if (stat(pathname, &st) == 0) {

                // free path2 memory
                free(path2);

                return (pathname);
            }
            else{
                // free pathname memory
                free(pathname);

                token = strtok(NULL, ":");
            }
        }

        // case file path not found return null and free memory
        free(path2);

        // before exiting check if the command is a file path
        if (stat(args, &st) == 0) {
            return (strdup(args));
        }
        
        return (NULL);
        

    }

    return (NULL);

}
