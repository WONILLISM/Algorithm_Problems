#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector<string> day = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
    vector<int> date_of_month = {31,29,31,30,31,30,31,31,30,31,30,31};
    int d = -1;
    for(int i=0; i<a-1; i++)
        d +=date_of_month[i];
    d+=b;
    answer = day[d%7];
    return answer;
}
int main(){
    int a = 5, b = 24;
    cout<<solution(a,b)<<endl;
    return 0;
}