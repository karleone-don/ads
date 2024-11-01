#include <iostream>
#include <vector>

using namespace std;

int p = 31;

int get_hash(string s){
    int h = 0;
    for(int i = 0; i < s.size(); i++){
        h = h * p + (s[i] - 'a' + 1);
    }
    return h;
}

int rk(string s, string k){
    int n = s.length(), m = k.length();
    int h = get_hash(s.substr(0, m));
    int hk = get_hash(k);
    int col = 0;
    int pm = 1;
    for(int i = 0; i < m - 1; i++){
        pm *= p;
    }
    for(int i = 0; i + m <= n; i++){
        if(h == hk){
            col++;
        }
        if(i + m < n){
            h = (h - (s[i] - 'a' + 1) * pm) * p + (s[i+m] - 'a' + 1);
        }
    }
    return col;
}

int main(){
    while(true){
        int a; cin >> a;
        if(a == 0){
            break;
        }
        vector<string> strings;
        for(int i = 0; i < a; i++){
            string s; cin >> s;
            strings.push_back(s);
        }
        string s; cin >> s;
        vector<string> asd;
        int maxcol = 0;
        for(int i = 0; i < a; i++){
            int col = rk(s, strings[i]);
            if(col > maxcol){
                asd.clear();
                maxcol = col;
            }
            if(col == maxcol){
                asd.push_back(strings[i]);
            }
        }
        cout << maxcol << endl;
        for(int i = 0; i < asd.size(); i++){
            cout << asd[i] << endl;
        }
    }
}