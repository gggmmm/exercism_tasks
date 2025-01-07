#include "sum_of_multiples.h"
#include <math.h>
#include <stdlib.h>

unsigned int sum(const unsigned int *factors,
                 const size_t number_of_factors,
                 const unsigned int limit)
{
    unsigned int    sum = 0;
    unsigned int    *multiples = malloc(sizeof(unsigned int));
    multiples[0] = 0;
    size_t          total = 1;

    // finding all the multiples
    for(size_t i=0; i<number_of_factors; i++) {
        if(factors[i] < limit){
            for(size_t j=1; j<limit; j++) {
                if(j*factors[i] < limit) {
                    multiples[total-1] = factors[i] * j;
                    total++;
                    multiples = realloc(multiples, total * sizeof(unsigned int));
                    multiples[total-1] = 0;
                }
            }
        }
    }

    // setting the duplicates to 0, so that when added all together they don't contribute
    for(size_t i=0; i<total; i++){
        for(size_t j=i+1; j<total; j++){
            if(multiples[i] == multiples[j])
                multiples[j] = 0;
        }
    }

    // final sum
    for(size_t i=0; i<total; i++){
        sum += multiples[i];
    }

    return sum;
}
