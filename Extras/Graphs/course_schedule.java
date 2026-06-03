//using dfs cycle detection:

class Solution {
    int n;
    public boolean dfs(int [][] adjMat, int start, boolean [] visited, boolean [] inRecursion){
        visited[start] = true;
        inRecursion[start] = true;
        for(int j = 0; j<n; j++){
           if(adjMat[start][j] == 1){
             if(!visited[j]){
                if(dfs(adjMat,j,visited,inRecursion)) return true;
            }
            else if(inRecursion[j])return true;
           }
        }
        inRecursion[start] = false;
        return false;
    }
    public boolean isCyclic(int [][] adjMat, boolean [] visited){
        boolean [] inRecursion = new boolean[n];
        for(int i = 0; i<n; i++){
            if(!visited[i] && dfs(adjMat,i,visited,inRecursion))return true;
        }
        return false;
    }
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        n = numCourses;
        int [][] adjMat = new int[numCourses][numCourses];
        for(int i = 0; i<prerequisites.length; i++){
            adjMat[prerequisites[i][0]][prerequisites[i][1]] = 1;
        }
        boolean [] visited = new boolean[numCourses];
        return !isCyclic(adjMat,visited);
    }
}

