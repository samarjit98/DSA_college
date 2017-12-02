import java.util.Scanner;

public class BinaryTree {
    static class Node{
        int key;
        Node left, right;

        public Node(int key){
            this.key=key;
            left=right=null;
        }
    }

    static class Tree{
        Node root;

        public Tree(){
            root=null;
        }

        public Node makeTreeUtil(Node curr){
            Scanner in=new Scanner(System.in);
            System.out.println("Key for current node:");
            int k=in.nextInt();
            curr=new Node(k);
            System.out.println(k+" Left:");
            int ans=in.nextInt();
            if(ans==1)curr.left=makeTreeUtil(curr.left);
            System.out.println(k+" Right:");
            ans=in.nextInt();
            if(ans==1)curr.right=makeTreeUtil(curr.right);
            return curr;
        }

        public void makeTree(){
            root=makeTreeUtil(root);
        }

        public void inorderUtil(Node curr){
            if(curr==null)return;
            inorderUtil(curr.left);
            System.out.print(curr.key+" ");
            inorderUtil(curr.right);
        }

        public void inorder(){
            inorderUtil(root);
        }
    }

    public static void main(String[] args){
        Tree T=new Tree();
        T.makeTree();
        T.inorder();
    }
}
