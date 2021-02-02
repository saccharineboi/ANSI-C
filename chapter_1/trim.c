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

void trim(char line[], int len)
{
        int i;
        for (i = len - 1; i >= 0 && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'); --i)
                ;
        if (i == -1)
                line[0] = '\0';
        else {
                line[i + 2] = '\0';
                line[i + 1] = '\n';
        }
}

int main()
{
        int len;
        char line[MAXLINE];

        while (len = get_line(line, MAXLINE)) {
                trim(line, len);
                printf("%s", line);
        }
}
