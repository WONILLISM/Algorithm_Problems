#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;
int rel_size, key_size;
vector<bool> check;
vector<vector<string>> rel;
vector<vector<bool>> ans;
unordered_set<string> us;

bool is_possible(){
    for (int i = 0; i < ans.size(); i++){
        for(int j = 0; j<ans[i].size(); j++){
            if (ans[i][j]&&(check[j] == ans[i][j]))
                return false;
        }
    }
    return true;
}

void set_set(){
    for (auto att : rel){
        string tmp="";
        for(int j = 0; j<check.size(); j++)
            if(check[j]) tmp+=att[j];
        us.insert(tmp);
    }
}

void process(int i, int cnt){
    if (i >= key_size)return;
    if (cnt){
        us.clear();
        set_set();
        if (us.size() == rel_size && is_possible())
            ans.push_back(check);
    }
    for (int j = i; j < key_size; j++){
        if (!check[j]){
            check[j] = true;
            process(j, cnt + 1);
            check[j] = false;
        }
    }
}
int solution(vector<vector<string>> relation) {
    rel = relation;
    rel_size = relation.size();
    key_size = relation[0].size();
    check.assign(key_size, false);
    process(0, 0);
    return ans.size();
}
int main(){
    // vector<vector<string>> relation = {
    //     {"100", "ryan", "music", "2"}, 
    //     {"200", "apeach", "math", "2"}, 
    //     {"300", "tube", "computer", "3"}, 
    //     {"400", "con", "computer", "4"}, 
    //     {"500", "muzi", "music", "3"}, 
    //     {"600", "apeach", "music", "2"}
    // };
    // vector<vector<string>> relation = {
    //     {"a", "b", "c"},
    //     {"1","b","c"},
    //     {"a","b","4"},
    //     {"a", "5", "c"}
    // };
    vector<vector<string>> relation = {
        {"01","110","0"},
        {"10","10","01"},
        {"0","0","01"},
        {"0","0","2"}
    };

    cout<<solution(relation)<<endl;
    return 0;
}