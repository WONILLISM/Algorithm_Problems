#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
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
string solution(string s) {
    string answer = "";
    vector<string> tmp = split(s," ");
    int Min = 1<<30;
    int Max = -1<<30;
    for(auto res : tmp){
        int a = stoi(res);
        Min = min(a,Min);
        Max = max(a,Max);
    }
         
    answer+=to_string(Min)+" ";
    answer+=to_string(Max);
    return answer;
}
int main(){
    cout<<solution("1 2 3 4")<<endl;
}