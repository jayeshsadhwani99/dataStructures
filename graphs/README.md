# Graphs

This is a non-linear data strcuture, just like a tree, and is a collection of objects or entities, called nodes/vertices that are connected by edges.

In a tree, there are rules dictating the conections of various nodes, for instance, in a tree with N nodes, we must exactly have (N-1) edges and there is exactly one edge in a parent child relationship etc.

Contrary to this, a graph has no rules dictating the connections among the nodes. It contains nodes and edges which can be connected in any possible way.

So, tree is just a special kind of a graph.

> A graph G is an ordered pair of a set V of vertices and a set E of edges.
>
> G = (V, E)
>
> **Ordered pair**: a pair of mathematical objects, where order matters, for example,
>
> (a, b) != (b, a) if (a != b)
>
> **Unordered pair**: simply a set of 2 mathematical objects with no specific order, for example,
>
> {a, b} = {b, a}

## Edges

How is an edge represented?

An edge is uniquely identified by it's 2 endpoints.

Edges can be of two types:

1. Directed:

   Connection is one-way.

2. Undirected:

   Connection is two-way.

A graph with all directed edges is called a **directed graph** or a **Digraph**

A graph with all undirected edges is called an **undirected graph**

## Weights

Sometimes, in a graph all connections cannot be treated as equal. Some connections can be prefereable to others. For example, a road network.

In these kind of cases, we associate a weight or a cost to each edge of the graph. These kind of graphs are called **Weighted Graphs**.

We can actually look at all the graphs as weighted graphs, an unweighted graph can be seen as a weighted graph in which the weight of all the edges is the same, typically, we assume it to be 1 unit.

## Applications

Any kind of real life application can be modelled using a graph, and they can be used to store all kinds of data.

Once data is modelled using a graph, a lot of problems can easily be solved by using standard graph theory algorithms.

Examples:

1. A Social Network
2. Interlinked webpages - WWW (World wide web)
3. Web crawling - This is just basically graph traversal to reccommend good search results.
4. Intercity road networks - Weighted undirected graph.
5. Intracity road networks - Weighted directed graphs: This is because there can be one-way roads in a city.

## Properties

- Self loop:

  An edge is called a self loop, or a self edge, if it only involves one vertex. These complicate algorithms and make working with graphs difficult.

  These can be seen in webpages, where a webpage links to itself.

- Multiedge / Parallel edge:
  An edge is called a multiedge, if it occurs more than once in a graph.

  These can be seen if we are modelling a flight network using graphs.

- If a graph doesn't have a self loop or a multi edge, then it is called a **simple graph**.

- Number of edges:

  Minimum number of edges for a graph = 0

  These can be calculated for a simple graph, cause if self loops are multi loops get involved, we obviously won't be able to calculate.

  1.  Directed-

      Here, we will have a directed edge from one node to every other node.

      So, in general,

      If |V| = n,

      then, for number of edges, E

      0 <= E <= n(n-1)

  2.  Undirected -

      Here, we will have only one edge from one node to another,

      So, similar to a directed graph,

      If |V| = n,

      then, for number of edges, E

      0 <= E <= n(n-1) / 2

- If the number of edges in a graph are close to the sqaure of it's number of nodes, that is the maximum number of edges, then it is called a **dense graph**.

- If the number of edges in a graph is really less, we call it a **sparse graph**. Typically, close to the number of vertices.

- **Path** - a sequence of vertices where each adjecent pair is connected by an edge.

  In a directed graph, all edges must also be aligned in one direction, the direction of path.

  - **Simple path** - a path in which no vertices, and hence, no edges are repeated.

  Most of the time when we say path, we mean a simple path. So, for the actual path, we use the term **walk**, and thus, the defination of a simple path becomes,

  A _walk_ in which no vertices, and hence, no edges are repeated.

  - **Trial** - a _walk_ in which no edges are repeated.

  If a trail is possible between two vertices, then certainly a simple path, or just a path is also possible.

- **Strongly Connected Graph** - A graph is called a strongly connected graph, if there is a path from any vertex to any other vertex.

  - If it's an undirected graph, we simply call it connected
  - If it's a directed graph, we call it strongly connected.

- **Weakly Connected Graphs** - If a directed graph is not strongly connected, but can be by treating all the edges as undirected, then it is called a weakly connected graph.

- **Closed walk** - If a walk starts and ends at the same vertex and the length of the walk(number of edges in the walk) is > 0.

  Some use the term **cycle** for a closed walk, but the term _cycle_ generally refers to a simple cycle.

- **Simple Cycle** - A simple cycle is a closed walk in which there is no repetition except the start and end vertices.

- **Acyclic graph** - A graph with no cycle. A tree would be an example of an acyclic graph.

## Graph Representation

We can store the graph in the computer's memory in different ways. Here we analyse the time and space complexity of different methods:

1. **Edge List**

   We create 2 lists,

   1. To store vertices
   2. To store edges

   Vertices can be a simple string, and in a realistic scenario the strings won't be very long, so the space complexity will be proportional to the number of vertices.

   For edges, we can store it in the form

   ```c
      struct Edge {
         int start_vertex;
         int end_vertex;
         int weight;
      }
   ```

   Here, the space complexity would be propoortional to the number of edges.

   Hence, the total space complexity of storing a graph would be `O(|V| + |E|)`

   We cannot do a lot better if we want to store a graph in the memory. So we are good with the memory usage.

   For **Time complexity**,

   The most frequently performed operations would be-

   1. Find nodes adjecent to given nodes-
      For this specific case, we would have to scan the whole edge list. We will have to perform a linear search.

      Time complexity for this operation will be `O(|E|)`

   2. Find if two given nodes are connected -
      Similar to the previous case, here too, we will have to perform a linear search.

      Thus, time complexity for this operation will also be `O(|E|)`

   If we take a look at that in terms of number of vertices, the time complexity would be

   `O(|V| * |V|)`, this is because the maximum number of edges is n(n-1), which is costly.
