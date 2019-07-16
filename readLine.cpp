#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream f("1.txt");
    string line, allLine;

    while (getline(f, line))
    {
        allLine += line += "\n";
    }

    f.close();

    cout << allLine << endl;
}