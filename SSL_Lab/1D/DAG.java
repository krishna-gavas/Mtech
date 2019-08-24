import java.io.*;
import java.util.*;

class DAG{

    private static int V;      //number of vertices
    static Map<Integer, List<Integer>> graph = new HashMap<>();        //Adjacency list


    static void topologicalSort(int u, int in[],int out[], Stack stack,boolean visited[]){
        if(in[u] == 0) {
            stack.push(u);
            Integer i;
            List<Integer> list = graph.get(u);
            if (stack.empty() == false)
                System.out.print(stack.pop() + " ");

            if(list != null){
                Iterator<Integer> it = list.iterator();
                while (it.hasNext()) {
                    i = it.next();
                    in[i]--;
                    if(in[i] == 0)
                        if (!visited[i])
                            topologicalSort(i, in, out, stack,visited);
                }
            }
            
            
        }

    }
  

    static void findInOutDegree(int n) 
	{ 
		int in[] = new int[n]; 
		int out[] = new int[n]; 

		for (int i = 0; i < n; i++) { 

			List<Integer> list = graph.get(i); 

			// Out degree for ith vertex will be the count 
            // of direct paths from i to other vertices 
            if(list != null){
                out[i] = list.size(); 
                for (int j = 0; j < list.size(); j++) 

                    // Every vertex that has an incoming 
                    // edge from i 
                    in[list.get(j)]++;
            }
                
            
			 
        } 

        Stack stack = new Stack();

        boolean visited[] = new boolean[n];
        for (int i = 0; i < n; i++)
            visited[i] = false;
         
		for (int i = 0; i < n; i++) { 
            topologicalSort(i,in,out,stack,visited);			
        } 
        System.out.println();
	}

    public static void main(String args[]){

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the total number of vertices: ");
        V = sc.nextInt();

        System.out.println("Enter the total number of Edges: ");
        int E = sc.nextInt();

        System.out.println("Enter the Edges(u,v): ");
        for(int i=0;i<E;i++){
            int u = sc.nextInt();
            int v = sc.nextInt();

            if(!graph.containsKey(u)) 
                graph.put(u, new LinkedList());

            graph.get(u).add(v);
        }

        //int n = graph.size(); 
		findInOutDegree(V); 


    }
}