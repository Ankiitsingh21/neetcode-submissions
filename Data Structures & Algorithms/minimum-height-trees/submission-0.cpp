class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
         if (n == 1) return {0};

        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> ans;
        int minHeight=INT_MAX;
        for(int i=0;i<n;i++){
            vector<int> dist(n,-1);
            queue<int> q;
            q.push(i);
            dist[i]=0;
            int maxHeight=0;
            while(!q.empty()){
                int top=q.front();
                q.pop();
                maxHeight=max(maxHeight,dist[top]);
                for(auto it:adj[top]){
                    if(dist[it]==-1){
                        dist[it]=dist[top]+1;
                        q.push(it);
                    }
                }
            }
            if(maxHeight<minHeight){
                     minHeight = maxHeight;
                     ans.clear();
                     ans.push_back(i);
            } else if (maxHeight == minHeight) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};