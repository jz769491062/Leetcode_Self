vector<int> topologicalSort(vector<vector<int>> &Adj, vector<int> &Indegree, int n){
    vector<int> res;
    queue<int> q;
    for(int i = 0;i<n;i++){
        if(Indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int front = q.front();
        q.pop();
        res.push_back(front);
        for(int successor: Adj[front]){
            Indegree[successor]--;
            if(Indegree[successor]==0){
                q.push(successor);
            }
        }
    }
    if(res.size()==n){return res;}
    return vector<int>();
}