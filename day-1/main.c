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

unsigned concatenate(unsigned x, unsigned y);

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
        char digitsCombined[4];
        
        for (int i = 0; i < strlen(fileData); i++)
        {
            if(isdigit(fileData[i]))
            {
                if (digitOne == -999)
                {
                    digitOne = fileData[i];
                }
                
                digitTwo = fileData[i];

            }
        }

        char buf1[sizeof(digitOne)];
        sprintf(buf1, "%d", digitOne);

        strcat(digitsCombined, buf1);
        puts(digitsCombined);
        
    }
    
}
