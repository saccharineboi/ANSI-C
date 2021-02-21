#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

void reverse(char s[])
{
        int tmp;
        for (int i = 0, j = strlen(s) - 1; i < j; ++i, --j)
                tmp = s[i], s[i] = s[j], s[j] = tmp;
}

void itoa(long n, char s[])
{
        int i, sign;

        if ((sign = n) < 0)
                n = -n;

        i = 0;
        do
                s[i++] = n % 10 + '0';
        while ((n /= 10) > 0);

        if (sign < 0)
                s[i++] = '-';
        s[i] = 0;
        reverse(s);
}

// ex 3-4
int main()
{
        int x = INT_MIN;

        char buffer[100];
        itoa(x, buffer);
        printf("%s\n", buffer);
        printf("%d\n", x);

        return 0;
}
