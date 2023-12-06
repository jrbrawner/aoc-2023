#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

void PartOne();
std::string CheckString(std::string numberString);

int main()
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
            std::string buffer;
            std::string numbers[10] = {};

            for (int i = 0; i < fileInput.length(); i++)
            {
                buffer += fileInput[i];
                std::string temp = CheckString(buffer);
                if (temp != "0")
                {
                    numbers->append(temp);
                    buffer.clear();
                }
                
                if (isdigit(fileInput[i]))
                {
                    int number = fileInput[i] - '0';
                    numbers->append(std::to_string(number));
                }
            }

            std::string digitsCombined = numbers[0] + numbers->back();
            std::cout << numbers->back() << "\n";
            //sum += std::stoi(digitsCombined);
            //std::cout << digitsCombined << "\n";
        }
    }
    inputFile.close();
    std::cout << "The result is: " << sum << "\n";
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