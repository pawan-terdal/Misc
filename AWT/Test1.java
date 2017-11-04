import java.awt.*;
import java.awt.event.*;

class MyWindowListener extends WindowAdapter
{
    @Override
    public void windowClosing(WindowEvent arg0) {
        System.exit(0);
    }
}

class Test1 extends Frame
{
    Test1()
    {
        super();
        setVisible(true);
        setBackground(Color.white);
        setTitle("LOL");
        setSize(500,500);
    }
    public static void main(String[] args) {
        Test1 myFrame = new Test1();
        myFrame.setLayout(new FlowLayout());
        Label l1 = new Label("Username");
        Label l2 = new Label("Password");

        TextField t1 = new TextField(50);
        TextField t2 = new TextField(50);
        t2.setEchoChar('*');
        Button b1 = new Button("SIGN UP");

        //Checkbox
        Checkbox cb1 = new Checkbox("Soccer");
        Checkbox cb2 = new Checkbox("Cricket");

        //Radio Buttons
        CheckboxGroup cg = new CheckboxGroup();
        Checkbox rb1 = new Checkbox("Male", cg, true);
        Checkbox rb2 = new Checkbox("Female", cg, false);

        // Login Form
        myFrame.add(l1);
        myFrame.add(t1);
        myFrame.add(l2);
        myFrame.add(t2);
        myFrame.add(b1);

        //Checkbox
        myFrame.add(cb1);
        myFrame.add(cb2);

        // Radio Buttons
        myFrame.add(rb1);
        myFrame.add(rb2);

        //Adding Adapter - Two ways
        //myFrame.addWindowListener(new MyWindowListener());
        myFrame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent arg0) {
                System.exit(0);
            }
        });
    }
}
