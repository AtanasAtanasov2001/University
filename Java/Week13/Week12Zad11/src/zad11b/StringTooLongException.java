package zad11b;


public class StringTooLongException extends RuntimeException{
    public StringTooLongException(String message) {
        super(message);
    }

    public StringTooLongException(){
        this("The string is too long." );
    }
}

