#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

int solution(vector<int> pri, int loc){
    int answer = 0;
    vector<int> tmp = pri;
    deque<int> dq;
    sort(tmp.begin(), tmp.end(),greater<int>());
    // for(auto i :tmp) cout<<i<<endl;
    
    for(auto i : pri)dq.push_back(i);

    int idx =0;
    while(!dq.empty()){
        int cur = dq.front();
        dq.pop_front();
        if(cur==tmp[idx]){
            answer++;
            if(loc == 0)break;
            else loc--;
            idx++;
        }
        else{
            if(loc == 0)loc = dq.size();
            else loc--;
            dq.push_back(cur);
        }
    }
    return answer;
}
int main(){
    // vector<int> priorities = {2,1,3,2};
    // int location = 2;
    vector<int> priorities = {1,1,9,1,1,1};
    int location = 0;
    cout<<solution(priorities, location)<<endl;
    return 0;
}

// #include<iostream>
// #include<vector>
// #include<algorithm>

// using namespace std;
// bool check[100];// 검사한 작업인지 체크
// int solution(vector<int> priorities, int location) {
// 	int answer = 0;
// 	vector<int> temp = priorities;      // 우선순위 순으로 정렬
// 	int p = priorities[location];       // 정답
// 	int count = priorities.size();
// 	int i = 0, j = 0;
// 	int cp = 0;     // 현재 우선순위

// 	sort(temp.begin(), temp.end(), greater<int>());
// 	cp = temp[i];

// 	while (count != 0) {
// 		if ((check[j] == false) && (cp == priorities[j])) {
// 			check[j] = true;
// 			count--;
// 			i++;
// 			//answer++;
// 			if ((cp == p) && (j == location))
// 				break;
// 			cp = temp[i];
// 		}
// 		j++;
// 		if (j == priorities.size())
// 			j = 0;

// 	}

// 	return answer = i;
// }