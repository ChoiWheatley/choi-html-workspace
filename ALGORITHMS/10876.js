/*
입력
첫 번째 줄에 테스트 케이스의 수 T (1 ≤ T ≤ 10^5)가 주어진다. 
이후 T 개의 테스트 케이스가 주어진다.

각 테스트 케이스는 한 줄로 구성되며, 
이 줄에는 A와 B (1 ≤ A ≤ B ≤ 10^18)가 공백을 사이로 두고 입력된다. 
이는 지학이가 A 이상 B 이하의 자연수들로 구성된 사전을 만들었음을 의미한다.

출력
각 테스트 케이스에 대해, 
수찬이가 읽어야 할 최소 페이지 수를 한 줄에 하나씩 출력한다.

예제 입력 1 
3
1 11
5 13
3 5
예제 출력 1 
4
5
3

힌트
각 테스트 케이스마다 사전을 앞에서부터 
차례로 읽어나가면 아래와 같다.
#1: 1, 10, 11, 2, 3, 4, 5, 6, 7, 8, 9
#2: 10, 11, 12, 13, 5, 6, 7, 8, 9
#3: 3, 4, 5
*/

let input = [];
let r = require("readline");
let rl = r.createInterface({
  input: process.stdin,
  output: process.stdout,
});
r.on("line", function (line) {
  if (line === "exit") {
    r.close();
  }
  input.push(line);
});
r.on("close", function () {});
