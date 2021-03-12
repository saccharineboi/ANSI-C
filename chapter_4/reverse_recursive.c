#include <stdio.h>
#include <string.h>

void reverse(char s[], int l, int r)
{
        int tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;

        if (l < r - 1)
                reverse(s, l + 1, r - 1);
}

// ex 4-13
int main()
{
        char line[] = "Hello World!";
        reverse(line, 0, strlen(line) - 1);
        printf("%s\n", line);

        return 0;
}
