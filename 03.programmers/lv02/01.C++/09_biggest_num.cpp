#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(const string &a, const string &b) { return a + b > b + a; }
string solution(vector<int> numbers)
{
    string answer = "";
    vector<string> strArr;
    for (int i = 0; i < numbers.size(); i++)
        strArr.push_back(to_string(numbers.at(i)));

    sort(strArr.begin(), strArr.end(), compare);

    for (string str : strArr)
        answer += str;

    if (answer[0] == '0')
        return "0";
    return answer;
}
int main()
{
    vector<int> numbers = {3, 30, 34, 5, 9};
    cout << solution(numbers) << endl; 
    return 0;
}