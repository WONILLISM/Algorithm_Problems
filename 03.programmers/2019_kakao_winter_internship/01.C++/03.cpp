#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>

using namespace std;

vector<bool> chk;
set<string> s;
void process(vector<string> user_id, vector<string> banned_id, string res, int idx){
    if(idx == banned_id.size()){
        sort(res.begin(), res.end());
        s.insert(res);
        return;
    }

    string bid = banned_id[idx];

    for(int i=0; i<user_id.size(); i++){
        string uid = user_id[i];

        if(uid.size()==bid.size()&&!chk[i]){
            bool flag = true;
            for(int j=0; j<bid.size(); j++){
                if(bid[j]!='*'&& bid[j]!=uid[j]){   //매핑이 불가능한 경우
                    flag = false;
                    break;
                }
            }
            if(flag){
                chk[i]=true;
                process(user_id,banned_id,res + to_string(i),idx+1);
                chk[i]=false;
            }
        }
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    chk.assign(user_id.size(), false);
    process(user_id, banned_id,"",0);
    answer = s.size();

    
    return answer;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // vector<string> id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
    // vector<string> bid = {"fr*d*", "abc1**"};

    // vector<string> id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
    // vector<string> bid = {"*rodo", "*rodo", "******"};

    vector<string> id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
    vector<string> bid = {"fr*d*", "*rodo", "******", "******"};

    cout<<solution(id,bid)<<endl;
    return 0;
}