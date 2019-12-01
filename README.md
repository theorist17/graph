# Simple Graph Traversal 

This project implements DFS, BFS, Djikstra algo.

## Geting Started

### Prerequites

Things you need to install this software

```
CMake
```
### Installing

A step by step series of commands to get a development env running

```
git clone https://github.com/theorist17/graph
cd graph
mkdir build
cd build
cmake ..
make
```

## Running the tests

### Setup input.txt

```
3       (# of vertices)
1 2 3   (for each vertex, enumerate its adjacent vertex)
2 1 3
3 1 2
2       (# of vertices, for another graph)
1 2
2 1
4       (another graph)
1 2 3
2 4
3 2
4       (4\n)
        (eof)
```
### Run BFS & DFS

```
./traversal (inside build/)
```

### Run Dijkstra

```
./shortest_path (inside build/)
```

## Authors
* **Hong-In Lee** - *Algorithm* - [theorist17](https://github.com/theorist17)

## Acknowledgements 

