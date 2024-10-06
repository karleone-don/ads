#include <iostream>

using namespace std;

int snake[800][800];

int binOdd(int n, int snake[], int c){
    int left = 0, right = c-1, mid;
    while(left <= right){
        mid = (left+right)/2;
        if(snake[mid] == n){
            return mid;
        }
        else if(snake[mid] < n){
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    return -1;
}

int binEven(int n, int snake[], int c){
    int left = 0, right = c-1, mid;
    while(left <= right){
        mid = (left+right)/2;
        if(snake[mid] == n){
            return mid;
        }
        else if(snake[mid] > n){
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    return -1;
}

int findRow(int n, int arr[][800], int b, int c){
    int left = 0, right = b - 1, mid, min, max;
    while(left <= right){
        mid = (left+right)/2;
        if(mid % 2 == 0){
            min = arr[mid][c-1];
            max = arr[mid][0];
        }
        else{
            max = arr[mid][c-1];
            min = arr[mid][0];
        }
        if(max >= n and n >= min){
            return mid;
        }
        else if(n > max){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return -1;
}

int main(){
    int a, b, c;
    cin >> a;
    int n[a];
    for(int i = 0; i < a; i++){
        cin >> n[i];
    }
    cin >> b >> c;
    for(int i = 0; i < b; i++){
        for(int j = 0; j < c; j++){
            cin >> snake[i][j];
        }
    }
    for(int i = 0; i < a; i++){
        int row = findRow(n[i], snake, b, c), col;
        if(row == -1){
            cout << -1 << endl;
            continue;
        }
        if(row % 2 == 0){
            col = binOdd(n[i], snake[row], c);
        }
        else{
            col = binEven(n[i], snake[row], c);
        }
        if(col == -1){
            cout << -1 << endl;
            continue;
        }
        cout << row << ' ' << col << endl;
    }
}