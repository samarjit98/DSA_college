import java.util.Scanner;
import java.util.LinkedList;
import java.util.Queue;

public class BFS_java {
    static class Graph{
        int V;
        LinkedList<Integer> adj[];

        Graph(int V){
            this.V=V;

            adj=new LinkedList[V];
            for(int i=0; i<V; i++){
                adj[i]=new LinkedList<>();
            }
        }

        public void addEdge(int src, int dest){
            adj[src].addLast(dest);
            adj[dest].addLast(src);
        }

        public void BFS(int n){
            Queue<Integer> q=new LinkedList<>();
            boolean visited[]=new boolean[this.V];
            for(int i=0; i<this.V; i++)visited[i]=false;
            q.add(n);
            visited[n]=true;

            while(!q.isEmpty()){
                int top=q.remove();
                System.out.print(top+" ");
                for(Integer c: adj[top]){
                    if(visited[c]==false){
                        visited[c]=true; q.add(c);
                    }
                }
            }
        }
    }

    public static void main(String args[]){
        Scanner in=new Scanner(System.in);
        int v=in.nextInt();
        int e=in.nextInt();
        Graph g=new Graph(v);
        for(int i=0; i<e; i++){
            int src=in.nextInt();
            int dest=in.nextInt();
            g.addEdge(src, dest);
        }
        int startvt=in.nextInt();
        g.BFS(startvt);
    }
}
