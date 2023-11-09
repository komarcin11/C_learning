#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str; // Declare a pointer to a character (will be used for the string)

    printf("Enter a string: ");

    // Allocate memory for the string
    str = (char *)malloc(1 * sizeof(char)); // Here, the * symbol denotes a pointer, and malloc allocates memory

    if (str == NULL) { // Check if memory allocation was successful
        printf("Memory allocation failed.\n");
        return 1; // Exit the program with an error status
    }

    int c; // Variable to store the characters read from the input
    size_t len = 0; // Variable to keep track of the length of the string

    // Read the string character by character
    while ((c = getchar()) != '\n' && c != EOF) { // Read characters until a newline or EOF is encountered
        str[len++] = c; // Store the character and increment the length
        str = (char *)realloc(str, (len + 1) * sizeof(char)); // Resize the memory block for the string

        if (str == NULL) { // Check if memory reallocation was successful
            printf("Memory reallocation failed.\n");
            return 1; // Exit the program with an error status
        }
    }

    str[len] = '\0'; // Null-terminate the string

    printf("You entered: %s\n", str); // Print the input string

    // Free the allocated memory
    free(str);

    return 0;
}
