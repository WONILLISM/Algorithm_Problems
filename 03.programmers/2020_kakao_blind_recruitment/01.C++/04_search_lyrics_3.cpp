#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    int qlen = queries.size();
    int wlen = words.size();

    for (int i = 0; i < qlen; i++) {
        string query = queries[i];
        string check = "";
        int start = 0, count = 0;   // ?가 시작되는 지점, ?의 개수
        bool flag = false;  // ? 가 나오기 시작했는지 안했는지
        bool qMark = true;  // 쿼리문이 ?가 포함 됐는지 안됐는지
        int cnt = 0;        // 해당 쿼리에 해당하는 워드의 개수
        for (int j = 0; j < query.size(); j++) {
            if (query[j] != '?') {  // query가 ?가 아니면 check에 누적
                check += query[j]; 
                qMark = false;
            }
            if (query[j] == '?' && !flag) { // query가 ?이고 처음 등장한다면
                start = j; 
                flag = true; 
            }
            // ?가 나온 적 있고, ?가 아닌 문자 이거나 마지막 문자일 때
            if ((flag && query[j] != '?') || (flag && j == query.size() - 1)) {
                if (start == 0) count = j;
                else
                    count = (j - start) + 1;
                flag = false;
            }
        }

        for (int j = 0; j < wlen; j++) {
            if (query.size() != words[j].size()) continue;  //
            if (qMark && query.size() == words[j].size()) {
                cnt++; 
                continue; 
            }
            string inc = "", exc = "";// ?  포함, ? 미포함
            if (start == 0) {   // 시작부분이 ?
                inc = words[j].substr(0, count);
                exc = words[j].substr(count);
            }
            else {  // 시작부분이 ? x
                inc = words[j].substr(start);
                exc = words[j].substr(0, start);
            }

            if ((exc.size() == check.size()) 
                    && ((check == exc) && (inc.size() == count)))
                cnt++;
        }
        answer.push_back(cnt);
    }

    return answer;
}
int main(){
    vector<string> words = {"frodo", "front", "frost", "frozen", "frame", "kakao"};
    // vector<string> words = {"frodo"};
    // vector<string> quries = {"????o"};
    vector<string> quries = {"fro??", "????o", "fr???", "fro???", "pro?"};


    for (auto ans : solution(words, quries))
        cout<<ans<<" ";
    
    return 0;
}
