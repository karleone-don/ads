// I am Ayanakoji

#include <iostream>
#include <queue>

using namespace std;

int main(){
    int a;
    string t;
    cin >> a >> t;
    queue<int> s, k;
    for(int i = 0; i < a; i++){
        t[i] == 'S' ? s.push(i) : k.push(i);
    }
    while(!s.empty() and !k.empty()){
        int i = s.front();
        int j = k.front();
        s.pop();
        k.pop();
        if(i < j){
            s.push(i+a);
        }
        else{
            k.push(j+a);
        }
    }
    cout << (s.empty() ? "KATSURAGI" : "SAKAYANAGI");
}