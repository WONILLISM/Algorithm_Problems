#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> tmp; 
    for(int i=0; i<dartResult.length(); i++){
        char c = dartResult[i];
        if(c>='0' && c<='9'){
            if(c == '1' && dartResult[i+1] == '0'){
                tmp.push_back(10);
                ++i;
            }
            else tmp.push_back(c - '0');
        }
        else{
            int back = tmp.size()-1;
            if(c == 'S') continue;
            else if(c == 'D') tmp[back] = tmp[back] * tmp[back];
            else if(c == 'T') tmp[back] = tmp[back] * tmp[back] * tmp[back];
            else if(c == '*'){
                if(back == 0) tmp[back] *=2;
                else{
                    tmp[back]*=2;
                    tmp[back-1]*=2;
                }
            }
            else if(c == '#')tmp[back] *=-1;
        }
    }
    for(auto res : tmp) answer += res;
    return answer;
}
int main(){
    string dartResult = {"1S2D*3T"};
    cout<<solution(dartResult)<<endl;

    return 0;
}