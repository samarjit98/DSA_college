package oop_lec2;
import java.util.Scanner;
import java.util.LinkedList;
import java.util.Queue;

class TNode{
    int data;
    TNode left, right;
    
    TNode(int n){
        data=n; left=right=null;
    }
}

class AVLTree{
    TNode head;
    
    AVLTree(){
        head=null;
    }
    private int height(TNode t){
        if(t==null)return 0;
        else return 1+Math.max(height(t.left), height(t.right));
    }
    private int balanceFactor(TNode t){
        return Math.abs(height(t.left)-height(t.right));
    }
    private TNode singleRightRotate(TNode t){
        TNode mainRight=t.right;
        TNode rightLeft=t.right.left;
        t.right=rightLeft;
        mainRight.left=t;
        return mainRight;
    }
    private TNode singleLeftRotate(TNode t){
        TNode mainLeft=t.left;
        TNode leftRight=t.left.right;
        t.left=leftRight;
        mainLeft.right=t;
        return mainLeft;
    }
    private TNode doubleRightRotate(TNode t){
        t.right=singleLeftRotate(t.right);
        t=singleRightRotate(t);
        return t;
    }
    private TNode doubleLeftRotate(TNode t){
        t.left=singleRightRotate(t.left);
        t=singleLeftRotate(t);
        return t;
    }
    private TNode insert(TNode t, int n){
        if(t==null){
            t=new TNode(n);
            return t;
        }
        if(n>t.data){
            t.right=insert(t.right, n);
            if(balanceFactor(t)>=2){
                if(n>t.right.data)t=singleRightRotate(t);
                else t=doubleRightRotate(t);
            }
        }
        else{
            t.left=insert(t.left, n);
            if(balanceFactor(t)>=2){
                if(n<t.left.data)t=singleLeftRotate(t);
                else t=doubleLeftRotate(t);
            }
        }
        return t;
    }
    public void add(int n){
        head=insert(head, n);
    }
    private void preorderUtil(TNode t){
        if(t==null)return;
        
        preorderUtil(t.left);
        System.out.print(t.data + " ");
        preorderUtil(t.right);
    }
    public void preorder(){
        preorderUtil(head);
        System.out.print("\n");
    }
    public void levelorder(){
        Queue<TNode> q=new LinkedList<>();
        q.add(head);
        while(!q.isEmpty()){
            for(int i=q.size(); i>0; i--){
                TNode tmp=q.poll();
                System.out.print(tmp.data+" ");
                if(tmp.left!=null)q.add(tmp.left);
                if(tmp.right!=null)q.add(tmp.right);
            }
            System.out.print("\n");
        }
    }
}

public class OOP_AVL {
    public static void main(String[] args){
        AVLTree t;
        t = new AVLTree();
        Scanner in=new Scanner(System.in);
        char ans='y';
        while(ans=='y'){
            t.add(in.nextInt()); ans=in.next().charAt(0);
        }
        t.preorder();
        t.levelorder();
    }
}
