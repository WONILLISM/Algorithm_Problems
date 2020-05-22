#include<iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int i=0; i<skill_trees.size(); i++){
        string str = skill_trees[i];
        string tmp ="";
        for(int j=0; j<str.size(); j++)
            if(skill.find(str[j])!=string::npos)tmp+=str[j];
        for(int j=0; j<tmp.size(); j++){
            
        }
    }
    return answer;
}
int main(){
    string skill = "CBD";
    vector<string> skill_trees = {"BACDE", "CBADF", "AECB", "BDA"};
    cout<<solution(skill,skill_trees)<<endl;
    return 0;
}