import java.util.*;

public class a {
    static boolean isDirected; // (directed / undirected)
    //adj list creation
    public static HashMap<Integer,ArrayList<Integer>> makeAdjList(){
        //making adjacency list:
        Scanner sc = new Scanner(System.in);


        System.out.println("Enter 'y' for directed and 'n' for undirected graph: ");
        isDirected = sc.next().equalsIgnoreCase("y");

        HashMap<Integer, ArrayList<Integer>> map = new HashMap<>(); //basically this is the 'adjacency' list
        //for each vertex we have list of integers...

        //Internal structure:
        // a-> [1,2,3] that means 1,2,3 are adjacent to vertex a
        // b-> [5,6,7] that means 5,6,7 are adjacent to vertex b

        char choice;
        int u,v;

        do {
            System.out.println("Enter edge (u-v): ");
            u = sc.nextInt();
            v = sc.nextInt();

            if(!map.containsKey(u)){
                map.put(u, new ArrayList<>()); //if, for a particular vertex no entry is made yet, initialize it with an Empty ArrayList
            }
            if(!map.containsKey(v)){
                map.put(v, new ArrayList<>()); //doing the same thing for vertex v
            }
            map.get(u).add(v); //add edge from u to v (i.e u ----> v)
            if(!isDirected){
                map.get(v).add(u); //add edge from v to u (i.e v ----> u) if undirected obv
            }
            System.out.println("Enter 'y' to continue inserting edges, Enter 'n' to exit: ");
            choice = sc.next().charAt(0);
        }while (choice != 'n');

        return map;
    }

    //FOR UNDIRECTED::::::::::::
    //dfs
    public static void dfs(HashMap<Integer,ArrayList<Integer>>adjList, int start, boolean [] visitedDFS){
        if(visitedDFS[start]) return; //if already visited then return (base case)
        visitedDFS[start] = true; //else make the current vertex visited

        System.out.print(start+" "); //print the current vertex (basically this is push order i.e. order in which vertices are visited)

        for (int neighbor : adjList.get(start)){ //go to all adjacent vertices of current vertex, basically visit all neighbors one by one and apply dfs one each of them if not visited
            if(!visitedDFS[neighbor]){
                dfs(adjList,neighbor,visitedDFS);
            }
        }
    }

    //bfs
    public static void bfs(HashMap<Integer,ArrayList<Integer>>adjList, int start, boolean [] visitedBFS){
        if(visitedBFS[start]) return; //if already visited then return

        Queue<Integer> q = new LinkedList<>(); // Queue in java is implemented using LinkedList class, we cant do Queue<Integer> q =  new Queue<>();

        q.add(start); //add starting vertex to queue
        visitedBFS[start] = true; //make it visited
        System.out.print(start+" "); //print it

        while(!q.isEmpty()){
            int curr = q.poll();
            for(int neighbor : adjList.get(curr)){ //visited one by one
                if(!visitedBFS[neighbor]){
                    q.add(neighbor);
                    visitedBFS[neighbor] = true;
                    System.out.print(neighbor+" ");
                }
            }
        }
    }

    //cycle detection using dfs:
    public static boolean dfsCycleDetectionUndirected(HashMap<Integer,ArrayList<Integer>>adjList, int start, boolean [] visitedDFS, int parent) {
        visitedDFS[start] = true;

        for(int neighbor : adjList.get(start)){
            if(neighbor == parent)continue;

            if(visitedDFS[neighbor])return true;

            if(dfsCycleDetectionUndirected(adjList,neighbor,visitedDFS,start))return true;
        }
        return false;
    }
    public static boolean isCyclicDFS_Undirected(HashMap<Integer,ArrayList<Integer>>adjList, boolean [] visitedDFS){
        for(int vertex : adjList.keySet()){
            if(!visitedDFS[vertex] && dfsCycleDetectionUndirected(adjList,vertex,visitedDFS,-1)){
                return true;
            }
        }
        return false;
    }

    //cycle detection using bfs:
    public static boolean bfsCycleDetectionUndirected(HashMap<Integer,ArrayList<Integer>>adjList, int start, boolean [] visitedBFS){
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{start,-1});
        visitedBFS[start] = true;
        while (!q.isEmpty()){
            int [] pair = q.poll();
            int source = pair[0];
            int parent = pair[1];

            for(int neighbor : adjList.get(source)){
                if(!visitedBFS[neighbor]){
                    visitedBFS[neighbor] = true;
                    q.add(new int[]{neighbor,source});
                }
                else if(neighbor != parent){
                    return true;
                }
            }
        }
        return false;
    }
    public static boolean isCyclicBFS_Undirected(HashMap<Integer,ArrayList<Integer>>adjList, boolean [] visitedBFS){
        for(int vertex : adjList.keySet()){
            if(!visitedBFS[vertex] && bfsCycleDetectionUndirected(adjList,vertex,visitedBFS)){
                return true;
            }
        }
        return false;
    }

    //FOR DIRECTED::::::::::::
    //using dfs:
    public static boolean dfsCycleDetectionDirected(HashMap<Integer,ArrayList<Integer>>adjList, int start, boolean [] visitedDFS, boolean [] inRecursion){
        visitedDFS[start] = true;
        inRecursion[start] = true;

        for(int neighbor : adjList.get(start)){
            if(!visitedDFS[neighbor] && dfsCycleDetectionDirected(adjList,neighbor,visitedDFS,inRecursion)) return true;
            else if(inRecursion[neighbor])return  true;
        }
        inRecursion[start] = false;
        return false;
    }
    public static boolean isCyclicDFS_Directed(HashMap<Integer,ArrayList<Integer>>adjList, boolean [] visitedDFS, boolean [] inRecursion){
        for(int vertex : adjList.keySet()){
            if(!visitedDFS[vertex] && dfsCycleDetectionDirected(adjList,vertex,visitedDFS,inRecursion)) return true;
        }
        return false;
    }

    public static void main(String[] args) {
        //create adj list:
        HashMap<Integer,ArrayList<Integer>> adjList = makeAdjList();

        int maxVertex = Collections.max(adjList.keySet());

        //print adjacency List:
        for(Map.Entry<Integer, ArrayList<Integer>> e : adjList.entrySet()){
            int u = e.getKey();
            ArrayList<Integer> list = e.getValue();
            System.out.println(u+"-> "+list.toString());
        }

        boolean [] visitedDFS = new boolean[maxVertex + 1];//for dfs
        boolean [] visitedBFS = new boolean[maxVertex + 1];//for bfs

        //dfs
        System.out.println("DFS: ");
        dfs(adjList,0,visitedDFS);
        System.out.println();
        //bfs
        System.out.println("BFS: ");
        bfs(adjList,0,visitedBFS);


        if(!isDirected){
            Arrays.fill(visitedDFS,false); //resetting
            Arrays.fill(visitedBFS,false); //resetting

            //cycle detection(using dfs):
            System.out.println("Cycle: "+(isCyclicDFS_Undirected(adjList, visitedDFS) ? "present" : "absent"));

            //cycle detection(using bfs):
            System.out.println("Cycle: "+(isCyclicBFS_Undirected(adjList, visitedBFS) ? "present" : "absent"));
        }
        else{
            boolean [] inRecursion = new boolean[maxVertex+1];
            //cycle detection(using dfs):
            System.out.println("Cycle: "+(isCyclicDFS_Directed(adjList, visitedDFS, inRecursion) ? "present" : "absent"));

            //cycle detection(using bfs):

        }
    }
}