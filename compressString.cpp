// Code to compress duplicates into number
// E.g. aaaabbb -> a4b3

#include<stdio.h>
#include<string.h>

int main()
{

        char c[100];
        char p[100];
        scanf ("%s", c);


        int j = 0, k = 0;

        while(j < strlen(c)) {
                char t = c[j];
                p[k++] = t;
                p[k] = '1';
                j++;

                while(t == c[j]) {
                        j++;
                        p[k]++;
                }

                if (j == strlen(c)) {
                        p[++k] = '\0';
                } else {
                }
                k++;
        }


        printf("%s", p);
        return 0;
}
