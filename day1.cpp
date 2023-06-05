1) Dijkstra's Algo 
class Solution{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    typedef pair<int,int> pii;
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        vector<int>dis(v,1e9);
        dis[s]=0;
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        pq.push({0,s});//dis,src
        while(!pq.empty())
        {
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node])
            {
                int edwt=it[1];
                int adjNode=it[0];
                if(edwt+dist<dis[adjNode])
                {
                    dis[adjNode]=edwt+dist;
                    pq.push({dis[adjNode],adjNode});
                }
                
            }
        }
        return dis;
        
    }
};


2) //Kosarajus's Algo
void dfs(int i, stack<int>& st, vector<int>& vis, vector<vector<int>>& adj) {
    vis[i] = 1;
    for (auto it : adj[i]) {
        if (!vis[it])
            dfs(it, st, vis, adj);
    }
    st.push(i);
}

void dfs2(int i, vector<int>& vis, vector<vector<int>>& adjT) {
    vis[i] = 1;
    for (auto it : adjT[i]) {
        if (!vis[it])
            dfs2(it, vis, adjT);
    }
}

int kosaraju(int v, vector<vector<int>>& adj) {
    vector<int> vis(v, 0);
    stack<int> st;
    for (int i = 0; i < v; i++) {
        if (!vis[i])
            dfs(i, st, vis, adj);
    }
    vector<vector<int>> adjT(v);

    for (int i = 0; i < v; i++) {
        vis[i] = 0;
        for (auto it : adj[i]) {
            adjT[it].push_back(i);
        }
    }

    int scc = 0;

    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!vis[node]) {
            scc++;
            dfs2(node, vis, adjT);
        }
    }
    return scc;
};


3)// Bellman Ford
vector<int> bellman_ford(int v, vector<vector<int>>& edges, int s) {
        
        vector<int>dist(v,1e8);
        dist[s]=0;
        for(int i=0;i<v;i++)
        {
                for(auto it:edges)
            {
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                if(dist[u]!=1e8 && dist[u]+wt<dist[v])
                {
                    dist[v]=dist[u]+wt;
                }
            }
        }
        
        for(auto it:edges)
        {
            int u=it[0];
                int v=it[1];
                int wt=it[2];
                if(dist[u]!=1e8 && dist[u]+wt<dist[v])
                {
                    return {-1};
                }
        }
        return dist;
        
        
    }
};


4) Floyd Warshall
	void shortest_distance(vector<vector<int>>&mat){
	    int n=mat.size();
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(mat[i][j]==-1)
	            {
	                mat[i][j]=1e8;
	                
	            if(i==j)
	            mat[i][j]=0;
	            }
	        }
	    }
	    
	    for(int k=0;k<n;k++)
	    {
	        for(int i=0;i<n;i++)
	        {
	            for(int j=0;j<n;j++)
	            {
	                mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
	            }
	        }
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(mat[i][j]==1e8)
	            {
	                mat[i][j]=-1;
	                
	            }
	        }
	    }
	}
};

5) Prims Algo

	typedef pair<int,int>pii;
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        pq.push({0,0}); //weight,node
        vector<int>vis(V,0);
        int sum=0;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int wt=it.first;
            if(vis[node])
            continue;
            vis[node]=1;
            sum+=wt;
            for(auto it:adj[node])
            
            {
                int adjnode=it[0];
                int edw=it[1];
                if(!vis[adjnode])
                {
                    pq.push({edw,adjnode});
                }
                
            }
        }
        return sum;

        6)// Kruskal's Algo
        class DisjointSet{
    public:
    vector<int>rank,par;
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        par.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            par[i]=i;
        }
    }
    int findPar(int node)
    {
        if(par[node]==node)
        return node;
        return par[node]=findPar(par[node]);
    }
    void UnionbyRank(int u,int v)
    {
        int p1=findPar(u);
        int p2=findPar(v);
        if(p1==p2)
        return;
        if(rank[p1]>rank[p2])
        par[p2]=p1;
        else if(rank[p2]>rank[p1])
        par[p1]=p2;
        else
        {
            rank[p1]++;
            par[p2]=p1;
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < v; i++) {
            for (auto it : adj[i]) {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;

                edges.push_back({wt, {node, adjNode}});
            }
        }
        DisjointSet ds(v);
        sort(edges.begin(), edges.end());
        int mstWt = 0;
        for (auto it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findPar(u) != ds.findPar(v)) {
                mstWt += wt;
                ds.UnionbyRank(u, v);
            }
        }

        return mstWt;
    }
};
