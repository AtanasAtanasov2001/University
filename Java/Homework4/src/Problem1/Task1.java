package Problem1;

import java.util.Scanner;

public class Task1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Byte num1 = in.nextByte();
        Byte num2 = in.nextByte();
            int x = num1 ^ num2;
            int setBits = 0;

            while (x > 0)
            {
                setBits += x & 1;
                x >>= 1;
            }
            String num1Binary = String.format("%8s", Integer.toBinaryString(num1 & 0xFF)).replace(' ', '0');
            String num2Binary = String.format("%8s", Integer.toBinaryString(num2 & 0xFF)).replace(' ', '0');
            String toReturn = "The Hamming distance between number1: " + num1Binary + " and number2: " + num2Binary + " is: " + setBits;
            System.out.println( toReturn);
    }

}


