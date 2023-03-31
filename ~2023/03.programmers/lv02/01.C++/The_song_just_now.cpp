#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
struct PP{
    int idx;
    string title, melody;
};
bool comp(PP a, PP b){
    if(a.melody.size() == b.melody.size())return a.idx < b.idx;
    else return a.melody.size()>b.melody.size();
}
string Replace(string s){
    string ret = "";
    for(int i=0; i<s.size()-1; i++){
        if(s[i+1] != '#') ret+=s[i];
        else{
            if(s[i] == 'C') ret+='H';
            else if(s[i] == 'D') ret+='I';
            else if(s[i] == 'F') ret+='J';
            else if(s[i] == 'G') ret+='K';
            else if(s[i] == 'A') ret+='L';
            i++;
        }
    }
    if(s[s.size()-1]!='#')ret +=s[s.size()-1];
    return ret;
}
PP split(string s,int index){
    PP ret;
    string tmp="";
    vector<string> str;    // 제목, 멜로디
    int idx =0, play_time=0;
    for(int i=0; i<=s.size(); i++){
        char c = s[i];
        if(c==','||c=='\0'){
            if(idx < 2){
                int d = idx ==0? -1:1;
                play_time += d* stoi(tmp.substr(0,2))*60 +d*stoi(tmp.substr(3,2));
                tmp.clear();
            }
            else{
                if(idx == 3){
                    tmp = Replace(tmp);
                }
                str.push_back(tmp);
                tmp = "";
            }
            idx++;
        }
        else tmp+=c;
    }
    ret = {index,str[0],""};
    for(int i=0; i<play_time; i++){
        ret.melody+=str[1][i%str[1].size()];
    }

    return ret;
}
string solution(string m, vector<string> musicinfos) {
    string answer = "";
    m = Replace(m);
    vector<PP> vss;
    for(int i=0; i<musicinfos.size(); i++){
        string s = musicinfos[i];
        PP tmp = split(s,i);
        string play = tmp.melody;
        auto itr = play.find(m);
        if(itr != string::npos)vss.push_back(tmp);        
    }

    sort(vss.begin(), vss.end(),comp);
    if(vss.size()) return answer = vss[0].title;
    else return answer = "(None)";
}
int main(){
    //string m  = "ABCDEFG";
    string m = "ABC#D#";
    //vector<string> musicinfos = {"12:00,12:14,HELLO,CDEFGAB","13:00,13:05,WORLD,ABCDEF"};
    vector<string> musicinfos = {"12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"};	
    cout<<solution(m, musicinfos)<<endl;
    return 0;
}