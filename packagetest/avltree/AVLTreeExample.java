/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package packagetest.avltree;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import packagetest.tree.BinaryTree;

/**
 *
 * @author c167256
 */

class TNode{
    int data;
    TNode left, right;
    
    TNode(int n){
        data=n; left=right=null;
    }
}

class AVLTree implements BinaryTree{
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
    private TNode insertUtil(TNode t, int n){
        if(t==null){
            t=new TNode(n);
            return t;
        }
        if(n>t.data){
            t.right=insertUtil(t.right, n);
            if(balanceFactor(t)>=2){
                if(n>t.right.data)t=singleRightRotate(t);
                else t=doubleRightRotate(t);
            }
        }
        else{
            t.left=insertUtil(t.left, n);
            if(balanceFactor(t)>=2){
                if(n<t.left.data)t=singleLeftRotate(t);
                else t=doubleLeftRotate(t);
            }
        }
        return t;
    }
    @Override
    public void insert(int n){
        head=insertUtil(head, n);
    }
    private void inorderUtil(TNode t){
        if(t==null)return;
        
        inorderUtil(t.left);
        System.out.print(t.data + " ");
        inorderUtil(t.right);
    }
    @Override
    public void inOrder(){
        inorderUtil(head);
        System.out.print("\n");
    }
    @Override
    public void levelOrder(){
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

public class AVLTreeExample {
    public static void main(String[] args){
        Scanner in=new Scanner(System.in);
        AVLTree avl=new AVLTree();
        char ans='y';
        while(ans=='y'){
            int i=in.nextInt();
            avl.insert(i);
            ans=in.next().charAt(0);
        }
        System.out.println("AVL In order:");
        avl.inOrder();
        System.out.println("AVL Level order:");
        avl.levelOrder();
    }
}
