#include "main.h" // including the header file

int main(void) {
    
    // code block for prompt

    // Printing Symbol for the shell
    char *printprompt = "@simpleshell~ ";

    char *lineprinter = NULL;

    size_t size = 0;

    ssize_t readn_chars;

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

        // printing the input from lineprinter
        printf("%s\n", lineprinter);

    }

    // freeing the memory allocated to lineprinter by the getline() func
    // It is outside the loop to only allow being called once to avoid double error
    free(lineprinter);

    return 0;
}
