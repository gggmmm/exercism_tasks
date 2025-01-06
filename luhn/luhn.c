#include "luhn.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool luhn(const char *num) {
    printf("%s\n", num);
    size_t len = strlen(num);
    if(len <= 1) // only process valid string
	return false;

    int num_valid_char = 0;
    int* clean_num = malloc(len*sizeof(int));
    if(!clean_num)
	return false; // can't allocate memory

    // convert char to numbers
    for(size_t i=0; i<len; i++){
        if((num[i]<'0' || num[i]>'9') && num[i] != ' ') // interrupt if not a number or space
            return false;
        if('0'<= num[i] && num[i] <= '9'){
            clean_num[num_valid_char++] = num[i] - '0';
        }

        if(num[i] != ' ')
            printf("%c - %d \n", num[i], clean_num[num_valid_char-1]);
    }
    if(num_valid_char <= 1)
	return false;

    for(int i=0; i<num_valid_char; i++) printf("%d", clean_num[i]);
    printf("\n");

    int sum = 0;
    // actually implementing the luhn algorithm
    for(int i=0; i<num_valid_char; i++){
        int tmp = clean_num[num_valid_char-i-1];

        if(i%2==1)
            tmp *= 2;

        if(tmp >= 10)
            tmp -= 9;
        printf("cn clean_num %d tmp %d i %d\n", clean_num[i], tmp, i);
        sum += tmp;
    }
    return (sum%10 == 0);
}

