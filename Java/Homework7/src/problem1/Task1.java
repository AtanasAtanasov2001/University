package problem1;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;

public class Task1 {
    public static void main(String[] args) {

        ArrayList<Integer> differentPictures = new ArrayList<>();
        double countEggs = 0.5;
        while(differentPictures.size() < 10){
            countEggs += 0.5;
            Random picture = new Random();
            int numPicture = picture.nextInt(1,11);
            if(!(differentPictures.contains(numPicture))) {
                differentPictures.add(numPicture);
            }
        }
        System.out.println("The average money needed to gather all 10 pictures is: " + countEggs + " leva!");
    }


}
