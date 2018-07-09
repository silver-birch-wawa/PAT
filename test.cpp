#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
#include<string.h>
#include <bits/stdc++.h>
using namespace std;

const int Max = 510;
vector<int> t[Max];
int indegree[Max];
 int main()
{
	priority_queue<int, vector<int>, greater<int> > q;
	vector<int> fin;
	int n, m, g, l;
	while(cin >> n >> m)
	{
		memset(indegree, 0, sizeof(indegree));

		for(int i=0; i<m; i++)
		{
			scanf("%d%d", &g, &l);
			if(find(t[g].begin(), t[g].end(), l) == t[g].end())
                        //ÅÐ¶ÏÖØ±ß
			{
				t[g].push_back(l);
				indegree[l] ++;
			}
		}

		for(int i=1; i<=n; i++)
			if(!indegree[i]) q.push(i);

		while(!q.empty())
		{
			int cur = q.top();
			q.pop();
			fin.push_back(cur);
			for(int i=0; i<t[cur].size(); i++)
			{
				int adj = t[cur][i];
				indegree[adj] --;
				if(!indegree[adj]) q.push(adj);
			}
		}

		for(int i=0; i<n; i++)
			if(i < n-1) printf("%d ", fin[i]);
			else printf("%d\n", fin[i]);

		while(!q.empty()) q.pop();
		fin.clear();
		for(int i=0; i<Max; i++) t[i].clear();
	}
	system("pause");
	return 0;
}
