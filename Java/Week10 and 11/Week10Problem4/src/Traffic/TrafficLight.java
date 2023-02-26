package Traffic;

public enum TrafficLight {
    RED(3000),
    GREEN(3000),
    YELLOW(3000);

    private final int dutarion;

    TrafficLight(int dutarion) {
        this.dutarion = dutarion;
    }

    public int getDutarion() {
        return dutarion;
    }
}
