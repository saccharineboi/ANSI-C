#include <stdio.h>

#define TABSIZE 8

// ex 1-20
int main()
{
        int c, i, j, tmp;

        i = 0;
        while ((c = getchar()) != EOF) {
                if (c == '\t') {
                        tmp = i;
                        for (j = 0; j < TABSIZE - tmp % TABSIZE; ++j, ++i)
                                putchar(' ');
                }
                else {
                        putchar(c);
                        if (c == '\n')
                                i = 0;
                        else
                                ++i;
                }
        }
}
