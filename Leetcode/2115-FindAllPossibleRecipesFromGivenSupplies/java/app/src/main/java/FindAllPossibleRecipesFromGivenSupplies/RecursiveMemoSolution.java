package FindAllPossibleRecipesFromGivenSupplies;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class RecursiveMemoSolution {
    // Recipe name to its index
    private Map<String, Integer> recipeToIndex;
    // Records if an ingredient is available
    private Map<String, Boolean> memo;

    public List<String> findAllRecipes(String[] recipes, List<List<String>> ingredients, String[] supplies) {
        // Init
        recipeToIndex = new HashMap<>();
        for (int i = 0; i < recipes.length; i++) {
            recipeToIndex.put(recipes[i], i);
        }
        memo = new HashMap<>();
        for (String s : supplies) {
            memo.put(s, true);
        }
        // Check each recipe
        List<String> possibleRecipes = new ArrayList<>();
        for (String recipe : recipes) {
            if (isPossible(recipe, ingredients)) {
                possibleRecipes.add(recipe);
            }
        }
        return possibleRecipes;
    }

    private boolean isPossible(String name, List<List<String>> ingredients) {
        if (memo.containsKey(name)) {
            return memo.get(name);
        }
        int index = recipeToIndex.getOrDefault(name, -1);
        if (index == -1) {
            return false;
        }
        // Mark recipe as impossible here.
        // If there's a cycle, isPossible will return false next time, avoiding infinite loop
        memo.put(name, false);
        for (String ingredient : ingredients.get(index)) {
            boolean possible = isPossible(ingredient, ingredients);
            if (!possible) {
                memo.put(name, false);
                return false;
            }
        }
        memo.put(name, true);
        return true;
    }
}
