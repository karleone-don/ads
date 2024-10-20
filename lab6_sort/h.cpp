#include <iostream>

using namespace std;

int binSearch(char arr[], char c, int n){
    int left = 0;
    int right = n - 1;
    while(left <= right){
        int mid = (left+right)/2;

        if(arr[mid] == c){
            return (mid+1)%n;
        }

        if(arr[mid] < c){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return (right+1)%n;
}

int main(){
    int a; cin >> a;
    char n[a];
    for(int i = 0; i < a; i++){
        cin >> n[i];
    }
    char c; cin >> c;
    int b = binSearch(n, c, a);
    cout << n[b];
}