#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int p = 2;

void get_string(vector<ll> &a){
    ll pm = 2, l = a.size();
    string s;
    s += a[0] + 'a';
    for(int i = 1; i < l; i++){
        ll k = a[i] - a[i-1];
        k /= pm;
        s += k +'a';
        pm *= p;
    }
    cout << s;
}

int main(){
    int a; cin >> a;
    vector<ll> n;
    for(int i = 0; i < a; i++){
        ll k; cin >> k;
        n.push_back(k);
    }
    get_string(n);
}