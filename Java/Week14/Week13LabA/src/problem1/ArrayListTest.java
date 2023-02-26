package problem1;

import java.util.*;

public class ArrayListTest {

    public static <E> void shuffle(ArrayList<E> list){
        if(list==null) return;
        Collections.shuffle(list);

    }

    public static <E extends Comparable<E>> E max(ArrayList<E> list){
        if(list==null) return null;

        return Collections.max(list);
    }

    public static <E> ArrayList<E> removeDublicates(ArrayList<E> list){
        if(list==null) return null;

        //return new ArrayList<>(new LinkedHashSet<>(list));
        ArrayList<E> noDublicates = new ArrayList<>();
        for (int i = 0; i < list.size(); i++) {
            if(Collections.frequency(list,list.get(i)) == 1){
                noDublicates.add(list.get(i));
            } else {
                list.remove(i);
                i--;
            }
        }
        return noDublicates;
    }

    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<>(Arrays.asList(1,7,2,3,3,4,6,5,7));
        System.out.println("list: " + list);
        shuffle(list);
        System.out.println("shuffled: " + list);
        System.out.println("max: " + max(list));
        System.out.println("No dublicates: " + removeDublicates(list));

    }
}
