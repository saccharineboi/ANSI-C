#include <stdio.h>

int strncmp_ptr(char* s, char* t, int n)
{
        if (!s || !t || n <= 0)
                return 0;       // not a good way to indicate error!
        for (; (*s == *t); ++s, ++t, --n)
                if (!*s || n == 1)
                        return 0;
        return *s - *t;
}

// ex 5-5 (strncmp)
int main()
{
        printf("%d\n", strncmp_ptr("hello", "hello world", 5));
}
