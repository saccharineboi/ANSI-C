#include <stdio.h>

void strncat_ptr(char* s, char* t, int n)
{
        if (!s || !t || n <= 0)
                return;
        for (; *s; ++s)
                ;
        while (n-- && (*s++ = *t++))
                ;
}

// ex 5-5 (strncat)
int main()
{
        char s[50] = "hello";
        char t[] = " world";
        strncat_ptr(s, t, 2);
        printf("%s\n", s);
}
