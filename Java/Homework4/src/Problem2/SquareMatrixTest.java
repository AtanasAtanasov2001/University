package Problem2;

import java.util.Random;
import java.util.Scanner;


public class SquareMatrixTest {
    public static void main(String[] args) {


        Random randomNumber = new Random();
        int size = randomNumber.nextInt(2,13);

        Random helper = new Random();
        int[][] grid = new int[size][size];
        for(int i = 0;i < size; i++)
        {
            for(int j = 0;j < size; j++)
            {
                grid[i][j]= helper.nextInt(9);
                System.out.print(grid[i][j]+"\t");
            }

            System.out.print("\n");
        }
        SquareMatrix matrix = new SquareMatrix (grid,size);
//        System.out.println(matrix.toString(grid));
          System.out.println(matrix.findMaxSum(grid));
        //System.out.println(matrix.toString(matrix.findMaxSubMatrix(grid,2)));
          matrix.printAll();
    }
}
