#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(vector<string> seoul) {
    auto itr = find(seoul.begin(), seoul.end(), "Kim");
    int idx  = itr - seoul.begin();
    return "김서방은 "+to_string(idx)+"에 있다";
}
int main(){
    cout<<solution({"a","Jane","Kim"})<<endl;
    return 0;
}