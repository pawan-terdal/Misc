import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class SwingApplet extends JApplet
{
    JButton btn1,btn2;
    JLabel jlab;

    public void init()
    {
        try
        {
            SwingUtilities.invokeAndWait(new Runnable() {
                public void run()
                {
                    makeGUI();
                }
            });
        }
        catch(Exception e)
        {

        }
    }

    public void makeGUI()
    {
        setLayout(new FlowLayout());
        jlab = new JLabel("");
        btn1 = new JButton("Alpha");
        btn2 = new JButton("Beta");
        btn1.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent le)
            {
                jlab.setText("Alpha pressed");
            }
        });
        btn2.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent le)
            {
                jlab.setText("Beta pressed");
            }
        });
        add(btn1);
        add(btn2);
        add(jlab);
    }
}
