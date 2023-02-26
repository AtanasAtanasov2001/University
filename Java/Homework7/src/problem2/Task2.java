package problem2;

import java.util.*;
import java.util.function.*;
import java.util.stream.*;

public class Task2 {
    public static void main(String[] args) {
        Stream<String> stream = Stream.of("aBc", "d","ef", "123456");
        List<String> stream2 = stream.map(element -> element.toUpperCase(Locale.ROOT)).sorted().toList();
        System.out.println(stream2);
    }
}
