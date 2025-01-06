#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arr.h"


/*
 * Reads count int values from f storing the values in
 * the specified array.
 *
 * Does not close the file f.
 */
void arr_readn(FILE *f, size_t count, int *arr)
{
	for (size_t i = 0; i < count; ++i)
	{
		fscanf(f, "%d", &arr[i]);
	}
}


/*
 * Reads characters from f storing the characters in the array
 * pointed at by s. Stops reading when a newline character '\n'
 * is reached, or when max_length characters are read. A newline
 * character is never stored in the array pointed at by s.
 * A null terminator is always stored to indicate the end of the
 * string.
 *
 * Returns true if a newline character is reached (indicating
 * that an entire line of the file was read). Returns false
 * if the last character read was not the newline character,
 * or if reading from the file failed for some reason.
 *
 * Does not close the file f.
 */
bool arr_readline(FILE *f, size_t max_length, char *s)
{

	for (size_t i = 0; i < max_length; ++i)
	{
		int c = fgetc(f);
        // check if found newline
		if (c == '\n')
		{
			s[i] = '\0';
			return true;
		}

		s[i] = (char)c;
	}

	s[max_length - 1] = '\0';
	return false;
}

/*
 * Extracts integer values from a string where the integer values
 * are separated from one another by a single comma (no spaces).
 * The integer values are returned in a newly allocated array
 * having capacity exactly equal to the number of integers extracted.
 * The number of extracted integers is written into the object
 * pointed at by n.
 */

int *arr_fromstr(const char *s, size_t *n)
{
    size_t count = 1;
    // count the commas
    for (size_t i = 0; s[i] != '\0'; ++i)
    {
        if (s[i] == ',')
            count++;
    }
    //allocate memory for integers
    int *arr_int = (int *)malloc(count * sizeof(int));
    char *token;
    char *r = (char *)s;

    //uses strtok_r to read integer values from the string
    for (size_t i = 0; i < count; ++i)
    {
        token = strtok_r(r, ",", &r);
        //Error parsing String
        if (token == NULL)
        {
            fprintf(stderr, "Error parsing string.\n");
            free(arr_int);
            *n = 0;
            return NULL;
        }

        arr_int[i] = atoi(token);
    }
    *n = count;
    return arr_int;
}


/*
 * Uncompresses the n element compressed array enc returning
 * a pointer to the first element of a new array
 * containing the uncompressed array. Writes the length of the
 * uncompressed array into the object pointed at by dec_len.
 *
 * The returned array has no excess capacity (i.e.,
 * all values in the returned array are meaningful).
 */
int *arr_decode(size_t n, const int *enc, size_t *dec_len)
{
    size_t decodedLength = 0;
    int Count = 0;
    int value = 0;

    // Calculate the length of array
    for (size_t i = 0; i < n; i += 2)
        decodedLength += enc[i];

    // allocates memory
    int *dec_arr = (int *)malloc(decodedLength * sizeof(int));
    size_t decIndex = 0;

    // populate decoded array
    for (size_t i = 0; i < n; i += 2)
    {
        Count = enc[i];
        value = enc[i + 1];
        for (size_t j = 0; j < Count; ++j)
            dec_arr[decIndex++] = value;
    }

    *dec_len = decodedLength;
    return dec_arr;
}
