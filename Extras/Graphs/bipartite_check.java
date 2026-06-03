class Solution {
    int n;
    public boolean dfs(int [][]adjMat, int curr, int [] color, int currColor){
        color[curr] = currColor;
        for(int neighbor : adjMat[curr]){
            if(color[neighbor] == currColor)return false;
            if(color[neighbor] == -1){
                int colorNeighbor = 1 - currColor;
                if(!dfs(adjMat,neighbor,color,colorNeighbor))return false;
            }
        }
        return true;
    }
    public boolean isBipartite(int[][] graph) {
        //color == 0 =>red
        //color == 1 =>green
        int n = graph.length;
        int [] color = new int[n];
        Arrays.fill(color,-1);
        for(int i = 0; i<n; i++){
            if(color[i] == -1)
                if(!dfs(graph,i,color,0))return false;
        }

        return true;
    }
}
