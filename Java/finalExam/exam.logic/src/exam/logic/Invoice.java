package exam.logic;

import java.security.InvalidParameterException;
import java.util.ArrayList;
import java.util.List;

public class Invoice {
    private String ID;
    private List<Item> items;
    private int count = 1;

    public Invoice() {
        items = new ArrayList<>();
        ID = String.format("%d",count);
        count++;
    }

    public List<Item> getItems() {
        return items;
    }

    public void setItems(List<Item> items) {
        if (items == null) {
            throw new InvalidParameterException();
        }

        this.items = items;
    }

    public String getID() {
        return ID;
    }

    public void setID(String ID) {
       this.ID = this.ID.length() >= 7 ? ID : "Too short!";
    }

    @Override
    public String toString() {
        return String.format("ID : %s , \n Items: %s", ID, items.toString());
    }
    double totalInvoicePrice( ){
        return 0;
    }
}
