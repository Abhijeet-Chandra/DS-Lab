import java.util.*;

public class all_important_algos {
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
            for(int neighbor : adjList.get(curr)){ // visit all neighbors of current vertex
                if(!visitedBFS[neighbor]){
                    q.add(neighbor);
                    visitedBFS[neighbor] = true;
                    System.out.print(neighbor+" ");
                }
            }
        }
    }

    //FOR UNDIRECTED::::::::::::
    //cycle detection using dfs:
    public static boolean dfsCycleDetectionUndirected(HashMap<Integer,ArrayList<Integer>>adjList, int start, boolean [] visitedDFS, int parent) {
        visitedDFS[start] = true; //mark current vertex as visited

        for(int neighbor : adjList.get(start)){ //check its neighbors 
            if(neighbor == parent)continue; // ignore the edge leading back to the parent, because every undirected edge appears twice

            if(visitedDFS[neighbor])return true; //if the for any of the neighbor, parent is not the current vertex, as well as neighbor is visited already, it means cycle is there

            if(dfsCycleDetectionUndirected(adjList,neighbor,visitedDFS,start))return true;
        }
        return false;
    }
    public static boolean isCyclicDFS_Undirected(HashMap<Integer,ArrayList<Integer>>adjList, boolean [] visitedDFS){
        for(int vertex : adjList.keySet()){
            if(!visitedDFS[vertex] && dfsCycleDetectionUndirected(adjList,vertex,visitedDFS,-1)){ //go to each vertex, if its not visited, apply dfs check on it
                return true;
            }
        }
        return false;
    }

    //cycle detection using bfs:
    public static boolean bfsCycleDetectionUndirected(HashMap<Integer,ArrayList<Integer>>adjList, int start, boolean [] visitedBFS){
        Queue<int[]> q = new LinkedList<>(); //since its bfs, we need a queue, also, in queue, we are keeping node as well as its parent as a pair {node, parent}
        q.add(new int[]{start,-1}); //intialize the queue with starting vertex, and its parent to be -1
        visitedBFS[start] = true; //mark it as visited
        while (!q.isEmpty()){ //while q is not empty
            int [] pair = q.poll(); //pop out the front most node
            int source = pair[0]; //pair[0] denotes the actual node
            int parent = pair[1];//pair [1] denotes the parent node

            for(int neighbor : adjList.get(source)){ //go to each neighbor of current node (source or pair[0]) one by one
                if(!visitedBFS[neighbor]){ //if its not visited
                    visitedBFS[neighbor] = true; //mark it as visited
                    q.add(new int[]{neighbor,source}); //add it to the queue along with its parent, i.e. {neigbor,source}
                }
                else if(neighbor != parent){ //if its visited, then we have to check whether the parent is neighbor itself, if yes just skip, if not, then return true, that means there is a cycle
                    return true;
                }
            }
        }
        return false;
    }
    public static boolean isCyclicBFS_Undirected(HashMap<Integer,ArrayList<Integer>>adjList, boolean [] visitedBFS){
        for(int vertex : adjList.keySet()){
            if(!visitedBFS[vertex] && bfsCycleDetectionUndirected(adjList,vertex,visitedBFS)){//go to each vertex, if its not visited, apply bfs check on it
                return true;
            }
        }
        return false;
    }

    //FOR DIRECTED::::::::::::
    //using dfs:
    public static boolean dfsCycleDetectionDirected(HashMap<Integer,ArrayList<Integer>>adjList, int start, boolean [] visitedDFS, boolean [] inRecursion){
        visitedDFS[start] = true;
        inRecursion[start] = true;// mark node as visited and currently present in recursion stack

        for(int neighbor : adjList.get(start)){
            if(!visitedDFS[neighbor] && dfsCycleDetectionDirected(adjList,neighbor,visitedDFS,inRecursion)) return true;
            else if(inRecursion[neighbor])return  true;
        }
        inRecursion[start] = false;// remove node from recursion stack while backtracking
        return false;
    }
    public static boolean isCyclicDFS_Directed(HashMap<Integer,ArrayList<Integer>>adjList, boolean [] visitedDFS, boolean [] inRecursion){
        for(int vertex : adjList.keySet()){
            if(!visitedDFS[vertex] && dfsCycleDetectionDirected(adjList,vertex,visitedDFS,inRecursion)) return true;
        }
        return false;
    }

    //Topological sort:
    //dfs:
    public static void dfsTopo(HashMap<Integer,ArrayList<Integer>>adjList, int start, boolean [] visitedDFS, Stack<Integer> pop_stack){
        if(visitedDFS[start]) return; //if already visited then return (base case)
        visitedDFS[start] = true; //else make the current vertex visited

        for (int neighbor : adjList.get(start)){ //go to all adjacent vertices of current vertex, basically visit all neighbors one by one and apply dfs one each of them if not visited
            if(!visitedDFS[neighbor]){
                dfsTopo(adjList, neighbor, visitedDFS, pop_stack);
            }
        }

        pop_stack.push(start); // push vertex after processing all descendants reversing this finishing order gives topological ordering
    }
    //bfs:
    public static void bfsTopo(HashMap<Integer,ArrayList<Integer>>adjList, int [] inDegree){
        Queue<Integer> queue = new LinkedList<>(); //queue to maintain vertices with 0 indegree
        for(int i = 0; i<inDegree.length; i++){
            if(inDegree[i]==0)queue.add(i); //if indegree == 0 add it to the queue
        }
        while(!queue.isEmpty()){
            int source = queue.poll(); //pop the vertex at front (remove the vertex)
            System.out.print(source+" "); //print that vertex
            for(int neighbor : adjList.get(source)){ //go to all its neighbors one by one and decrease their indegree
                inDegree[neighbor]--;
                if(inDegree[neighbor] == 0)queue.add(neighbor); //if indegree of any neighbor becomes 0, add it to the queue
            }
        }
    }
    public static void topoSort(HashMap<Integer,ArrayList<Integer>> adjList,boolean [] visitedDFS){
        if(!isDirected){
            System.out.println("Graphs is not directed!!"); //for topo sort, graph should be directed and acyclic
            return;
        }

        //topo using dfs:
        Stack<Integer> pop_stack = new Stack<>(); //stack to maintain pop order
        for(int vertex : adjList.keySet()){ //apply dfs on all vertices one by one
            if(!visitedDFS[vertex])
                dfsTopo(adjList, vertex, visitedDFS,pop_stack);
        }

        System.out.println("Topo sort using DFS: ");
        while(!pop_stack.isEmpty()){ //empty out the stack to get reverse pop order
            System.out.print(pop_stack.pop()+" ");
        }
        System.out.println();

        //topo using bfs:(Kahn's algo):
        int [] inDegree = new int[visitedDFS.length]; //array to maintain indegree
        for(int vertex : adjList.keySet()){ //calculate indegree of each vertex
            for(int neighbor : adjList.get(vertex)){
                inDegree[neighbor]++;
            }
        }

        System.out.println("\nTopo sort using BFS:");
        bfsTopo(adjList,inDegree);

        //NOTE: // visited array is unnecessary because a node enters the queue  only when its indegree becomes 0, which can happen at most once
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
        boolean [] inRecursion = new boolean[maxVertex+1];

        //TRAVERSALS:
        //dfs
        System.out.println("DFS: ");
        dfs(adjList,0,visitedDFS);
        System.out.println();
        //bfs
        System.out.println("BFS: ");
        bfs(adjList,0,visitedBFS);

        //CYCLE DETECTION:
        if(!isDirected){
            Arrays.fill(visitedDFS,false); //resetting
            Arrays.fill(visitedBFS,false); //resetting

            //cycle detection(using dfs):
            System.out.println("Cycle: "+(isCyclicDFS_Undirected(adjList, visitedDFS) ? "present" : "absent"));

            //cycle detection(using bfs):
            System.out.println("Cycle: "+(isCyclicBFS_Undirected(adjList, visitedBFS) ? "present" : "absent"));
        }
        else{
            
            //cycle detection(using dfs):
            System.out.println("Cycle: "+(isCyclicDFS_Directed(adjList, visitedDFS, inRecursion) ? "present" : "absent"));

            //cycle detection(using bfs):

        }

        //TOPOLOGICAL SORT:
        Arrays.fill(visitedDFS,false); //resetting
        Arrays.fill(inRecursion, false); //resetting
        if (isDirected && !isCyclicDFS_Directed(adjList,visitedDFS,inRecursion)) { //if its directed and acyclic (DAG)
            Arrays.fill(visitedDFS,false); //resetting again cuz we used this in cycle detection lol
            topoSort(adjList,visitedDFS);
        }
    }
}