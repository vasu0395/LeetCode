// link : https://leetcode.com/problems/sum-of-distances-in-tree/

class Solution {
public:
    vector<int>count;
    vector<int>distance;
    int countSubtree(vector<int>adj[],int s,vector<int>&visit){
        visit[s]=1;
        for(auto it : adj[s]){
            if(visit[it]==0){
                count[s] += countSubtree(adj,it,visit);
            }
        }
        
        count[s]+=1;
        return count[s];
    }
    
    void distanceFromRoot(vector<int>adj[],int s,vector<int>&visit){
        visit[s]=1;
        int d=0;
        queue<int>q;
        q.push(s);
        int sum=0;
        while(!q.empty()){
            int t=q.size();
            for(int i=0;i<t;i++){
                int f=q.front();
                q.pop();
                
                sum+=d;
                
                for(auto it : adj[f])
                {
                    if(visit[it]==0){
                        visit[it]=1;
                        q.push(it);
                    }
                }
            }
            d++;
        }
        distance[s]=sum;
    }
    
    void fillMyAnswer(vector<int>adj[],int s,vector<int>&visit){
        //dist[node] = dist[parent] - count[node] + (n - count[node])
        visit[s]=1;
        queue<int>q;
        q.push(s);
        
        while(!q.empty()){
            int t=q.size();
            for(int i=0;i<t;i++){
                int f=q.front();
                q.pop();
                
                for(auto it : adj[f]){
                    if(visit[it]==0){
                        visit[it]=1;
                        q.push(it);
                        distance[it]=distance[f] - count[it] + (visit.size() - count[it]);
                    }
                }
            }
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        count.resize(n);
        vector<int>visit(n,0);
        countSubtree(adj,0,visit);
        
        
        distance.resize(n);
        vector<int>visit2(n,0);
        distanceFromRoot(adj,0,visit2);
        
        vector<int>visit3(n,0);
        fillMyAnswer(adj,0,visit3);
        return distance;
    }
};