#include <stdio.h>
#include <stdlib.h>


int collatz(long int n);  // colatz function declaration 
int main(int argc, char *argv[]) {
if (argc != 3) {    // check for 2 input numbers

        fprintf(stderr, "Usage: %s arg1 arg2\n", argv[0]);  // print a message
        return 1; // Non-zero return value usually indicates a problem
    }
    long int num1 = atoi(argv[1]); // num1 initialization  using the atoi function 
    long int num2 = atoi(argv[2]); // num2 -\\-        -\\-
    if ( num1==0 || num1<0 || num1<-100000000 || num1>100000000){ //check for the values of num1
        printf("0\n");
        return 0;
    }
    if (num1>num2){ // check for largest limit
        printf("0\n");
        return 0;
    }
    //printf("The integers are %d and %d.\n", num1, num2);
    //printf(":%d \n",count);
    int max=0; // max initialization 
    for (int i=num1;i<=num2; i++){ // repeat from num1 to num2
        int mak=collatz(i); // call collatz function  and save the result to the mak
        if (mak>max){ 
            max=mak; // check for the longest sequence 
        }
    }
    printf("%d\n",max); // print  the longest sequence 
    return 0;
}


int collatz (long int n){ // Collatz function calculating the Collatz conjecture
        int isEven,count=1; //  initialize isEven and count
        do{
            isEven = n % 2; // check if n is even or odd
            if (isEven == 0){
                //Even
                n=n/2;
            }
            else{
                //odd
                n=(3*n)+1;
            }
            count++; // increase sequence
        }while(n!=1); 
    return count;
}
