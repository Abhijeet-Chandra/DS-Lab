//using dfs:
class Solution {
    int n;
    public void dfs(int [][] adjMat, int start, boolean [] visited){
        if(visited[start])return;
        visited[start] = true;
        for(int j = 0; j<n; j++){
            if(adjMat[start][j]==1&&!visited[j]){
                dfs(adjMat,j,visited);
            }
        }
    }
    public int findCircleNum(int[][] isConnected) {
        n = isConnected.length;
        boolean [] visited = new boolean[n];
        int provinces = 0;
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                dfs(isConnected, i, visited);
                provinces++;
            }
        }
        return provinces;
    }
}


//using bfs:

class Solution {
    int n;
    public void bfs(int [][] adjMat, int start, boolean [] visited){
        Queue<Integer> q = new LinkedList<>();
        q.add(start);
        visited[start] = true;
        while(!q.isEmpty()){
            int node = q.poll();
            for(int j = 0; j<n; j++){
                if(adjMat[node][j]==1&&!visited[j]){
                    q.add(j);
                    visited[j] = true;
                }
            }
        }
    }
    public int findCircleNum(int[][] isConnected) {
        n = isConnected.length;
        boolean []visited = new boolean[n];;
        int provinces = 0;
        for(int i = 0; i<n; i++){
            if(!visited[i])
            {
                bfs(isConnected, i, visited);
                provinces++;
            }
        }
        return provinces;
    }
}
