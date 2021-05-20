#include <stdio.h>

int strend_ptr(char* s, char* t)
{
        if (!s || !t)
                return 0;
        for (; *s; ++s) {
                char* tmp = s;
                for (; *t && *tmp && *t == *tmp; ++t, ++tmp)
                        ;
                if (!*tmp && !*t)
                        return 1;
        }
        return 0;
}

// ex 5-4
int main()
{
        printf("%d\n", strend_ptr("hello world", "hello"));     // 0
        printf("%d\n", strend_ptr("hello world", "world"));     // 1
}
