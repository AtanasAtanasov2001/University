package zad3;

import java.util.ArrayList;
import java.util.List;

public class RemoveDublicateTest {

    public static <E>ArrayList removeDublicates(ArrayList<E> list) {
        ArrayList<E> uniques = new ArrayList<>();
        for (E item : list) {
            if(!uniques.contains(item)) {
                uniques.add(item);
            }
        }
        return uniques;
    }

    public static void main(String[] args) {
        ArrayList<Integer> integers = new ArrayList<>(List.of(1,1,1,2,3,4,2,3,4,1));
        System.out.printf("List: %s\n", integers);
        System.out.printf("Unique List: %s\n", removeDublicates(integers));

        ArrayList<String> strings = new ArrayList<>(List.of("a","a","a","b","c"));
        System.out.printf("List: %s\n", strings);
        System.out.printf("Unique List: %s\n", removeDublicates(strings));
    }
}
