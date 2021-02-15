#include <stdio.h>
#include <string.h>

#define BUFFER_MAX      50

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

int countbits_fast(unsigned x)
{
        int cnt = 0;
        for (cnt = 0; x != 0; x &= (x - 1))
                ++cnt;
        return cnt;
}

// ex 2-9
int main()
{
        int x = 12345;
        char buffer[BUFFER_MAX];
        serializebits(x, buffer, BUFFER_MAX);
        printf("%s\n", buffer);
        printf("%d\n", countbits_fast(x));

        return 0;
}
