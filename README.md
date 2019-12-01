# Simple Graph Traversal 

This project implements DFS, BFS, Djikstra algo.

## Geting Started

### Prerequites

Things you need to install this software

```
CMake
```

### Installing on Unix Terminal

A step by step series of commands to get a development env running

```
git clone https://github.com/theorist17/graph
cd graph
mkdir build
cd build
cmake ..
make
```

### Installing on Microsoft Visual Studio
```
1. Open VS
2. File -> Clone or check out code ..
3. Set Repository location = https://github.com/theorist17/graph
4. After building, move input.txt and input2.txt into the /out/build/ directory
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
./traversal
or
traversal.exe
```
Output
```
----------------------------
Graph 1
----------------------------
Vertex
3
----------------------------
Edges
1 2 3
2 1 3
3 1 2
----------------------------
Adjacency matrix
0 1 1
1 0 1
1 1 0
----------------------------
Depth first search
1 2 3
----------------------------
Breadth first search
1 2 3
----------------------------
```


### Run Dijkstra

```
./shortest_path
or 
traversal.exe
```
Output
```
----------------------------
Graph 1
----------------------------
Vertex
5
----------------------------
Edges
1 2 10 4 30 5 100
2 3 50
3 5 10
4 3 20 5 60
5
----------------------------
Adjacency list
node 1 : 2 (10) 4 (30) 5 (100)
node 2 : 3 (50)
node 3 : 5 (10)
node 4 : 3 (20) 5 (60)
node 5 :
----------------------------
Dijkstra algorithm
Starting vertex : 1
Vertex 2 : 1 - 2, distance : 10
Vertex 3 : 1 - 4 - 3, distance : 50
Vertex 4 : 1 - 4, distance : 30
Vertex 5 : 1 - 4 - 3 - 5, distance : 60
----------------------------
```

## Authors
* **Hong-In Lee** - *Algorithm* - [theorist17](https://github.com/theorist17)

## Acknowledgements 

