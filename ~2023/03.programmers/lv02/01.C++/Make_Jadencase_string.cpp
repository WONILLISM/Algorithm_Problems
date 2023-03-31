#include <string>
#include <vector>

using namespace std;

vector<string> split(string s, string delimiter){
    vector<string> ret;
    int pos_start = 0, pos_end = 0, delim_len = delimiter.size();
    string token;

    while((pos_end = s.find(delimiter, pos_start)) != string::npos){
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        ret.push_back(token);
    }
    ret.push_back(s.substr(pos_start));
    return ret;
}
string solution(string s) {
    string answer = "";
    vector<string> tmp = split(s," ");
    for(auto res : tmp){
        if(res[0]>='a'&&res[0]<='z')
            res[0] = res[0] - 'a' + 'A';
        for(int i=1; i<res.size(); i++){
            if(res[i]>='A'&&res[i]<='Z'){
                res[i]=res[i] - 'A'+'a';
            }
        }
        answer +=res+" ";
    }
    answer.pop_back();

    return answer;
}

// #include <string>
// #include <vector>

// using namespace std;

// string solution(string s) {
//     string answer = "";

//     answer += toupper(s[0]);
//     for (int i = 1; i < s.size(); i++)
//         s[i - 1] == ' ' ? answer += toupper(s[i]) : answer += tolower(s[i]);

//     return answer;
// }