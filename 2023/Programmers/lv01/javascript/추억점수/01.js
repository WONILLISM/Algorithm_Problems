function makeYearningMap(name, yearning) {
  let ret = new Map();

  for (let i = 0; i < name.length; ++i) {
    ret.set(name[i], yearning[i]);
  }
  return ret;
}

function cal(yearningMap, curPhoto) {
  let ret = 0;

  for (let i = 0; i < curPhoto.length; ++i) {
    const key = curPhoto[i];
    if (yearningMap.has(key)) {
      ret += yearningMap.get(key);
    }
  }
  return ret;
}

function solution(name, yearning, photo) {
  var answer = [];
  let yearningMap = makeYearningMap(name, yearning);

  for (let i = 0; i < photo.length; ++i) {
    const result = cal(yearningMap, photo[i]);
    answer.push(result);
  }

  return answer;
}
