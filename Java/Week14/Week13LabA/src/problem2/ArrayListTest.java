package problem2;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.ListIterator;

public class ArrayListTest {
    public static void main(String[] args) {
        ArrayList<String> alist = new ArrayList<>(
                Arrays.asList("Лили", "Мария", "Георги", "Илия", "Цвета"));
        ArrayList<String> blist = new ArrayList<>(
                Arrays.asList("Лили", "Георги","Цвета", "Георги"));
        Iterator<String> aIterator = alist.iterator();
        Iterator<String> bIterator;


        String aText;
        StringBuilder common = new StringBuilder();
        while(aIterator.hasNext()) {
            bIterator = blist.iterator();
            aText = aIterator.next();
            while(bIterator.hasNext()){
                if(aText.equals(bIterator.next())) {
                    common.append(aText).append(", ");
                    break;
                }
            }
        }
        System.out.printf("Common elements: %s\n",
                (common.length() == 0) ? "none" : common.substring(0,common.length() - 2));



        ArrayList<String> list = new ArrayList<>(
                Arrays.asList("Лили", "Мария", "Георги", "Илия", "Цвета","Георги"));

        list.add(list.indexOf("Георги") + 1, "Симеон");
//        ListIterator<String> nameIterator = list.listIterator();
//        while(nameIterator.hasNext()){
//            if(nameIterator.next().equals("Георги")) {
//                list.add(nameIterator.nextIndex(),"Симеон");
//                break;
//            }
//        }
    }
}
