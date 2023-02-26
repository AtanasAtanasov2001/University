package package3a;

public class OuterClassB {

    @Override
    public String toString() {
        System.out.println("OuterClassB");
        return "OuterClassB";
    }

    public InnerClassB getInnerClassB() {
        return new InnerClassB();
    }

    class InnerClassB extends OuterClassA.InnerClassA {
        public InnerClassB() {
            super("My name");
        }

        @Override
        public String toString() {
            System.out.println("InnerClassB" + getMyName());
            return "InnerClassB";
        }
    }
}
