#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef struct failure_rate{
    int idx;
    double faulure;
}fr;
bool comp(failure_rate a, failure_rate b){
    if (a.faulure == b.faulure) return a.idx < b.idx;
    return a.faulure > b.faulure;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> cnt(N + 1, 0);
    int size = stages.size();
    for (auto i : stages)
        if(i != N + 1) cnt[i]++;
    
    vector<failure_rate> res;
    for (int i = 1; i <= N; i++){
        int key = i;
        int value = cnt[i];
        if (size == 0) res.push_back({key, 0});
        else res.push_back({key, value / (double) size});
        size -= value;
    }

    sort(res.begin(), res.end(), comp);
    for (auto r : res)
        answer.push_back(r.idx);
    return answer;
}
int main(){
    int N = 5;
    vector<int> stages = {2, 1, 2, 6, 2, 4, 3, 3};
    for (auto ans : solution(N, stages))
        cout<<ans<<endl;
    return 0;
}