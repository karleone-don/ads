#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b; cin >> a;
    vector<int> Ox;
    vector<int> high;
    for(int i = 0; i < a; i++){
        int n, k; cin >> n >> k;
        if(k == 0){
            Ox.push_back(n);
        }
        else{
            high.push_back(abs(k));
        }
    }
    if(Ox.size() < 2 || high.size() == 0){
        cout << 0;
    }
    else{
        sort(Ox.begin(), Ox.end());
        double s1 = Ox[Ox.size()-1] - Ox[0];
        sort(high.begin(), high.end());
        double s3 = high[high.size()-1];
        cout << setprecision(9) << s1*s3/2;
    }
}