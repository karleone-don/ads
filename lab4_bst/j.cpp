#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void binarySearch(int arr[], int left, int right){
    if (left > right){
        return;
    }
    int mid = (left+right)/2;
    cout << arr[mid] << ' ';
    binarySearch(arr, mid+1, right);
    binarySearch(arr, left, mid-1);
}

int main(){
    int a, b;
    cin >> a;
    b = pow(2, a)-1;
    int n[b];
    for(int i = 0; i < b; i++){
        cin >> n[i];
    }
    sort(n, n+b);
    binarySearch(n, 0, b-1);
}