package Problem1;

import java.util.Scanner;

public class StockTest {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        System.out.print("Input symbol: ");
        String symbol = input.next();
        System.out.print("Input name: ");
        String name = input.next();

        Stock stock = new Stock(symbol,name);
        System.out.print("Input previousClosingPrice: ");
        double previousClosingPrice = input.nextDouble();
        System.out.print("Input currentPrice: ");
        double currentPrice = input.nextDouble();

        stock.setPreviousClosingPrice(previousClosingPrice);
        stock.setCurrentPrice(currentPrice);

        System.out.println("Name: " + stock.getName());
        System.out.println("Symbol: " + stock.getSymbol());
        System.out.println("PreviousClosingPrice: " + stock.getPreviousClosingPrice());
        System.out.println("CurrentPrice: " + stock.getCurrentPrice());
        System.out.printf("Percentage of change: %.2f%%", stock.changePercent());

    }
}
