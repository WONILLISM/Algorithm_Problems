#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define PII pair<int,int>

using namespace std;
bool comp(string a, string b){return a.size()<b.size();}
vector<string> split(string s, string delimiter){
	vector<string> ret;
	int pos_start = 0, pos_end = 0, delim_len = delimiter.size();
	string token;

	while((pos_end = s.find(delimiter, pos_start)) != string::npos){
		token = s.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		ret.push_back(token);
	}
	ret.push_back(s.substr(pos_start));
	return ret;
}
vector<int> solution(string s) {
	vector<int> answer;
	s = s.substr(2,s.size()-4);
	vector<string> ret = split(s,"},{");
	sort(ret.begin(),ret.end(),comp);
	
	vector<string> tmp;
	for(auto i : ret){
		tmp = split(i,",");
		for(auto j : tmp){
			if(find(answer.begin(),answer.end(),stoi(j))==answer.end()){
				answer.push_back(stoi(j));
			}
		}
	}
	
	return answer;
}
int main() {
	//string s = "{ {2},{2,1},{2,1,3},{2,1,3,4} }";
	string s = "{{4,2,3},{3},{2,3,4,1},{2,3}}";
	//string s = "{{123}}";
	//string s = "{{20,111},{111}}";
	for (auto ans : solution(s))
		cout << ans << " ";
	return 0;
}