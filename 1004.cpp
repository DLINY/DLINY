/*  This Code is Submitted by wywcgs for Problem 1004 on 2006-07-23 at 02:01:30 */ 
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAX = 6400;
typedef long long int64;

int pp[MAX], ppn = 0;

void nextPal(int&, int, int);
bool Rabbin_Miller(int);
int gbc(int, int);
int modular_exp(int, int, int);

int main()
{
	int i, j, n, m;

	for(i = 1; i < 10; i++) {
		int p = (i + 1) / 2; n = 1;
		for(j = 1; j < p; j++) n *= 10;
		int u = n, l = 10 * u - 1;
		for(j = 0; n < l; j++) nextPal(n, u, i);
	}
	while(scanf("%d %d", &n, &m) != EOF) {
		int b = lower_bound(pp, pp+ppn, n) - pp;
		for(i = b; i < ppn && pp[i] <= m; i++) printf("%d\n", pp[i]);
	}
	
	return 0;
}

void nextPal(int& a, int u, int i)
{
	int p = (i + 1) / 2;
	int b = a, n[8], j, m = 0;
	
	for(j = 0; j < p; j++) n[j] = b % 10, b /= 10;
	if((n[p-1]&1) == 0 || (u != 1 && n[p-1] == 5)) a += u;
	else {
		a++;
		for(j = 0; j < p; j++) m = m*10+n[p-1-j];
		for(j = i&1; j < p; j++) m = m*10+n[j];
		if(Rabbin_Miller(m)) pp[ppn++] = m;
	}
}
bool Rabbin_Miller(int n)
{
	int i, a;
	if(n == 1 || n == 101101) return false;
	else if(n == 2) return true;
	srand(100);
	for(i = 0; i < 5; i++) {
		do {
			a = rand() % (n-1) + 2;
		} while(gbc(n, a) != 1);
		if(modular_exp(a, n-1, n) != 1) return false;
	}
	return true;
}
int gbc(int a, int b)
{
    if(a % b == 0) return b;
    else return gbc(b, a%b);
}
int modular_exp(int a, int b, int n)
{
	int64 d = 1;
	int bin[32], l, i;
	for(l = 0; b != 0; l++) bin[l] = b&1, b >>= 1;
	for(i = l-1; i >= 0; i--) {
		d = d * d % n;
		if(bin[i] == 1) d = d * a % n;
	}
	return d;//ABOUT
}
