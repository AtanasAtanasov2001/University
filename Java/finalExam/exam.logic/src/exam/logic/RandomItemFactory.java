package exam.logic;

import java.util.*;
import java.util.function.Function;
import java.util.function.Supplier;

public interface RandomItemFactory  extends Function<Integer,String>, Supplier<List<Item>> {
    Random GENERATOR = new Random();
    int BARCODE_SIZE = 5;

    default String apply(Integer num){
        String BARCODE = "";
        for (int i = 0; i < num; i++) {
            int helper = GENERATOR.nextInt(0,2);
            if(helper == 0) {
                BARCODE += ":";
            }
            else if(helper == 1) {
                BARCODE += "|";
            }
        }
        return BARCODE;
    }
    private void setRandomData(List<Item> items, int count){
        for (int i = 0; i < count; i++) {
            Item toAdd = new Item(apply(BARCODE_SIZE),GENERATOR.nextInt(1,10),GENERATOR.nextInt(20,30));
            items.add(i,toAdd);
        }
    }
    default List<Item> get(){
        List<Item> toReturn = new ArrayList<>();
        int count = GENERATOR.nextInt(1,6);
        setRandomData(toReturn,count);
        return toReturn;
    }
}
