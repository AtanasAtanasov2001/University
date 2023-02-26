package SecondPackage;

import java.util.Arrays;

public class Result {
    char[] chars;
    int data;

    public Result() {
        this.chars = new char[0];
        this.data = 0;
    }

    public Result(char[] chars, int data) {
        this.chars = chars;
        this.data = data;
    }

    public char[] getChars() {
        return chars;
    }

    public void setChars(char[] chars) {
        this.chars = chars;
    }

    public int getData() {
        return data;
    }

    public void setData(int data) {
        if (data > 0)
            this.data = data;
        else
            this.data = 1;
    }

    @Override
    public String toString() {
        String charsString = "";
        for (int i = 0; i < chars.length; i++) {
            charsString += Character.toString(chars[i]);
        }
        return String.format("%s,%d" , charsString,data);
    }

    public static void main(String[] args) {
        char[] chars = new char[3];
        for (int i = 0; i < chars.length; i++) {
            chars[i] = 'A';
        }
        int data = 8;
        Result result = new Result(chars,data);
        System.out.println(result.toString());
    }
}
