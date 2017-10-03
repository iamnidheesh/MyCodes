#include<bits/stdc++.h>
using namespace std;
int m,n,t,s1,s2,d1,d2;
#define INF 10000000
char a[210][210];
int dis[210][210];
int wait[210][210];
vector <pair < int,pair<int,int> > > v[30][30];
bool check(int x,int y) {
	if(x >= 0 && x < m && y >= 0 && y < n )
		return true;
	else
		return false;
}
void moddij(pair <int,int> s, pair <int,int> d) {
    priority_queue < pair<int,pair <int,int> > , vector < pair<int,pair <int,int> > >,greater < pair<int,pair <int,int> > > > pq;
    int x[4] = {1,-1,0,0};
    int y[4] = {0,0,-1,1};
    dis[s.first][s.second] = 0;
    pq.push(make_pair(0,s));
    while(!pq.empty()) {
    	
    	pair <int,int> u = (pq.top()).second;
    	pq.pop();	
    	if(u == d)
    		break;
    	for(int i = 0;i < 4;i++) {
    		pair <int,int> v = make_pair(u.first + x[i],u.second + y[i]);
    		if(check(v.first,v.second)) {
    			int timeToPass;
    			if(dis[u.first][u.second] + 1 >= wait[v.first][v.second]  )
	    			timeToPass = dis[u.first][u.second] + 1;
    			else
    				timeToPass = wait[v.first][v.second];
	    		if(timeToPass < dis[v.first][v.second]) {
	    			pq.push(make_pair(timeToPass,v));
	    			dis[v.first][v.second] = timeToPass;
	    		} 
	    	}
    	}
    }
}
int main() {

	cin>>t;
	while(t--) {
		cin>>m>>n;
		for(int i = 0;i < m;i++)
			scanf("%s",a[i]);
		for(int i = 0;i < m;i++)
			for(int j = 0;j < n;j++) {
				cin>>wait[i][j];
				dis[i][j] = INF;
			}
		cin>>s1>>s2>>d1>>d2;
		moddij(make_pair(s1,s2),make_pair(d1,d2));
		printf("%d\n",dis[d1][d2]);
	}
}