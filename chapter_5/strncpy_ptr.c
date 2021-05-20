#include <stdio.h>

void strncpy_ptr(char* s, char* t, int n)
{
        if (!s || !t || n <= 0)
                return;
        for (int i = 0; i < n && (*s++ = *t++); ++i)
                ;
}

// ex 5-5 (strncpy)
int main()
{
        char s[50] = "first";
        char t[] = " second";

        strncpy_ptr(s, t, 50);
        printf("%s\n", s);
}
