package Problem1;

public class MonetaryCoin extends Coin {
    int value;

    public MonetaryCoin(Face face, int value) {
        super(face);
        this.value = value;
    }

    public int getValue() {
        return value;
    }

}
