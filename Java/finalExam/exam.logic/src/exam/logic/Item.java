package exam.logic;

import java.util.Queue;

public class Item {
    private String BARCODE;
    private double quantity;
    private double price;

    public Item(String BARCODE, double quantity, double price) {
        setBARCODE(BARCODE);
        setPrice(price);
        setQuantity(quantity);
    }

    public String getBARCODE() {
        return BARCODE;
    }

    public void setBARCODE(String BARCODE) {
        this.BARCODE = BARCODE != null ? BARCODE : "No barcode!";
    }

    public double getQuantity() {
        return quantity;
    }

    public void setQuantity(double quantity) {
        this.quantity = quantity > 0 ? quantity : 0;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = quantity > 0 ? price : 0;
    }

    @Override
    public String toString() {
        return String.format("BARCODE : %s, Quantity : %2f, Price : %2f", BARCODE, quantity,price);
    }
}
