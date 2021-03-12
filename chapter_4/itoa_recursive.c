#include <stdio.h>

void itoa_recursive(char s[], int n)
{
        static int stck, i;
        if (n < 0) {
                s[i++] = '-';
                n = -n;
        }

        ++stck;
        if (n / 10)
                itoa_recursive(s, n / 10);
        s[i++] = n % 10 + '0';
        if (--stck == 0) {
                s[i] = '\0';
                i = 0;
        }
}

// ex 4-12
int main()
{
        char test[20];
        
        itoa_recursive(test, 0);
        printf("%s\n", test);

        itoa_recursive(test, 99);
        printf("%s\n", test);

        itoa_recursive(test, 123);
        printf("%s\n", test);

        itoa_recursive(test, -5678);
        printf("%s\n", test);

        return 0;
}
