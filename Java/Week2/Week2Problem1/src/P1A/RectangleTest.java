package P1A;

import java.util.Scanner;

public class RectangleTest {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Input width: ");
        double width = input.nextDouble();
        System.out.print("Input height: ");
        double height = input.nextDouble();

        Rectangle rectangle = new Rectangle(width, height);

        System.out.println(rectangle);
        System.out.println("Area: " + rectangle.getArea());
        System.out.println("Perimeter: " + rectangle.getPerimeter());

        Rectangle rectangle1 = new Rectangle();
        //in the constructor we make the color yellow

        Rectangle.setColor("red");
        System.out.println(rectangle1.toString());
    }
}
