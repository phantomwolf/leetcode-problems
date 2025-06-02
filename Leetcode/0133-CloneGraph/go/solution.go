/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Neighbors []*Node
 * }
 */

 func cloneGraph(node *Node) *Node {
    // Base case
    if node == nil {
        return nil
    }

    graph := make([]*Node, 101)
    return clone(node, graph)
}

func clone(node *Node, graph []*Node) *Node {
    // If node is already cloned, just return it
    if graph[node.Val] != nil {
        return graph[node.Val]
    }

    newNode := &Node {
        Val: node.Val,
        Neighbors: []*Node{},
    }
    graph[node.Val] = newNode
    for _, n := range node.Neighbors {
        newNode.Neighbors = append(newNode.Neighbors, clone(n, graph))
    }
    return newNode
}
