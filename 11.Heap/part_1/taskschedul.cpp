#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freqmap(26, 0);
        for(auto ch : tasks) freqmap[ch - 'A']++;
        
        priority_queue<int> pq;
        for(auto it : freqmap){
            if(it > 0) pq.push(it);
        }
        int takentime = 0;

        while(pq.size()){
            vector<int> notcompleted;
            for(int i = 1; i <= n+1; i++){
                if(pq.size()){
                    int freq = pq.top(); pq.pop();
                    freq--;
                    notcompleted.push_back(freq);
                }
            }
            for(auto it : notcompleted){
                if(it > 0) pq.push(it);
            }
            if(pq.empty()) takentime += notcompleted.size();
            else takentime += n + 1;
        }
        return takentime;
    }
};

int main() {

    return 0;
}