package P1A;

public class Rectangle {
    private double width;
    private double height;
    static String color;

    public Rectangle() {
        this(1.0, 1);
    }

    public Rectangle(double width, double height) {
        setWidth(width);
        setHeight(height);
        setColor("yellow");
    }

    public void setWidth(double width) {
        if(width > 0) {
            this.width = width;
        }else {
            this.width = 1;
        }
    }

    public double getWidth() {
        return width;
    }

    public double getHeight() {
        return height;
    }


    public void setHeight(double height) {
        if (height > 0) {
            this.height = height;
        } else {
            this.height = 1;
        }
    }

    public static void setColor(String color) {
        if (color == null) {
            Rectangle.color = "yellow";
        } else {
            Rectangle.color = color;
        }
    }

    public static String getColor() {
        return color;
    }

    public double getArea() {

        return width * height;
    }

    public double getPerimeter() {
        return 2* (width + height);
    }
    @Override
    public String toString() {
        return String.format("width %f," + "height %f, color: %s", width,height,color );
    }
}
