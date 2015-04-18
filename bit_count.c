#include <stdio.h>
#include <stdlib.h>


// Define a function to count the bits in a
// number, and find the hightest and lowest
// 1 bit positions. Valid positions are 0
// for the lowest position, through 31 for
// the highest position. If the number has
// no 1 bits, the positions are both -1.
// ... you will need to change this function
// definition entirely
void analyze(const unsigned x, unsigned *bit_count, int *high_1, int *low_1) {
    *bit_count=0;
    //high_1, low_1;
    *high_1 = *low_1 = 0;
    //unsigned* result = malloc(sizeof(unsigned)*3);
    //unsigned myArray[3]={};
    if(x == 0){
        (*high_1) = -1;
        (*low_1) = -1;
    }

    for(int i = 0; i<32; i++){
        if (((x>>i)&1) == 1){
            (*bit_count)++;
            (*high_1) = i;
        }
    }
    for(int j = 0; j<32; j++){
        if (((x>>j)&1) == 1){
            (*low_1) = j;
            break;
        }
    }
    //myArray[0] = bit_count;
    //myArray[1] = high_1;
    //myArray[2] = low_1;
    //result = &myArray;
    //return result;
}


void bit_analyze(const int x) {
    unsigned bit_count = 0;
    int high_1, low_1;
    high_1 = low_1 = 0;
    

    
    // Call the function you defined, and update
    // the 3 values: bit_count, high_1, low_1.
    // ... you will need to change this function
    // call to match your function definition
    //unsigned* myArray = analyze(x);
    //bit_count = *myArray;
    //high_1 = *(myArray+1);
    //low_1 = *(myArray+2);
    
    analyze(x, &bit_count, &high_1, &low_1);
    
    printf("   NUMBER: %u\n",x);
    printf("     BITS: %u\n",bit_count);
    printf("HIGHEST 1: %d\n",high_1);
    printf(" LOWEST 1: %d\n",low_1);
    printf("\n");
}
int stoi(const char * str) {
    char * x = NULL;
    const long parsed = strtol(str, &x, 0);
    return x==str ? 0 : (int)parsed;
}
int main(int argc,
         const char * argv[]) {
    bit_analyze(argc>1 ? stoi(argv[1]) : 0);    
    return 0;
}
