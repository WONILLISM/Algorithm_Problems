#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

const double MUL = 65536.0;

unordered_map<string,int> split(string s){
    unordered_map<string, int> ret;
    if(s.empty())return ret;
    for (int i = 0; i < s.size()-1; i++){
        s[i] = tolower(s[i]);
        s[i+1] =tolower(s[i+1]);
        if (s[i] < 'a' || s[i] > 'z') continue;
        if (s[i+1] < 'a' || s[i+1] > 'z') continue;
        
        string tmp="";
        tmp += s[i];
        tmp += s[i+1];

        if(ret.find(tmp)==ret.end())ret.insert({tmp,1});
        else ret[tmp]++;
    }
    return ret;
}
int solution(string str1, string str2) {
    double answer = 0;
    unordered_map<string, int> m1;
    unordered_map<string, int> m2;

    m1 = split(str1);
    m2 = split(str2);
    if(m1.empty() || m2.empty()) return MUL;

    int _union = 0;
    int _intersection = 0;

    for(auto i : m1) _union+=i.second;

    for(auto i : m2){ 
        string key = i.first;
        int m2_v = i.second;
        if(m1.find(key)!= m1.end()){
            int m1_v = m1[key];
            if(m1_v<m2_v){
                _union -= m1_v;
                _union += m2_v;
                _intersection+=m1_v;
            }
            else _intersection+=m2_v;
            
        }
        else _union+=m2_v;
    }
    if(_union==0 || _intersection==0) return MUL;
    else return answer = MUL * (_intersection / (double)_union);
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