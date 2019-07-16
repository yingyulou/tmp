#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void __parseFileToList(const string &inputFileName, vector<string> &lineList)
{
    ifstream f(inputFileName);
    string line;

    while (getline(f, line))
    {
        lineList.emplace_back(line);
    }
}


string __choice(const vector<string> &lineList)
{
    srand(time(NULL));

    return lineList[rand() % lineList.size()];
}


int main()
{
    vector<string> listListA, lineListB, lineListC, tmpLineList;

    __parseFileToList("SettingsData.txt", listListA);
    __parseFileToList("CharactersData.txt", lineListB);
    __parseFileToList("SituationsData.txt", lineListC);

    string tmpFileName, nowStr;
    int choiceNum = 0;
    bool breakBool = true;

    ofstream fo;

    while (breakBool)
    {
        cout << "Input your choice: " << endl;

        if (scanf("%d", &choiceNum) != 1)
        {
            fflush(stdin);
            continue;
        }

        switch(choiceNum)
        {
            case 1:

                cout << "Input file path: " << endl;
                cin >> tmpFileName;
                tmpLineList.clear();
                __parseFileToList(tmpFileName, tmpLineList);

                for (auto &line: tmpLineList)
                {
                    cout << line << endl;
                }

                break;

            case 2:

                nowStr += __choice(listListA) += __choice(lineListB) += __choice(lineListC);
                break;

            case 3:

                cout << "Input file path: " << endl;
                cin >> tmpFileName;

                fo.open(tmpFileName);
                fo << nowStr << endl;
                fo.close();

                break;

            case 4:

                cout << nowStr << endl;
                break;

            case 5:

                breakBool = false;
                break;
        }
    }
}