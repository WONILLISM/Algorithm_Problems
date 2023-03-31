#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;
	return answer;
}
int main(){
	vector<vector<int>> nodeinfo = {{5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2}};
	for (auto ans : solution(nodeinfo))
		for (auto a : ans)
			cout<<a<<" "<<endl;
	return 0;
}