function findStartPoint(park) {
  for (let y = 0; y < park.length; ++y) {
    for (let x = 0; x < park[y].length; ++x) {
      if (park[y][x] === "S") {
        return [y, x];
      }
    }
  }
}

function process(park, routes, S) {
  let cur = S.map((s) => Number(s));

  const n = park.length;
  const m = park[0].length;

  for (let i = 0; i < routes.length; ++i) {
    const route = routes[i].split(" ");
    const dir = route[0];
    const acc =
      dir === "N"
        ? [-1, 0]
        : dir === "E"
        ? [0, 1]
        : dir === "W"
        ? [0, -1]
        : [1, 0];

    let move = Number(route[1]);

    let cy = cur[0];
    let cx = cur[1];
    let ny = cy;
    let nx = cx;

    for (let j = 0; j < move; ++j) {
      ny += acc[0];
      nx += acc[1];

      if (ny >= 0 && ny < n && nx >= 0 && nx < m && park[ny][nx] !== "X") {
        cur = [ny, nx];
      } else {
        cur = [cy, cx];
        break;
      }
    }
  }
  return cur;
}

function solution(park, routes) {
  var answer = [];
  answer = process(park, routes, findStartPoint(park));
  return answer;
}
