#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Trie{
public:
    Trie *child[26];
    bool flag;
    int cnt;

    Trie() : flag(false), cnt(1){
        for (int i = 0; i < 26; i++)
            child[i] = 0;
    }
    ~Trie(){
        for (int i = 0; i < 26; i++)
            if (child[i])
                delete child[i];
    }

    void insert(const char* key){
        if (!*key)
            flag = true;
        else{
            int next = *key - 'a';
            if (!child[next])
                child[next] = new Trie();
            else 
                child[next]->cnt++;
            child[next]->insert(key + 1);
        }
    }

    int search(const char *key){
        int next = *key - 'a';
        if (*key == '?'){
            int tmp = 0;
            for (int i = 0; i < 26; i++){
                if (child[i]) 
                    tmp += child[i]->cnt;
            }
            return tmp;
        }
        if (!child[next]) return 0;
        if (*(key + 1) == '?') return child[next]->cnt;
        return child[next]->search(key + 1);
    }
};
Trie *root[10001];
Trie *re_root[10001];
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer(queries.size(), 0);

    for (auto w : words){
        int len = w.size();
        
        const char *c = w.c_str();
        if (!root[len]) root[len] = new Trie();
        root[len]->insert(c);

        string rev = w;
        reverse(rev.begin(), rev.end());
        const char *r = rev.c_str();
        cout<<rev<<endl;
        
        if (!re_root[len]) re_root[len] = new Trie();
        re_root[len]->insert(r);
    }
    int i = 0;
    for (auto q : queries){
        int len = q.size();

        if (q[len-1] == '?'){
            const char *c = q.c_str();
            if (!root[len]){
                i++;
                continue;
            }
            else answer[i] = root[len]->search(c);
        }
        else {
            string rev = q;
            reverse(rev.begin(), rev.end());
            const char *r = rev.c_str();
            if (!re_root[len]){
                i++;
                continue;
            }
            else answer[i] = re_root[len]->search(r);
        }
        i++;
    }
    return answer;
}
int main(){
    // vector<string> words = {"frodo", "front", "frost", "frozen", "frame", "kakao"};
    vector<string> words = {"frodo"};
    vector<string> quries = {"????o"};
    // vector<string> quries = {"fro??", "????o", "fr???", "fro???", "pro?"};


    for (auto ans : solution(words, quries))
        cout<<ans<<" ";
    
    return 0;
}
