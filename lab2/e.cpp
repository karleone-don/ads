#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a; 
    cin >> a;
    string n[a];
    for(int i = 0; i < a; i++){
        cin >> n[i];
    }
    reverse(n, n+a);
    vector<string> m;
    m.push_back(n[0]);
    for(int i = 1; i < a; i++){
        if(n[i-1] != n[i]){
            m.push_back(n[i]);
        }
    }
    int b = m.size();
    cout << "All in all: " << b << endl << "Students:" << endl;
    
    for(int i = 0; i < b; i++){
        cout << m[i] << endl;
    }
}