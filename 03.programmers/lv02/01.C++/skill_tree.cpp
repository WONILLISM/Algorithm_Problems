#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	vector<bool> check(26);    

	for (int i = 0; i < skill.length(); i++)    
		check[skill[i] - 65] = true;

	for (int i = 0; i < skill_trees.size(); i++) {
		int index = 0;
		int j;
        string s = skill_trees[i];
		for (j = 0; j < s.length(); j++) {
			if (check[s[j] - 65]) {
				if (skill[index] == s[j]) index++;
				else break;
			}
		}
		if (j == skill_trees[i].length())
			answer++;
	}
	return answer;
}
int main(){
    string skill = "CBD";
    vector<string> skill_trees = {"BACDE", "CBADF", "AECB", "BDA"};
    cout<<solution(skill,skill_trees)<<endl;
    return 0;
}