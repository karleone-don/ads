#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

bool customCompare(char a, char b, const unordered_map<char, int>& customOrder) {
    return customOrder.at(a) < customOrder.at(b);
}

int main() {
    int a;
    string word;
    cin >> a >> word;

    string newAlphabet = "aeioubcdfghjklmnpqrstvwxyz";
    unordered_map<char, int> customOrder;

    for (int i = 0; i < newAlphabet.size(); ++i) {
        customOrder[newAlphabet[i]] = i;
    }

    sort(word.begin(), word.end(), 
              [&](char a, char b) { return customCompare(a, b, customOrder); });

    cout << word;
}
