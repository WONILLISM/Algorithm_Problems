#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;


int solution(vector<int> stones, int k) {
    int left = 1, right = *max_element(stones.begin(),stones.end());
    int size = stones.size();
    while(left <= right){
        int mid = (left + right) / 2;
        int cnt = 0;
        bool flag = false;
        for(int i = 0; i < size; i++){
            //cnt가 연속으로 1씩 더해져 k보다 크거나 같아지는 경우에는 건널 수 없음.
            if(stones[i] - mid <= 0) cnt++;
            else cnt = 0;
            if(cnt >= k){
                flag = true;
                break;
            }
        }

        if(flag) right = mid - 1;   
        else left = mid + 1;        
    }
    return left;
}
int main(){
    vector<int> s = {2, 4, 5, 3, 2, 1, 4, 2, 5, 1};
    int k = 3;
    cout << solution(s, k) << endl;
    return 0;
}