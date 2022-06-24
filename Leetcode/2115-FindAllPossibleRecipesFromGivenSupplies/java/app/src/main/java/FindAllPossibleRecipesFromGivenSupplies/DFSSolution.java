package FindAllPossibleRecipesFromGivenSupplies;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class DFSSolution {
    List<List<Integer>> graph;
    Map<String, Integer> nameToId;
    List<String> idToName;
    List<Boolean> visited;

    public List<String> findAllRecipes(String[] recipes, List<List<String>> ingredients, String[] supplies) {
        buildGraph(recipes, ingredients, supplies);
        boolean[] possible = new boolean[graph.size()];
        for (String s : supplies) {
            int id = nameToId.get(s);
            possible[id] = true;
            visited.set(id, true);
        }
        boolean[] onPath = new boolean[graph.size()];
        // Visit every vertex
        for (int v = 0; v < graph.size(); v++) {
            if (!visited.get(v)) {
                possible[v] = isPossible(v, visited, possible, onPath);
            }
        }
        List<String> result = new ArrayList<>();
        for (int i = 0; i < recipes.length; i++) {
            if (possible[i]) {
                result.add(recipes[i]);
            }
        }
        return result;
    }

    // Return false when cycle detected or ingredient isn't available; otherwise return true
    private boolean isPossible(int v, List<Boolean> visited, boolean[] possible, boolean[] onPath) {
        visited.set(v, true);
        onPath[v] = true;
        for (int w : graph.get(v)) {
            if (!visited.get(w)) {
                possible[w] = isPossible(w, visited, possible, onPath);
                if (!possible[w]) {
                    onPath[v] = false;
                    return false;
                }
            } else if (onPath[w] || !possible[w]) {
                // Cycle detected or impossible to make w
                onPath[v] = false;
                return false;
            }
        }
        // All ingredients are possible and no cycle detected
        onPath[v] = false;
        return true;
    }

    private void buildGraph(String[] recipes, List<List<String>> ingredients, String[] supplies) {
        graph = new ArrayList<>();
        nameToId = new HashMap<>();
        idToName = new ArrayList<>();
        visited = new ArrayList<>();
        // Add recipes as vertice
        for (int i = 0; i < recipes.length; i++) {
            graph.add(new ArrayList<>());
            idToName.add(recipes[i]);
            visited.add(false);
            nameToId.put(recipes[i], i);
        }
        // Add supplies as vertice
        for (String s : supplies) {
            graph.add(new ArrayList<>());
            idToName.add(s);
            visited.add(true);  // mark all ingredient as visited
            nameToId.put(s, graph.size() - 1);
        }
        // Add edges
        for (int i = 0; i < ingredients.size(); i++) {
            for (String ingre : ingredients.get(i)) {
                // Get or create vertex id
                int j;
                if (nameToId.containsKey(ingre)) {
                    j = nameToId.get(ingre);
                } else {
                    // Create a new vertex for an unavailable ingredient
                    graph.add(new ArrayList<>());
                    idToName.add(ingre);
                    visited.add(true);  // mark all ingredient as visited
                    j = graph.size() - 1;
                    nameToId.put(ingre, j);
                }
                graph.get(i).add(j);
            }
        }
    }

    private void printGraph() {
        for (int v = 0; v < graph.size(); v++) {
            System.out.printf("%s", idToName.get(v));
            if (graph.get(v).isEmpty()) {
                System.out.println("");
                continue;
            }
            System.out.printf(" =>");
            for (int w : graph.get(v)) {
                System.out.printf(" %s,", idToName.get(w));
            }
            System.out.println("");
        }
    }
}
