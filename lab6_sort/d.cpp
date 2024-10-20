#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int a; cin >> a;
    string n[a], m[a];
    for(int i = 0; i < a; i++){
        cin >> n[i];
    }
    for(int i = 0; i < a; i++){
        m[i] = n[i].substr(5) + n[i].substr(2, 3) + n[i].substr(0, 2);
    }
    sort(m, m+a);
    for(int i = 0; i < a; i++){
        cout << m[i].substr(8) + m[i].substr(5, 3) + m[i].substr(0, 5) << endl;
    }
}