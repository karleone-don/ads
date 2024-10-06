#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b;
    int n[a];
    for(int i = 0; i < a; i++){
        cin >> n[i];
        for(int j = 0; j < 3; j++){
            cin >> c;
            if(c > n[i]){
                n[i] = c;
            }
        }
    }
    sort(n, n+a);
    cout << n[b-1];
}