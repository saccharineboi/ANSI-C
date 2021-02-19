#include <stdio.h>
#include <ctype.h>
#include <string.h>

void expand(char s1[], char s2[])
{
        int i, j, k = 0;
        char cp, cn;

        for (i = 0; isspace(s1[i]); ++i)
                ;
        if (s1[i] == '-')
                s2[k++] = s1[i++];
        for (cp = s1[i]; s1[i] && s1[i] != '-'; ++i)
                cp = s1[i];
        if (s1[i] == '-')
                cn = s1[++i];
        if (isdigit(cp) && isdigit(cn)) {
                for (j = cp; j <= cn; ++j, ++k)
                        s2[k] = j;
        }
        else if ((isupper(cp) && isupper(cn)) || (islower(cp) && islower(cn))) {
                for (j = cp; j <= cn; ++j, ++k)
                        s2[k] = j;
        }
        s2[k] = 0;
}

// ex 3-3 (incomplete!!)
int main()
{
        char pattern[] = "2-9";
        char result[100];

        expand(pattern, result);
        printf("%s\n", result);
}
