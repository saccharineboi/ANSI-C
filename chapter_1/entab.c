#include <stdio.h>

#define TABSIZE 8

// ex 1-21
int main()
{
        int c, i, j;

        i = 0;
        while ((c = getchar()) != EOF) {
                if (c == ' ') {
                        ++i;
                        if (i / TABSIZE) {
                                i = 0;
                                putchar('\t');
                        }
                }
                else {
                        for (j = 0; j < i; ++j)
                                putchar(' ');
                        i = 0;
                        putchar(c);
                }
        }
}
