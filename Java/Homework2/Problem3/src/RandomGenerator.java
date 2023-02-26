import java.util.Random;
import java.text.NumberFormat;
import java.util.Scanner;

public class RandomGenerator {
    public static  int randomNumberRange(int min, int max) {

        int n = (max + 1 - min) + min;
        return (int)(Math.random()* n);
    }
    public static int drawRandomNumber() {
            int num = randomNumberRange(0,99);

            if (num >= 0 && num <= 20) {
                return  1;
                //System.out.print(1 + " ");
            }
            else if ( num >= 21 && num <= 50) {
                return  2;
                //System.out.print(2 + " ");
            }
            else if(num >= 51 && num < 100 ){
                return  3;
                //System.out.print(3 + " ");
            }
            return num;
    }
    public static void main(String[] args) {
        int countOnes = 0;
        int countTwos = 0;
        int countThrees = 0;
        double n;
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the number of numbers: ");
        n = input.nextDouble();

        for(int i = 0; i < n; i++) {
            int num = drawRandomNumber();
            if(num == 1) {
                countOnes++;
            }
            else if(num == 2) {
                countTwos++;
            }
            else if (num == 3) {
                countThrees++;
            }
            else {
                System.out.println(num);
            }

        }
        System.out.println(countOnes);
        System.out.println(countTwos);
        System.out.println(countThrees);
        double counterOnes = countOnes/n;
        double counterTwos = countTwos/n;
        double counterThrees = countThrees/n;
        NumberFormat defaultFormat = NumberFormat.getPercentInstance();
        defaultFormat.setMinimumFractionDigits(3);
        System.out.println("Percentage of ones: " + defaultFormat.format(counterOnes) );
        System.out.println("Percentage of twos: " + defaultFormat.format(counterTwos) );
        System.out.println("Percentage of threes: " + defaultFormat.format(counterThrees) );
    }
}
