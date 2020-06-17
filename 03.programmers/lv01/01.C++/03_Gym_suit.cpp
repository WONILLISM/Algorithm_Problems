#include <iostream>
#include <string>
#include <vector>

using namespace std;
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> students(n+1,1);
    for(auto r : reserve)students[r] +=1;
    for(auto l : lost) students[l] -=1;
    for(int i=1; i<=n; i++){
        if(students[i] == 0){
            if(students[i-1] == 2) students[i-1] = students[i] = 1;
            else if(students[i+1] == 2) students[i] = students[i+1] = 1;
        }
    }
    for(int i=1; i<=n; i++)
        if(students[i])answer++;
    return answer;
}
int main(){
    int n = 5;
    vector<int> lost = {2,4};
    vector<int> reserve = {3};
    cout<<solution(n,lost, reserve)<<endl;
    return 0;
}