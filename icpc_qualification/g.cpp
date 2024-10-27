#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n; cin>>n;
    bool k = false;
    for(int i = 0; i < n; i++){
        int g; cin >> g;
        if(g % 2 == 1){
            k = true;
            break;
        }
    }
    if(!k) cout<<"Dmitry";
    else cout<<"Alice";
}