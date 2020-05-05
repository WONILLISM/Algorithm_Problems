#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int GCD(int a, int b){
    if(a%b==0)return b;
    return GCD(b, a%b);
}
int LCM(int a, int b){return (a*b)/GCD(a,b);}
int solution(vector<int> arr) {
    int answer = arr[0];   
    for(int i=1; i<arr.size(); i++)
        answer = LCM(answer,arr[i]);

    return answer;
}
int main(){
    cout<<solution({4,6,20})<<endl;
    return 0;
}

// int solution(vector<int> arr) {
//     int answer =0;
//     sort(arr.begin(), arr.end());
//     int chk = 0;
//     while(chk!=arr.size()){
//         answer += arr[0];
//         chk=0;
//         for(int i=0; i<arr.size(); i++)
//             if(answer % arr[i] == 0)chk++;
//     }

//     return answer;
// }