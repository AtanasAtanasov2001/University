/* Chapter 2 of Java How to Program: Fourth Edition
 Debugging Problem */
package lab1;
import java.util.Scanner;
public class Arithmetic {
   public static void main( String[] args )
   {
     
      int num1,num2, num3, sum, product;
      double average;
      Scanner input = new Scanner(System.in);
       System.out.println("Enter first integer: ");
      num1  =   input.nextInt( );
       System.out.println("Enter second integer:");
      num2  =  input.nextInt(  );
       System.out.println("Enter third integer:");
      num3 = input.nextInt( );
  
 
      
      sum = num1 + num2 + num3;
      product = num1 * num2 * num3;
      average = ( num1 + num2 + num3 ) / 3.0;
      
      System.out.println( "The sum is " + sum +
         "\nThe product is " + product +  "\nThe average is "
          + average);
   }

} // end class Arithmetic

