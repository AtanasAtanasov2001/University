package zad5;

public class FindMaxTest {
    public static <E extends Comparable<E>> E max(E[][] list) {
        E max = list[0][0];
        
        for (int i = 0; i < list.length; i++) {
            for (int j = 0; j < list[i].length; j++) {
                if(list[i][j].compareTo(max) > 0) {
                    max = list[i][j];
                }
            }
        }
        return max;
    }

    public static void main(String[] args) {
        Integer[][] integers = {
                {1,2,3},
                {4,50,6},
                {7,8,9}
        };
        System.out.printf("Max element is %d\n", max(integers));

        String[][] strings = {
                {"a","b","c"},
                {"zd","e","f"}
        };
        System.out.printf("Max element is %s\n", max(strings));
    }
}
