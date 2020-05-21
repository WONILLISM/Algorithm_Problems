#include <string>
#include <iostream>
using namespace std;

bool solution(string s){
    int p=0,y=0;
    for(char c : s){
        c = tolower(c);
        if(c=='p') p++;
        if(c=='y') y++;
    }
    return p == y;
}