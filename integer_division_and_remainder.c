#include <stdio.h>
#include <stdlib.h>

int divide(int x, int y, int *rem, double *quot)
 {
    *quot = (double)(x) / y;
    *rem = x % y;
     return (int)(x/y);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: divide int1 int2\n");
    } 
    else {
    int val1 = atoi(argv[1]);
    int val2 = atoi(argv[2]);
     
    
    int remainder;
    double quotient;
    
    int  iquo= divide(val1, val2, &remainder, &quotient);
    
    printf("%d rem %4d\n", iquo, remainder);
    
    printf("%8.3lf\n", quotient); 
    }
}
