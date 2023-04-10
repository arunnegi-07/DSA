#include<iostream>
#include <queue>
using namespace std;

int main(){

    priority_queue<int, vector<int>, greater<int>> pq;
    int k = 5;
    int arr[6] = { 10, 2, 4, 8, 6, 9 };
       for (int i = 0; i < 6; i++) {
        pq.push(arr[i]);
    }  

    // while (!pq.empty()) {
    //     cout << pq.top() << ' ';
    //     pq.pop();
    // }
      for(int i=1;i<=k-1;i++)
           pq.pop();
    
    cout << "Kth smallest is: " << pq.top();
} 