#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int cnt[32001];
	vector<int> a[32001];
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		a[x].push_back(y);
		cnt[y]++;
	}
	priority_queue<int> q;
	for(int i=1;i<=n;i++){
		if(cnt[i]==0){
			q.push(-i);
		}
	}
	while(!q.empty()){
		int x = -q.top();
		q.pop();
		cout<<x<<endl;
		for(int i=0;i<a[x].size();i++){
			int y = a[x][i];
			cnt[y]--;
			if(cnt[y]==0)q.push(-y);		
		}		
	}	
	return 0;
}
