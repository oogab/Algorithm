#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

int dist[10000];
int from[10000];
char how[10000];
bool check[10000];

char h[4] = { 'D', 'S', 'L', 'R' };

int howD(int num) {
	int tmp = num * 2;
	if (tmp > 9999) {
		tmp = tmp % 10000;
	}
	return tmp;
}

int howS(int num) {
	int tmp = num - 1;
	if (tmp < 0) {
		tmp = 9999;
	}
	return tmp;
}

int howL(int num) {
	int tmp = (num % 1000) * 10 + num / 1000;
	return tmp;
}

int howR(int num) {
	int tmp = (num % 10) * 1000 + num / 10;
	return tmp;
}

void bfs(int s, int e) {
	queue<int> q;
	
	dist[s] = 0;
	from[s] = -1;
	how[s] = '\0';

	q.push(s);
	check[s] = true;
	while (!q.empty()) {
		//printf("bfs\n");
		int cur = q.front(); q.pop();
		/*if (cur == e) {
			break;
		}*/
		for (int i = 0; i < 4; i++) {
			char dh = h[i];
			int next;
			if (dh == 'D') {
				next = howD(cur);
				if (check[next] == false) {
					dist[next] = dist[cur] + 1;
					from[next] = cur;
					how[next] = 'D';
					check[next] = true;
					q.push(next);
				}
			}
			else if (dh == 'S') {
				next = howS(cur);
				if (check[next] == false) {
					dist[next] = dist[cur] + 1;
					from[next] = cur;
					how[next] = 'S';
					check[next] = true;
					q.push(next);
				}
			}
			else if (dh == 'L') {
				next = howL(cur);
				if (check[next] == false) {
					dist[next] = dist[cur] + 1;
					from[next] = cur;
					how[next] = 'L';
					check[next] = true;
					q.push(next);
				}
			}
			else {
				next = howR(cur);
				if (check[next] == false) {
					dist[next] = dist[cur] + 1;
					from[next] = cur;
					how[next] = 'R';
					check[next] = true;
					q.push(next);
				}
			}
		}
	}
	
	return;
}

int main(void) {
	vector<char> answer;

	int N;
	scanf("%d", &N);

	while (N--) {
		int start, end;
		scanf("%d %d", &start, &end);
		
		memset(dist, -1, sizeof(dist));
		memset(from, -1, sizeof(from));
		memset(how, '\0', sizeof(how));
		memset(check, false, sizeof(check));
		answer.clear();

		bfs(start, end);

		/*string ans = "";
		while (end != start) {
			ans += how[end];
			end = from[end];
		}
		reverse(ans.begin(), ans.end());
		cout << ans << endl;*/
		answer.push_back(how[end]);
		int cnt = dist[end] - 1;
		int prev = from[end];

		while (cnt--) {
			answer.push_back(how[prev]);
			prev = from[prev];
		}
		reverse(answer.begin(), answer.end());

		for (int i = 0; i < answer.size(); i++) {
			printf("%c", answer[i]);
		}
		puts("\n");
		/*answer.push_back(how[end]);
		int cnt = dist[end]-1;
		int prev = from[end];
		while (prev != start) {
			// 아.. 처음에 여기서 실수..
			answer.push_back(how[from[prev]]);
			prev = from[prev];
		}
		reverse(answer.begin(), answer.end());*/

		/*for (int i = 0; i < answer.size(); i++) {
			printf("%c", answer[i]);
		}*/

		//puts("\n");
	}

	// 최적화 시켜 보자

	return 0;
}