/* 문제 설명
 정수 배열 numbers가 주어집니다. numbers에서 서로 다른 인덱스에 있는 두 개의 수를 뽑아 더해서 만들 수 있는 모든 수를 배열에 오름차순으로 담아 return 하도록 solution 함수를 완성해주세요.
 제한사항
numbers의 길이는 2 이상 100 이하입니다.
numbers의 모든 수는 0 이상 100 이하입니다.
입출력 예
numbers	result
[2,1,3,4,1]	[2,3,4,5,6,7]
[5,0,2,7]	[2,5,7,9,12]
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> check;
vector<int> answer;
void process(int i, int sum, int cnt, vector<int> numbers){
    if (cnt == 2){
        auto itr = find(answer.begin(), answer.end(), sum);
        if (itr == answer.end())
            answer.push_back(sum);
        return ;
    }

    for (int j = i; j < check.size(); j++){
        if (!check[j]){
            check[j] = true;
            process(j, sum + numbers[j], cnt + 1, numbers);
            check[j] = false;
        }
    }
}
vector<int> solution(vector<int> numbers) {
    check.assign(numbers.size(), false);
    sort(answer.begin(), answer.end());
    return answer;
}
