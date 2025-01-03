#include <stdio.h>
#include <string.h>

int main()
{
    char a[30], fs[100] = "", t[2], sd, ed;
    int i;

    // Input string
    printf("Enter a string: ");
    scanf("%s", a);

    // Input start and end delimiters
    printf("Enter the start delimiter: ");
    scanf("%c", &sd); // Note the space before %c to skip any newline
    printf("Enter the end delimiter: ");
    scanf("%c", &ed);

    // Add the start delimiter to the result
    strncat(fs, &sd, 1);

    // Process the input string
    for (i = 0; a[i] != '\0'; i++)
    {
        t[0] = a[i];
        t[1] = '\0'; // Null-terminate the temporary string

        // If the character matches the delimiters, escape it by appending the delimiter again
        if (a[i] == sd || a[i] == ed)
        {
            strncat(fs, &a[i], 1);
        }

        // Append the character to the final string
        strncat(fs, &a[i], 1);
    }

    // Add the end delimiter to the result
    strncat(fs, &ed, 1);

    // Print the final string
    printf("\nThe final string is: %s\n", fs);

    return 0;
}
