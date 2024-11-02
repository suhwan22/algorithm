# BFS(Breadth First Search) 너비 우선 탐색

| solved | 난이도 | 문제 번호 | 문제 제목 |
| :--: | :--: | :--: | :--: |
| ✔ | <img src="https://static.solved.ac/tier_small/11.svg" alt="G5" class="css-1vnxcg0" width=20 height=20 align=center > | 10026 | [적록색약](https://www.acmicpc.net/problem/10026) 
| ✔ | <img src="https://static.solved.ac/tier_small/9.svg" alt="S2" class="css-1vnxcg0" width=20 height=20 align=center > | 1012 | [유기농 배추](https://www.acmicpc.net/problem/1012) |
| ✔ | <img src="https://static.solved.ac/tier_small/14.svg" alt="G2" class="css-1vnxcg0" width=20 height=20 align=center > | 11967 | [불켜기](https://www.acmicpc.net/problem/11967) |
| ✔ | <img src="https://static.solved.ac/tier_small/12.svg" alt="G4" class="css-1vnxcg0" width=20 height=20 align=center > | 12851 | [숨바꼭질](https://www.acmicpc.net/problem/12851) |
| ✔ | <img src="https://static.solved.ac/tier_small/11.svg" alt="G5" class="css-1vnxcg0" width=20 height=20 align=center > | 13549 | [숨바꼭질 3](https://www.acmicpc.net/problem/13549) |
| ✔ | <img src="https://static.solved.ac/tier_small/12.svg" alt="G4" class="css-1vnxcg0" width=20 height=20 align=center > | 13913 | [숨바꼭질 4](https://www.acmicpc.net/problem/13913) |
| ✔ | <img src="https://static.solved.ac/tier_small/13.svg" alt="G3" class="css-1vnxcg0" width=20 height=20 align=center > | 14442 | [벽 부수고 이동하기 2](https://www.acmicpc.net/problem/14442) |
| ✔ | <img src="https://static.solved.ac/tier_small/13.svg" alt="G3" class="css-1vnxcg0" width=20 height=20 align=center > | 1600 | [말이 되고픈 원숭이](https://www.acmicpc.net/problem/1600) |
| ✔ | <img src="https://static.solved.ac/tier_small/14.svg" alt="G2" class="css-1vnxcg0" width=20 height=20 align=center > | 16920 | [확장 게임](https://www.acmicpc.net/problem/16920) |
| ✔ | <img src="https://static.solved.ac/tier_small/15.svg" alt="G1" class="css-1vnxcg0" width=20 height=20 align=center > | 16933 | [벽 부수고 이동하기 3](https://www.acmicpc.net/problem/16933) |
| ✔ | <img src="https://static.solved.ac/tier_small/9.svg" alt="S2" class="css-1vnxcg0" width=20 height=20 align=center > | 16953 | [A → B](https://www.acmicpc.net/problem/16953) |
| ✔ | <img src="https://static.solved.ac/tier_small/10.svg" alt="S1" class="css-1vnxcg0" width=20 height=20 align=center > | 1697 | [숨바꼭질](https://www.acmicpc.net/problem/1697) |
| ✔ | <img src="https://static.solved.ac/tier_small/16.svg" alt="P5" class="css-1vnxcg0" width=20 height=20 align=center > | 17071 | [숨바꼭질 5](https://www.acmicpc.net/problem/17071) |
| ✔ | <img src="https://static.solved.ac/tier_small/10.svg" alt="S1" class="css-1vnxcg0" width=20 height=20 align=center > | 1926 | [그림](https://www.acmicpc.net/problem/1926) |
| ✔ | <img src="https://static.solved.ac/tier_small/16.svg" alt="P5" class="css-1vnxcg0" width=20 height=20 align=center > | 20304 | [비밀번호 제작](https://www.acmicpc.net/problem/20304) |
| ✔ | <img src="https://static.solved.ac/tier_small/13.svg" alt="G3" class="css-1vnxcg0" width=20 height=20 align=center > | 2146 | [다리 만들기](https://www.acmicpc.net/problem/2146) |
| ✔ | <img src="https://static.solved.ac/tier_small/10.svg" alt="S1" class="css-1vnxcg0" width=20 height=20 align=center > | 2178 | [미로 탐색](https://www.acmicpc.net/problem/2178) |
| ✔ | <img src="https://static.solved.ac/tier_small/13.svg" alt="G3" class="css-1vnxcg0" width=20 height=20 align=center > | 2206 | [벽 부수고 이동하기](https://www.acmicpc.net/problem/2206) |
| ✔ | <img src="https://static.solved.ac/tier_small/10.svg" alt="S1" class="css-1vnxcg0" width=20 height=20 align=center > | 2468 | [안전 영역](https://www.acmicpc.net/problem/2468) |
| ✔ | <img src="https://static.solved.ac/tier_small/12.svg" alt="G4" class="css-1vnxcg0" width=20 height=20 align=center > | 2573 | [빙산](https://www.acmicpc.net/problem/2573) |
| ✔ | <img src="https://static.solved.ac/tier_small/10.svg" alt="S1" class="css-1vnxcg0" width=20 height=20 align=center > | 2583 | [영역 구하기](https://www.acmicpc.net/problem/2583) |
| ✔ | <img src="https://static.solved.ac/tier_small/10.svg" alt="S1" class="css-1vnxcg0" width=20 height=20 align=center > | 2667 | [단지번호붙이기](https://www.acmicpc.net/problem/2667) |
| ✔ | <img src="https://static.solved.ac/tier_small/16.svg" alt="P5" class="css-1vnxcg0" width=20 height=20 align=center > | 3197 | [백조의 호수](https://www.acmicpc.net/problem/3197) |
| ✔ | <img src="https://static.solved.ac/tier_small/13.svg" alt="G3" class="css-1vnxcg0" width=20 height=20 align=center > | 4179 | [불!](https://www.acmicpc.net/problem/4179) |
| ✔ | <img src="https://static.solved.ac/tier_small/10.svg" alt="S1" class="css-1vnxcg0" width=20 height=20 align=center > | 5014 | [스타트링크](https://www.acmicpc.net/problem/5014) |
| ✔ | <img src="https://static.solved.ac/tier_small/12.svg" alt="G4" class="css-1vnxcg0" width=20 height=20 align=center > | 5427 | [불](https://www.acmicpc.net/problem/5427) |
| ✔ | <img src="https://static.solved.ac/tier_small/11.svg" alt="G5" class="css-1vnxcg0" width=20 height=20 align=center > | 6593 | [상범 빌딩](https://www.acmicpc.net/problem/6593) |
| ✔ | <img src="https://static.solved.ac/tier_small/10.svg" alt="S1" class="css-1vnxcg0" width=20 height=20 align=center > | 7562 | [나이트의 이동](https://www.acmicpc.net/problem/7562) |
| ✔ | <img src="https://static.solved.ac/tier_small/11.svg" alt="G5" class="css-1vnxcg0" width=20 height=20 align=center > | 7569 | [토마토](https://www.acmicpc.net/problem/7569) |
| ✔ | <img src="https://static.solved.ac/tier_small/11.svg" alt="G5" class="css-1vnxcg0" width=20 height=20 align=center > | 7576 | [토마토](https://www.acmicpc.net/problem/7576) |
| ✔ | <img src="https://static.solved.ac/tier_small/15.svg" alt="G1" class="css-1vnxcg0" width=20 height=20 align=center > | 9328 | [열쇠](https://www.acmicpc.net/problem/9328) |
| ✔ | <img src="https://static.solved.ac/tier_small/13.svg" alt="G3" class="css-1vnxcg0" width=20 height=20 align=center > | 9466 | [텀 프로젝트](https://www.acmicpc.net/problem/9466) |

[문제집 링크](https://www.acmicpc.net/workbook/view/7313)
