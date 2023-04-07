function solution(players, callings) {
  var answer = [];

  let playerMap = new Map();
  let orderMap = new Map();
  for (let i = 0; i < players.length; ++i) {
    playerMap.set(players[i], i);
    orderMap.set(i, players[i]);
  }

  for (let calling of callings) {
    let callingIdx = playerMap.get(calling);
    let prev = orderMap.get(callingIdx - 1);
    let prevIdx = playerMap.get(prev);

    playerMap.set(calling, prevIdx);
    playerMap.set(prev, callingIdx);
    orderMap.set(callingIdx, prev);
    orderMap.set(prevIdx, calling);
  }
  for (let val of orderMap.values()) {
    answer.push(val);
  }
  return answer;
}
