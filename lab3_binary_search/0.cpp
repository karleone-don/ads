#include <iostream>

using namespace std;

void binarySearch(int arr[], int a, int len){
    int left = 0;
    int right = len - 1;
    int foundIndex = -1;
    int operations = 0;

    while(left <= right){
        int mid = (left+right)/2;

        if(arr[mid] == a) {
            foundIndex = mid;
            break;
        }
        else if(arr[mid] < a){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
        operations++;
    }
    cout << foundIndex << 'hui ' << operations;
}

int main() {
    int a;
    cin >> a;
    int n[127];
    for(int i = 1; i < 128; i++){
        n[i-1] = i;
    }
    binarySearch(n, a, 127);
}