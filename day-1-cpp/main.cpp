#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <list>
#include <bits/stdc++.h>

bool HasOnlyDigits(std::string s);
std::string CheckString(std::string numberString);
bool InList(std::string find, std::string *array);

int main()
{
    std::ifstream inputFile;
    std::string fileInput;
    std::string stringNumbers[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::string numbers[9] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

    int sum = 0;
    
    inputFile.open("test.txt");
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
            //// need to account for multiple occurences of one digit
            //check line for all occurences of 1-9, get position 
            for(std::string number : numbers)
            {
                int found = fileInput.find(number);
                while (found != -1)
                {
                    numberPositions.push_back(found);
                    std::cout << fileInput << "\n";
                    fileInput.erase(found, 1);
                    found = fileInput.find(number);
                    
                }
                
            }
            /*
            for(int num : numberPositions)
            {
                std::cout << num << "\n";
            }

            */
            
            //sort list of positions, retrieve smallest and biggest position
            numberPositions.sort();
            int low = numberPositions.front();
            int high = numberPositions.back();

            

            std::string calcString;
            //get low position number
            char result = fileInput[low];

            if (isdigit(result))
            {
                std::string temp(1, result);
                calcString.append(temp);
            }
            else
            {
                std::string buffer(1, result);
                bool found = false;
                int counter = 1;

                while (found == false)
                {
                    
                    char nextChar = fileInput[low+counter];
                    std::string stringNextChar(1, nextChar);
                    buffer.append(stringNextChar);

                    if (InList(buffer, stringNumbers) == true)
                    {
                        found = true;
                        calcString.append(CheckString(buffer));
                        break;
                    }
                    counter += 1;
                    
                }  
            }

            //get high position number
            result = fileInput[high];

            if (isdigit(result))
            {
                std::string temp(1, result);
                
                calcString.append(temp);
            }
            else
            {
                std::string buffer(1, result);
                bool found = false;
                int counter = 1;

                while (found == false)
                {
                    char nextChar = fileInput[high+counter];
                    std::string stringNextChar(1, nextChar);
                    buffer.append(stringNextChar);

                    if (InList(buffer, stringNumbers) == true)
                    {
                        found = true;
                        calcString.append(CheckString(buffer));
                        break;
                    }
                    counter += 1;
                }  
            }
           
            sum += std::stoi(calcString);
            
        }
    }
    inputFile.close();

    std::cout << "The result is: " << sum << "\n";

    
}

std::string CheckString(std::string numberString)
{
    if (numberString == "one") return "1";
    if (numberString == "two") return "2";
    if (numberString == "three") return "3";
    if (numberString == "four") return "4";
    if (numberString == "five") return "5";
    if (numberString == "six") return "6";
    if (numberString == "seven") return "7";
    if (numberString == "eight") return "8";
    if (numberString == "nine") return "9";
    return 0;
}

bool HasOnlyDigits(const std::string s){
  return s.find_first_not_of( "0123456789" ) == std::string::npos;
}

bool InList(std::string find, std::string *array)
{
    bool found = false;
    for (int i = 0; i <= sizeof(array); i++)
    {
        if (find == array[i])
        {
            found = true;
            break;
        }
        
    }
    
    return found;
}