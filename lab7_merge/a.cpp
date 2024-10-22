#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(){
    int a; cin >> a;
    cin.ignore();
    
    for(int i = 0; i < a; i++){
        vector<string> input;
        string line;
        getline(cin, line);
        stringstream ss(line);
        string word;
        while (ss >> word) {
            input.push_back(word);
        }
        int b = input.size();
        for(int j = 1; j < b; j++){
            string current = input[j];
            int k = j - 1;
            while(k >= 0 && input[k].size() > current.size()){
                input[k + 1] = input[k];
                k--;
            }
            input[k + 1] = current;;
        }

        for(int j = 0; j < b; j++){
            cout << input[j] << " ";
        }
        cout << endl;
    }
}