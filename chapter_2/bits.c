#include <stdio.h>
#include <string.h>

#define BUFFER_MAX      50

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
        return (~(~(~0u >> n) >> (32 - p)) & x) | ((~(~0u << n) & y) << (p - n));
}

unsigned invert(unsigned x, int p, int n)
{
        return ~((~(~0u >> n) >> (32 - p)) & x) & (~(~0u >> n) >> (32 - p)) | (~(~(~0u >> n) >> (32 - p)) & x);
}

unsigned rightrot(unsigned x, int n)
{
        return (((~0u >> (32 - n)) & x) << (32 - n)) | (x >> n);
}

unsigned leftrot(unsigned x, int n)
{
        return (((~0u << (32 - n)) & x) >> (32 - n)) | (x << n);
}

void reverse(char* buffer, int len)
{
        int i, j, tmp;
        for (i = 0, j = len - 1; i < j; ++i, --j)
                tmp = buffer[i], buffer[i] = buffer[j], buffer[j] = tmp;
}

void serializebits(unsigned x, char* out, int max)
{
        const int size = 32;
        char buffer[size + 1];
        int j = 0;
        for (int i = 0; i < size; ++i) {
                if (i && !(i % 8))
                        buffer[j++] = ' ';
                if (x & 1)
                        buffer[j++] = '1';
                else
                        buffer[j++] = '0';
                x >>= 1;
        }
        buffer[j] = 0;
        reverse(buffer, j);
        strncpy(out, buffer, max);
}

// ex 2-{6,7,8}
int main()
{
        unsigned x = 123456789;
        unsigned y = 987654321;

        char buffer[BUFFER_MAX];
        serializebits(x, buffer, BUFFER_MAX);
        printf("x:\t\t%s\n", buffer);
        serializebits(leftrot(x, 8), buffer, BUFFER_MAX);
        printf("serialized:\t%s\n", buffer);

        return 0;
}
