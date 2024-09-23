#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    int a, b = 0, c = 0;
    cin >> a;
    vector<pair<int, int>> m;
    int n[a];
    for(int i = 0; i < a; i++){
        cin >> n[i];
    }
    sort(n, n+a);
    m.push_back(make_pair(n[0], 1));
    for(int i = 1; i < a; i++){
        if(n[i-1] == n[i]){
            m[b].second++;
        }
        else{
            if(c < m[b].second){
                c = m[b].second;
            }
            m.push_back(make_pair(n[i], 1));
            b++;
        }
    }
    if(c < m[b].second){
        c = m[b].second;
    }
    int d = m.size();
    for(int i = d-1; i >= 0; i--){
        if(c == m[i].second){
            cout << m[i].first << ' ';
        }
    }
}