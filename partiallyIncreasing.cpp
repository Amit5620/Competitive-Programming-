#include<bits/stdc++.h>
#define NN 200100

using namespace std;
using pii = pair <int, int>;
const int inf = 0x3f3f3f3f;

int A[NN], nxt[NN];
map <int, int> mp;

vector <int> vec[NN];
int B[NN], N, ans[NN];

void init(int n) {
	N = n;
	for(int i = 0; i <= N; i ++) B[i] = inf;
}
void update(int u, int x) {
	for(; u; u -= u & -u) B[u] = min(B[u], x);
}
int calc(int u, int ans = inf) {
	for(; u <= N; u += u & -u) ans = min(ans, B[u]);
	return ans;
}

vector <pii> query[NN];
int arr[NN];

int main() {
	int T; cin >> T;
	while(T --) {
		int n, q; scanf("%d %d", &n, &q);
		for(int i = 1; i <= n + 1; i ++) nxt[i] = -1;
		for(int i = 1; i <= n; i ++) {
			scanf("%d", A + i);
		}
		for(int i = n; i >= 1; i --) {
			int id = i + 1;
			while(id <= n && A[i] >= A[id]) {
				id = nxt[id];
			}
			nxt[i] = id;
		}
		mp.clear();
		for(int i = n; i >= 1; i --) {
			if(mp.count(A[i])) {
				nxt[i] = min(nxt[i], mp[A[i]]);
			}
			mp[A[i]] = i;
		}
		int nn = 0;
		for(int i = 1; i <= n; i ++) arr[++nn] = A[i];
		sort(arr + 1, arr + nn + 1);
		nn = unique(arr + 1, arr + nn + 1) - arr - 1;
		for(int i = 1; i <= n; i ++) A[i] = lower_bound(arr + 1, arr + nn + 1, A[i]) - arr;
		init(nn);
		for(int i = n; i >= 1; i --) {
			int pos = calc(A[i]);
			if(pos <= n) {
				vec[pos].push_back(i);
			}
			update(A[i], nxt[i]);
		}
		for(int i = 1; i <= q; i ++) {
			int L, R; scanf("%d %d", &L, &R);
			query[R].push_back(pii(L, i));
		}
		init(n);
		for(int i = 1; i <= n; i ++) {
			for(int u : vec[i]) update(u, i - u + 1);
			for(auto p : query[i]) {
				int L = p.first, id = p.second;
				ans[id] = calc(L);
				if(ans[id] == inf) ans[id] = -1;
				else {
					int x = ans[id] - 3;
					ans[id] = i - L + 1 - x;
				}
			}
		}
		for(int i = 1; i <= q; i ++) printf("%d\n", ans[i]);
		for(int i = 1; i <= n; i ++) {
			vec[i].clear();
			query[i].clear();
		}
	}
	
}
