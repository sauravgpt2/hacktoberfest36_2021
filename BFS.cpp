// The only catch here is, unlike trees, graphs may contain cycles, 
// so we may come to the same node again. To avoid processing a node more 
// than once, we use a boolean visited array. For simplicity, 
// it is assumed that all vertices are reachable from the starting vertex. 
