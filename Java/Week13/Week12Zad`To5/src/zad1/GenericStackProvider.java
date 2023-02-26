package zad1;

public class GenericStackProvider {
    public class GenericStack<E> {


        private int topIndex = 0;
        private E[] array = (E[]) new Object[10];

        public int getSize() {
            return topIndex;
        }

        public E peek() {
            if (isEmpty()) {
                return null;
            }

            return array[getSize() - 1];
        }

        public void push(E o) {
            if(topIndex == array.length) {
                expandArray();
            }
            array[topIndex++] = o;
        }

        public E pop() {
            if(isEmpty()) {
                return  null;
            }
            E o = peek();
            array[getSize() - 1] = null;
            topIndex--;
            return o;
        }

        public boolean isEmpty() {
            return getSize() == 0;
        }

        private void expandArray(){
            E[] copy = (E[]) new Object[array.length * 2];
            for (int i = 0; i < array.length; i++) {
                copy[i] = array[i];
            }
            array = copy;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < topIndex; i++) {
                sb.append(array[i]).append(" ");
            }
            return "stack: " + sb.toString();
        }
    }

    public<T>  GenericStack<T> getGenericStack() {
        return new GenericStack<>();
    }

    public static void main(String[] args) {
        GenericStackProvider genericStackProvider = new GenericStackProvider();
        GenericStack<Integer> integerStack = genericStackProvider.getGenericStack();

        for (int i = 0; i < 10; i++) {
            integerStack.push(i);
        }
        System.out.println(integerStack);

        GenericStack<String> textString = genericStackProvider.getGenericStack();

        for (int i = 0; i < 10; i++) {
            textString.push( i + "a");
        }
        System.out.println(textString);

    }
}
