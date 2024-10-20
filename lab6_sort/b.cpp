#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int a, b; cin >> a >> b;
    vector<int> k;
    queue<int> n, m;

    for(int i = 0; i < a; i++){
        int c; cin >> c;
        k.push_back(c);
    }
    sort(k.begin(), k.end());
    for(int i = 0; i < a; i++){
        n.push(k[i]);
    }
    k.clear();
    for(int i = 0; i < b; i++){
        int c; cin >> c;
        k.push_back(c);
    }
    sort(k.begin(), k.end());
    for(int i = 0; i < b; i++){
        m.push(k[i]);
    }
    while(!n.empty() && !m.empty()){
        if(n.front() == m.front()){
            cout << n.front() << ' ';
            n.pop();
            m.pop();
        }
        else if(n.front() < m.front()){
            n.pop();
        }
        else{
            m.pop();
        }
    }
}