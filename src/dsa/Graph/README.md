# Graph: API
- Type: `Graph`
- Functions: `init_graph`, `add_edge`, `is_adjacent`, `degree`,
`get_adjacents`, `mark_visited`, `is_visited`, `dfs`, `reset_visted`, `dfs_using_stack`

## Using matrix vertices - edge
- Properties:
    - Undirected graph
    - Simple/multigraph
    - No self-loop

> [See implementation](./lib/vertices_edges_graph.c)

## Using matrix vertices - vertices
- Properties:
    - Undirected/Directed(*) graph
    - Simple/Multigraph
    - Self-loop

(*): Not implement yet

> [See implementation](./lib/vertices_vertices_graph.c)

## Using list of adjacents
- Properties:
    - Directed/Undirected(*) graph
    - Simple/Multigraph
    - Self-loop

(*): Not implement yet

> [See implementation](./lib/list_adjacent_graph.c)
