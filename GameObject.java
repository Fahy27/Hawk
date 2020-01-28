import java.awt.*;
public class GameObject {
    private int x, y;

    private Color c;


    public GameObject()
    {
        int color1 = (int)(Math.random() * 256);
        int color2 = (int)(Math.random() * 256);
        int color3 = (int)(Math.random() * 256);

        c = new Color(color1, color2, color3);

        x = (int)(Math.random() * 580);
        y = (int)(Math.random() * 580);





    }

    public void move()
    {
        x += (int) ((Math.random()*10)-(Math.random()*10));
        y += (int) ((Math.random()*10)-(Math.random()*10));


    }





    public void paint(Graphics g)
    {
        g.setColor(c);
        g.fillRect(x, y, 20, 20);

    }


}
