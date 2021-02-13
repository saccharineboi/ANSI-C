#include <stdio.h>
#include <ctype.h>

int htoi(const char s[])
{
        int i = 0, n = 0;

        if (s[i] == '0')
                ++i;
        if (s[i] == 'x' || s[i] == 'X')
                ++i;
        else if (i == 1)
                return n;

        for (; s[i]; ++i) {
              if (isdigit(s[i]))
                      n = 16 * n + (s[i] - '0');
              else if ((s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <= 'F'))
                      n = 16 * n + (s[i] - (isupper(s[i]) ? 'A' : 'a')) + 10;
              else
                      return n;
        }
        return n;
}

// ex 2-3
int main()
{
        printf("%d\n", htoi("0xff"));

        return 0;
}
