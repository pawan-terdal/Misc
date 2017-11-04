import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

class SwingDemo
{
    SwingDemo()
    {
        JFrame jfrm = new JFrame("Simple Swing APP");
        jfrm.setLayout(new FlowLayout());
        jfrm.setSize(275, 100);
        jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JLabel jlab = new JLabel("LOL");
        jfrm.add(jlab);
        JButton btn1 =  new JButton("Alpha");
        JButton btn2 = new JButton("Beta");
        btn1.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ae)
            {
                jlab.setText("Alpha pressed.");
            }
        });
        btn2.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ae)
            {
                jlab.setText("Beta pressed.");
            }
        });
        jfrm.add(btn1);
        jfrm.add(btn2);
        jfrm.setVisible(true);

    }
}

class SimpleSwing
{
    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run()
            {
                new SwingDemo();
            }
        });
    }
}
