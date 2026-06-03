class Solution {
    int n;
    public int[] topoOrder(int [][] adjMat, int [] inDegree){
        Queue<Integer> q = new LinkedList<>();
        for(int i = 0; i<n; i++){
            if(inDegree[i] == 0)q.add(i);
        }
        ArrayList<Integer> list = new ArrayList<>();
        while(!q.isEmpty()){
            int node = q.poll();
            list.add(node);
            for(int j = 0; j<n; j++){
                if(adjMat[node][j] == 1){
                    inDegree[j]--;
                    if(inDegree[j]==0){
                        q.add(j);
                    }
                }
            }
        }
        if(list.size() != n) return new int[0];
        int [] ans = new int[list.size()];
        for(int i = 0; i<list.size(); i++)ans[i] = list.get(i);
        return ans;
    }
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        n = numCourses;
        int [][] adjMat = new int[n][n];
        int [] inDegree = new int[n];
        for(int i = 0; i<prerequisites.length; i++){
            adjMat[prerequisites[i][1]][prerequisites[i][0]] = 1;
            inDegree[prerequisites[i][0]]++;
        }
        return topoOrder(adjMat, inDegree);
    }
}
