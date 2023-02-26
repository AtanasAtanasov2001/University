package package3a;

public class ClassTest {
    public static void main(String[] args) {
        ClassA upcast = (ClassA) new ClassB();
        upcast.methodA();
    }
}
