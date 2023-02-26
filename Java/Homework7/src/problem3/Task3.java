package problem3;

import java.util.*;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class Task3 {
    public static void main(String[] args)
    {
        //стринг 1#2# … 99#100
        System.out.println("Stream reduce:");
        Optional<String> streamReduce  =  IntStream.rangeClosed(1, 100)
                .mapToObj(i -> "" + i)
                .reduce((i, j) -> i + "#" + j);
        streamReduce.ifPresent(System.out::println);

        //списък от 20 произволни числата в интервала 0 до 30
        Random rand = new Random();
        List<Integer> list = new ArrayList<>();
        for(int i = 0; i < 20; i++){
            list.add(rand.nextInt(31));
        }

        System.out.println("Stream generate by Random:");
        Stream<Integer> streamToPrint = list.stream();
        streamToPrint.forEach(i -> System.out.printf("%d ", i));
        System.out.println();

        //Има ли число, което се дели на 5
        System.out.println("Have elements in stream that are divisible by 5:");
        Stream<Integer> streamTo5 = list.stream();
        streamTo5.filter(i -> i % 5 == 0)
                .forEach(i -> System.out.printf("%d ", i));
        System.out.println();

        //Дали всички числа са по- малки от 15
        boolean allLower = list.stream()
                .allMatch(i -> i < 15);
        System.out.printf("All lower by 15: %b\n", allLower);

        //Дали броят на числата по- големи от средната стойност на всички елементи е по- голям от 5
        double averageList = list.stream()
                .mapToInt(x -> x)
                .average().getAsDouble();

        long countOfList =  list.stream().filter(x -> x > averageList).count();
        boolean have5 = countOfList > 5;

        System.out.printf("Whether the count of numbers, bigger than the average value of all elements is greather than 5 : %b", have5);
    }
}
