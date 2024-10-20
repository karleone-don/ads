#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int a, b; cin >> a;
    int n[a];
    for(int i = 0; i < a; i++){
        cin >> n[i];
    }
    sort(n, n+a);
    if(a > 2){
        b = abs(n[0]-n[1]);
        for(int i = 2; i < a; i++){
            int c = abs(n[i] - n[i-1]);
            if(c < b){
                b = c;
            }
        }
        for(int i = 1; i < a; i++){
            int c = abs(n[i] - n[i-1]);
            if(c == b){
                cout << n[i-1] << ' ' << n[i] << ' ';
            }
        }
    }
    else if(a == 1){
        cout << n[0] << ' ' << n[1];
    }
}