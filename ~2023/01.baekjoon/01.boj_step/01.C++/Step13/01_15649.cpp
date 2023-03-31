#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

int n, m;
vector<int> stack;
vector<int> visit;

void solution(int cnt, int j){
	if (cnt == m){
		for (auto ans : stack)
			cout<<ans<<" ";
		cout<<endl;
		return ;
	}
	for (int i = 1; i <= n; i++){
		if (!visit[i]){
			visit[i] = true;
			stack.push_back(i);
			solution(cnt + 1, i + 1);
			stack.pop_back();
			visit[i] = false;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	visit.assign(n + 1, false);
	solution(0, 1);
	
	return 0;
}