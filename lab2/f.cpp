#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b, c;
    cin >> a;
    vector<int> n;
    for(int i = 0; i < a; i++){
        cin >> b;
        n.push_back(b);
    }
    cin >> b >> c;
    auto it = n.begin() + c;  
    n.insert(it, b);
    for(int i = 0; i < a+1; i++){
        cout << n[i] << ' ';
    }
}