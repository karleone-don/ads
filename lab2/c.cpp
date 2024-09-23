#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a;
    for(int i = 0; i < a; i++){
        cin >> b;
        if(i % 2 == 0){
            cout << b << ' ';
        }
    }
}