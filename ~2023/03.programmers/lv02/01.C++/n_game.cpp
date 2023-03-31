#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string change(int number, int n,string ret){
    char idx = number%n>=10?number%n - 10 +'A':number%n + '0';
    if(number/n==0)return idx + ret;
    else return change(number/n,n,idx + ret);
}
string solution(int n, int t, int m, int p) {
    string answer = "";
    int number = 0, index = 0;
    while(true){
        string number_str = change(number, n, "");
        for(auto num : number_str){
            if(index == p-1)answer +=num;
            if(answer.size() == t)return answer;
            index = (index +1)%m;
        }
        number++;
    }
    return answer;
}
int main(){
    int n = 2;
    int t = 4;
    int m = 2;
    int p = 1;

    cout<<solution(n,t,m,p)<<endl;
    return 0;
}