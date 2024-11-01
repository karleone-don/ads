#include <iostream>

using namespace std;
using ll = long long;

int p = 31;

int get_hash(string s){
    int h = 0;
    for(int i = 0; i < s.size(); i++){
        h = h * p + (s[i] - 'a' + 1);
    }
    return h;
}

void count(string s, int left, int len){
    int h1 = get_hash(s.substr(left, len));
    int hs = get_hash(s.substr(0, len));
    int n = s.size();
    int num = 0;
    int pm = 1;
    for(int i = 0; i < len - 1; i++){
        pm *= p;
    }
    for(int i = 0; i + len <= n; i++){
        if(h1 == hs){
            num++;
        }
        if(i + len < n){
            hs = (hs - (s[i] - 'a' + 1) * pm) * p + (s[i+len] -'a' + 1);
        }
    }
    cout << num << endl;
}

int main(){
    string s; cin >> s;
    int a; cin >> a;
    for(int i = 0; i < a; i++){
        int b, c; cin >> b >> c;
        b -= 1; c -= b;
        count(s, b, c);
    }
}