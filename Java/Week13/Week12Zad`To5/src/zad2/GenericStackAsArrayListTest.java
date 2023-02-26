package zad2;

import java.util.Scanner;

public class GenericStackAsArrayListTest {
    public static class GenericStack<E> extends java.util.ArrayList<E>{

        public int getSize() {
            return super.size();
        }

        public E peek() {
            return super.get(getSize() - 1);
        }

        public void push(E o) {
            super.add(o);
        }

        public E pop() {
            E o = super.get(getSize() - 1);
            super.remove(getSize() - 1);
            return o;
        }

        public boolean isEmpty() {
            return super.isEmpty();
        }

        @Override
        public String toString() {
            return "stack: " + super.toString();
        }
    }

    public static void main(String[] args) {
        GenericStack<String> textStack = new GenericStack<>();
        Scanner input = new Scanner(System.in);

        for (int i = 0; i < 5; i++) {
            System.out.printf("Enter text (%d/%d): ", i + 1,5);
            textStack.push(input.nextLine());
        }

        for (int i = 0; i < 5; i++) {
            System.out.printf("%s ", textStack.pop());
        }
        System.out.println();
    }
}
