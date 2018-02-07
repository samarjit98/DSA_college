/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package awtappl1;
import java.awt.*;
import java.awt.event.*;
import javax.swing.BoxLayout;
/**
 *
 * @author c167256
 */

class Dial extends Dialog implements ActionListener{
    Button b;
    Label l;
    String s1, s2;
    Dial(Fram f, String s1, String s2){
        super(f, "Java Dialog");
        this.s1=s1; this.s2=s2;
    }
    public void activate(){
        b=new Button(s2);
        l=new Label(s1);
        b.addActionListener(this);
        add(l, BorderLayout.NORTH);
        add(b, BorderLayout.SOUTH);
        setSize(200, 200);
        setVisible(true);
    }
    @Override
    public void actionPerformed(ActionEvent e){
        setVisible(false);
    }
}
class Fram extends Frame implements ActionListener{
    Button b;
    Label[] l;
    TextField[] tf;
    Dial err, d;
    public void activate(){
        err=new Dial(this, "Error: Recheck form", "OK");
        d=new Dial(this, "Success", "OK");
        b=new Button("Check");
        b.addActionListener(this);
        tf=new TextField[4];
        l=new Label[4];
        l[0]=new Label("Name:"); l[1]=new Label("Roll:"); l[2]=new Label("Email:"); l[3]=new Label("Password");
        for(int i=0; i<4; i++){tf[i]=new TextField(20); add(l[i]); add(tf[i]);}
        setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
        add(b, BorderLayout.SOUTH);
        setSize(500, 500);
        setVisible(true);
    }
    @Override
    public void actionPerformed(ActionEvent e){
        if("oop".equals(tf[3].getText()))d.activate();
        else err.activate();
    }
}
public class AwtAppl1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Fram f=new Fram();
        f.activate();
    }
    
}
