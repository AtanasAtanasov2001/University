package Problem2;

public class SquareMatrix {
    private int[][] dataArray;
    private int size;

    public SquareMatrix() {
        this.dataArray = new int[0][0];
        this.size = 0;
    }
    public SquareMatrix(int[][] dataArray,int size) {
        this.dataArray = dataArray;
        this.size = size;
    }

    public int[][] getDataArray() {
        return dataArray;
    }

    public void setDataArray(int[][] dataArray) {
        if(size < 0) {
            this.dataArray = new int[0][0];
        } else {
            this.dataArray = dataArray;
        }
    }

    public SquareMatrix(SquareMatrix other) {
        this.size = other.size;
        setDataArray(other.getDataArray());
    }

    //@Override
    public String toString(int[][] grid) {
        String str = new String();
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid.length; j++) {
                str += String.valueOf(grid[i][j]);
                str += " ";
            }
            str += "\n";
        }

        return str.toString();
    }
    public int findMaxSum(int[][] mat) {
        //System.out.println(toString(subMatrix));
        int sum = 0;

        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - 1; j++) {
                int tempSum = 0;
                tempSum += mat[i][j];
                tempSum += mat[i+1][j];
                tempSum += mat[i][j+1];
                tempSum += mat[i+1][j+1];
                if(tempSum > sum) {
                    sum = tempSum;
                }
            }
        }
        return sum;
    }
    public void printAll(){
        System.out.println("Maximum sum: " + findMaxSum(getDataArray()));
        int [][] maxSubmatrix = new int[2][2];
        int maxSum = findMaxSum(getDataArray());
        System.out.println("Submatrixes with maximum sum:" );
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - 1; j++) {
                int tempSum = 0;
                tempSum += getDataArray()[i][j];
                tempSum += getDataArray()[i+1][j];
                tempSum += getDataArray()[i][j+1];
                tempSum += getDataArray()[i+1][j+1];
                if(tempSum == maxSum) {
                    System.out.println("[" + i +", "+ j + "]");
                }
            }
        }
    }
}
