#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <map>

using namespace std;

bool isInteger(string word){
    regex integerRegex("^[+-]?[0-9]+$");
    return regex_match(word, integerRegex);

}

bool isFixedPointNum(string word){
    regex fixedNumRegex("^[+-]?[0-9]\\.[0-9]+$");
    return regex_match(word, fixedNumRegex);
}

bool isSpecialName(string word){
    regex specialNameRegex("^\\$[a-zA-Z_][a-zA-Z0-9_]*$");
    return regex_match(word, specialNameRegex);
}

int main(int argc, char* argv[]){

    if (argc < 2){
        cout << "NO SPECIFIED INPUT FILE NAME." << endl;
        exit (1);
        return 0;
    }

    ifstream file;
    file.open(argv[1]);
    if (!file.is_open()){
        cout << "CANNOT OPEN THE FILE " << argv[1] << endl;
        exit(1);
        return 0;
    }

    map<int, int> integers;
    map<double, int> fixedPointNumbers;
    map<string, int> specialNames; 
    vector<string> intWords, realWords, specialWords;
    
    string word;
    while (file >> word){
        if (isInteger(word)){
            intWords.push_back(word);
            int val = stoi(word);
            ++integers[val];
        }
        else if (isFixedPointNum(word)){
            realWords.push_back(word);
            double val = stod(word);
            fixedPointNumbers[val]++;
        }
        else if (isSpecialName(word)){
            specialWords.push_back(word);
            specialNames[word]++;
        }
    }

    if (integers.empty() && fixedPointNumbers.empty() && specialNames.empty()){
        cout << "File is empty." << endl;
        exit(1);
        return 0;
    }

    cout << "Number of integers in the file: " << intWords.size() << endl;
    cout << "Number of reals in the file: " << realWords.size() << endl;
    cout << "Number of special names in the file: " << specialWords.size() << endl;


    if (integers.size() >= 1){
        cout << "\nList of integer values and their number of occurrences:" << endl;
        for (auto i : integers){
            cout << i.first << ": " << i.second << endl;
        }
    }

    if (fixedPointNumbers.size() >= 1){
        cout << "\nList of real values and their number of occurrences:" << endl;
        for (auto i : fixedPointNumbers){
            cout << i.first << ": " << i.second << endl;
        }
    }

    if (specialNames.size() >= 1){
        cout << "\nList of special names and their number of occurrences:" << endl;
        for (auto i : specialNames){
            cout << i.first << ": " << i.second << endl;
        }
    }

    return 0;
}
