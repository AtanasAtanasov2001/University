package Traffic;

public class TrafficLightTest {
    public static void main(String[] args) {
        long start = System.currentTimeMillis();
        long testDuration = start;
        while(testDuration - start < 10000) {
            long currentTime = System.currentTimeMillis();
            for (TrafficLight light: TrafficLight.values()) {
                System.out.println(light);
                while(currentTime - testDuration < light.getDutarion()) {
                    currentTime = System.currentTimeMillis();
                }
                testDuration = currentTime;
            }
            testDuration = System.currentTimeMillis();
        }
    }
}
