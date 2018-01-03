package oop_lec2;
import java.util.Scanner;

class TreeNode{
    int data;
    TreeNode left, right;
    TreeNode(int n){
        data=n; left=right=null;
    }
}
class Tree{
    TreeNode head;
    
    Tree(){
        head=null;
    }
    private TreeNode addUtil(TreeNode t, int n){
        if(t==null){
            t=new TreeNode(n);
            return t;
        }
        
        if(n>t.data)t.right=addUtil(t.right, n);
        else t.left=addUtil(t.left, n);
        return t;
    }
    public void add(int n){
        head=addUtil(head, n);
    }
    private void preorderUtil(TreeNode t){
        if(t==null)return;
        
        preorderUtil(t.left);
        System.out.println(t.data);
        preorderUtil(t.right);
    }
    public void preorder(){
        preorderUtil(head);
    }
}
public class OOP_tree {
    public static void main(String[] args){
        Tree t=new Tree();
        Scanner in=new Scanner(System.in);
        char ans='y';
        while(ans=='y'){
            t.add(in.nextInt()); ans=in.next().charAt(0);
        }
        t.preorder();
    }
}
