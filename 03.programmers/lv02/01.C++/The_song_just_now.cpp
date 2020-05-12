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
    int n1 =s.find("C#");
    int n2 =s.find("D#");
    int n3 =s.find("F#");
    int n4 =s.find("G#");
    if(n1!=-1){s.replace(n1,s.size(),"H");}
    if(n2!=-1){s.replace(n2,s.size(),"I");}
    if(n3!=-1){s.replace(n3,s.size(),"J");}
    if(n4!=-1){s.replace(n4,s.size(),"K");}
    return s;
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
        int n = tmp.melody.find(m);
        if(n!=-1)vss.push_back(tmp);
    }

    sort(vss.begin(), vss.end(),comp);
    if(vss.size()) return answer = vss[0].title;
    else return answer = "None";
}
int main(){
    //string m  = "ABCDEFG";
    string m = "ABC#";
    //vector<string> musicinfos = {"12:00,12:14,HELLO,CDEFGAB","13:00,13:05,WORLD,ABCDEF"};
    vector<string> musicinfos = {"12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"};	
    cout<<solution(m, musicinfos)<<endl;
    return 0;
}