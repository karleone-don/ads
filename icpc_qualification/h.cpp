#include <bits/stdc++.h>

using namespace std;

int main(){
    int a;cin >> a;
    for(int i = 0; i < a; i++){
        string s; cin >> s;
        int c; cin >> c;
        int n[9] = {0};
        int b = s.size();
        for(int i = 0; i < b; i++){
            n[s[i]]++;
        }
        //while()
        cout << n[0];
        cout << s << endl;
    }
}