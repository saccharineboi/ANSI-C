#include <stdio.h>

void strcat_ptr(char* s, char* t)
{
        for (; *s; ++s)
                ;
        while (*s++ = *t++)
                ;
}

// ex 5-3
int main()
{
        char b0[50] = "hello world";
        char b1[] = ", what's up?";
        strcat_ptr(b0, b1);
        printf("%s\n", b0);
}
