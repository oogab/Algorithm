#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
bool check[100001] = { false };
int d[100001] = { 0 };
int m[100001] = { 0 };

int main(void) {
	int start, end;
	cin >> start >> end;

	queue<int> q;

	q.push(start);
	check[start] = true;
	d[start] = 0;
	m[start] = 1;
	while (!q.empty()) {
		int subin = q.front(); q.pop();
		if (subin == end) {
			break;
		}

		int next = subin - 1;
		if (0 <= next && next <= 100000) {
			if (check[next] == false) {
				q.push(next);
				check[next] = true;
				d[next] = d[subin] + 1;
				m[next] = m[subin];
			}
			else if (d[next] == d[subin] + 1) {
				m[next] += m[subin];
			}
		}
		int next1 = subin + 1;
		if (0 <= next1 && next1 <= 100000) {
			if (check[next1] == false) {
				q.push(next1);
				check[next1] = true;
				d[next1] = d[subin] + 1;
				m[next1] = m[subin];
			}
			else if (d[next1] == d[subin] + 1) {
				m[next1] += m[subin];
			}
		}
		int next2 = subin * 2;
		if (0 <= next2 && next2 <= 100000) {
			if (check[next2] == false) {
				q.push(next2);
				check[next2] = true;
				d[next2] = d[subin] + 1;
				m[next2] = m[subin];
			}
			else if (d[next2] == d[subin] + 1) {
				m[next2] += m[subin];
			}
		}
	}

	cout << d[end] << endl;
	cout << m[end] << endl;

	return 0;
}