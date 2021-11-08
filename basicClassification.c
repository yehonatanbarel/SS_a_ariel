// #include <math.h>
#include <stdio.h>
#include "NumClass.h"
// int isPrime(int num);
// int factorial(int num);
/// int isStrong(int num);

#define true 1
#define false 0

// ================ in this file the func are: isPrime & isStrong =================


int isPrime(int num){
    // init 'i' variable
    int i;
    // run from 2 to num /2. if any num from 2 - (num/2) is divide num so the num from input is not prime
  if(num ==1){
      return true;
  }
  for (i = 2; i <= num / 2; ++i) {
    if (num % i == 0) {
      return 0;
    }
  }
  return 1;
}

  //=====================================
int factorial(int num){
    long fact = 1;
    for (int i = 1; i <= num; ++i) {
        fact *= i;
    }
    return (int) fact;
}

int isStrong(int num){
    int sum = 0;
    int temp=num;
    int digit = 0;
    while(temp>0){
        digit = temp % 10;
        sum += factorial(digit);
        temp = temp / 10;
    }
    if(num == sum){
        return 1;
    }
    return 0;
}
// void main(){
//     int a;
//     printf("Enter a number: ");
//     scanf("%d", &a);
//     if(isStrong(a)){
//         printf("True");
//     }
//     else{
//         printf("False");
//     }
// }