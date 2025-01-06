#include "rotational_cipher.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *rotate(const char *text, int shift_key) {
    size_t size = strlen(text) ;
    char *res = malloc(size*sizeof(char));
    if(res==NULL) return NULL; // end if cannot allocate memory

    printf("%s shk %d\n", text, shift_key);
    printf("%c %d %c %c\n", text[0], text[0], 'a', 'a');

    char ch;
    for(size_t i = 0 ; text[i] != '\0' ; i++) {
        ch = '!'; // just a token

        if('a' <= text[i] && text[i] <= 'z') {
            ch = 'a';
        } if('A' <= text[i] && text[i] <= 'Z') {
            ch = 'A';
        }

        if(ch == '!') {
            res[i] = text[i];
        } else {
            res[i] = (text[i] - ch); // to int range
            res[i] += shift_key;     // shift as per cypher
            res[i] = res[i] % 26;    // make sure it's between 'a' and 'z'
            res[i] += ch;            // back to char range
        }
    }
    printf("%s\n", res);
    return res;
}
