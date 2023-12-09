
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
/*
Determine which games would have been possible if the bag had been
loaded with only 12 red cubes, 13 green cubes, and 14 blue cubes. 
What is the sum of the IDs of those games?
*/


class GameResult
{
    public:
        int id;
        bool possible = true;

        int redLimit = 12;
        int greenLimit = 13;
        int blueLimit = 14;

        void init(string lineInput)
        {
            size_t pos = 0;
            string token;
            string delimiter = ";";

            while ((pos = lineInput.find(delimiter)) != std::string::npos) 
            {
                token = lineInput.substr(0, pos);            
                lineInput.erase(0, pos + delimiter.length());
                ParseGameString(token);
            }
            ParseGameString(lineInput);
        }

        void ParseGameString(string gameLine)
        {
            int gamePosition;
            //cout << gameLine << "\n";
            gamePosition = gameLine.find(":");

            if (gamePosition != -1)
            {
                string gameIdString = gameLine.substr(0, gamePosition);
                string resultString = gameLine.substr(gamePosition+1);
                GetGameId(gameIdString);
                ParseGameResults(resultString);
            }
            else
            {
                ParseGameResults(gameLine);
            }
        }

        void GetGameId(string gameIdString)
        {
            string ID;

            for (char character : gameIdString)
            {
                
                if (isdigit(character))
                {
                    ID.append(to_string(character - '0'));
                }
            }
            id = stoi(ID);
        }

        void ParseGameResults(string gameResult)
        {

            size_t pos = 0;
            string token;
            string delimiter = ",";

            while ((pos = gameResult.find(delimiter)) != std::string::npos) 
            {
                token = gameResult.substr(0, pos);            
                gameResult.erase(0, pos + delimiter.length());
                  
                AppendGameScore(token);
            }
            AppendGameScore(gameResult);
            
        }

        void AppendGameScore(string gameScore)
        {
           
            string scoreString = gameScore.substr(0,3);
            string stringTotal;
            int total;

            string colors[3] = {"blue", "red", "green"};

            for (char character : scoreString)
            {
                if (isdigit(character))
                {
                    stringTotal.append(to_string(character - '0'));
                }
            }
            total = stoi(stringTotal);
            cout << total << "\n";
            for (string color : colors)
            {
                if (gameScore.find(color) != -1)
                {
                    if (color == "blue" && total > blueLimit) possible = false;
                    if (color == "green" && total > greenLimit) possible = false;
                    if (color == "red" && total > redLimit) possible = false;
                }
            }

        }


};

int main()
{
    ifstream inputFile;
    string lineInput;

    vector<GameResult> results = {};

    inputFile.open("input.txt");
    while(getline(inputFile, lineInput))
    {
        size_t pos = 0;
        string token;
        string delimiter = ";";

        GameResult gameResult;

        gameResult.init(lineInput);

        results.push_back(gameResult);
    }
    int sum = 0;

    for(GameResult result : results)
    {
        if (result.possible == true)
        {
            sum += result.id;
        }
    }
    

    cout << "The result is: " << sum << "\n";
}

