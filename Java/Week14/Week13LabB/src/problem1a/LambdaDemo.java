package problem1a;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.function.Consumer;
import java.util.function.DoubleToIntFunction;
import java.util.function.Predicate;

public class LambdaDemo {
    public static void main(String[] args)
    {
        Predicate<Salesperson> predicate1 =
                salesperson -> salesperson.getNumSales() > 1200;
// да се инициализира
        Predicate<Salesperson> predicate2 =
                salesperson -> salesperson.getSalary() > 900;;
// да се инициализира
        Predicate<Salesperson> predicate =
                salesperson -> predicate1.test(salesperson) || predicate2.test(salesperson);
// да се инициализира
        Consumer<Salesperson> consumer1 = salesperson -> {
            salesperson.addBonus(salesperson.getSalary() * 0.05);
            System.out.println(salesperson);
        };
// да се инициализира
        Consumer<Salesperson> consumer2 = salesperson -> {

            if (predicate.test(salesperson)) {
                salesperson.addBonus(salesperson.getSalary() * 0.02);
            } else {
                salesperson.addBonus(-salesperson.getSalary() * 0.02);
            }

            System.out.println(salesperson);
        };
// да се инициализира
        Comparator<Salesperson> comparator1 =
                (s1,s2) -> Double.compare(s2.getSalary(),s1.getSalary());
// да се инициализира
        Comparator<Salesperson> comparator2 = (s1,s2) -> {
            if (Double.compare(s2.getSalary(), s1.getSalary()) == 0)
                return s1.getNumSales() - s2.getNumSales();
            else  return Double.compare(s2.getSalary(),s1.getSalary());
        };
// да се инициализира
        Salesperson[] salespersons =
                {
                        new Salesperson("John Doe", 2000, 949),
                        new Salesperson("Jane Doe", 3900, 1500),
// да се добавят още 10 обекти от тип Salesperson
// или да се инициализират с Random стойности
                };
        List<Salesperson> listOfSalespersons = new ArrayList<>();
// обектите на salespersons да се запишат в listOfSalespersons
        for (Salesperson salesperson: salespersons)
        {
            applyBonus(salesperson, predicate1, consumer1);
            System.out.println(salesperson);
            salesperson.printNumSales(salesperson);
        }
        for (Salesperson salesperson: salespersons)
        {
            applyBonus(salesperson, predicate2, consumer2);
            System.out.println(salesperson);
        }
        sort(listOfSalespersons, comparator1);
        System.out.println(listOfSalespersons);
        sort(listOfSalespersons, comparator2);
        System.out.println(listOfSalespersons);
    }
    public static void applyBonus(Salesperson salesperson,
                                  Predicate<Salesperson> predicate,
                                  Consumer<Salesperson> consumer)
    {
// Напишете if команда, където използвайте predicate
// за да определите дали да изпълните consumer
// Изпълнете consumer, когато условието на if командата е изпълнено

        if(salesperson == null || predicate==null || consumer == null)
            return;
        if(predicate.test(salesperson)) consumer.accept(salesperson);
    }
    public static void applyBonus(List<Salesperson> salespersons,
                                  Predicate<Salesperson> predicate,
                                  Consumer<Salesperson> consumer)
    {
// Напишете if команда, където използвайте predicate
// за да определите дали да изпълните consumer
// Изпълнете consumer, когато условието на if командата е изпълнено

    }
    public static void sort(List<Salesperson> salespersons,
                            Comparator<Salesperson> comparator)
    {
// Сортирайте salespersons като използвате comparator
    }
    public static void group(List<Salesperson> salespersons)
    {
// Групирайте имената на salespersons по първата буква в
// името изведете отделните групи на стандартен изход
    }
}
