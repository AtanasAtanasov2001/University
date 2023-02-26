package SecondPackage;

import FirstPackage.Cipherable;

import java.util.Random;

public class Wrapper {
    int size;

    public Wrapper() {
        this.size = 0;
    }

    public Wrapper(int size) {
        this.size = size;
    }

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        if(size < 0) {
            this.size = 0;
        } else {
            this.size = size;
        }

    }

    class FixedRandom implements Cipherable{

        public char[] getSecretChars(int seed) {
            Random helper = new Random(seed);
            char[] toReturn = new char[size];
            for (int i = 0; i < size; i++) {
                toReturn[i] = (char)(helper.nextInt(0,26) + 'A');
            }
            return toReturn;
        }
    }
    class FixedSelection implements Cipherable{
        public char[] getSecretChars(int seed) {

            Random helper = new Random(seed);
            char[] toReturn = new char[size];
            char[] randomGenerated = new char[seed];
            int randomIndex ;

            for (int i = 0; i < randomGenerated.length; i++) {
                randomGenerated[i] = (char)(helper.nextInt(0,26) + 'A');
            }

            for (int i = 0; i < toReturn.length; i++) {
                randomIndex = helper.nextInt(seed);
                toReturn[i] = randomGenerated[randomIndex];
            }
            return  toReturn;
        }
    }
    public Cipherable makeFixedSelection(){
        return new FixedRandom();
    }
    public Cipherable makeFixedRandom(){
        return new FixedSelection();
    }
}