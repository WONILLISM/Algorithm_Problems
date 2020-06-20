#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> D;
vector<bool> visit;
int Budget, answer;
void process(int sum, int cnt, int i){
    if(sum>Budget || cnt>=D.size())return;
    
    answer = max(cnt, answer);
    for(int j=i; j<visit.size(); j++){
        if(!visit[j]){
            visit[j] = true;
            process(sum + D[j], cnt+1, j);
            visit[j] = false;
        }
    }
}
int solution(vector<int> d, int budget) {
    d = D;
    Budget = budget;
    visit.assign(d.size(),false);
    process(0,0,0);

    return answer;
}
int main(){
    vector<int> d = {1,3,2,5,4};
    int budget = 9;
    cout<<solution(d,budget)<<endl;
    return 0;
}