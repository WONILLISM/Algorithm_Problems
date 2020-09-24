#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

int n, m;
vector<int> stack;

void solution(int cnt, int j){
	if (cnt == m){
		for (auto ans : stack)
			cout<<ans<<" ";
		cout<<endl;
		return ;
	}
	for (int i = j; i <= n; i++){
			stack.push_back(i);
			solution(cnt + 1, i);
			stack.pop_back();
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	solution(0, 1);
	
	return 0;
}