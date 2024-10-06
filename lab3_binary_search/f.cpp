#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int a, b;
    cin >> a;
    int n[a];
    for(int i = 0; i < a; i++){
        cin >> n[i];
    }
    sort(n, n+a);
    cin >> b;
    int power, count, sum;
    for(int i = 0; i < b; i++){
        cin >> power;
        count = 0, sum = 0;
        while(n[count] <= power and count < a){
            sum += n[count];
            count++;
        }
        cout << count << ' ' << sum << endl;
    }
}