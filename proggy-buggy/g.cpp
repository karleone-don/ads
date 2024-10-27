#include <iostream>

using namespace std;

int main(){
    int a, b = 26; cin >> a;
    a -= 2024;
    b += a*365;
    b %= 7;
    while(b <= 24){
        b += 7;
    }
    cout << b;
}