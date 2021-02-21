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

void itob(long n, char s[], int b)
{
        int i, sign;

        if ((sign = n) < 0)
                n = -n;

        i = 0;
        do {
                long r = n % b + '0';
                s[i++] = ((r > '9') ? (n % b + 'a' - 10) : (r));
        }
        while ((n /= b) > 0);

        if (sign < 0)
                s[i++] = '-';
        s[i] = 0;
        reverse(s);
}

// ex 3-5
int main()
{
        int x = INT_MAX;

        char buffer[100];
        itob(x, buffer, 16);
        printf("%s\n", buffer);
        printf("%x\n", x);

        return 0;
}
