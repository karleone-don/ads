#include <bits/stdc++.h>
using namespace std;

int diff(string a, string b){
    int count = 0;
    for(int i=0; i<7; i++){
        count += a[i]!=b[i];
    }
    return count;
}


int main(){
    string a, b; cin >> a >> b;

    string one = "0010010";
    string two = "1011101";
    string three = "1011011";
    string four = "0111010";
    string five = "1101011";
    string six = "1101111";
    string seven = "1010010";
    string eight = "1111111";
    string nine="1111011";
    string zero = "1110111";

    int ans = 0;

    if(b==six){
        cout << 1;
    } else {
        cout<<0;
    }
    

    
    
    
}
