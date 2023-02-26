package data.model;

public class Inventory {
    private final String ID;
    private Category category;
    private double price;
    private final String description;

    public Inventory(String ID, Category category, double price) {
        this.ID = ID;
        this.category = category;
        this.price = price;

        this.description = "Product-" + ID;
    }

    public String getID() {
        return ID;
    }

    public Category getCategory() {
        return category;
    }

    public void setCategory(Category category) {
        if (category == null)
            this.category = Category.A;
        else
            this.category = category;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        if (price < 0)
            this.price = 0;
        else
            this.price = price;
    }

    @Override
    public String toString() {
        return String.format("Product: %s\ncategory: %s\nprice: %.2f\nsuppliers: %s",
                ID, category.toString(), price, category.getSuppliers().toString());
    }
}
