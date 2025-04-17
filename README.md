# Leetcode-diameter-of-a-tree-
# Tree Diameter

## 🌳 Problem Statement

Given an undirected tree represented by an edge list, return the **diameter** of the tree.
The **diameter** is the length of the longest path between any two nodes in the tree.

---

## 🔍 Approach

The diameter of a tree can be found using **two BFS passes**:
1. **First BFS** from any arbitrary node (say, node `0`) to find the **farthest node `X`**.
2. **Second BFS** from node `X` to find the **farthest node `Y`** from `X`.
3. The number of edges between `X` and `Y` is the **diameter**.
This works because the longest path in a tree (diameter) always lies between two leaf nodes.

---

## 🚀 Example

### Input:
```cpp
edges = {{0,1}, {0,2}, {1,3}, {3,4}, {4,5}}
Output:
Copy
Edit
4
Explanation:
The longest path is 2 → 0 → 1 → 3 → 4 → 5 with 4 edges.

📈 Time and Space Complexity
Time Complexity: O(N) where N is the number of nodes.

Space Complexity: O(N) for the adjacency list and visited array.

✅ Topics Covered
Graph traversal

Breadth-First Search (BFS)

Tree algorithms

Longest path in a tree

🧠 Fun Fact
This technique is often used in problems involving trees where the longest distance between two nodes is needed. It works on both rooted and unrooted trees.

