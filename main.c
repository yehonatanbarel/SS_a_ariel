#include <stdio.h>
#include "NumClass.h"
#include "advancedClassificationRecursion.c"
#include "basicClassification.c"
//#include "advancedClassificationLoop.c"



int main(){
// enter 2 num
int x;
int y;
//printf("Enter 2 numbers:\n");
scanf("%d%d",&x,&y);
//scanf("%d",&y);
int i = x;

//============ IS ARMSTRONG =====================

printf("The Armstrong numbers are:");
for(i = x; i <= y; i++){
    if(isArmstorng(i)){
        printf(" %d",i);
    }
}
//

//=============== IS PALINDROME =====================

printf("\nThe Palindromes are:");
for(i = x; i <= y; i++){
    if(isPalindrome(i)){
        printf(" %d",i);
    }
}
//============== IS PRIME ================

printf("\nThe Prime numbers are:");
for(i = x; i <= y; i++){
    if(isPrime(i)){
        printf(" %d",i);
    }
}

//============= IS STRONG ==================

printf("\nThe Strong numbers are:");
for(i = x; i <= y; i++){
    if(isStrong(i)){
        printf(" %d",i);
    }
}

//====================================
printf("\n");

return 0;
}