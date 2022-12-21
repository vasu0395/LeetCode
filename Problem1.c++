// Problem link :- https://leetcode.com/problems/possible-bipartition/

class Solution {
public:
    bool isPossible(vector<int>adj[],int s,vector<int>&visit,vector<int>&color){
        queue<int>q;
        q.push(s);
        visit[s]=1;
        
        while(!q.empty()){
            int t=q.size();
            for(int i=0;i<t;i++){
                int f=q.front();
                q.pop();
                
                for(auto e : adj[f]){
                    if(visit[e]==0){
                        color[e]=!color[f];
                        q.push(e);
                        visit[e]=1;
                    }else if(visit[e]==1 && color[e]==color[f]){
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>visit(n+1,0);
        vector<int>color(n+1,0);
        
        vector<int>adj[n+1];
        for(int i=0;i<dislikes.size();i++){
            int x=dislikes[i][0];
            int y=dislikes[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        for(int i=1;i<=n;i++){
            if(visit[i]==0){
                color[i]=0;
                if (!isPossible(adj,i,visit,color)){
                return false;
                }
            }
        }
        
        return true;
    }
};