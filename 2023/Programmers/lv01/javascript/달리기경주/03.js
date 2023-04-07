function solution(players, callings) {
  var answer = [];

  let pMap = new Map();
  for (let i = 0; i < players.length; ++i) {
    pMap.set(players[i], i);
  }
  for (let calling of callings) {
    const idx = pMap.get(calling);
    const prev = players[idx - 1];

    pMap.set(calling, idx - 1);
    pMap.set(prev, idx);
    players[idx] = prev;
    players[idx - 1] = calling;
  }
  answer = players;

  return answer;
}
