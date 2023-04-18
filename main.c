#include "main.h" // including the header file

int main(void) {
    
    // code block for prompt

    // Printing Symbol for the shell
    char *printprompt = "@simpleshell~ ";

    char *lineprinter = NULL;

    size_t size = 0;

    printf("%s", printprompt);
    
    // getline() func reads in an input from the stdin and stores it in the lineprinter variable
    getline(&lineprinter, &size, stdin);

    // printing the input from lineprinter
    printf("%s\n", lineprinter);

    // freeing the memory allocated to lineprinter by the getline() func
    free(lineprinter);

    return 0;
}
