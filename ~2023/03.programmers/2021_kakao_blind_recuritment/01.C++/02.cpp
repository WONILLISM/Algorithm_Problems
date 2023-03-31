#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

map<string, int> ordered;
bool check[20];

bool cmp(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

void power_set(string str, int n, int depth, int len)
{
    if(n == depth)
    {
        int i;
        string tmp = "";
        for(i = 0; i < n; i++)
        {
            if(check[i] == 1)
            {
                tmp.push_back(str[i]);
            }
        }
        if (tmp.length() >= len)
        {
            if (!ordered[tmp])
            {
                ordered.insert(pair<string, int>(tmp, 0));
            }
            ordered[tmp] += 1;
        }
        return;
    }
    check[depth]=1;
    power_set(str, n,depth+1, len);
    check[depth]=0;
    power_set(str, n,depth+1, len);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<string> tmp;
    
    for (auto order : orders)
    {
        sort(order.begin(), order.end());
        tmp.push_back(order);
    }
    
    for (int i = 0; i < orders.size(); i++)
        power_set(tmp[i], (int)tmp[i].length(), 0, 2);
    
    ordered.erase("");
    
    map<string, int>::iterator iter;
    
    for (int i = 0; i < course.size(); i++)
    {
        vector<pair<string, int>> vecs;
        vector<pair<string, int>> max;
        for (iter = ordered.begin(); iter != ordered.end(); iter++)
        {
            if (course[i] == iter->first.length() && iter->second > 1)
            {
                vecs.push_back(make_pair(iter->first, iter->second));
            }
        }
        if (!vecs.empty())
        {
            sort(vecs.begin(), vecs.end(), cmp);
            max.push_back(vecs[0]);
            for (auto vec : vecs)
            {
                cout << vec.first << " : " << vec.second << endl;
                if (max[0].second == vec.second)
                    answer.push_back(vec.first);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}