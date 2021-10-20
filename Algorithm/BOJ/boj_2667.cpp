//#define _CRT_SECURE_NO_WARNINGS
//
//#include <cstdio>
//#include <vector>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//int N;
//int map[25][25];
//bool check[25][25] = { false };
//
//// down, up, right, left
//int dx[4] = { 0, 0, 1, -1 };
//int dy[4] = { 1, -1, 0, 0 };
//
//int bfs(int row, int col) {
//	int cnt = 0;
//	queue<int> qr;
//	queue<int> qc;
//
//	qr.push(row);
//	qc.push(col);
//	check[row][col] = true;
//	cnt += 1;
//
//	while (!qr.empty()) {
//		int curR = qr.front();
//		int curC = qc.front();
//		qr.pop();
//		qc.pop();
//		for (int d = 0; d < 4; d++) {
//			int nextR = curR + dy[d];
//			int nextC = curC + dx[d];
//			if (0 <= nextR && nextR < N && 0 <= nextC && nextC < N) {
//				if (check[nextR][nextC]) continue;
//				if (map[nextR][nextC] == 1) {
//					qr.push(nextR);
//					qc.push(nextC);
//					cnt += 1;
//				}
//				check[nextR][nextC] = true;
//			}
//		}
//	}
//
//	return cnt;
//}
//
//
//int main(void) {
//	scanf("%d", &N);
//
//	vector<int> result;
//
//	for (int r = 0; r < N; r++) {
//		for (int c = 0; c < N; c++) {
//			int num;
//			scanf("%1d", &num);
//			map[r][c] = num;
//		}
//	}
//
//	for (int r = 0; r < N; r++) {
//		for (int c = 0; c < N; c++) {
//			if (map[r][c] == 1 && !check[r][c]) {
//				result.push_back(bfs(r, c));
//			}
//		}
//	}
//
//	sort(result.begin(), result.end());
//	printf("%d\n", result.size());
//	for (int i = 0; i < result.size(); i++) {
//		printf("%d\n", result[i]);
//	}
//
//	/*for (int r = 0; r < N; r++) {
//		for (int c = 0; c < N; c++) {
//			printf(check[r][c] ? "true" : "false");
//		}
//		printf("\n");
//	}*/
//
//	return 0;
//}