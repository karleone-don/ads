#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m; cin>>n>>m;
    bool check = true;

    for (int i=0; i<n; i++){
        bool r, ii, c, a = false;
        int countA = 0;
        for(int j=0; j<m; j++){
            char x; cin >> x;
            if(x=='R'){
                r = true;
            } else if(x=='A'){
                countA++;
                if(countA>1){
                    check = false;
                    cout<<"No";
                    return 0;
                }
                r = true;
                a = true;
            } 
            
            else if(x=='C'){
                c = true;
            } else if(x=='I') {
                ii = true;
            } 
        }
        if(!(r * a * c * ii)){
            check = false;
        }
    }
    if(check) cout<<"Yes";
    else cout<<"No";
}