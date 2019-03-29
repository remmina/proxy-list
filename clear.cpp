#include <bits/stdc++.h>

#define NS (10000005)

using namespace std;

ifstream fin;

ofstream fout;

int cnt, tot, n, ed[NS], sz = 1;

char s[NS];

map<char, int> nxt[NS];

string res[NS];

void insert()
{
	int a = 1;
	n = strlen(s), reverse(s, s + n);
	for (int i = 0; i < n; i += 1)
	{
		if (!nxt[a][s[i]]) nxt[a][s[i]] = ++sz;
		a = nxt[a][s[i]];
		if (ed[a]) return;
	}
	ed[a] = 1;
}

void dfs(int a)
{
	if (ed[a])
	{
		for (int i = n - 1; i >= 0; i -= 1) res[tot] += s[i];
		tot++;
		return;
	}
	for (map<char, int>::iterator i = nxt[a].begin(); i != nxt[a].end(); i++)
		s[n++] = i->first, dfs(i->second), n--;
}

int main(int argc, char const* argv[])
{
	if (argc != 2) puts("Wrong arg!"), exit(0);
	fin.open(argv[1]);
	while (fin >> s) insert(), cnt++;
	printf("%d lines in total.\n", cnt);
	fin.close(), fout.open(argv[1]);
	n = 0, dfs(1), sort(res, res + tot);
	for (int i = 0; i < tot; i += 1) fout << res[i] << endl;
	fout.close();
	printf("%d lines in total after removing duplication.\n", tot);
	return 0;
}