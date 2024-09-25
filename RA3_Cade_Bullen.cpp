#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

int countWords(ifstream &file)
{
    string word;
    regex specialName("[@_][a-zA-Z][a-zA-Z0-9_]*");
    int wordCount = 0;
    int specialNameCount = 0;

    while (file >> word)
    {
        if (regex_match(word, specialName))
        {
            specialNameCount++;
        }
        else
        {
            wordCount++;
        }
    }

    return wordCount + specialNameCount;
}

int countSpecialNames(ifstream &file)
{
    string word;
    regex specialNameRegex("[@_][a-zA-Z][a-zA-Z0-9]*(_[a-zA-Z0-9]+)*");
    int specialNameCount = 0;

    while (file >> word)
    {
        if (regex_match(word, specialNameRegex))
        {
            specialNameCount++;
        }
    }

    return specialNameCount;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "NO SPECIFIED INPUT FILE NAME." << endl;
        return 1;
    }

    string fileName = argv[1];
    ifstream file(fileName);

    if (!file.is_open())
    {
        cerr << "CANNOT OPEN THE FILE " << fileName << endl;
        return 1;
    }

    if (file.peek() == std::ifstream::traits_type::eof())
    {
        cout << "File is empty." << endl;
        return 0;
    }

    int total = 0;

    if (argc == 3)
    {
        string flag = argv[2];
        if (flag == "-all")
        {
            total = countWords(file);
            cout << "Total number of words: " << total << endl;

            file.clear();
            file.seekg(0, std::ios::beg);

            total = countSpecialNames(file);
            cout << "Total number of special names: " << total << endl;
        }
        else if (flag == "-sp")
        {
            file.clear();
            file.seekg(0, std::ios::beg);

            total = countSpecialNames(file);
            cout << "Total number of special names: " << total << endl;
        }
        else
        {
            cout << "UNRECOGNIZED FLAG " << flag << endl;
            return 1;
        }
    }
    else
    {
        total = countWords(file);
        cout << "Total number of words: " << total << endl;
    }

    file.close();
    return 0;
}