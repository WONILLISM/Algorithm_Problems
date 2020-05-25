#include<iostream>
#include <string>
#include <vector>

using namespace std;

int chk_alpha(char c){
    if(c>='a'&&c<='z')return '0';
    else if (c>='A'&& c<='Z')return '1';
    else return -1;
}
string solution(string s, int n) {
    //string answer = "";
    for(int i=0; i<s.size(); i++){
        char c = s[i];
        int chk = chk_alpha(c);
        if(chk == -1)continue;
        // else{ 
        //     if(c + n > chk) s[i] 
        // }
        else if(chk==0){
            if(c+n>'z')s[i] = 'a'-1 + (s[i] + n -'z');
            else s[i] +=n;
        }
        else if(chk==1)){
            if(c+n>'Z')s[i] = 'A'-1 + (s[i] + n -'Z');
            else s[i] +=n;
        }
    }
    return s;
}


// #include<iostream>
// #include <string>
// #include <vector>

// using namespace std;

// int chk_alpha(char c){
//     if(c>='a'&&c<='z')return 0;
//     else if (c>='A'&& c<='Z')return 1;
//     else return -1;
// }
// string solution(string s, int n) {
//     //string answer = "";
//     for(int i=0; i<s.size(); i++){
//         char c = s[i];
//         if(chk_alpha(c) == -1)continue;
//         else if(chk_alpha(c)==0){
//             if(c+n>'z'){
//                 cout<<"97 + 122 -"<<int(s[i]) <<"+"<< n-1<<endl;
//                 cout<< 'a' + 'z' - s[i] + n -1<<" "<<endl;
//                 s[i] = 'a' + 'z' - s[i] + n -1;
//             }
//             else s[i] +=n;
//         }
//         else if(chk_alpha(c==1)){
//             if(c+n>'Z')s[i] = 'A' + 'Z' - s[i] + n -1;
//             else s[i] +=n;
//         }
//         //cout<<s[i]<<" ";
//     }
//     return s;
// }