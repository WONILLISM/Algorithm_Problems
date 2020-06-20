#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<int> d, int budget) {
    int answer = 0, sum=0;
    sort(d.begin(), d.end());
    for(int i=0; i<d.size(); i++){
        if(sum + d[i] > budget) return answer;
        else sum +=d[i], answer++;
    }
    return answer;
}
int main(){
    vector<int> d = {2,2,3,3};
    int budget = 10;
    cout<<solution(d,budget)<<endl;
    return 0;
}

/* ----------- TLE -------------------
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
*/