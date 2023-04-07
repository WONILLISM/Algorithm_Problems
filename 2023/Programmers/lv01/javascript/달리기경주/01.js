function solution(players, callings) {
  var answer = [];

  for (let calling of callings) {
    let i = 0;
    while (calling !== players[i]) {
      ++i;
    }

    if (i > 0) {
      let tmp = players[i];
      players[i] = players[i - 1];
      players[i - 1] = tmp;
    }
  }
  answer = players;

  return answer;
}
