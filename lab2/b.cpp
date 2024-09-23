#include <iostream>
#include <string>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    string s[a];
    for(int i = 0; i < a; i++){
        cin >> s[i];
    }
    for(int i=b; i < a+b; i++){
        cout << s[i%a] << ' ';
    }
}