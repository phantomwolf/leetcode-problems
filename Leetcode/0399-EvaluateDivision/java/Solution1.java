class Solution1 {
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        // Define graph node as variable, and edge as the value of equation
        Map<String, Map<String, Double>> graph = new HashMap<>();
        for (int i = 0; i < equations.size(); i++) {
            List<String> equation = equations.get(i);
            String from = equation.get(0);
            String to = equation.get(1);
            double value = values[i];
            // edge: from / to
            graph.computeIfAbsent(from, k -> new HashMap<String, Double>())
                .put(to, value);
            // edge: to / from
            graph.computeIfAbsent(to, k -> new HashMap<String, Double>())
                .put(from, 1/value);
        }
        // Queries
        double[] res = new double[queries.size()];
        for (int i = 0; i < queries.size(); i++) {
            List<String> query = queries.get(i);
            String from = query.get(0);
            String to = query.get(1);
            // Base case 1: at least one variable in the query is not in the graph
            if (!graph.containsKey(from) || !graph.containsKey(to)) {
                res[i] = -1;
                continue;
            }
            // Base case 2: two variables in the query are the same
            if (from.equals(to)) {
                res[i] = 1;
                continue;
            }
            // DFS to find a path from two variables
            Set<String> visited = new HashSet<>();
            res[i] = evaluate(graph, from, to, 1, visited);
        }
        return res;
    }

    private double evaluate(Map<String, Map<String, Double>> graph, String currNode, String targetNode, double accValue, Set<String> visited) {
        if (currNode.equals(targetNode)) {
            return accValue;
        }
        visited.add(currNode);
        double res = -1.0;
        // Neighbors
        Map<String, Double> edges = graph.get(currNode);
        if (edges.containsKey(targetNode)) {
            // Reached target
            return accValue * edges.get(targetNode);
        }
        // Visit all neighbors
        for (Map.Entry<String, Double> entry : edges.entrySet()) {
            String nextNode = entry.getKey();
            if (visited.contains(nextNode)) {
                continue;
            }
            double value = entry.getValue();
            res = evaluate(graph, nextNode, targetNode, accValue * value, visited);
            if (res != -1.0) {
                break;
            }
        }
        return res;
    }
}