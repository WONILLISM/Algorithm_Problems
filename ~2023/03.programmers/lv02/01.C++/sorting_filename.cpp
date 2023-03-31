#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct SSII{
    string file_name;
    string header;
    int number;
    int index;
};

bool comp(SSII a, SSII b){
    if(a.header == b.header)
        if(a.number == b.number)
            return a.index<b.index;
        else return a.number<b.number;
    else return a.header<b.header;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<SSII> tmp;
    for(int i =0; i<files.size(); i++){
        string file = files[i];
        int h=0,n=0;
        for(int j=0; j<file.size(); j++){
            if(isdigit(file[j])) break;
            else h = j;
        }
        for(int j=h+1; i<file.size(); j++){
            if(!isdigit(file[j])) break;
            else n =j;
        }
        string header = file.substr(0, h+1);
        int number = stoi(file.substr(h+1, n-h));
        
        for(int j=0; j<header.size(); j++) header[j] = tolower(header[j]);
        tmp.push_back({file, header, number,i});
        //cout<<header<<" "<<number<<endl;
    }
    sort(tmp.begin(), tmp.end(), comp);
    for(auto ans : tmp)
        answer.push_back(ans.file_name);
    return answer;
}
int main(){
    vector<string> files = {"img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"};
    for(auto ans : solution(files))
        cout<<ans<<" ";
    cout<<endl;
    return 0;
}