class UnionFind
{
    public:
    vector<int> parent;
    vector<int> rank;
    int count;
    UnionFind(int n):parent(n),rank(n),count(n)
    {
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            rank[i]=1;
        }
    }
    int find(int a)
    {
        if(parent[a]!=a)
            parent[a]=find(parent[a]);
        return parent[a];
    }
    void unionSet(int a,int b)
    {
        int x=find(a);
        int y=find(b);
        if(x!=y)
        {
            if(rank[x]>rank[y])
                parent[y]=x;
            else
            {
                parent[x]=y;
                if(rank[x]==rank[y])
                    rank[y]++;
            }
            count--;
        }
    }
    int getCount()
    {
        return count;
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        if(n==0) return 0;
        UnionFind uf(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                    uf.unionSet(i,j);
            }
        }
        return uf.getCount();
    }
};