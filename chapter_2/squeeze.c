#include <stdio.h>

#define true    1
#define false   0

void squeeze(char s[], char t[])
{
        int i, j, k, found;

        for (i = j = 0; s[i]; ++i) {
                found = false;
                for (k = 0; t[k] && !found; ++k)
                        if (t[k] == s[i])
                                found = true;
                if (!found)
                        s[j++] = s[i];
        }
        s[j] = 0;
}

// ex 2-4
int main()
{
        char s[] = "hello, world!";
        char t[] = "ol";
        squeeze(s, t);
        printf("%s\n", s);

        return 0;
}
