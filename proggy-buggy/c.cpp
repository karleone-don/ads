#include <iostream>
#include <cmath>
//S = a^2
//S = pi*r^2
//r = a/sqrt(pi) 

using namespace std;

int main(){
    int a; cin >> a;
    double r = a/sqrt(M_PI);
    cout << r;
}