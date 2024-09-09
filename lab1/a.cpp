#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a, b;
    cin >> a;
    for(int i = 0; i < a; i++){
        cin >> b;
        vector<int> n;
        vector<int> m;
        n.push_back(b);
        for(int i = 1; i < b; i++) {
            n.push_back(b-i);
            m = n;
            for(int j = 0; j < i+1; j++){
                n[j] = m[(j+b-i)%(i+1)];
            };
        }
        reverse(n.begin(), n.end());
        for(int i = 0; i < b; i++){
                cout << n[i] << " ";
            }
        cout << endl;
    }
}