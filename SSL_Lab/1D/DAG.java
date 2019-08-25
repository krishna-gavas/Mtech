import java.io.*;
import java.util.*;
import java.util.stream.*;

class DAG{

    private static int V;      //number of vertices
    static Map<String, List<String>> graph = new HashMap<>();        //Adjacency list
    static Map<String, List<String>> prerequisite = new HashMap<>();        // Prerequisite info
    static Map<String, List<String>> Register = new HashMap<>();        //Registered Student

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
                for (int j = 0; j < list.size(); j++){
                    in.replace(list.get(j),(in.get(list.get(j))) + 1);
                    prerequisite.get(list.get(j)).add(i);
                }
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
    
    static void RegisterCourse(String name, String course){
        
        List<String> list1 = prerequisite.get(course); 
        if(list1 != null){
            Integer flag = 0;
            for(int j=0; j<list1.size(); j++){
                String str = list1.get(j);
                if(Register.get(str).contains(name)){
                    //Nothing Here
                }
                else{
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                Register.get(course).add(name);
                System.out.println("Registered Successfully");
            }
            else
                System.out.println("Registration Failed");
        }
        else{
            
            Register.get(course).add(name);
            System.out.println("Registered Successfully");
        }
    }

    public static void main(String args[])throws IOException
    {

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the total number of Courses: ");
        V = sc.nextInt();

        System.out.println("Enter the Courses: ");
        for(int i=0;i<V+1;i++){
            String ver = sc.nextLine();
            if(!graph.containsKey(ver)) 
                graph.put(ver, new LinkedList());
            
            if(!prerequisite.containsKey(ver)) 
                prerequisite.put(ver, new LinkedList());

            if(!Register.containsKey(ver)) 
                Register.put(ver, new LinkedList());
        }

        System.out.print("Enter the total number of Edges: ");
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
        Integer choice = 1;

        while(choice == 1){
            
            System.out.print("Enter Student Name: ");
            String name = in.readLine();
    
            System.out.print("Enter Course Name: ");
            String course = in.readLine();
    
            RegisterCourse(name,course);

            System.out.print("Press 1 to continue, 2 to exit: ");
            choice = Integer.parseInt(in.readLine());
            System.out.println();
        }
        

        sc.close();
    }
}