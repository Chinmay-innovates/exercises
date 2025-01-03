#include <stdio.h>
#include <string.h>

#define BIT "01111110"

int main()
{
    char a[100], fs[200] = "", temp[6];
    int i, count = 0;

    printf("Enter a bit string: ");
    scanf("%s", a);

    // Add the opening BIT flag
    strcat(fs, BIT);

    for (i = 0; a[i] != '\0'; i++)
    {
        // Add the current bit to the final string
        strncat(fs, &a[i], 1);

        // Count consecutive 1's
        if (a[i] == '1')
        {
            count++;
        }
        else
        {
            count = 0; // Reset count if the bit is not 1
        }

        // If five consecutive 1's are detected, append a zero
        if (count == 5)
        {
            strcat(fs, "0");
            count = 0; // Reset count after appending a zero
        }
    }

    // Add the closing BIT flag
    strcat(fs, BIT);

    printf("\nThe final string is: %s\n", fs);

    return 0;
}
