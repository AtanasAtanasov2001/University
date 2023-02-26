package zad9;

public class RecursiveSums {
    public static void main(String[] args) {
        System.out.printf("%-10s%-10s\n", "i", "sum");
        for (int i = 0; i < 11; i++) {
            System.out.printf("%-10d%-10.2f\n", i, computeSum(i));
        }
    }
    private static double computeSumIterative(int i){
        double result = 0;
        while(i > 0) {
            result += i / ( 2.0 * i + 1);
            i--;
        }
        return result;
    }
    private static double computeSum(int i){
        if(i <= 0) {
            return 0;
        }
        return i / ( 2.0 * i + 1) + computeSum(i - 1 );
    }
}
