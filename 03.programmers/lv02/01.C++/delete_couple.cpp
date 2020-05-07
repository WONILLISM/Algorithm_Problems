#include <iostream>
#include<string>
#include<vector>
using namespace std;

int solution(string s){
    vector<int> v;
    for(auto c : s){
        if(!v.empty()&&v.back() == c)v.pop_back();
        else v.push_back(c);
    }
    return v.size()==0?1:0;
}
int main(){
    cout<<solution("baba")<<endl;
    return 0;
}