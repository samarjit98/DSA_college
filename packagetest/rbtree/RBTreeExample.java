/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package packagetest.rbtree;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import packagetest.tree.BinaryTree;

/**
 *
 * @author c167256
 */
class RBNode{
    int data;
    char color;
    RBNode left, right, parent;
    RBNode(int data){
        this.data=data; left=right=parent=null; color='r';
    }
}

class RedBlackTree implements BinaryTree{
    RBNode head;
    
    RedBlackTree(){
        head=null;
    }
    private RBNode redBlackInsert(RBNode t, RBNode tptr){
        if(t==null){
            return tptr;
        }
        
        if(tptr.data>t.data){
            t.right=redBlackInsert(t.right, tptr);
            t.right.parent=t;
        }
        else{
            t.left=redBlackInsert(t.left, tptr);
            t.left.parent=t;
        }
        return t;
    }
    private RBNode rotateLeft(RBNode root, RBNode tptr){
        RBNode tptrRight=tptr.right;
        tptr.right=tptrRight.left;
        if(tptr.right!=null)tptr.right.parent=tptr;
        tptrRight.parent=tptr.parent;
        if(tptr.parent==null)root=tptrRight;
        else if(tptr==tptr.parent.left)tptr.parent.left=tptrRight;
        else tptr.parent.right=tptrRight;
        tptrRight.left=tptr;
        tptr.parent=tptrRight;
        return root;
    }
    private RBNode rotateRight(RBNode root, RBNode tptr){
        RBNode tptrLeft=tptr.left;
        tptr.left=tptrLeft.right;
        if(tptr.left!=null)tptr.left.parent=tptr;
        tptrLeft.parent=tptr.parent;
        if(tptr.parent==null)root=tptrLeft;
        else if(tptr==tptr.parent.right)tptr.parent.right=tptrLeft;
        else tptr.parent.left=tptrLeft;
        tptrLeft.right=tptr;
        tptr.parent=tptrLeft;
        return root;
    }
    private RBNode fixTree(RBNode root, RBNode tptr){
        RBNode parentPtr, grandParentPtr;
        while(tptr!=root && tptr.color!='b' && tptr.parent.color=='r'){
            parentPtr=tptr.parent;
            grandParentPtr=tptr.parent.parent;
            if(parentPtr==grandParentPtr.left){
                RBNode unclePtr=grandParentPtr.right;
                if(unclePtr!=null && unclePtr.color=='r'){
                    grandParentPtr.color='r';
                    parentPtr.color='b';
                    unclePtr.color='b';
                    tptr=grandParentPtr;
                }
                else{
                    if(tptr==parentPtr.right){
                        root=rotateLeft(root, parentPtr);
                        tptr=parentPtr;
                        parentPtr=tptr.parent;
                    }
                    root=rotateRight(root, grandParentPtr);
                    char ch=parentPtr.color;
                    parentPtr.color=grandParentPtr.color;
                    grandParentPtr.color=ch;
                    tptr=parentPtr;
                }
            }
            else{
                RBNode unclePtr=grandParentPtr.left;
                if(unclePtr!=null && unclePtr.color=='r'){
                    grandParentPtr.color='r';
                    parentPtr.color='b';
                    unclePtr.color='b';
                    tptr=grandParentPtr;
                }
                else{
                    if(tptr==parentPtr.left){
                        root=rotateRight(root, parentPtr);
                        tptr=parentPtr;
                        parentPtr=tptr.parent;
                    }
                    root=rotateLeft(root, grandParentPtr);
                    char ch=parentPtr.color;
                    parentPtr.color=grandParentPtr.color;
                    grandParentPtr.color=ch;
                    tptr=parentPtr;
                }
            }
        }
        root.color='b';
        return root;
    }
    @Override
    public void insert(int n){
        RBNode tptr=new RBNode(n);
        head=redBlackInsert(head, tptr);
        head=fixTree(head, tptr);
    }
    @Override
    public void levelOrder(){
        Queue<RBNode> q=new LinkedList<>();
        q.add(head);
        while(!q.isEmpty()){
            for(int i=q.size(); i>0; i--){
                RBNode tmp;
                tmp = q.poll();
                System.out.print(tmp.data+" ");
                if(tmp.left!=null)q.add(tmp.left);
                if(tmp.right!=null)q.add(tmp.right);
            }
            System.out.print("\n");
        }
    }
    private void inOrderUtil(RBNode t){
        if(t==null)return;
        inOrderUtil(t.left);
        System.out.print(t.data+" ");
        inOrderUtil(t.right);
    }
    @Override
    public void inOrder(){
        inOrderUtil(head);
        System.out.print("\n");
    }
}

public class RBTreeExample {
    public static void main(String[] args){
        Scanner in=new Scanner(System.in);
        RedBlackTree rb=new RedBlackTree();
        char ans='y';
        while(ans=='y'){
            int i=in.nextInt();
            rb.insert(i); 
            ans=in.next().charAt(0);
        }
        System.out.println("RB In order:");
        rb.inOrder();
        System.out.println("RB Level order:");
        rb.levelOrder();
    }
}
