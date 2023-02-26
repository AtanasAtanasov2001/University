package Problem1;

public class MonetaryCoinTest {
    public static void main(String[] args) {
        MonetaryCoin mc = new MonetaryCoin(Face.tail,50);
        System.out.println(mc.getValue());
        for (int i = 0; i < 10; i++) {
            mc.flip();
            System.out.println(mc.toString());
        }
    }
}
