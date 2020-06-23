#include<iostream>
#include <string>
#include <vector>

using namespace std;

string process(int x){
    if(x==1)return "#";
    else return process(x/2) + (x%2 == 1?"#":" ");
}
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0; i<n; i++){
        string s = process(arr1[i]|arr2[i]);
        for(int j=0; j<s.size() - n; j++) s = " " + s;
        answer.push_back(s);
    }
    return answer;
}

int main(){
    // int n = 5;
    // vector<int> arr1 = {9, 20, 28, 18, 11};
    // vector<int> arr2 = {30, 1, 21, 17, 28};
    int n = 6;
    vector<int> arr1 = {46, 33, 33 ,22, 31, 50};
    vector<int> arr2 = {27 ,56, 19, 14, 14, 10};
    for(auto ans : solution(n, arr1, arr2))
        cout<<ans<<" ";
    cout<<endl;
    return 0;
}