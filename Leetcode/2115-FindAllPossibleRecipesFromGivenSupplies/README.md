# 2115. Find All Possible Recipes from Given Supplies
You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. Ingredients to a recipe may need to be created from other recipes, i.e., ingredients[i] may contain a string that is in recipes.

You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.

Return a list of all the recipes that you can create. You may return the answer in any order.

Note that two recipes may contain each other in their ingredients.

Constraints:

    n == recipes.length == ingredients.length
    1 <= n <= 100
    1 <= ingredients[i].length, supplies.length <= 100
    1 <= recipes[i].length, ingredients[i][j].length, supplies[k].length <= 10
    recipes[i], ingredients[i][j], and supplies[k] consist only of lowercase English letters.
    All the values of recipes and supplies combined are unique.
    Each ingredients[i] does not contain any duplicate values.

Example 1:

    Input: recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
    Output: ["bread"]
    Explanation:
    We can create "bread" since we have the ingredients "yeast" and "flour".

Example 2:

    Input: recipes = ["bread","sandwich"], ingredients = [["yeast","flour"],["bread","meat"]], supplies = ["yeast","flour","meat"]
    Output: ["bread","sandwich"]
    Explanation:
    We can create "bread" since we have the ingredients "yeast" and "flour".
    We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".

Example 3:

    Input: recipes = ["bread","sandwich","burger"], ingredients = [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies = ["yeast","flour","meat"]
    Output: ["bread","sandwich","burger"]
    Explanation:
    We can create "bread" since we have the ingredients "yeast" and "flour".
    We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
    We can create "burger" since we have the ingredient "meat" and can create the ingredients "bread" and "sandwich".

## Analysis
This problem is basically a graph problem. Each recipe/ingredient is a vertex, and each edge means "is made of". Beware of cyclic dependencies.

## Recursive Solution with Memo
Actually there's no need to build the graph first. Just create a recursive function and check every recipe. For every recipe, check each of its ingredient:

1. If it's an available ingredient, continue
2. If it's another recipe, recursively examine it
3. If it's neither of the above, it's definitely an unvailable ingredient. Return false.
4. If all ingredients are possible to make, return true.

To avoid repeated calculations, use a memo to cache the results.

### Cycle detection
The first time we meet a recipe, mark it as impossible immediately before recursively processing its ingredients: ```memo.put(recipe, false)```.

Because if a cycle exists, eventually the recursive function will reach the same recipe again. In this case, we should return false. Since we've prepared the answer in the memo, this time the function will just return false instead of running infinitely.

## Graph DFS
Build the graph by creating vertice for each recipe and ingredient.

For available supplies, mark them as visited and possible; for unavailable ones, mark them visited and impossible. This is because non-recipe ingredients don't have any dependencies. If we do DFS, they'll be marked as possible due to that. So we have to mark unavailable ingredients as impossible.
