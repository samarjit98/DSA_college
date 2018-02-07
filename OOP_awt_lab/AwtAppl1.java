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

class Dial1 extends Dialog implements ActionListener{
    Button b;
    Label l;
    String s1, s2;
    Dial1(Fram f, String s1, String s2){
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
class Dial2 extends Dialog implements ActionListener{
    Button b;
    Label[] l;
    Fram f;
    Dial2(Fram f){
        super(f, "Java Dialog");
        this.f=f;
    }
    public void activate(){
        b=new Button("Done");
        l=new Label[10];
        b.addActionListener(this);
        for(int i=0; i<4; i++){l[i]=new Label(f.l[i].getText()+" "+f.tf[i].getText()); add(l[i]);}
        l[4]=new Label(f.l[4].getText()+" "+f.gender.getSelectedItem()); add(l[4]);
        setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
        add(b);
        setSize(400, 400);
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
    Choice gender;
    public void activate(){
        b=new Button("Check");
        b.addActionListener(this);
        tf=new TextField[4];
        l=new Label[5];
        l[0]=new Label("Name:"); l[1]=new Label("Roll:"); l[2]=new Label("Email:"); l[3]=new Label("Password:"); l[4]=new Label("Gender:");
        for(int i=0; i<4; i++){tf[i]=new TextField(20); add(l[i]); add(tf[i]);}
        gender=new Choice();
        gender.add("Male"); gender.add("Female"); gender.add("Other");
        add(l[4]);
        add(gender);
        setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
        add(b, BorderLayout.SOUTH);
        setSize(500, 500);
        setVisible(true);
    }
    @Override
    public void actionPerformed(ActionEvent e){
        if("oop".equals(tf[3].getText())){
            Dial2 d=new Dial2(this);
            d.activate();
        }
        else{
            Dial1 err=new Dial1(this, "Error: Recheck Form", "OK");
            err.activate();
        }
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
