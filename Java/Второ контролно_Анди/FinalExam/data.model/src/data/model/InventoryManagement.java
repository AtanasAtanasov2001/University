package data.model;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class InventoryManagement {
    private RandomCategorySupplier supplier;
    private List<Inventory> inventories;

    public InventoryManagement() {
        supplier = () -> {
            return new ArrayList<>();
        };
        inventories = supplier.getRandomData(5, 300, 1000);
    }

    public String showInventory() {
        List<String> result = inventories.stream().map((element)->{
            return element.toString() +
                    "\n";
        }).collect(Collectors.toList());

        return result.toString();
    }

    public double averagePrice() {
        double result = inventories.stream().mapToDouble(Inventory::getPrice).average().getAsDouble();
        return result;
    }

    public List<Inventory> sortInventoryTypeAndID() {
        return null;
    }

    public String findLargestPricePerCategory() {
        double result = inventories.stream().mapToDouble(Inventory::getPrice).max().getAsDouble();
        return Double.toString(result);
    }
}
