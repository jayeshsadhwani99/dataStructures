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
