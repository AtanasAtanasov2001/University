package data.model;

import java.util.ArrayList;
import java.util.List;
import java.util.function.Supplier;

public interface RandomCategorySupplier extends Supplier<List<Inventory>> {
    private void updateType(Category type) {
        type.getSuppliers().clear();
        int n = CanRandomize.RAND.GENERATOR.nextInt(4) + 1;

        for (int i = 0; i < n; i++) {
            type.getSuppliers().add(String.format("%s Supplier %d", type.toString(), i));
        }

        type.setReorderQty(CanRandomize.RAND.GENERATOR.nextInt(10*n) + 1);
    }

    default List<Inventory> getRandomData(int howMany, int a, int b) {
        List<Inventory> list = new ArrayList<>();

        for (int i = 0; i < howMany; i++) {
            int categoryNumber = CanRandomize.RAND.GENERATOR.nextInt(4) + 1;
            double salary = (CanRandomize.RAND.GENERATOR.nextDouble() % (b-a)) + a;
            Category temp;
            switch (categoryNumber)
            {
                case 1: temp = Category.A; break;
                case 2: temp = Category.B; break;
                case 3: temp = Category.C; break;
                case 4: temp = Category.D; break;
                default: temp = Category.A; break;
            }

            list.add(new Inventory(Integer.toString(i), temp, salary));
        }

        return list;
    }
}
