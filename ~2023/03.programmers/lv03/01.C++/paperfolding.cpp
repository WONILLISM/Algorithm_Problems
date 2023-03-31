#include<iostream>
#include <string>
#include <deque>
#include <vector>

using namespace std;
vector<int> solution(int n) {
    vector<int> answer;
    deque<int> tmp;
    vector<int> prev;
    prev.push_back(0);
    for(int i=1; i<n; i++){
        tmp.push_back(0);
        for(int j=prev.size()-1; j>=0; j--){
            tmp.push_front(prev[j]);
            prev[j] = prev[j]==0?1:0;
        }
        for(int j=prev.size()-1; j>=0; j--)
            tmp.push_back(prev[j]);
        prev.clear();
        while(!tmp.empty()){
            prev.push_back(tmp.front());
            tmp.pop_front();
        }
    }
    answer = prev;
    return answer;
}
int main(){
    int n = 3;
    for(int ans : solution(n))
        cout<<ans<<" ";

    return 0;
}

