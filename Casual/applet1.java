import java.awt.*;
import java.applet.*;

public class applet1 extends Applet
{
    String msg;
    public void init()
    {
        setBackground(Color.cyan);
        setForeground(Color.blue);
        msg = "Init";
    }

    public void start()
    {
        msg += " Start";
    }

    public void paint(Graphics g)
    {
        msg += " Paint";
        g.drawString(msg, 10, 30);
    }
}
