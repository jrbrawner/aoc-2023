#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <list>
#include <bits/stdc++.h>

bool HasOnlyDigits(std::string s);
std::string CheckString(std::string numberString);
void PartOne();

int main()
{
    std::ifstream inputFile;
    std::string fileInput;
    std::string stringNumbers[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::string numbers[9] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

    int sum = 0;
    
    inputFile.open("input.txt");
    if (inputFile.is_open())
    {
        while (inputFile.good())
        {
            inputFile >> fileInput;
            std::list<int> numberPositions = {};
            
            //check line for all occurences of one-nine, get position
            for(std::string number : stringNumbers)
            {
                int found = fileInput.find(number);

                if(found != std::string::npos)
                {
                    numberPositions.push_back(found);
                }
            }
            //check line for all occurences of 1-9, get position 
            for(std::string number : numbers)
            {
                int found = fileInput.find(number);

                if(found != std::string::npos)
                {
                    numberPositions.push_back(found);
                }
            }
            //sort list of positions, retrieve smallest and biggest position
            numberPositions.sort();
            int low = numberPositions.front();
            int high = numberPositions.back();

            std::string calcString;
            //get low position number
            char result = fileInput[low];
            
        }
    }
    inputFile.close();
    
}

std::string CheckString(std::string numberString)
{
    if (numberString.find("one") != std::string::npos) return "1";
    if (numberString.find("two") != std::string::npos) return "2";
    if (numberString.find("three") != std::string::npos) return "3";
    if (numberString.find("four") != std::string::npos) return "4";
    if (numberString.find("five") != std::string::npos) return "5";
    if (numberString.find("six") != std::string::npos) return "6";
    if (numberString.find("seven") != std::string::npos) return "7";
    if (numberString.find("eight") != std::string::npos) return "8";
    if (numberString.find("nine") != std::string::npos) return "9";
    return "0";
}

bool HasOnlyDigits(const std::string s){
  return s.find_first_not_of( "0123456789" ) == std::string::npos;
}

void PartOne()
{
    std::ifstream inputFile;
    inputFile.open("input.txt");

    std::string fileInput;

    int sum = 0;

    if (inputFile.is_open())
    {
        while (inputFile.good())
        {

            inputFile >> fileInput;

            int digitOne = -999;
            int digitTwo;
            
            for (int i = 0; i < fileInput.length(); i++)
            {
                if (isdigit(fileInput[i]))
                {
                    if (digitOne == -999)
                    {
                        digitOne = fileInput[i] - '0';
                    }
                    digitTwo = fileInput[i] - '0';
                }
            }
            std::string stringDigitsCombined = std::to_string(digitOne) + std::to_string(digitTwo);
            sum += std::stoi(stringDigitsCombined);
            
        }
    }
    inputFile.close();
    std::cout << "The result is: " << sum << "\n";
}