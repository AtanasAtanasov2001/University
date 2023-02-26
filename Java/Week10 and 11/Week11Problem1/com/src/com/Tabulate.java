package com;

import functions.Computable;

import java.util.Scanner;

public class Tabulate {
    private Computable callback;

    public Tabulate(Computable callback) {
       setCallback(callback);
    }

    public Computable getCallback() {
        return callback;
    }

    public void setCallback(Computable callback) {
        if(callback != null) {
            this.callback = callback;
        } else {
            Functions f = new Functions();
            this.callback = f.getSinFunction();
        }
    }
    public void tabulate( double a, double b, int steps) {
        tabulateFunction(a,b,steps,callback);
    }
    public static void tabulateFunction(double a, double b, int steps, Computable computable) {
        if(steps < 0) {
            System.out.println("Please enter a well defined step! ");
            return;
        }
        if(a >= b) {
            System.out.println("Please enter a well defined interval! ");
            return;
        }

        Scanner input = new Scanner(System.in);
        System.out.printf("%10s%10s%n", "X", "F(X)");
        System.out.printf("%10.2f%10.2f%n", a, computable.function(a));
        double size = (b - a) / steps;
        for (int i = 1; i <= size ; i++) {
            double x = a + i * steps;
            double y = computable.function(x);
            System.out.printf("%10.2f%10.2f%n", x , y);
            if(i % 20 == 0) {
                System.out.println("Please press Enter to continue");
                input.nextLine();
            }
        }
    }
}
