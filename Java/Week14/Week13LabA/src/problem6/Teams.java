package problem6;

import java.util.*;

public class Teams {
    public static void main(String[] args) {
        TreeMap<String,String> teams = new TreeMap<>();

        teams.put("San Francisco", "Forti-niners");
        teams.put("Chicago", "Bears");
        teams.put("Denver", "Broncos");
        teams.put("Seattle", "Seahawks");
        teams.put("Miami", "Dolphins");
        teams.put("Detroit", "Lions");

        //a)
        System.out.println("Size: " + teams.size());
        System.out.println("Chicago: " + teams.get("Chicago"));

        //b)
        teams.put("San Francisco", "Niners");

        //c)
        System.out.printf("San Diego %s a team \n", teams.containsKey("San Diego") ? "has" : "doesn't have");

        //d)
        teams.remove("Denver");

        //e)
        teams.put("Dallas", "Cowboys");

        System.out.printf("%-20s%-20s\n", "Key: ", "Value: ");
        for (Map.Entry<String,String> e : teams.entrySet()) {
            System.out.printf("%-20s%-20s\n",
                    e.getKey(), e.getValue());
        }

        //g)
        List<Map.Entry<String,String>> entries;

        entries = new ArrayList<>(teams.entrySet());
        entries.sort(Map.Entry.comparingByValue());
        Collections.reverse(entries);

        System.out.printf("%-20s%-20s\n", "Key: ", "Value: ");
        for (Map.Entry<String,String> e : entries) {
            System.out.printf("%-20s%-20s\n",
                    e.getKey(), e.getValue());
        }

        System.out.println(teams);
    }
}
