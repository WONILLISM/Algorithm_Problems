#include<iostream>
#include <string>
#include <vector>

using namespace std;

int chk_alpha(char c){
    if(c>='a'&&c<='z')return 0;
    else if (c>='A'&& c<='Z')return 1;
    else return -1;
}
string solution(string s, int n) {
    for(int i=0; i<s.size(); i++){
        char c = s[i];
        if(chk_alpha(c) == -1)continue;
        else if(chk_alpha(c)==0){
            if(c+n>'z')s[i] = 'a'-1 + (s[i] + n -'z');
            else s[i] +=n;
        }
        else if(chk_alpha(c==1)){
            if(c+n>'Z')s[i] = 'A'-1 + (s[i] + n -'Z');
            else s[i] +=n;
        }
    }
    return s;
}