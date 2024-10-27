#include <iostream>
#include <string>

using namespace std;

int main(){
    long long a; cin >> a;
    long long b = 1;
    const char* digits = "0123456789AB";
    for(int i = 2; i <= a; i++){
        b *= i;
    }
    string s;
    while(b > 0){
        int c = b % 12;
        s += digits[c];
        b /= 12;
    }
    long long k = 0, l = 0;
    while(s[l] == '0'){
        k++;
        l++;
    }
    cout << k;
}