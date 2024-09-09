#include <iostream>
#include <vector>

using namespace std;

bool n[4000] = {false};

int main() {
    int a;
    cin >> a;
    vector<int> m;
    for(int i = 2; i < 64; i++){
        if(n[i] == false){
            for(int j = i*i; j < 4000; j += i){
                n[j] = true;
            }
        }
    }
    for(int i = 2; i < 4000; i++){
        if(n[i] == false){
            m.push_back(i);
        }
    }
    cout << m[m[a-1]-1];
}