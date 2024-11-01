#include <iostream>
#include <string>

using namespace std;

int p = 31;

int get_hash(string s){
    int h = 0;
    for(int i = 0; i < s.size(); i++){
        h = h * p + (s[i] - 'a' + 1);
    }
    return h;
}

int main(){
    string s1, s2, par; cin >> s1 >> s2 >> par;
    int n1 = s1.size(), n2 = s2.size(), m = par.size();
    int h1 = get_hash(s1.substr(0, m));
    int h2 = get_hash(s2.substr(0, m));
    int hm = get_hash(par);
    int pm = 1;
    for(int i = 0; i < m-1; i++){
        pm *= p;
    }
    int a = 0;
    for(int i = 0; i + m <= n1; i++){
        if(h1 == hm && h2 == hm){
            a++;
        }
        h1 = (h1 - (s1[i] - 'a' + 1)*pm) * p + (s1[i+m] - 'a' + 1);
        h2 = (h2 - (s2[i] - 'a' + 1) * pm) * p + (s2[i+m] - 'a' + 1); 
    }
    cout << a;
}