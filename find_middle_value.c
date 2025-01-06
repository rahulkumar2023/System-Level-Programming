#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int returncode = 0;
    if (argc == 1) 
    {
        printf("%f\n",0.0);
    } 
    else if (argc == 4)
    {
        double val[3];

        for (int i = 1; i <= 3; i++) 
        {
            val[i - 1] = atof(argv[i]);
        }

        if (val[0] > val[1])
        {
            if (val[1] >= val[2]) 
            {
                printf("%f\n", val[1]);
            } else if (val[0] <= val[2])
            {
                printf("%f\n", val[0]);
            } else 
            {
                printf("%f\n", val[2]);
            }
        } else if (val[0] > val[2]) 
        {
            if (val[2] >= val[1])
            {
                printf("%f\n", val[2]);
            } else if (val[0] <= val[1]) 
            {
                printf("%f\n", val[0]);
            } else 
            {
                printf("%f\n", val[1]);
            }
        } 
    }
    else 
        {
            returncode = 1; // Invalid input
        }
    
    return returncode;
}


