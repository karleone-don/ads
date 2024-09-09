#include <iostream>

using namespace std;

bool n[1000000] = {false};

int main(){
    int a;
    cin >> a;
    n[1] = true;
    for(int i = 2; i < 1000; i++){
        if(n[i] == false){
            for(int j = i*i; j < 1000000; j += i){
                n[j] = true;
            }
        }
    }
    if(!n[a]){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}