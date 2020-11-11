#include <bits/stdc++.h>
using namespace std;
 
int n, m, max_t;
int ans = 0;
vector<int> beauty, u, v, t;
vector<pair<int, int>> adj[10000];
bool vis[10000];
void dfs(int s, int t, int ct)
{
    if(t > max_t)
        return;

    if(s ==0 )
    {
        ans = max(ans, ct);
    }
    for(int i=0;i<adj[s].size();i++)
    {
        int x = adj[s][i].first;
        int d = adj[s][i].second;

        if(vis[x])
            dfs(x, t + d, ct);
        else{
            vis[x] = true;
            dfs(x, t+d, ct + beauty[x]);
            vis[x] = false;
        }
    }
}

void solve()
{
    for(int i=0;i<m;i++)
    {
        adj[u[i]].push_back({v[i], t[i]});

        adj[v[i]].push_back({u[i], t[i]});
    }
    vis[0] = true;

    dfs(0, 0, beauty[0]);
}

int main()
{
    cin>>n>>m>>max_t;
    beauty.resize(n);
    u.resize(m);
    v.resize(m);
    t.resize(m);
    int temp1;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>beauty[i];
    cin>>m;
    for(int i=0;i<m;i++)
        cin>>u[i];
    cin>>m;
    for(int i=0;i<m;i++)
        cin>>v[i];
    cin>>m;
    for(int i=0;i<m;i++)
        cin>>t[i];

    solve();
    cout<<ans<<endl;
    cin.get();
}


