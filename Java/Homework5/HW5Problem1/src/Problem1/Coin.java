package Problem1;

import java.util.Random;

public class Coin {
    Random rand;
    Face face;

    public Coin(Face face) {
        setFace(face);
    }

    public Face getFace() {
        return face;
    }

    public void setFace(Face face) {
        this.face = face;
    }
    //I use the random variable to determine whether
    // the coil will flip to head or tail
    public void flip() {
        rand = new Random();
        int side = rand.nextInt(0,2);
        if(side == 0) {
            this.face = Face.tail;
        }
        else if(side == 1) {
            this.face = Face.head;
        }
    }
    public boolean isHeads() {
        return this.face == Face.head;
    }

    @Override
    public String toString() {
        return String.format("%s", face);
    }

}
