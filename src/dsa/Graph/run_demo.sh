#!/bin/bash

# Declare program name
demo1=demo_vertices_edges_graph
demo2=demo_vertices_vertices_graph
demo3=demo_list_adjacent_graph

# Compile all
make prog=$demo1 type=vertices_edges
make prog=$demo2 type=vertices_vertices
make prog=$demo3 type=list_adjacent

# Run all
./$demo1.out
./$demo2.out
./$demo3.out
