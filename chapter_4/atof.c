#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 1000

int get_line(char line[], int max)
{
        int i, c;

        for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
                line[i] = c;
        if (c == '\n')
                line[i++] = c;
        line[i] = 0;
        return i;
}

double nth(double x, int p)
{
        double r = 1.0;
        if (p < 0)
                for (; p < 0; ++p)
                        r /= x;
        else if (p > 0)
                for (; p > 0; --p)
                        r *= x;
        return r;
}

double atof(char s[])
{
        double value, power;
        int i, sign, exp, res;

        for (i = 0; isspace(s[i]); ++i)
                ;
        sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '-' || s[i] == '+')
                ++i;
        for (value = 0.0; isdigit(s[i]); ++i)
                value = 10.0 * value + (s[i] - '0');
        if (s[i] == '.')
                ++i;
        for (power = 1.0; isdigit(s[i]); ++i) {
                value = 10.0 * value + (s[i] - '0');
                power *= 10.0;
        }
        if (s[i] == 'e' || s[i] == 'E')
                ++i;
        exp = (s[i] == '-') ? -1 : 1;
        if (s[i] == '-' || s[i] == '+')
                ++i;
        for (res = 0; isdigit(s[i]); ++i)
                res = res * 10 + s[i] - '0';

        return sign * value / power * nth(10.0, exp * res);
}

// ex 4-2
int main()
{
        char line[MAXLINE];
        double sum = 0.0;

        while (get_line(line, MAXLINE))
                printf("sum: %f\n", sum += atof(line));

        return 0;
}
