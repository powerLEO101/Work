#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

const int MAXN = 200;
const int MAXL = 1e6;

int n, tot;
int w[MAXL | 1];
char str[MAXL + 2];
std::vector < int > e[MAXL | 1];

namespace AC_automaton {
	struct Node {
		int cnt, id;
		Node *ch[26], *fail;
		Node() {
			cnt = 0;
			id = ++tot;
			memset(ch, 0, sizeof(ch));
			fail = NULL;
		}
	} *root, *a[MAXN | 1], *q[MAXL | 1];
	Node *insert(char *a) {
		if(root == NULL) root = new Node;
		Node *o = root;
		int len = strlen(a + 1);
		for(int i = 1; i <= len; ++i) {
			int idx = a[i] - 'a';
			if(o -> ch[idx] == NULL) o -> ch[idx] = new Node;
			o = o -> ch[idx];
			++(o -> cnt);
		}
		return o;
	}
	void build() {
		int head = 1, tail = 0;
		for(int i = 0; i < 26; ++i) {
			if(root -> ch[i] == NULL) root -> ch[i] = root;
			else {
				root -> ch[i] -> fail = root;
				q[++tail] = root -> ch[i];
				e[root -> id].push_back(root -> ch[i] -> id);
				w[root -> ch[i] -> id] = root -> ch[i] -> cnt;
			}
		}
		while(head <= tail) {
			Node *now = q[head++];
			for(int i = 0; i < 26; ++i) {
				if(now -> ch[i] == NULL) now -> ch[i] = now -> fail -> ch[i];
				else {
					now -> ch[i] -> fail = now -> fail -> ch[i];
					q[++tail] = now -> ch[i];
					e[now -> ch[i] -> fail -> id].push_back(now -> ch[i] -> id);
					w[now -> ch[i] -> id] = now -> ch[i] -> cnt;
				}
			}
		}
	}
	void dfs(int x) {
		for(std::vector < int >::iterator it = e[x].begin(); it != e[x].end(); ++it) {
			int to = *it;
			dfs(to);
			w[x] += w[to];
		}
	}
}

using namespace AC_automaton;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%s", str + 1);
		a[i] = insert(str);
	}
	build();
	dfs(1);
	for(int i = 1; i <= n; ++i) {
		printf("%d\n", w[a[i] -> id]);
	}
	return 0;
}

