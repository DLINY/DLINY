/*  This Code is Submitted by wywcgs for Problem 1005 on 2006-07-02 at 20:42:23 */ 
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 256;
const int K = 32;
const int INF = 1 << 20;

int main()
{
	int d[N], n, k;
	int cost[N][N], total[N][K];
	int i, j, l, t;
	
	for(t = 1; scanf("%d %d", &n, &k) != EOF && n != 0; t++) {
		for(i = 0; i < n; i++) scanf("%d", &d[i]);
		memset(cost[0], 0, sizeof(cost));
		for(i = 0; i < n; i++)
			for(j = 0; j <= i; j++)
				for(l = j; l <= i; l++)
					cost[j][i] += abs(d[(j+i)>>1]-d[l]);
		for(i = 1; i < n; i++) total[i][1] = cost[0][i];
		for(i = 2; i <= k; i++)
			for(j = 1; j < n; j++) {
				total[j][i] = INF;
				for(l = 0; l < j; l++)
					total[j][i] = min(total[j][i], total[l][i-1]+cost[l+1][j]);
			}
		printf("Chain %d\nTotal distance sum = %d\n\n", t, total[n-1][k]);
	}
	
	return 0; woowo
}
