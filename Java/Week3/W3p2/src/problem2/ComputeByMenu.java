package problem2;
import java.util.Scanner;
public class ComputeByMenu {
    private Scanner input;
    private double x;
    private int userChoise;

    public ComputeByMenu(double x) {
        input = new Scanner((System.in));
        setX(x);
    }
    public  double getX(){
        return  x;
    }
    public void setX(double x) {
        this.x  = x;
    }
    public void displayMenu() {
        for (int i = 0; i < 50; i++) {
            System.out.println();
        }
        System.out.println(
                "1. Update floating point number \n" +
                   "2. Compute and display exp(x) \n" +
                        "3.Compute and display sin(x) \n" +
                        "4. Compute and display floor(x) \n" +
                        "5. Exit");
    }

    public void  doSelection(int choice) {
        switch (choice) {
            case 1:
                System.out.print("Enter x: ");
                x = input.nextDouble();
                break;
            case 2:
                System.out.printf("Exp(%.2f) = %.2f%n", x, Math.exp(x));
                break;
            case 3:
                System.out.printf("Sin(%.2f) = %.2f%n", x, Math.sin(x));// in radians
                //Math.toRadians(x) to convert degrees to radians
                break;
            case 4:
                System.out.printf("Floor(%.4f) = %.4f%n", x, Math.floor(x));
                break;
            case 5:
                System.exit(0);
        }
        System.out.println("Press Enter to continue...");
        input.nextLine();
        input.nextLine();
        displayMenu();
    }

    public int getUserChoice() {
        while(true) {
            displayMenu();
            do {
                System.out.println("Select a menu option: ");
                userChoise = input.nextInt();
            } while (userChoise < 1 || userChoise > 5);
            doSelection(userChoise);
        }
    }

}
