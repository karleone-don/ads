#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long a = 0, b;
    while(cin >> b){
        a += b;
        cout << a << endl;
        if(b == 0){
            break;
        }
    }
}