/*
 
 Lab number : 0
 Problem number : 1
 
 Number of days
 - Write C/C++ program to calculate the number of days from January 1 to a given data.
 - Make the program capable of computing values for as many as 20 dates
 
 The data should be input in the following format :
 Line 1   : n
 Line 2   : month day
 Line 3   : month day
 .
 .
 .
 Line n+1 : month day
 
 Note : You can assume that there are 28 days in February
 
 */

#include <iostream>

int findDaySinceJan1(int month, int day);

int main() {
    int input;
    int month;
    int day;
    
    printf("Enter the number of input dates : ");
    scanf("%d", &input);
    for(int i=0; i<input; i++){
        scanf("%d %d", &month, &day);
        printf("Number of days since January 1 : %d\n", findDaySinceJan1(month, day));
    }
    return 0;
}

int findDaySinceJan1(int month, int day) {
    int arrayMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int total = 0;
    
    for(int i=0; i<month-1 ; i++){
        total += arrayMonth[i];
    };
    
    total += day;
    return total;
};
