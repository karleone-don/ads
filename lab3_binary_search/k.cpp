#include <iostream>
#include <algorithm>

using namespace std;

int binSearch(int arr[], int size, int num){
    
}

int main(){
    int a, b, sum = 0;
    cin >> a >> b;
    int n[a];
    for(int i = 0; i < a; i++){
        int c;
        cin >> c;
        sum += c;
        n[i] = sum;
    }
    int min_pos = a + 1;

    if(min_pos == a + 1){
        cout << 0;
    }
    else{
        cout << min_pos;
    }
}