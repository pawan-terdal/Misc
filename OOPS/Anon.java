import java.awt.*;
import java.applet.*;
import java.awt.event.*;

public class Anon extends Applet
{
    public void init()
    {
        addMouseListener(new MouseAdapter() {
            public void mousePressed(MouseEvent me)
            {
                showStatus("MousePressed.");
            }
        });
    }
}
