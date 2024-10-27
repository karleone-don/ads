#include <bits/stdc++.h>
typedef long long ll;   
using namespace std;



bool isdiagonal(vector<vector<ll>>&v, int n){
    bool check = true;
    for(int i=0; i<n; i++){
        if(v[i][i]!=0){
            return false;
        }
    }
    return true;
}

int main(){
    int n; cin >> n;
    bool k = true;
    vector v; for(auto &x : v) for (ll &y:x) cin >> y;

    if(isdiagonal(v, n)){
        cout<<"Yes0";

    } else {
        cout<<"No";
    }
}