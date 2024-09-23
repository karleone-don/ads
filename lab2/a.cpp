#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int a, k, t;
    long long l = 100000000;
    cin >> a;
    int n[a];
    for(int i = 0; i < a; i++){
        cin >> n[i];
    }
    cin >> k;
    for(int i = 0; i < a; i++){
        if(abs(n[i]-k) < l){
            l = abs(n[i]-k);
            t = i;
        }
        if(l == 0){
            break;
        }
    }
    cout << t;
}