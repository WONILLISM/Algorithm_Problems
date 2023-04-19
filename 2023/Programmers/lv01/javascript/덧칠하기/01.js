function solution(n, m, section) {
  var answer = 0;

  let chk = 0;

  for (let s of section) {
    if (chk < s) {
      answer++;
      chk = s + m - 1;
    }
  }

  return answer;
}
