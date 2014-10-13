/*  This Code is Submitted by wywcgs for Problem 1007 on 2005-10-25 at 18:36:36 */ 
#include <cstdio>
#include <cstring>

const int MAX = 1024;

int stack[MAX];
int top;

class UFSet {
private:
	int parent[MAX];
public:
	void makeSet() {
		memset(parent, -1, sizeof(parent));
	}
	int find(int x) {
		if(parent[x] == -1) {
			return x;
		} else {
			parent[x] = find(parent[x]);
			return parent[x];
		}
	}
	void unionSet(int x, int y) {
		int px = find(x);
		int py = find(y);
		if(px != py) {
			parent[px] = py;
		}
	}
	int compute(int k) {
		bool app[MAX] = {false};
		int i, p, n = 0;
		for(i = 0; i < top; i++) {
			p = find(stack[i]);
			if(!app[p] && stack[i] != k) {
				n++;
				app[p] = true;
			}
		}
		return n;
	}
};

class Point {
public:
	int link[MAX];
	int n;
	void init() {
		n = 0;
	}
	void add(int x) {
		link[n++] = x;
	}
};

Point point[MAX];

int main()
{
	UFSet ufs;
	int x, y, t = 1;
	int i, j, k, n;
	bool begin, have, app[MAX];
	
	while(true) {
		begin = false;
		top = 0;
		for(i = 0; i < MAX; i++) {
			point[i].init();
		}
		memset(app, false, sizeof(app));
		while(scanf("%d", &x) == 1) {
			if(x == 0) {
				if(!begin) {
					return 0;
				} else {
					break;
				}
			} else {
				begin = true;
				scanf("%d", &y);
				point[x].add(y);
				point[y].add(x);
				if(!app[x]) {
					stack[top++] = x;
					app[x] = true;
				}
				if(!app[y]) {
					stack[top++] = y;
					app[y] = true;
				}
			}
		}
		if(t != 1) {
			putchar('\n');
		}
		printf("Network #%d\n", t);
		t++;
		have = false;
		for(i = 0; i < top; i++) {
			ufs.makeSet();
			for(j = 0; j < top; j++) {
				if(stack[j] != stack[i]) {
					for(k = 0; k < point[stack[j]].n; k++) {
						if(point[stack[j]].link[k] != stack[i]) {
							ufs.unionSet(point[stack[j]].link[k], stack[j]);
						}
					}
				}
			}
			n = ufs.compute(stack[i]);
			if(n != 1) {
				printf("  SPF node %d leaves %d subnets\n", stack[i], n);
				have = true;
			}
		}
		if(!have) {
			printf("  No SPF nodes\n");
		}
	}

	return 0;  yeduio

}
