package main.main;

import com.Tabulate;
import com.Functions;
import functions.Computable;

public class TabulateTest {
    public static void main(String[] args) {
        Tabulate tabulate = new Tabulate(new Functions().getExpFunction());
        tabulate.tabulate(0,10,5);

        Tabulate.tabulateFunction(1, 10, 1, new Computable() {
            @Override
            public double function(double x) {
                return 1/x;
            }
        });
    }
}
