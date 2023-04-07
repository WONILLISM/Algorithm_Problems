function solution(park, routes) {
  var answer = [];
  const n = park.length;
  const m = park[0].length;

  const dy = { N: -1, E: 0, S: 1, W: 0 };
  const dx = { N: 0, E: 1, S: 0, W: -1 };

  let y = park.findIndex((y) => y.includes("S"));
  let x = park[y].split("").findIndex((x) => x === "S");

  for (let route of routes) {
    const [dir, len] = route.split(" ");
    let nlen = Number(len);

    let cy = y;
    let cx = x;
    let ny;
    let nx;
    while (nlen--) {
      (ny = y + dy[dir]), (nx = x + dx[dir]);

      if (ny >= 0 && ny < n && nx >= 0 && nx < m && park[ny][nx] !== "X") {
        (y = ny), (x = nx);
      } else {
        (y = cy), (x = cx);
        break;
      }
    }
  }
  answer = [y, x];

  return answer;
}
