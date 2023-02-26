package lab1;

import java.util.Scanner;

public class Temperature {
    public static void main(String[] args) {
//        a) compute and output the celsius equivalent of an input Fahrenheit temperature,
//                using the calculation
//        C = 5.0 / 9.0 * ( F - 32 );
        Scanner input = new Scanner(System.in);
        double fahrenheit;
        double celsius;

//        b) compute and output Fahrenheit the equivalent of an input celsius temperature,
//                using the calculation
//        F = 9.0 / 5.0 * C + 32;

//        c) Use the methods from parts (a) and (b) to write an application that enables the
//        user either to enter a Fahrenheit temperature and display the Celsius equivalent
//        or to enter a Celsius temperature and display the Fahrenheit equivalent.
        System.out.println("Input 1 for Fahrenheit to Celsius" +
                            "or 2 for Celsius to Fahrenheit: ");
        int option = input.nextInt();
        if(option == 1 ) {
            //a)
            System.out.println("Input degrees Fahrenheit: ");
            fahrenheit = input.nextDouble();

            celsius = 5.0 / 9.0 * (fahrenheit - 32.);
            System.out.printf("\n Celsius: %.2f",celsius );
        }
        else if(option == 2) {
            //b)
            System.out.println("Input degrees Celsius: ");
            celsius = input.nextDouble();

            fahrenheit = 9.0 / 5.0 * celsius + 32;
            System.out.printf("\n Fahrenheit: %.1f",fahrenheit);
        }
        else {
            System.out.println("Invalid output");
        }

        //format specifiers:
        //%s - string
        //%d - int
        //%f - double/float -> %.2f - 2 символа след десетичната запетая
                        //  -> %.0f - 0 символа след десетичната запетая
        //\n - new line
    }
}
