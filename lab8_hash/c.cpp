#include <iostream>
#include <vector>

using namespace std;

int p = 31;

int get_hash(string s){
    int h = 0;
    for(int i = 0; i < s.size(); i++){
        h = h * p +(s[i] - 'a' + 1);
    }
    return h;
}

void rk(string s, string k, vector<bool> &a){
    int n = s.size(), m = k.size();
    int h = get_hash(s.substr(0, m));
    int hk = get_hash(k);
    int pm = 1;
    for(int i = 0; i < m-1; i++){
        pm *= p;
    }
    for(int i = 0; i+m <= n; i++){
        if(h == hk){
            for(int j = i; j < i+m; j++){
                a[j] = true;
            }
        }
        if(i+m < n){
            h = (h - (s[i] - 'a' + 1) * pm) * p + (s[i+m] - 'a' + 1);
        }
    }
}

int main(){
    string s; cin >> s;
    int n; cin >> n;
    vector<bool> m(s.size(), false);
    for(int i = 0; i < n; i++){
        string k; cin >> k;
        rk(s, k, m);
    }
    for(int i = 0; i < s.size(); i++){
        if(!m[i]){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}