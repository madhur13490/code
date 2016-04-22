#include<string.h>

// Returns 0 if first string is
// either lexicographically smaller than second or shorter in length
// otherwise 1

int charCompare(char a, char b)
{
    if (a == b) return -1;
    if (a < b) return 0;
    else return 1;
}

int LexOrder(char *first, char *second)
{
    int t, i, j;
    
    if (strlen(first) < strlen(second)) {
        for (i = 0; i < strlen(first); i++) {
            t = charCompare(first[i], second[i]);
            if ( t == -1) continue;
            else return t;
        }
        return 0; 
    } else if (strlen(first) > strlen(second)) {
        for (i = 0; i < strlen(second); i++) {
            t = charCompare(first[i], second[i]);
            if ( t == -1) continue;
            else return t;
        }
        return 1; 
    } else {
        for (i = 0, j = 0; i < strlen(first) && strlen(second); i++, j++) {
            t = charCompare(first[i], second[j]);
            if ( t == -1) continue;
            else return t;
        }
        return 0;
    }
}
    
