package months;

public class MonthsTest {
    public static void main(String[] args) {
        System.out.println(Months.JAN);
        System.out.println();

        for(Months m : Months.values()) {
            System.out.println(m);
        }
    }
}
