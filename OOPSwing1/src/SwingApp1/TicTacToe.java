package SwingApp1;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class Dial extends JDialog implements ActionListener{
    JLabel l;
    JButton b;

    Dial(String s){
        l=new JLabel(s);
        b=new JButton("OK");
        b.addActionListener(this);
        add(b, BorderLayout.SOUTH);
        add(l, BorderLayout.NORTH);
        setSize(300, 300);
        setVisible(true);
    }
    public void actionPerformed(ActionEvent e){
        dispose();
    }
}

class F extends JFrame implements MouseListener, ActionListener{
    JLabel[][] labels;
    JTextField tf;
    JPanel p;
    JButton b;
    int[][] mirror;
    int chance;
    int round;

    F(){
        labels=new JLabel[3][3];
        for(int i=0; i<3; i++)for(int j=0; j<3; j++)labels[i][j]=new JLabel(Integer.toString(i+j+1));
        tf=new JTextField("TIC TAC TOE");
        b=new JButton("Exit Game");
        mirror=new int[3][3];
        chance=0;
        round=0;
    }
    public void init(){
        p=new JPanel();
        p.setLayout(new GridLayout(3, 3));
        for(int i=0; i<3; i++)for(int j=0; j<3; j++)labels[i][j].addMouseListener(this);
        for(int i=0; i<3; i++)for(int j=0; j<3; j++)p.add(labels[i][j]);
        b.addActionListener(this);
        add(p, BorderLayout.CENTER);
        add(tf, BorderLayout.NORTH);
        add(b, BorderLayout.SOUTH);
        setSize(500, 500);
        setVisible(true);
    }
    public void actionPerformed(ActionEvent e){
        dispose();
    }
    public void mouseClicked(MouseEvent e){
        tf.setText("TIC TAC TOE");
        for(int i=0; i<3; i++)for(int j=0; j<3; j++){
            if(e.getSource()==labels[i][j]){
                if(mirror[i][j]==0){
                    mirror[i][j]=chance+1;
                    if(chance==0){
                        labels[i][j].setText("X");
                        chance=1;
                    }
                    else {
                        labels[i][j].setText("O");
                        chance = 0;
                    }
                }
                else{
                    tf.setText("Wrong Label!");
                    return;
                }
            }
        }
        round++;
        int flag=0;
        for(int i=0; i<3; i++)if(mirror[i][0]==mirror[i][1] && mirror[i][1]==mirror[i][2] && mirror[i][0]!=0)flag=1;
        for(int i=0; i<3; i++)if(mirror[0][i]==mirror[1][i] && mirror[1][i]==mirror[2][i] && mirror[0][i]!=0)flag=1;
        if((mirror[0][0]==mirror[1][1] && mirror[1][1]==mirror[2][2] && mirror[1][1]!=0)||(mirror[0][2]==mirror[1][1] && mirror[1][1]==mirror[2][0] && mirror[1][1]!=0))flag=1;
        if(flag==1){
            if(chance==0){
                Dial d=new Dial("Winner is O!");
            }
            else{
                Dial d=new Dial("Winner is X!");
            }
        }
        else if(round==9){
            Dial d=new Dial("Game ends in a Draw!");
        }
    }
    public void mouseEntered(MouseEvent e){

    }
    public void mouseExited(MouseEvent e){

    }
    public void mousePressed(MouseEvent e){

    }
    public void mouseReleased(MouseEvent e){

    }
}

public class TicTacToe {
    public static void main(String[] args){
        F obj=new F();
        obj.init();
    }
}
