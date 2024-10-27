#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    int a = 0, b = s.size();
    for(int i = 0; i < b; i++){
        if(s[i] == '{'){
            a++;
        }
    }
    int c = 0;
    while(a > 0){
        a /= 2;
        c++;
    }
    cout << c-1;
}
