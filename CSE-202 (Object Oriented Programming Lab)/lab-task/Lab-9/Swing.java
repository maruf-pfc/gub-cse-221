import javax.swing.*;
import java.awt.*;
import java.util.*;

public class Swing extends JFrame{
    public ImageIcon img;
    public Container c;
    public JLabel name;
    public JLabel imagelabel;

    Swing(){
        iconset();
    }

    public void iconset(){
        c = this.getContentPane();
        c.setLayout(null);
        c.setBackground(Color.yellow);

        img = new ImageIcon(getClass().getResource("calculator.jpg"));
        name = new JLabel(img);
        
        name = new JLabel("Enter your name: ");
        name.setBounds(20, 5, 150, 200);
        c.add(name);

        imagelabel = new JLabel();
        img = new ImageIcon("calculator.jpg");
        imagelabel.setIcon(img);
        imagelabel.setBounds(20, 30, 150, 200);
        c.add(imagelabel);
    }
    
    public static void main(String[] args) {
        Swing frame = new Swing();

        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        frame.setSize(300, 200);
        frame.setLocationRelativeTo(null);
        frame.setTitle("Swing");
    }
}