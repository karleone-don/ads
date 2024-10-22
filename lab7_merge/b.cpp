#include <iostream>

using namespace std;

int main(){
    int a; cin >> a;
    int n[a];
    for(int i = 0; i < a; i++){
        cin >> n[i];
    }
    int b; cin >> b;
    int m[b];
    for(int i = 0; i < b; i++){
        cin >> m[i];
    }
    int k[a+b];
    int ai = 0, bi = 0;
    while(ai < a || bi < b){
        if(ai == a){
            k[ai+bi] = m[bi];
            bi++;
        }
        else if(bi == b){
            k[ai+bi] = n[ai];
            ai++;
        }
        else{
            if(n[ai] < m[bi]){
                k[ai+bi] = n[ai];
                ai++;
            }
            else{
                k[ai+bi] = m[bi];
                bi++;
            }
        }
    }
    for(int i = 0; i < a+b; i++){
        cout << k[i] << ' ';
    }
}