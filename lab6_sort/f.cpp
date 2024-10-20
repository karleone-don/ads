#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

int main(){
    map<string, double> gradeMap = {
        {"A+", 4.00}, {"A", 3.75}, {"B+", 3.50},
        {"B", 3.00}, {"C+", 2.50}, {"C", 2.00},
        {"D+", 1.50}, {"D", 1.00}, {"F", 0.00}
    };

    cout << fixed << setprecision(3);

    int a; cin >> a;
    pair<double, pair<string, string>> n[a];
    for(int i = 0; i < a; i++){
        cin >> n[i].second.first >> n[i].second.second;
        int b; cin >> b;
        double count = 0, sum = 0;
        for(int j = 0; j < b; j++){
            string gr; cin >> gr;
            int cr; cin >> cr;
            count += cr;
            sum += cr * gradeMap[gr];
        }
        n[i].first = sum/count;
    }
    sort(n, n+a);
    for(int i = 0; i < a; i++){
        cout << n[i].second.first << ' ' << n[i].second.second << ' ' << n[i].first << endl;
    }
}