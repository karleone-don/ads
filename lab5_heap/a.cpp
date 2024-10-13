#include <iostream>
#include <algorithm>

using namespace std;

struct Heap // min Heap
{
    long long *a;
    long long size;
    long long capacity;

    Heap(long long x){
        this->a = new long long[x];
        this->capacity = x;
        this->size = 0;
    }

    int parent(long long i){
        return (i-1) / 2;
    }

    int left(long long i){
        return i*2 + 1;
    }

    int right(long long i){
        return i*2 + 2;
    }

    void HeapUp(long long i){
        if(i > 0){
            long long p = parent(i);
            if(a[p] > a[i]){
                swap(a[p], a[i]);
                HeapUp(p);
            }
        }
    }

    void HeapDown(long long i){
        long long l = left(i);
        long long r = right(i);
        long long min = i;
        
        if(l < this->size && a[min] > a[l]){
            min = l;
        }
        if(r < this->size && a[min] > a[r]){
            min = r;
        }

        if(min != i){
            swap(a[min], a[i]);
            HeapDown(min);
        }
    }

    void add(long long x){
        a[size] = x;
        size++;
        HeapUp(size - 1);
    }

    void cut_min(){
        a[0] = a[size - 1];
        size = max((long long)0, size - 1);
        HeapDown(0);
    }
};

int main(){
    long long a; cin >> a;
    Heap h(a);
    for(int i = 0; i < a; i++){
        long long b; cin >> b;
        h.add(b);
    }

    long long sum = 0;
    while(h.size != 1){
        long long x = 0;
        x += h.a[0];
        h.cut_min();
        x += h.a[0];
        h.cut_min();
        h.add(x);
        sum += x;
    }
    cout << sum;
}