package package3c;

public class ClassB extends ClassA{
    public void print() {
        System.out.println("Print from B");
    }

    public static void methodB(ClassA a) {
        ClassB b = (ClassB) a;
        b.print();
    }

    public static void main(String[] args) {
        methodB(new ClassB());
    }
}
