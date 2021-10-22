#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <string.h>
#include <queue>
#include <map>

using namespace std;

int puzzle[3][3];

// down, up, right, left
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

// 123456789
// 100000000

int main(void) {
	int start = 0;
	int n = 100000000;

	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			int tmp;
			cin >> tmp;
			if (tmp == 0) tmp = 9;
			tmp *= n;
			start += tmp;
			n /= 10;
		}
	}

	queue<int> q;
	q.push(start);
	map<int, int> d;
	d[start] = 0;

	while (!q.empty()) {
		int cur_num = q.front(); q.pop();
		string cur = to_string(cur_num);
		int z = cur.find('9');
		int x = z % 3;
		int y = z / 3;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < 3 && 0 <= ny && ny < 3) {
				string next = cur;
				swap(next[y * 3 + x], next[ny * 3 + nx]);
				int num = stoi(next);
				if (d.count(num) == 0) {
					d[num] = d[cur_num] + 1;
					q.push(num);
				}
			}
		}
	}

	if (d.count(123456789)) {
		cout << d[123456789] << endl;
	}
	else {
		cout << -1 << endl;
	}

	return 0;
}