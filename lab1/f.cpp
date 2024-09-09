#include <iostream>
#include <vector>

using namespace std;

bool n[105000] = {false};

int main(){
    int a;
    cin >> a;
    vector<int> m;
    for(int i = 2; i < 325; i++){
        if(n[i] == false){
            for(int j = i*i; j < 105000; j += i){
                n[j] = true;
            }
        }
    }
    for(int i = 2; i < 105000; i++){
        if(n[i] == false){
            m.push_back(i);
        }
    }
    cout << m[a-1];
}