#include<iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool comp(char a, char b){return a > b;}
string solution(string s) {
    sort(s.begin(), s.end(), comp);
    return s;
}
int main(){
    string s = "Zbcdefg";
    cout<<solution(s)<<endl;
    return 0;
}