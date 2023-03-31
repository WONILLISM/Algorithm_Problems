#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int cnt[501];
struct ID{
	int idx;
	double value;
};

bool comp(ID a, ID b){
    if(a.value == b.value)return a.idx < b.idx;
	return a.value > b.value;
}
vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	int size = stages.size();
	for(int i : stages)
		if(i!=N+1)cnt[i]++;
	
	vector<ID> ans;
	for(int i=1; i<=N; i++){
		int key = i;
		int value = cnt[i];
		if(size == 0)ans.push_back({key, 0});
		else ans.push_back({key,value/(double)size});
		size -= value;
	}
	
	sort(ans.begin(), ans.end(), comp);
	for(auto res : ans)
		answer.push_back(res.idx);
    return answer;
}
int main(){
    vector<int> s = {2, 1, 2, 6, 2, 4, 3, 3};
    int n = 5;
	// vector<int> s = {4,4,4,4,4};
    // int n = 5;
    for(auto ans : solution(n,s))
        cout<<ans<<" ";
    return 0;
}



// 1 2 2 2 3 3 4 6
// vector<int> solution(int N, vector<int> stages) {
//     vector<int> answer;
//     vector<pair<double,int>> res(N,{0,0});
//     sort(stages.begin(), stages.end());
//     int l=0, r=0, n = stages.size();
//     int idx=0;
//     while(1){
//         if(r>=stages.size())break;
//         if(stages[l]==stages[r]) {
//             r++;
//         }
//         else{
//             int num = r-l;
//             res[idx] ={n/(double)num, idx++};
//             n-=num;
//             l +=num;
//         }
//     }

//     sort(res.begin(), res.end());
//     for(int i=res.size()-1; i>=0; i--)
//         answer.push_back(res[i].second);
    
//     return answer;
// }