#include <stdio.h>
#include <string.h>
const char *bindiv(const char *, const char *);
const char *binsub(const char *, const char *);
int f = 0, ll = 0;
main()
{
    char *a, p[20] = "10001000000100001",
             g[30], g1[30], yy[30] = "", td[30], *aa;
    int l = 0, i;
    // clrscr();
    printf("enter transfered data : ");
    scanf("%s", g);
    printf("enter received data : ");
    scanf("%s", td);
    strcpy(g1, g);
    strcat(g, "0000000000000000");
    printf("\n%s ) %s (", p, g);
    a = bindiv(g, p);
    if (strlen(a) < 16)
    {
        for (i = strlen(a); i < 16; i++)
        {
            yy[l++] = '0';
        }
        yy[l] = '\0';
    }
    strcat(yy, a);
    strcat(g1, yy);
    printf("\n ------------------");
    printf("\ncrc is %s", yy);
    strcat(td, yy);
    printf("\n\n%s ) %s (", p, td);
    ll = 0;
    aa = bindiv(td, p);
    strcpy(a, aa);
    printf("\n %s", a);
    printf("\n -----------------");
    if (f == 1)
        printf("\ndata transfered correctly");
    else
        printf("\ndata transfered incorrectly");
    // getch();
}

const char *bindiv(const char *s, const char *d)
{
    int i, j, k = 0, x = 17, h, p = 0, l;
    char q[25] = "", b[30], *w;
    for (i = 0; i < strlen(s); i++)
    {
        if ((i + x) > strlen(s))
            x = (i + x) - strlen(s) + 1;
        for (j = i; j < (i + x); j++)
        {
            b[k++] = s[j];
        }
        b[k] = '\0';
        if (ll != 0)
            printf("\n %s", b);
        ll = 1;
        if (strlen(b) == 16)
        {
            break;
        }
        printf("\n %s", d);
        printf("\n -----------------");
        w = binsub(b, d);
        k = 0;
        i = j - 1;
        for (l = 0; l < strlen(w); l++)
        {
            if (w[l] == '1')
                break;
        }
        if (l == strlen(w))
        {
            f = 1;
            return (w);
        }
        for (h = l; h < strlen(w); h++)
        {
            q[p++] = w[h];
        }
        q[p] = '\0';
        x = 17 - strlen(q);
        strcpy(b, "");
        strcat(b, q);
        k = strlen(q);
        p = 0;
    }
    return (b);
}
const char *binsub(const char *x, const char *y)
{
    int i, j = 0;
    char w[25] = "", e[3], f[3], n[3];
    e[0] = '1';
    e[1] = '\0';
    f[0] = '0';
    f[1] = '\0';
    for (i = 0; i < strlen(x); i++)
    {
        if ((x[i] == '1') && (y[i] == '1'))
            strcat(w, f);
        else if ((x[i] == '0') && (y[i] == '0'))
            strcat(w, f);
        else
            strcat(w, e);
    }
    n[0] = '\0';
    n[1] = '\0';
    strcat(w, n);
    return (w);
}