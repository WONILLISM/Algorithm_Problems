#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
#define endl '\n'

using namespace std;

bool comp(string a, string b){
	if (a.size() == b.size())
		return a < b;
	return a.size() < b.size();
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	unordered_set<string> ss;
	vector<string> vs;
	int n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		ss.insert(s);
	}
	for (auto s : ss)
		vs.push_back(s);
	sort(vs.begin(), vs.end(), comp);
	for (auto s : vs)
		cout<<s<<endl;
	return 0;
}