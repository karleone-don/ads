#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void merge(vector<deque<int>>& arr, int left, int mid, int right, int size){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<deque<int>> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left, o = 1;
    while (i < n1 && j < n2) {
        if (L[i][0] > R[j][0]) {
            arr[k] = L[i];
            i++;
        }
        else if(L[i][0] == R[j][0]){
            while(0 < size){
                if(L[i][o] < R[j][o]){
                    arr[k] = L[i];
                    i++;
                    break;
                }
                else if(L[i][o] == R[j][o]){
                    o++;
                }
                else{
                    arr[k] = R[j];
                    j++;
                    break;
                }
            }
        }
         else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<deque<int>>& arr, int left, int right, int size){
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, size);
        mergeSort(arr, mid + 1, right, size);

        merge(arr, left, mid, right, size);
    }
}

int main(){
    int a, b; cin >> a >> b;
    vector<deque<int>> n;
    for(int i = 0; i < a; i++){
        deque<int> k;
        int sum = 0;
        for(int j = 0; j < b; j++){
            int num; cin >> num;
            k.push_back(num);
            sum += num;
        }
        k.push_front(sum);
        n.push_back(k);
    }

    mergeSort(n, 0, a-1, a);
    for(int i = 0; i < a; i++){
        for(int j = 1; j <= b; j++){
            cout << n[i][j] << ' ';
        }
        cout << endl;
    }
}