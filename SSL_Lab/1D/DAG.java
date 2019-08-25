import java.io.*;
import java.util.*;
import java.util.stream.*;

class DAG{

    private static int V;      //number of vertices
    static Map<String, List<String>> graph = new HashMap<>();        //Adjacency list
    static Map<String, List<String>> graph2 = new HashMap<>();

    static void topologicalSort(Map<String, Integer> in,Map<String, Integer> out, Stack stack,Map<String,Integer> visited){

        for (String k: graph.keySet()) { 
            if( (in.get(k) == 0) && (visited.get(k) == 0)){  

                    visited.replace(k,1);
                    stack.push(k);

                    topologicalSort(in,out,stack,visited);

                    while(stack.empty() == false)
                        System.out.print(stack.pop() + " ");

                    String str;
                    List<String> list = graph.get(k);
                    if(list != null){
                        Iterator<String> it = list.iterator();
                        while (it.hasNext()){
                            str = it.next();
                            in.replace(str,in.get(str) - 1);
                            if(in.get(str) == 0)
                                topologicalSort(in, out, stack, visited);
                        }
                    }              
            }              			
         }

    }
  

    static void findInOutDegree(int n) 
	{ 
        Map<String, Integer> in = new HashMap<>();
        Map<String, Integer> out = new HashMap<>();
        Map<String,Integer> visited = new HashMap<>();

        for (String i: graph.keySet()){
            in.put(i,0);
            out.put(i,0);
            visited.put(i,0);
        }

		for (String i: graph.keySet()) { 
            List<String> list = graph.get(i); 
            
            if(list != null){
                out.replace(i,list.size()); 
                for (int j = 0; j < list.size(); j++) 
                        in.replace(list.get(j),(in.get(list.get(j))) + 1);
            }
            else{
                out.replace(i, 0);
            }

        }
        
        // System.out.println("Vertex\tIn\tOut"); 
		// for (String k: graph.keySet()) { 
		// 	System.out.println(k + "\t" + in.get(k) + "\t" + out.get(k)); 
		// }


        Stack stack = new Stack();
         
        topologicalSort(in,out,stack,visited);

        while(stack.empty() == false)
                System.out.print(stack.pop() + " ");

        System.out.println();
	}

    public static void main(String args[])throws IOException
    {

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the total number of Courses: ");
        V = sc.nextInt();

        System.out.println("Enter the Courses: ");
        for(int i=0;i<V+1;i++){
            String ver = sc.nextLine();
            if(!graph.containsKey(ver)) 
                graph.put(ver, new LinkedList());
        }

        System.out.println("Enter the total number of Edges: ");
        int E = sc.nextInt();

        System.out.println("Enter the Edges(u,v): ");

        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        for(int i=0;i<E;i++){
            String line = in.readLine();
            String[] tokens = line.split(" ");
            String u = tokens[0];
            String v = tokens[1];

            graph.get(u).add(v);
        }

        //int n = graph.size(); 
		findInOutDegree(V); 

        sc.close();
    }
}