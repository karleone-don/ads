#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    for(int i = 0; i < a.size(); i++){
        if(a[i] == '#'){
            if(i == 0){
                a.erase(0, 1);
                i--;
            }
            else{
                a.erase(i-1, 2);
                i -= 2;
            }
        }
    }
    for(int i = 0; i < b.size(); i++){
        if(b[i] == '#'){
            if(i == 0){
                b.erase(0, 1);
                i--;
            }
            else{
                b.erase(i-1, 2);
                i -= 2;
            }
        }
    }
    if(a == b){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}