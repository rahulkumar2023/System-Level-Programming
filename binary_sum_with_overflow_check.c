#include <stdio.h>

/*
 * Prints the values of a on a single line with no space between
 * the values. Prints a newline character after printing all of
 * the array values.
 * 
 * Values are printed left to right starting from a[0] and ending with a[7].
 */
 
void print(int a[static 8]) {
    for (int i = 0; i < 8; i++) {
        printf("%d", a[i]);
    }
    printf("\n");
}

 /*
 * Translates a string str consisting of '0' and '1' characters
 * into an array bin consisting of 0 and 1 integer values. For
 * example, the string "00000001" results in the array bin
 * having the values bin[0] = 0, bin[1] = 0, ..., bin[7] = 1.
 */
 
void tobinary(char str[static 8], int bin[static 8]) 
{
    for (int i = 0; i < 8; i++) 
    {
        bin[i] = str[i] - '0';
    }
}

/*
 * Sums the 8-digit binary values x and y storing the result
 * in z. The sum is computed using the standard long
 * addition algorithm from grade school.
 */
 
int sum(int x[static 8], int y[static 8], int z[static 8]) {
    int carry = 0;
    for (int i = 7; i >= 0; i--) {
        int tempSum = x[i] + y[i] + carry;
        z[i] = tempSum % 2;
        carry = tempSum / 2;
    }
    return carry;  // Return the carry for overflow check
}


int main(int argc, char *argv[]) {
    // if less than 2 agruments then exit without error
    if (argc != 3)
    {
        return 0;  
    }

    char *binary1 = argv[1];
    char *binary2= argv[2];

    int x[8], y[8], result[8];

    tobinary(binary1, x);
    tobinary(binary2, y);

    int carry = sum(x, y, result);
    print(result);
    
    if (carry == 1) {
        printf("Overflow\n");
    } 

    return 0;
}

