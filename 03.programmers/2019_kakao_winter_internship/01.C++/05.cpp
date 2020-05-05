#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int answer=1<<30;

int solution(vector<int> stones, int k){
    if(stones.size()<k){
        sort(stones.begin(),stones.end());
        return answer = stones.back();
    }
    deque<int> deq;    
    bool inc = false, dec = false;   // 증감 확인
    int d1 = stones[0] - stones[1];
    if(d1 >= 0) dec = true;
    if(d1 <= 0) inc  = true;
    deq.push_back(stones[0]);
    deq.push_back(stones[1]);
    if(k<=2)return deq.front()>deq.back()?deq.front():deq.back();
    for(int i = 2; i<stones.size(); i++){
        int d2 = stones[i-1] - stones[i];
        deq.push_back(stones[i]);
        if(d2==0){
            dec = true;
            inc = true;
        }
        else if(d2 >0){
            if(d1 < 0) deq.pop_front();
            dec = true;
            inc = false;
        }
        else if(d2<0){
            if(d1 >0) deq.pop_front();
            dec = false;
            inc = true;
        }
        if(deq.size() == k){
            if(dec) answer = min(answer, deq.front());
            if(inc) answer = min(answer, deq.back());
            deq.pop_front();
        }
        d1 = d2;
    }

    return answer;
}
int main(){
    // vector<int> s = {2, 4, 5, 3, 2, 1, 4, 2, 5, 1};
    vector<int> s = {4,5,6};
    int k = 2;
    cout << solution(s, k) << endl;
    return 0;
}