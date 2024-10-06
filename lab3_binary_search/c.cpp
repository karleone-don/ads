#include <iostream>
#include <algorithm>

using namespace std;

int binSearch(int arr[], int a, int len, bool lr){
    int left = 0, right = len - 1, foundIndex;
    lr == 0 ? foundIndex = 0 : foundIndex = len-1;
    while(left <= right){
        int mid = (left+right)/2;
        if(arr[mid] == a){
            cout << mid << ' ';
            return mid;
        }
        else if(arr[mid] < a){
            left = mid + 1;
            if(lr == 0){
                foundIndex = mid;
            }
        }
        else{
            right = mid - 1;
            if(lr == 1){
                foundIndex = mid;
            }
        }
    }
    cout << foundIndex << ' ';
    return foundIndex;
}

int findbin(int arr[], int left, int right, int len){
    int l_index = binSearch(arr, left, len, 1);
    int r_index = binSearch(arr, right, len, 0);
    return r_index - l_index + 1;
}

int main(){
    int a, b, c;
    cin >> a >> b;
    int n[a];
    for(int i = 0; i < a; i++){
        cin >> n[i];
    }
    int l1, r1, l2, r2;
    for(int i = 0; i < b; i++){
        cin >> l1 >> r1 >> l2 >> r2;
        if(l1 <= l2){
            if (r1 < l2){
                c = findbin(n, l1, r1, a);
                c += findbin(n, l2, r2, a);
            }
            else if(r1 < r2){
                c = findbin(n, l1, r2, a);
            }
            else{
                c = findbin(n, l2, r2, a);
            }
        }
        else{
            if (r2 < l1){
                c = findbin(n, l1, r1, a);
                c += findbin(n, l2, r2, a);
            }
            else if(r2 < r1){
                c = findbin(n, l2, r1, a);
            }
            else{
                c = findbin(n, l1, r1, a);
            }
        }
        cout << c << endl;
    }
}