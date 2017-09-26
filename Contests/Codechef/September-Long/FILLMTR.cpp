            #include <bits/stdc++.h>
            using namespace std;
            int t,n,q,x,y,w,parent[100001],vis[100001],flag,num;
            vector <int> adj[100001];
            vector <int> zero[100001],nodes;
            map <pair <int,int> ,int > mark;
            vector <pair <int,int> > edge1;
            void dfs(int x) {
             
                vis[x] = num;
                for(vector <int> :: iterator it = zero[x].begin(); it != zero[x].end();it++) {
                    int i = *it;
                    if(!vis[i]) {
                        dfs(i);
                    }
                }
            }
            void findcycle(int x) {
                for(vector <int> :: iterator it = adj[x].begin(); it != adj[x].end();it++) {
                    int i = *it;
                    if(vis[i] == -1) {
                        parent[i] = x;
                        vis[i]  = 1 + vis[x];
                        findcycle(i);
                    }
                    else if (parent[x] != i) {
                        if((vis[x] - vis[i] + 1) %2 != 0)
                            flag = 0;
                    }
                }
            }
            int main() {
             
                cin>>t;
                while(t--) {
                    cin>>n>>q;
                    flag = 1;
                    for(int i = 1;i <= n;i++) {
                        adj[i].clear();
                        zero[i].clear();
                        parent[i] = -1;
                        vis[i] = 0;
                    }
                    mark.clear(),nodes.clear();
                    edge1.clear();
                    for(int i = 0;i < q;i++) {
                        scanf("%d%d%d",&x,&y,&w);
                        if(w == 0) {
                            zero[x].push_back(y);
                            zero[y].push_back(x);
                        }
                        else {
                            edge1.push_back(make_pair(x,y));
                        }
                    }
                    for(int i  = 1;i <= n;i++) {
                        if(!vis[i]) {
                            num = i;
                            dfs(i);
                        }
                    }
                    for(int i = 0;i < edge1.size();i++) {
                        int v = edge1[i].first,u = edge1[i].second;
                        if(vis[v])
                            v = vis[v];
                        if(vis[u])
                            u = vis[u];
                        if(!mark[make_pair(u,v)] && !mark[make_pair(v,u)]) {
                            if(u != v) {
                                mark[make_pair(u,v)] = 1;
                                mark[make_pair(v,u)] = 1;
                                adj[v].push_back(u);
                                adj[u].push_back(v);
                                nodes.push_back(u);
                                nodes.push_back(v);
                            }
                            else {
                                flag = 0;
                                break;
                            }
                        }
                    }
                    for(int i = 1;i <= n;i++) {
                        vis[i] = -1;
                    }
                    for(int i = 0;i < nodes.size();i++) {
                        int v = nodes[i];
                        if(vis[v] == -1) {
                            vis[v] = 0;
                            findcycle(v);
                        }
                        if(!flag)   
                            break;
                    }
                    if(flag)
                        printf("yes\n");
                    else
                        printf("no\n");
                }
            }  