// #include <math.h>
#include <stdio.h>
#include "NumClass.h"
// int ownPow(int x,int y);
// int isArmstorng(int num);
// int isPalindrome(int num);

#define true 1
#define false 0

//=========================== THIS IS FOR ARMSTORNG & PALINDROEM ===============================

int ownPow(int x,int y){
    int number = 1;
    for (int i = 0; i < y; ++i){
        number *= x;
    }
    return number;
}
//==========================================================

int isArmstorng(int num){
    int power = 0;
    int temp = num;
    int sum = 0;
    // this is for the finding out the power
    while(temp>0){
        temp= temp / 10;
        power++;
    }
    // need to init the temp again to be the num
    // (because now temp is zero)
    temp = num;
    // run on while loop to do for every digit in the num 
    // to be in power that we found out above
    int digit;
    while(temp>0){
        digit = temp % 10;
        sum += ownPow(digit,power);
        temp = temp / 10;
    }
    // check if the sum we get is the num in the input
    // (check if it's an armstrong number)
    if(num == sum){
        return 1;
    }
    return 0;
}

int isPalindrome(int num){
    int temp = num;
    int len = 0;
    // this is for the finding out the length of the number (the number of digit)
    while(temp>0){
        temp= temp / 10;
        len++;
    }
    // now temp is zero so we need to init to it again the num from the input
    temp = num;
    // this array will hold the digit of the number in each cell but in reverse
    // but if this is a palindrome it doesnt metter it will be the same number also in reverse
    int arrDigit[len];
    for(int i = 0; i < len;i++){
        arrDigit[i] = temp % 10;
        temp = temp / 10;
    }
    // the number of time the  'if' in the 'for loop' below needs to be true, is as the length of the number didvie into 2 ( len/2 ).
    // it's true for double and for odd number ( in odd number the digit in the center is the same).
    // so after every time the 'if' statement is true we will add 1 ( numOfTimeNeedToBeTrue++ ) and at the end check if this variable 
    // ( numOfTimeNeedToBeTrue  == len / 2 ) and if it does the number in the input is palindrome
    int numOfTimeNeedToBeTrue = 0;
    // this will work if the length of the number is double or odd
    for(int i = 0; i < len /2; i++){
        if(arrDigit[i] == arrDigit[len -1 -i]){
            numOfTimeNeedToBeTrue++;
        }
    }
    if( numOfTimeNeedToBeTrue == (len / 2 ) ){
        return 1; 
    } 
    return 0;
}



// void main(){
//     int a;
//     printf("Enter a number: ");
//     scanf("%d", &a);
//     if(isArmstorng(a)==true){
//         printf("True");
//     }
//     else{
//         printf("False");
//     }
// }