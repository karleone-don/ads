#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll r, g, b; cin >> r >> g >> b;
    
    vector<ll> v;
    v.push_back(r);
    v.push_back(g);
    v.push_back(b);
    sort(v.begin(), v.end());
    
    ll f = v[2], k= v[1], c = v[0];

    if(f > k+c+1){
        cout << 0;
        return 0;
    }

    if (f==k && k==c){
        ll ans = 1;
        for(ll i=1; i<=3*k; i++){
            ans *= i;
        }
        cout << ans%998244353;

        return 0;
    }

    ll ans = 1;

    for(ll i=1; i<=c; i++){
        ans *= (k+i)/i;
    }
    cout << ans%998244353;

}