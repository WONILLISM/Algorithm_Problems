#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int time_to_sec(const string time) {
	int h = stoi(time.substr(0, 2));
	int m = stoi(time.substr(3, 2));
	int s = stoi(time.substr(6, 2));
	int ms = stoi(time.substr(9, 3));

	m += h * 60;
	s += m * 60;
	ms += s * 1000;

	return ms;
}

int duration_to_sec(string duration) {
	duration.erase(duration.end() - 1);
	float time = stof(duration);
	int sec = time * 1000;
	return sec;
}

int solution(vector<string> lines) {
	int answer = 0;
	vector<pair<int, int>> records;

	for (string line : lines) {		
		vector<string> res;
		string tmp = "";
		for (int i = 0; i <= line.size(); i++){
			if (line[i] == ' ' || !line[i]){
				res.push_back(tmp);
				tmp = "";
			}
			else tmp +=line[i];
		}

		int end_time = time_to_sec(res[1]);
		int begin_time = end_time - duration_to_sec(res[2]) + 1;
		records.push_back(make_pair(begin_time, end_time));
	}

	for (int i = 0; i < records.size(); i++) {
		int cnt = 1;
		int endTime = records[i].second;

		for (int j = i + 1; j < records.size(); j++) {
			if (records[j].first < endTime + 1000) {
				cnt++;
			}
		}
		answer = max(cnt, answer);
	}

	return answer;
}

int main(){
	// vector<string> lines = {
	// 	"2016-09-15 20:59:57.421 0.351s", 
	// 	"2016-09-15 20:59:58.233 1.181s", 
	// 	"2016-09-15 20:59:58.299 0.8s", 
	// 	"2016-09-15 20:59:58.688 1.041s", 
	// 	"2016-09-15 20:59:59.591 1.412s", 
	// 	"2016-09-15 21:00:00.464 1.466s", 
	// 	"2016-09-15 21:00:00.741 1.581s", 
	// 	"2016-09-15 21:00:00.748 2.31s", 
	// 	"2016-09-15 21:00:00.966 0.381s", 
	// 	"2016-09-15 21:00:02.066 2.62s"
	// };
	// vector<string> lines = {"2016-09-15 00:00:00.000 2.3s", "2016-09-15 23:59:59.999 0.1s"};
	vector<string> lines = {"2016-09-15 01:00:04.001 2.0s", "2016-09-15 01:00:07.000 2s"};
	cout<<solution(lines)<<endl;
	return 0;
}