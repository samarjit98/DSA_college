import java.util.Scanner;
import java.util.LinkedList;

public class graph_java {
    static class Graph{
        int V;
        LinkedList<Integer> adj[];

        Graph(int v){
            this.V=v;

            adj=new LinkedList[v];

            for(int i=0; i<v; i++){
                adj[i]=new LinkedList<>();
            }
        }

        public void addEdge(int src, int dest){
            adj[src].addLast(dest);
            adj[dest].addLast(src);
        }

        public void printGraph(){
            for(int i=0; i<this.V; i++){
                System.out.print(i);
                for(Integer crawler: adj[i]){
                    System.out.print("->"+crawler);
                }
                System.out.print("\n");
            }
        }
    }

    public static void main(String[] args){
        Scanner in=new Scanner(System.in);
        int v=in.nextInt();
        int e=in.nextInt();
        Graph g=new Graph(v);
        for(int i=0; i<e; i++){
            int src=in.nextInt();
            int dest=in.nextInt();
            g.addEdge(src, dest);
        }
        g.printGraph();
    }
}
