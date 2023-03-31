#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int MUL = 65536;


vector <string> makeArr(string str){
    vector<string> sv;
    string sub;

    for(int i = 0; i < str.length()-1; i++){
        if(!isalpha(str[i]) || !isalpha(str[i+1])) continue;
        str[i] = tolower(str[i]);
        str[i+1] = tolower(str[i+1]);
        sub = str.substr(i,2);
        sv.push_back(sub);
    }
    return sv;
}
int solution(string str1, string str2) {
    int answer = 0;
    vector <string> sv1 = makeArr(str1);
    vector <string> sv2 = makeArr(str2);
    vector <string> sv = sv2;

    if(sv1.empty() && sv2.empty()) return MUL;

    for(int i = 0; i < sv1.size(); i++){
        auto itr = find(sv.begin(), sv.end(), sv1[i]);
        if(itr != sv.end()){
            sv.erase(itr);
            answer++;
        }
    }
    return MUL * ((double)answer/(double)(sv1.size()+sv2.size()-answer));
}
int main(){
    // string s1 = "handshake";    //ha an nd ds sh ha ak ke
    // string s2 = "shake hands";  //sh ha ak ke ha an nd ds
    // string s1 = "FRANCE";
    // string s2 = "french";
    // string s1 ="aa1+aa2";
    // string s2 = "AAAA12";
    string s1="";
    string s2 = "";
    cout<<solution(s1,s2)<<endl;

    return 0;
}