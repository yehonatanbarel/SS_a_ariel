// #include <math.h>
#include <stdio.h>
#include "NumClass.h"
#define true 1
#define false 0
int numReverse(int num, int reverse);
int isPalindrome(int num);
int ownPow(int x,int y);
int isArmstorngRec(int num, int power);
int isArmstorng(int num);


//============================ THIS IS FOR ARMSTORNG & PALINDROEM ===============================
    int numReverse(int num, int reverse){
        if (num == 0) {
            return reverse;
        }

        reverse = reverse * 10 + (num % 10);
        reverse = numReverse(num / 10, reverse);
        return reverse;
    }

    int isPalindrome(int num){
        int reverse = 0;
        reverse = numReverse(num, reverse);
        return (num == reverse);
    }
//==========================================================
int ownPow(int x, int y){
    int res = 1;
    int neg = 0;
    if(y<0) {
        neg = 1;
        y=-y;
    }
    while (y > 0){
        res *= x;
        y--;
    }
    if(neg)
        res = 1/res;
    return res;
}
int ownPow2(int x,int y)
{
    int number = 1;
    for (int i = 0; i < y; ++i){
        number *= x;
    }
    return number;
}
//==========================================================


// from this func we get the power
int numPow(int num){
    int power = 0;
    int temp = num;
    // this is for the finding out the power
    while(temp>0){
        temp= temp / 10;
        power++;
    }
    return power;
}

int isArmstorngRec(int num, int power){
        int digit = 0;
        int sum = 0;
        int totalSum = 0;
        if(num > 0){
        digit = num % 10;
        sum += (int) (ownPow(digit,power) + isArmstorngRec(num / 10, power));
        }
        totalSum = sum;
        return totalSum;
}
int isArmstorng(int num){
    int power = numPow(num);
    if(isArmstorngRec(num,power) == num){
        return 1;
    }
    return 0;
}

// void main(){
//     int a;
//     printf("Enter a number: ");
//     scanf("%d", &a);
//     printf("%d",Power(a,2));
//     if(isPalindrome(a)==1){
//         printf("True");
//     }
//     else{
//         printf("False");
//     }
// }