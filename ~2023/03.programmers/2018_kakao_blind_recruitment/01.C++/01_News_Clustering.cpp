#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MUL = 65536;

vector<string> make_multi_set(string str){
    vector<string> ret;
    for (int i = 0; i < str.size() - 1; i++){
        if (!isalpha(str[i]) || !isalpha(str[i + 1])) continue;
        str[i] = tolower(str[i]);
        str[i + 1] = tolower(str[i + 1]);
        ret.push_back(str.substr(i, 2));
    }
    return ret;
}
int solution(string str1, string str2) {
    int answer = 0;
    vector<string> sv1 = make_multi_set(str1);
    vector<string> sv2 = make_multi_set(str2);
    vector<string> sv = sv2;

    if (sv1.empty() && sv2.empty()) return MUL;

    for (int i = 0; i < sv1.size(); i++){
        auto itr = find(sv.begin(), sv.end(), sv1[i]);
        if (itr != sv.end()){
            sv.erase(itr);
            answer++;
        }
    }
    return MUL * ((double)answer/(double)(sv1.size() + sv2.size() - answer));
}
int main(){
    string str[5][2] = {
        {"FRANCE", "french"},
        {"handshake", "shake hands"},
        {"aa1+aa2", "AAAA12"},
        {"E=M*C^2", "e=m*c^2"}
    };
    for (int i = 0; i<5; i++)
        cout<<solution(str[i][0], str[i][1])<<endl;
    return 0;
}