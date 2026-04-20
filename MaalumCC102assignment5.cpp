#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Write to original.txt
    ofstream outFile("original.txt");
    if (!outFile) {
        cout << "Error creating original.txt\n";
        return 1;
    }

    outFile << "One\n";
    outFile << "Two\n";
    outFile << "Three\n";
    outFile << "Four\n";
    outFile << "Five\n";
    outFile << "Six\n";

    outFile.close();

    // Read from original.txt
    ifstream inFile("original.txt");
    if (!inFile) {
        cout << "Error opening original.txt\n";
        return 1;
    }

    vector<string> words;
    string line;

    while (getline(inFile, line)) {
        words.push_back(line);
    }

    inFile.close();

    sort(words.begin(), words.end());

    ofstream sortedFile("sorted.txt");
    if (!sortedFile) {
        cout << "Error creating sorted.txt\n";
        return 1;
    }

    for (string word : words) {
        sortedFile << word << endl;
    }

    sortedFile.close();

    cout << "Sorting completed.\n";
    return 0;
}
