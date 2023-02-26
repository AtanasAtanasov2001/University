package package3a;

public class TestOuterInnerLab3 {
    public static void main(String[] args) {
        OuterClassA oa = new OuterClassA();
        OuterClassB ob = new OuterClassB();

        OuterClassA.InnerClassA ia = new OuterClassA.InnerClassA("Ia");
        OuterClassB.InnerClassB ib = ob.getInnerClassB();
        ib.setMyName("Ib");

        oa.toString();
        ob.toString();
        ia.toString();
        ib.toString();
    }
}
