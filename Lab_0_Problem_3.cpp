#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int storedArray[10];
    
    // Stores 10 numbers in an array
    printf("From number : ");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d",&storedArray[i]);
    }
    
    int original[10];
    for (int num = 0; num < sizeof(storedArray) / sizeof(int); num++)
    {
        original[num] = storedArray[num];
    }
    
    // Sorting array
    int temp;
    for (int m = 0; m < sizeof(storedArray) / sizeof(int) - 1; m++)
    {
        for (int k = 0; k < sizeof(storedArray) / sizeof(int) - 1; k++)
        {
            if (storedArray[k] > storedArray[k + 1])
            {
                temp = storedArray[k];
                storedArray[k] = storedArray[k + 1];
                storedArray[k + 1] = temp;
            }
        }
    }
    printf("To sorted number: ");
    for (int l = 0; l < sizeof(storedArray) / sizeof(int); l++)
    {
        printf("%d ", storedArray[l]);
    }
    printf("\nThe two smallest numbers are %d and %d\n", storedArray[0], storedArray[1]);
    printf("The two largest numbers are %d and %d", storedArray[8], storedArray[9]);
    printf("\n\n");
    return 0;
}
