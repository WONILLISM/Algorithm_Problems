#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int size = cities.size();
    vector<string> cache;
    if(!cacheSize)return answer = 5*size;
    for(int i=0; i<cities.size(); i++){
        string tmp = "";
        for(char a : cities[i]) tmp+=tolower(a);
        auto itr = find(cache.begin(), cache.end(),tmp);
        if(itr != cache.end()){
            cache.erase(itr);
            cache.push_back(tmp);
            answer++;
        }
        else{
            if(cache.size() < cacheSize) cache.push_back(tmp);
            else{
                cache.erase(cache.begin());
                cache.push_back(tmp);
            }
            answer +=5;
        }
    }
    return answer;
}
int main(){
    int cacheSize = 3;
    vector<string> cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"};
    cout<<solution(cacheSize, cities)<<endl;
    return 0;
}