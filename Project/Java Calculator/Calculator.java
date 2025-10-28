
package calculator;

import javax.swing.*;
import java.awt.*;

import java.awt.event.*;

public class Calculator implements ActionListener {
    JFrame f;
    Container c;
    JLabel lb1, lb2, lb3;
    JTextField tf1, tf2;
    JPanel p;
    JButton[] btn;
    String[] ch = {"+", "-", "*", "/",
                   "0", "1", "2", "%",
                   "3", "4", "5", ".",
                   "6", "7", "8","9"};
    Calculator()
    {
        f = new JFrame("Calculator");
        f.setBounds(100, 200, 300, 400);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        c = f.getContentPane();
        c.setLayout(null);
        
        lb1 = new JLabel("Number 1");
        lb1.setBounds(10, 10, 60, 30);
        
        tf1 = new JTextField();
        tf1.setBounds(80, 10, 195, 30);
        
        lb2 = new JLabel("Number 2");
        lb2.setBounds(10, 50, 60, 30);
        
        tf2 = new JTextField();
        tf2.setBounds(80, 50, 195, 30);
        
        lb3 = new JLabel("Result:   ");
        lb3.setBounds(10, 90, 200, 30);
        
        p = new JPanel();
        p.setLayout(new GridLayout(4, 4, 2, 2));
        p.setBounds(10, 130, 265, 200);
        //p.setBackground(Color.BLACK);
        
        c.add(lb1);
        c.add(tf1);
        c.add(lb2);
        c.add(tf2);
        c.add(lb3);
        c.add(p);
        
        btn = new JButton[16];
        
        for(int i=0; i<16; i++)
        {
            btn[i] = new JButton();
            btn[i].setText(ch[i]);
            btn[i].addActionListener(this);
            p.add(btn[i]);
        }
        
        f.setVisible(true);
    }
    public void actionPerformed(ActionEvent e)
    {
        String v;
        int num1, num2, result;
        if(e.getSource()==btn[0])
        {
            v = tf1.getText();
            num1 = Integer.parseInt(v);
            
            v = tf2.getText();
            num2 = Integer.parseInt(v);
            
            result = num1 + num2;
            v = Integer.toString(result);
            v = "Result:         "+v;
            lb3.setText(v);
            
        }
        if(e.getSource()==btn[1])
        {
            v = tf1.getText();
            num1 = Integer.parseInt(v);
            
            v = tf2.getText();
            num2 = Integer.parseInt(v);
            
            result = num1 - num2;
            v = Integer.toString(result);
            v = "Result:         "+v;
            lb3.setText(v);  
        }
        if(e.getSource()==btn[2])
        {
            v = tf1.getText();
            num1 = Integer.parseInt(v);
            
            v = tf2.getText();
            num2 = Integer.parseInt(v);
            
            result = num1 * num2;
            v = Integer.toString(result);
            v = "Result:         "+v;
            lb3.setText(v);  
        }
        if(e.getSource()==btn[3])
        {
            v = tf1.getText();
            num1 = Integer.parseInt(v);
            
            v = tf2.getText();
            num2 = Integer.parseInt(v);
            
            result = num1 / num2;
            v = Integer.toString(result);
            v = "Result:         "+v;
            lb3.setText(v);  
        }
        if(e.getSource()==btn[2])
        {
            v = tf1.getText();
            num1 = Integer.parseInt(v);
            
            v = tf2.getText();
            num2 = Integer.parseInt(v);
            
            result = num1 * num2;
            v = Integer.toString(result);
            v = "Result:         "+v;
            lb3.setText(v);  
        }
    }
    public static void main(String[] args) {
        Calculator test = new Calculator();
    }
    
}
