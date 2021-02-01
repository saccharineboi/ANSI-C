#include <stdio.h>

#define MAXLEN          25      // max chars in a word

// vertical histogram (ex 1-13)
int main()
{
        int i, j, c, nc, max, tmp;
        int freq[MAXLEN];

        for (i = 0; i < MAXLEN; ++i)
                freq[i] = 0;

        max = nc = 0;
        while ((c = getchar()) != EOF) {
                if (c == ' ' || c == '\t' || c == '\n') {
                        if (nc > 0 && nc < MAXLEN) {
                                ++freq[nc];
                                if (freq[nc] > max)
                                        max = freq[nc];
                        }
                        nc = 0;
                }
                else
                        ++nc;
        }

        tmp = max;
        for (i = 0; i < max; ++i) {
                for (j = 0; j < MAXLEN; ++j) {
                        if (freq[j] > 0) {
                                if (freq[j] >= tmp)
                                        printf(" _ ");
                                else
                                        printf("   ");
                        }
                }
                --tmp;
                putchar('\n');
        }

        for (i = 0; i < MAXLEN; ++i)
                if (freq[i] > 0)
                        printf("%2d ", freq[i]);
        putchar('\n');

        for (i = 0; i < MAXLEN; ++i)
                if (freq[i] > 0)
                        printf("%2d ", i);
        putchar('\n');
}
