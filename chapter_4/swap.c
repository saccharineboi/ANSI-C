#include <stdio.h>
#include <string.h>

#define swap(t, x, y)   \
{                       \
        t tmp = x;      \
        x = y;          \
        y = tmp;        \
}

// ex 4-14
int main()
{
        int l = 22, r = 44;
        swap(int, l, r);
        printf("l: %d, r: %d\n", l, r);

        return 0;
}
