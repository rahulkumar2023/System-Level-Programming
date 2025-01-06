#include <stdlib.h>
#include <stdio.h>
#include "arr.h"


int main(int argc, char *argv[])
{
    // Check if the correct number of command line arguments is provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the file for reading
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return 2;
    }

    // Read the number of remaining lines in the file
    int numLines;
    arr_readn(file, 1, &numLines);

    // Consume the remainder of the line
    char temp[10];
    if (fgets(temp, sizeof(temp), file) == NULL)
    {
        fprintf(stderr, "Error reading remainder of the line.\n");
        fclose(file);
        return 3;
    }

    // Read and process each line in the file
    for (int i = 0; i < numLines; ++i)
    {   char line[100];
        if (!arr_readline(file, sizeof(line), line))
        {
            fprintf(stderr, "Error reading line %d.\n", i + 1);
            fclose(file);
            return 4;
        }
        // Extract integer values from the line
        size_t numValues;
        int *encoded = arr_fromstr(line, &numValues);

        if (encoded == NULL)
        {
            fprintf(stderr, "Error extracting values from line %d.\n", i + 1);
            fclose(file);
            return 5;
        }
        // Decode the array
        size_t decoded_len;
        int *decoded = arr_decode(numValues, encoded, &decoded_len);
        if (decoded == NULL)
        {
            fprintf(stderr, "Error decoding array from line %d.\n", i + 1);
            free(encoded);
            fclose(file);
            return 6;
        }
        // Print the decoded values
        for (size_t j = 0; j < decoded_len; ++j)
        {
            if (decoded[j] == 0)
                printf(" ");
            else
                printf("#");

        }
        printf("\n");

        // Free allocated memory
        free(encoded);
        free(decoded);
    }

    // Close the file
    fclose(file);
    return 0;
}

