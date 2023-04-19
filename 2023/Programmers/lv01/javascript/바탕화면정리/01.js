function solution(wallpaper) {
  var answer = [];
  // 행 길이
  const n = wallpaper.length;
  // 열 길이
  const m = wallpaper[0].length;

  // 시작점
  let sy = n,
    sx = m;
  // 끝점
  let ey = 0,
    ex = 0;

  // 바탕화면 탐색
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      // 시작점을 찾기위한 정방향 탐색
      if (wallpaper[i][j] === "#") {
        if (sy > i) {
          sy = i;
        }
        if (sx > j) {
          sx = j;
        }
      }
      // 끝점을 찾기위한 역방향 탐색
      if (wallpaper[n - i - 1][m - j - 1] === "#") {
        if (ey <= n - i) {
          ey = n - i;
        }
        if (ex <= m - j) {
          ex = m - j;
        }
      }
    }
  }
  answer = [sy, sx, ey, ex];

  return answer;
}
