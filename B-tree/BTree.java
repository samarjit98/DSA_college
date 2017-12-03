import java.util.Scanner;

public class BTree {
    static class BTreeNode{
        public int t;
        public int n;
        public int keys[];
        boolean leaf;
        BTreeNode child[];

        public BTreeNode(int _t, boolean _leaf){
            t=_t; leaf=_leaf; n=0;
            keys=new int[2*t-1];
            child=new BTreeNode[2*t];
        }
        public void traverse(){
            int i=0;
            for(i=0; i<n; i++){
                if(!leaf)child[i].traverse();
                System.out.print(keys[i]+" ");
            }
            if(!leaf)child[i].traverse();
        }
        public void splitChild(int i, BTreeNode y){
            BTreeNode z=new BTreeNode(t, y.leaf);
            z.n=t-1;

            for(int j=0; j<t-1; j++)z.keys[j]=y.keys[j+t];
            if(!y.leaf){
                for(int j=0; j<t; j++)z.child[j]=y.child[j+t];
            }
            y.n=t-1;

            for(int j=n; j>=i+1; j--)child[j+1]=child[j];
            child[i+1]=z;

            for(int j=n-1; j>=i; j--)keys[j+1]=keys[j];
            keys[i]=y.keys[t-1];
            n++;
        }
        public void insertNonFull(int k){
            int i=n-1;
            if(leaf){
                while(i>=0 && keys[i]>k){
                    keys[i+1]=keys[i];
                    i--;
                }
                keys[i+1]=k;
                n++;
            }
            else{
                while(i>=0 && keys[i]>k)i--;
                if(child[i+1].n==2*t-1){
                    splitChild(i+1, child[i+1]);
                    if(keys[i+1]<k)i++;
                }
                child[i+1].insertNonFull(k);
            }
        }
    }

    static class Btree{
        BTreeNode root;
        int t;

        public Btree(int _t){
            t=_t;
            root=null;
        }
        public void traverse(){
            if(root!=null)root.traverse();
        }
        public void insert(int k){
            if(root==null){
                root=new BTreeNode(t, true);
                root.keys[0]=k;
                root.n=1;
            }
            else{
                if(root.n==2*t-1){
                    BTreeNode s=new BTreeNode(t, false);
                    s.child[0]=root;
                    s.splitChild(0, root);
                    if(k<s.keys[0])s.child[0].insertNonFull(k);
                    else s.child[1].insertNonFull(k);
                    root=s;
                }
                else root.insertNonFull(k);
            }
        }
    }

    public static void main(String[] args){
        Btree b=new Btree(3);
        Scanner in=new Scanner(System.in);
        char ans='y';
        while(ans=='y'){
            int t=in.nextInt();
            b.insert(t);
            ans=in.next().charAt(0);
        }
        b.traverse();
    }
}
