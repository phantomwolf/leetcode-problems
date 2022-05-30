class Solution {
    // Backtracking
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        List<List<Integer>> paths = new ArrayList<>();
        int target = graph.length - 1;
        // (index, vertex) pair
        Stack<Pair<Integer, Integer>> stack = new Stack<>();
        stack.push(new Pair<Integer, Integer>(0, 0));
        while (!stack.isEmpty()) {
            // forward as much as possible
            while (graph[stack.peek().getValue()].length > 0 && stack.peek().getValue() != target) {
                Pair<Integer, Integer> pair = new Pair<>(0, graph[stack.peek().getValue()][0]);
                stack.push(pair);
            }
            if (stack.peek().getValue() == target) {
                // found a path
                List<Integer> path = stack.stream().map(p -> p.getValue()).collect(Collectors.toList());
                paths.add(path);
            }
            // backtrack
            Pair<Integer, Integer> pair = stack.pop();
            while (!stack.isEmpty()) {
                int index = pair.getKey();
                int prevVertex = stack.peek().getValue();
                if (index + 1 < graph[prevVertex].length) {
                    // make a different choice
                    stack.push(new Pair<Integer, Integer>(index + 1, graph[prevVertex][index + 1]));
                    break;
                }
                // step back
                pair = stack.pop();
            }
        }
        return paths;
    }
}
