#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define PII pair<int,int>

using namespace std;
bool comp(vector<int> a, vector<int> b) { return a.size() < b.size(); }
vector<int> solution(string s) {
	vector<int> answer;
	vector<vector<int>> str;
	unordered_map<int,int> um;	//idx, num
	bool chk = false;
	string tmp = "";
	int idx = 0;
	for (int i = 1; i < s.size() - 1; i++) {
		char c = s[i];
		if (c == '{') {
			chk = true;
			str.push_back(vector<int>());
		}
		else if (chk) {
			if (c == '}') {
				str[idx++].push_back(stoi(tmp));
				tmp.clear();
				chk = false;
			}
			else if(c==','){
				str[idx].push_back(stoi(tmp));
				tmp.clear();
			}
			else if (c != ',')tmp += c;
		}
	}	
	sort(str.begin(), str.end(), comp);
	idx = 1;
	vector<PII> ans;
	for (int i = 0; i < str.size(); i++) {
		for (int j = 0; j < str[i].size(); j++) {
			if (um.find(str[i][j])==um.end()) {
				um.insert({ str[i][j],idx });
				ans.push_back({ idx++,str[i][j] });
			}
		}
	}
	sort(ans.begin(), ans.end());
	for (auto res : ans)
		answer.push_back(res.second);

	return answer;
}
int main() {
	//string s = "{ {2},{2,1},{2,1,3},{2,1,3,4} }";
	//string s = "{{4,2,3},{3},{2,3,4,1},{2,3}}";
	//string s = "{{123}}";
	string s = "{{20,111},{111}}";
	for (auto ans : solution(s))
		cout << ans << " ";
	return 0;
}