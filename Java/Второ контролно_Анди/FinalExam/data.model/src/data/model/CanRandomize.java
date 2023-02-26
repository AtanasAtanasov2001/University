package data.model;

import java.util.Random;

public enum CanRandomize {
    RAND(new Random());
    public final Random GENERATOR = new Random();


    CanRandomize(Random random) {

    }
}
