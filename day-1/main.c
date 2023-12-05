/*Solving advent of code challenge day 1.
    For example:

    1abc2
    pqr3stu8vwx
    a1b2c3d4e5f
    treb7uchet
    In this example, the calibration values of these four lines are 12, 38, 15, and 77. Adding these together produces 142.

    Consider your entire calibration document. What is the sum of all of the calibration values?
*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int sum;
    FILE *fp;
    char* fileData;
    size_t len = 0;
    __ssize_t read;
    
    fp = fopen("input.txt", "r");
    
    if(fp == NULL)
    {   
        perror("Error opening file");
    }
    
    while((read = getline(&fileData, &len, fp)) != -1)
    {
        int digitOne = -999;
        int digitTwo;
        char sDigitOne[8];
        char sDigitTwo[4];
        
        for (int i = 0; i < strlen(fileData); i++)
        {
            if(isdigit(fileData[i]))
            {
                if (digitOne == -999)
                {
                    digitOne = fileData[i] - '0';
                }
                
                digitTwo = fileData[i] - '0';

            }
        }

        sprintf(sDigitOne, "%d", digitOne);
        sprintf(sDigitTwo, "%d", digitTwo);

        strcat(sDigitOne, sDigitTwo);
        int result;
        sscanf(sDigitOne, "%d", &result);
        sum += result;
    }
    printf("Result is: %d\n", sum);
}