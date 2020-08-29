#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int cnt;
class Trie{
public:
    Trie *child[128];
    bool flag;

    Trie() : flag(false){
        for (int i = 0; i < 128; i++)
            child[i] = 0;
    }
    ~Trie(){
        for (int i = 0; i < 128; i++)
            if (child[i])
                delete child[i];
    }

    void insert(const char* key){
        if (!*key)
            flag = true;
        else{
            int next = *key;
            if (!child[next])
                child[next] = new Trie();
            child[next]->insert(key + 1);
        }
    }

    void search(const char *key){
        if (!*key) {
            if (this->flag)
                cnt++;
            return ;
        }
        int next = *key;
        if (child[next] == 0){
            if (*key == '?'){
                for (int i = 1; i < 128; i++)
                    if (child[i])
                        child[i]->search(key + 1);
                return ;
            }
            else 
                return ;
        }
        else
            child[next]->search(key + 1);
    }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    Trie *root = new Trie;
    for (auto w : words){
        const char *c = w.c_str();
        root->insert(c);
    }
    for (auto q : queries){
        const char *c = q.c_str();
        cnt = 0;
        root->search(c);
        answer.push_back(cnt);
    }
    return answer;
}
int main(){
    vector<string> words = {"frodo", "front", "frost", "frozen", "frame", "kakao"};
    vector<string> quries = {"fro??", "????o", "fr???", "fro???", "pro?"};

    for (auto ans : solution(words, quries))
        cout<<ans<<" ";
    
    return 0;
}