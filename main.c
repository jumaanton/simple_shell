#include "main.h" // including the header file

int main(void) {
    
    // code block for prompt

    // Printing Symbol for the shell
    char *printprompt = "@simpleshell~ ";

    char *lineprinter = NULL;

    size_t size = 0;

    // Adding an infinite loop to keep the shell running until the user exits

    while (1) {
        // printing the prompt
        printf("%s", printprompt);

        // getline() func reads in an input from the stdin and stores it in the lineprinter variable
        getline(&lineprinter, &size, stdin);

        // printing the input from lineprinter
        printf("%s\n", lineprinter);

    }

    // freeing the memory allocated to lineprinter by the getline() func
    // It is outside the loop to only allow being called once to avoid double error
    free(lineprinter);

    return 0;
}
