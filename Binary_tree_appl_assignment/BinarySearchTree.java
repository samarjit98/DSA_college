import java.util.Scanner;

public class BinarySearchTree {
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

        public Node insertUtil(Node curr, int k){
            if(curr==null){
                curr=new Node(k);
                return curr;
            }

            if(k>curr.key)curr.right=insertUtil(curr.right, k);
            else curr.left=insertUtil(curr.left, k);
            return curr;
        }

        public void insert(int k){
            root=insertUtil(root, k);
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
        Scanner in=new Scanner(System.in);
        int t=in.nextInt();
        for(int i=0; i<t; i++){
            int k=in.nextInt(); T.insert(k);
        }
        T.inorder();
    }
}
