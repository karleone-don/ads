#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
    ll n, k; cin >> n >> k;
    if (n==1){
        cout << 1 << endl;
        return;
    }
    ll c = 0;
    if(n%2==0){
        while(n>1){
            c++;
            n/=2;
        }
    } else {
        c++;
        while(n>1){
            c++;
            n/=2;
        }
    }

    cout << c << endl;
}


int main(){
    ll t; cin >>t;
    while(t--){
        solve();
    }
}