package data.model;

import java.util.ArrayList;
import java.util.List;

public enum Category {
    A(1, new ArrayList<>()),
    B(2, new ArrayList<>()),
    C(3, new ArrayList<>()),
    D(4, new ArrayList<>());
    private int reorderQty;
    private List<String> suppliers;

    Category(int reorderQty, List<String> suppliers) {
        setReorderQty(reorderQty);
        setSuppliers(suppliers);
    }

    public int getReorderQty() {
        return reorderQty;
    }

    public void setReorderQty(int reorderQty) {
        if (reorderQty < 0)
            this.reorderQty = 0;
        else
            this.reorderQty = reorderQty;
    }

    public List<String> getSuppliers() {
        return suppliers;
    }

    public void setSuppliers(List<String> suppliers) {
        if (suppliers == null)
            this.suppliers = new ArrayList<>();
        else
            this.suppliers = suppliers;
    }
}
