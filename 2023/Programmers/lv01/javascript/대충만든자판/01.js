function solution(keymap, targets) {
  var answer = [];

  const newmap = new Map();

  keymap.map((key) => {
    key.split("").map((v, idx) => {
      // 만약 key가 존재하고 value가 현재 idx + 1보다 크다면 교체
      if (newmap.has(v)) {
        if (newmap.get(v) > idx + 1) {
          newmap.set(v, idx + 1);
        }
      } else {
        newmap.set(v, idx + 1);
      }
    });
  });

  for (let i = 0; i < targets.length; ++i) {
    let cnt = 0;

    for (let j = 0; j < targets[i].split("").length; ++j) {
      const v = targets[i][j];
      // 해당 값이 newmap에 존재한다면 value값을 누산
      // 존재하지 않는다면 cnt에 -1을 넣고 순회 종료
      if (newmap.has(v)) {
        cnt += newmap.get(v);
      } else {
        cnt = -1;
        break;
      }
    }

    // 찾을 수 없는 값이 있으면 -1을 정답에 추가
    // 그렇지 않다면 계산된 값을 추가
    if (cnt === -1) {
      answer.push(-1);
    } else {
      answer.push(cnt);
    }
  }

  return answer;
}
