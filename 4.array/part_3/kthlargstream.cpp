#include <bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<>> minHeap;

    void f(int val) {
        minHeap.push(val);
        if (minHeap.size() > k)
        minHeap.pop();
    }

    KthLargest(int k, vector<int>& nums){
        this->k = k;
        for (int num : nums) f(num);
    }

    int add(int val) {
        f(val);
        return minHeap.top();
    }
};

int main() {

    return 0;
}