#include <iostream>

using namespace std;

int main() {
    int a;
    cin >> a;
    int n[a], m[a];
    for(int i = 0; i < a; i++){
        cin >> n[i];
    }

    for(int i = 0; i < a; i++){
        m[i] = -1;
        for(int j = i-1; j >= 0; j--){
            if(n[i] >= n[j]){
                m[i] = n[j];
                break;
            }
        }
        cout << m[i] << " ";
    }
}