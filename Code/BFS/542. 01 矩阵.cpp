// https://leetcode.cn/problems/01-matrix/description/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<pair<int,int>> around = {{0,1},{0,-1},{-1,0},{1,0}};
        queue<pair<int,int>> que;
        // INT_MAX用于后续不断优化到最近的0的距离
        vector<vector<int>> result(m,vector<int>(n, INT_MAX));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] == 0){
                    result[i][j] = 0;
                    que.push({i,j});
                }
            }
        }
        while(!que.empty()){
            auto temp = que.front();
            que.pop();
            for(int i = 0 ; i < 4 ; i ++){
                int x = temp.first + around[i].first;
                int y = temp.second + around[i].second;
                if( x >= 0 && x < m && y >= 0 && y < n){
                    // 注意+1，毕竟跨格子本身就是1的距离
                    if(result[x][y] > result[temp.first][temp.second] + 1){
                        result[x][y] = result[temp.first][temp.second] + 1;
                        que.push({x,y});
                    }
                }
            }
        }
        return result;

// 作者：xzp
// 链接：https://leetcode.cn/leetbook/read/bfs/ekqh6e/?discussion=rKGlM1
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    }
};