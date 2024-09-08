#include <stdio.h>
#include <string.h>
# define STUFF "010101"
void main()
{
    char a[20], fs[50] = "", t[6], r[5];
    int i, j, p = 0, q = 0;
    // clrscr();
    printf("Enter a  bit string: ");
    scanf("%s", a);
    strcat(fs, STUFF);
    if (strlen(a) < 5)
    {
        strcat(fs, a);
    }
    else
    {
        for (i = 0; i < strlen(a) - 4; i++)
        {
            for (j = i; i < i + 5; i++)
            {
                t[p++] = a[j];
            }
            t[p] = '\0';
            if (strcmp(t, "11111") == 0)
            {
                strcat(fs, "111110");
                i = j - 1;
            }
            else
            {
                r[0] = a[i];
                r[1] = '\0';
                strcat(fs, r);
            }
            p = 0;
        }

        for (q = i; q < strlen(a); q++)
        {
            t[p++] = a[q];
        }
        t[p] = '\0';
        strcat(fs, t);
    }
    strcat(fs, STUFF);
    printf("\nThe final string is: %s", fs);
    // getch();
}
