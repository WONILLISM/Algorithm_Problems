#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<vector<string>, int> um;

typedef struct table{
	table *child[3];
	string key;
	int idx;
	int val;

	table() : idx(0){
		for(int i = 0; i<3; i++)
			child[i] = NULL;
	}
	~table(){
		for (int i = 0; i<3; i++){
			if (child[i])
				delete child[i];
		}
	}

	void insert(string key){
		if (key.empty()){
			return ;
		}
		if (key == "cpp" || key == "backend" || key == "junior" || key == "chicken"){
			if (!child[0])
				child[0] = new table();
			child[0]->insert()
		}
	}
} table;

unordered_map <table, int> um;

vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	for (auto inf : info){
		vector<string> tmp;
		int val;
		int idx = 0;
		tmp.push_back("");
		for(int j = 0; j <inf.size(); j++){
			if (inf[j] == ' '){
				idx++;
				tmp.push_back("");
			}
			else{
				tmp[idx] +=inf[j];
			}
		}
		table t = {tmp[0], tmp[1], tmp[2], tmp[3]};
		
	}
	return answer;
}
int main(){
	vector<string> info = {
		"java backend junior pizza 150",
		"python frontend senior chicken 210",
		"python frontend senior chicken 150",
		"cpp backend senior pizza 260",
		"java backend junior chicken 80",
		"python backend senior chicken 50"
	};
	vector<string> query = {
		"java and backend and junior and pizza 100",
		"python and frontend and senior and chicken 200",
		"cpp and - and senior and pizza 250",
		"- and backend and senior and - 150",
		"- and - and - and chicken 100",
		"- and - and - and - 150"};
	solution(info, query);
	return 0;
}