
    #include<bits/stdc++.h>
    using namespace std;
    stack < int > st;
    vector < pair<int,int> > a[50010];
    int n,u,v,t,wt;
    int dis[50010];
    int dfs(int s) {
        int curr;
        st.push(s);
        memset(dis,-1,sizeof(dis));
        dis[s] = 0;
        while(!st.empty()) {
            curr  = st.top();
            st.pop();
            //printf("%d  ",curr);
            for(vector < pair<int,int> > :: iterator it = a[curr].begin();it != a[curr].end();it++) {
                if(dis[it->first] == -1) {
                    st.push(it->first);
                    dis[it->first] = dis[curr] + it->second;
                }
            }
        }
        int maks = dis[s];
        int maks_node = s;
        for (int i = 1; i <= n; ++i) {
            if (dis[i] > maks) { maks = dis[i]; maks_node = i; }
        }
        return maks_node;
    }
    int main() {
        cin>>t;
        while(t--) {
        cin>>n;
        for(int i = 0;i < n-1;i++) {
            scanf("%d%d%d",&u,&v,&wt);
            a[u].push_back(make_pair(v,wt));
            a[v].push_back(make_pair(u,wt));
        }
       int ns = dfs(u);
       int ans = dfs(ns);
       printf("%d\n",dis[ans]);
       for(int i = 1;i <= n;i++)
        a[i].clear();
        }
    }
