#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int n = phone_number.size();
    for(int i = 0; i<n; i++)
        answer += n-i>4?'*':phone_number[i];
    return answer;
}
int main(){
    cout<<solution("01033334444")<<endl;
    return 0;
}