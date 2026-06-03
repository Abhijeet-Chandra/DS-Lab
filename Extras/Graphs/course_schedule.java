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


//using bfs cycle detection (kahn's algo):
class Solution {
    int n;
    public boolean canWriteTopo(int [][] adjMat, int [] inDegree){
        Queue<Integer> q = new LinkedList<>();
        int count=0;
        for(int i = 0; i<n; i++){
            if(inDegree[i] == 0)q.add(i);
        }
        while(!q.isEmpty()){
            int node = q.poll();
            count++;
            for(int j = 0; j<n; j++){
                if(adjMat[node][j] == 1){
                    inDegree[j]--;
                    if(inDegree[j]==0){
                        q.add(j);
                    }
                }
            }
        }
        return count == n;
    }
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        n = numCourses;
        int [][] adjMat = new int[n][n];
        int [] inDegree = new int[n];
        for(int i = 0; i<prerequisites.length; i++){
            adjMat[prerequisites[i][1]][prerequisites[i][0]] = 1;
            inDegree[prerequisites[i][0]]++;
        }
        return canWriteTopo(adjMat, inDegree);
    }
}

