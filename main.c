#include "main.h" // including the header file

int main(void) {
    
    // code block for prompt

    // Printing Symbol for the shell
    char *printprompt = "@simpleshell~ ";

    char *lineprinter = NULL;

    size_t size = 0;

    // initializing variable to exit the shell when user presses ctrl + d
    ssize_t readn_chars;

    // initializing the variables to handle commands
    char *lineprinter2 = NULL;

    //delim is a string of characters that are used to separate the input from the user
    const char *delim = " \n\t\r";

    // // declaring execution function
    // // command execution prototype
    // void cmd_exe(char **args);

    // // getting pathname prototype
    // char *get_pathname(char *args);

    // Adding an infinite loop to keep the shell running until the user exits

    while (1) {
        // printing the prompt
        printf("%s", printprompt);

        // getline() func reads in an input from the stdin and stores it in the lineprinter variable
        // getline(&lineprinter, &size, stdin);

        readn_chars = getline(&lineprinter, &size, stdin);

        // checking if EOF has been reached or if an error has occured or if the user exits the shell
        if (readn_chars == EOF || readn_chars == -1) {
            // // freeing the memory allocated to lineprinter by the getline() func
            // free(lineprinter);
            // // exiting the shell
            // exit(0);

            printf("Byeeeee!! Too bad you are leaving...\n");
            return (-1);
        }

        // Handling commands in the shell
        // were trying to omplement the strtok() func to handle commands
        // strtok() func takes in two arguments, the first is the string to be tokenized and the second is the delimeter


        // allocating stapace for the lineprinter2 variable using the malloc()
        //multiplying the size of the char by the number of characters read in by the getline() func
        lineprinter2 = malloc(sizeof(char) * readn_chars);

        if (lineprinter2 == NULL) {
            printf("Error: Unable to allocate memory\n");
            return (-1);
        }

        // making a copy of the lineprinter variable to the lineprinter2 variable
        strcpy(lineprinter2, lineprinter);

        // tokenizing the lineprinter2 variable
        char *token = strtok(lineprinter, delim);

        // calculating the number of tokens available
        int numtokens = 0;

        while (token != NULL) {
            numtokens++;
            token = strtok(NULL, delim);
        }

        // alocating space for the array of tokens

        char **tokens = malloc(sizeof(char *) * numtokens);

        // storing the tokens in the array of tokens
        token = strtok(lineprinter2, delim);

        int i = 0;

        while (token != NULL) {
            tokens[i] = token;
            i++;
            token = strtok(NULL, delim);
        }

        // // printing the contents of the array of tokens
        // for (int i = 0; i < numtokens; i++) {
        //     printf("%s\n", tokens[i]);
        // }

        // executing the commands
        cmd_exe(tokens);

        // printing the input from lineprinter
        printf("%s\n", lineprinter);

    }

    // freeing the memory allocated to lineprinter by the getline() func
    // It is outside the loop to only allow being called once to avoid double error
    free(lineprinter);

    free(lineprinter2);


    return 0;
}
