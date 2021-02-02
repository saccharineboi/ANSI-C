#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int max)
{
        int i, c;

        for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
                line[i] = c;
        if (c == '\n')
                line[i++] = c;
        line[i] = '\0';
        return i;
}

void reverse(char line[], int len)
{
        int tmp;
        for (int i = 0, j = len - 2; i < j; ++i, --j)
                tmp = line[i], line[i] = line[j], line[j] = tmp;
}

int main()
{
        int len;
        char line[MAXLINE];

        while (len = get_line(line, MAXLINE)) {
                reverse(line, len);
                printf("%s", line);
        }
}
