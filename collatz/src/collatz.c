#include <stdio.h>
#include <stdlib.h>
int collatz(long int n);
int main(int argc, char *argv[]) {
if (argc != 3) {
        fprintf(stderr, "Usage: %s arg1 arg2\n", argv[0]);
        return 1; // Non-zero return value usually indicates a problem
    }
    long int num1 = atoi(argv[1]);
    long int num2 = atoi(argv[2]);
    if ( num1==0 || num1<0 || num1<-100000000 || num1>100000000){
        printf("0\n");
        return 0;
    }
    if (num1>num2){
        printf("0\n");
        return 0;
    }
    //printf("The integers are %d and %d.\n", num1, num2);
    //printf(":%d \n",count);
    int max=0;
    for (int i=num1;i<=num2; i++){
        int mak=collatz(i);
        if (mak>max){
            max=mak;
        }
    }
    printf("%d\n",max);
    return 0;
}


int collatz (long int n){
        int isEven,count=1;
        do{
            isEven = n % 2;
            if (isEven == 0){
                //Even
                n=n/2;
            }
            else{
                //odd
                n=(3*n)+1;
            }
            count++;
        }while(n!=1);
    return count;
}
