import java.util.*;

public class SimilarAnagrams {

    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> groupedAnagrams = new ArrayList<>();
        HashMap<String, List<String>> map = new HashMap<>();
        for (String current : strs) {
            char[] characters = current.toCharArray();
            Arrays.sort(characters);
            String sorted_string = characters.toString();
            if (!map.containsKey(sorted_string)) {
                map.put(sorted_string, new ArrayList<>());
            }
            map.get(sorted_string).add(current);
        }
        // values is a collection. so we need to use addAll instead of add(this is used
        // to add a single element)
        groupedAnagrams.addAll(map.values());
        return groupedAnagrams;

    }

    public static void main(String[] args) {
    }
}