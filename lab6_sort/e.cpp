#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int a, b; cin >> a >> b;
    vector<vector<int>> m;
    for(int i = 0; i < b; i++){
        vector<int> n;
        m.push_back(n);
    }
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            int x; cin >> x;
            m[j].push_back(x);
        }
    }
    for(int i = 0; i < b; i++){
        sort(m[i].begin(), m[i].end());
        reverse(m[i].begin(), m[i].end());
    }
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            cout << m[j][i] <<  ' ';
        }
        cout << endl;
    }
}