#include <iostream>

using namespace std;

bool binSearch(int arr[], int size, int num){
    int left = 0; int right = size-1, mid;
    while(left <= right){
        mid = (left+right)/2;
        if(arr[mid] == num){
            return true;
        }
        else if(arr[mid] < num){
            left = mid + 1;
        }
        else{
            right = mid - 1; 
        }
    }
    return false;
}

int main(){
    int a, b;
    cin >> a;
    int n[a];
    for(int i = 0; i < a; i++){
        cin >> n[i];
    }
    cin >> b;
    if(binSearch(n, a, b)){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}