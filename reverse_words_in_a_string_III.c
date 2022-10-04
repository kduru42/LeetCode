#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *reverseWords(char * s){
    int i;
    int temp;
    int toReverse;
    char *reversed;
    
    i = 0;
    toReverse = 0;
    reversed = (char *)malloc(sizeof(char) * strlen(s) + 1);
    while(s[i])
    {
        while (s[i] != 32 && s[i])
            i++;
        temp = i - 1;
        while (toReverse < i)
            reversed[toReverse++] = s[temp--];
        reversed[toReverse++] = s[i];
        i++;
        if (!s[i - 1])
            return (reversed);
    }
    return (reversed);
}
