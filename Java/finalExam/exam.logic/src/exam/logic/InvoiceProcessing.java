package exam.logic;

import java.security.InvalidParameterException;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class InvoiceProcessing implements RandomItemFactory{
    List<Invoice> invoices;

    @Override
    public String apply(Integer num) {
        return RandomItemFactory.super.apply(num);
    }

    @Override
    public List<Item> get() {
        return RandomItemFactory.super.get();
    }

    public InvoiceProcessing(int count) {
        this.invoices = new ArrayList<>();
        for (int i = 0; i < count; i++) {
            List<Item> helper = get();
            Invoice toReturn = new Invoice();
            toReturn.setItems(helper);
            invoices.add(toReturn);
        }
    }

    public List<Invoice> getInvoices() {
        return invoices;
    }

    public void setInvoices(List<Invoice> invoices) {
        if(invoices == null){
            throw new InvalidParameterException();
        }
        this.invoices = invoices;
    }
    public String showInvoices(){
        return invoices.stream().map(Invoice::toString).collect(Collectors.joining("\n"));
    }
    public double totalPrice(){
        return 0;
    }
    public String showSortedByPriceInvoices(){
        return "";
    }
    public String printTotalByBarcode (){
        return "";
    }



}
