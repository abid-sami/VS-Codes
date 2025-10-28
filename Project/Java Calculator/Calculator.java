import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Calculator implements ActionListener{
    JFrame f;
    Container c;
    JLabel ib1,ib2,ib3;
    JTextField tf1,tf2;
    JPanel p;
    JButton[] btn;
    boolean firstSelected=true;
    String[] ch={"+","-","*","/","0","1","2","%","3","4","5",".","6","7","8","9"};

    Calculator(){
        f=new JFrame("Calculator");
        f.setBounds(100,200,300,400);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setResizable(false);

        c=f.getContentPane();
        c.setLayout(null);

        ib1=new JLabel("Num 1");
        ib1.setBounds(10,10,60,30);

        tf1=new JTextField();
        tf1.setBounds(80,10,195,30);

        ib2=new JLabel("Num 2");
        ib2.setBounds(10,50,60,30);

        tf2=new JTextField();
        tf2.setBounds(80,50,195,30);

        ib3=new JLabel("Result : ");
        ib3.setBounds(10,90,265,30);

        p=new JPanel();
        p.setLayout(new GridLayout(4,4,2,2));
        p.setBounds(10,130,265,200);
        p.setBackground(Color.BLACK);

        c.add(ib1);
        c.add(tf1);
        c.add(ib2);
        c.add(tf2);
        c.add(ib3);
        c.add(p);

        btn=new JButton[16];
        for(int i=0;i<16;i++){
            btn[i]=new JButton(ch[i]);
            btn[i].addActionListener(this);
            p.add(btn[i]);
        }

        tf1.addMouseListener(new MouseAdapter(){
            public void mouseClicked(MouseEvent e){
                firstSelected=true;
            }
        });

        tf2.addMouseListener(new MouseAdapter(){
            public void mouseClicked(MouseEvent e){
                firstSelected=false;
            }
        });

        f.setVisible(true);
    }

    public void actionPerformed(ActionEvent e){
        String v;
        double num1,num2;

        if(e.getSource()==btn[0]){
            v=tf1.getText();
            num1=Double.parseDouble(v);
            v=tf2.getText();
            num2=Double.parseDouble(v);
            double result=num1+num2;
            ib3.setText("Result : "+result);
        }

        if(e.getSource()==btn[1]){
            v=tf1.getText();
            num1=Double.parseDouble(v);
            v=tf2.getText();
            num2=Double.parseDouble(v);
            double result=num1-num2;
            ib3.setText("Result : "+result);
        }

        if(e.getSource()==btn[2]){
            v=tf1.getText();
            num1=Double.parseDouble(v);
            v=tf2.getText();
            num2=Double.parseDouble(v);
            double result=num1*num2;
            ib3.setText("Result : "+result);
        }

        if(e.getSource()==btn[3]){
            v=tf1.getText();
            num1=Double.parseDouble(v);
            v=tf2.getText();
            num2=Double.parseDouble(v);
            double result=num1/num2;
            ib3.setText("Result : "+result);
        }

        if(e.getSource()==btn[7]){
            v=tf1.getText();
            num1=Double.parseDouble(v);
            v=tf2.getText();
            num2=Double.parseDouble(v);
            double result=num1%num2;
            ib3.setText("Result : "+result);
        }

        for(int i=4;i<16;i++){
            if(e.getSource()==btn[i]){
                String current;
                if(firstSelected){
                    current=tf1.getText();
                    current=current+ch[i];
                    tf1.setText(current);
                }else{
                    current=tf2.getText();
                    current=current+ch[i];
                    tf2.setText(current);
                }
            }
        }
    }

    public static void main(String[] args){
        new Calculator();
    }
}
