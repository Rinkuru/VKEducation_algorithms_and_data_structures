#include <stdlib.h>
#include <stdio.h>
#include <climits>
#include <cassert>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

/* Для неориентированного графа цикл есть, если при DFS
 * попадаем в уже посещенную вершину, которая не является родителем.*/
bool hasCycleDfs(const std::vector<std::vector<int>> &graph,
                 int vertex,
                 int parent,
                 std::vector<bool> &visited) {
  visited[vertex] = true;
  for (int neighbor : graph[vertex]) {
    if (!visited[neighbor]) {
      if (hasCycleDfs(graph, neighbor, vertex, visited)) {
        return true;
      }
    } else if (neighbor != parent) {
      return true;
    }
  }
  return false;
}

bool hasCycle(const std::vector<std::vector<int>> &graph) {
  std::vector<bool> visited(graph.size(), false);
  for (int vertex = 0; vertex < static_cast<int>(graph.size()); ++vertex) {
    if (!visited[vertex] && hasCycleDfs(graph, vertex, -1, visited)) {
      return true;
    }
  }
  return false;
}

/* Граф является деревом, если он связный и не содержит циклов.
 * DFS от вершины 0 одновременно проверяет цикл и связность. */
bool isTree(const std::vector<std::vector<int>> &graph) {
  if (graph.empty()) {
    return true;
  }

  std::vector<bool> visited(graph.size(), false);
  if (hasCycleDfs(graph, 0, -1, visited)) {
    return false;
  }

  for (bool seen : visited) {
    if (!seen) {
      return false;
    }
  }
  return true;
}

/* Дейкстра хранит в приоритетной очереди пары
 * (текущее лучшее расстояние, вершина) и делает relax всех ребер. */
std::vector<int> dijkstra(const std::vector<std::vector<std::pair<int, int>>> &graph, int start) {
  assert(0 <= start && start < static_cast<int>(graph.size()));

  std::vector<int> distances(graph.size(), INT_MAX);
  distances[start] = 0;

  std::priority_queue<
    std::pair<int, int>,
    std::vector<std::pair<int, int>>,
    std::greater<std::pair<int, int>>
  > priorityQueue;
  priorityQueue.push({0, start});

  while (!priorityQueue.empty()) {
    int currentDistance = priorityQueue.top().first;
    int currentVertex = priorityQueue.top().second;
    priorityQueue.pop();

    if (currentDistance > distances[currentVertex]) {
      continue;
    }

    for (const auto &edge : graph[currentVertex]) {
      int neighbor = edge.first;
      int weight = edge.second;
      int nextDistance = currentDistance + weight;
      if (nextDistance < distances[neighbor]) {
        distances[neighbor] = nextDistance;
        priorityQueue.push({nextDistance, neighbor});
      }
    }
  }
  return distances;
}

/* Двудольность проверяем BFS-раскраской:
 * соседи каждой вершины должны получать противоположный цвет. */
bool isBipartite(const std::vector<std::vector<int>> &graph) {
  std::vector<int> color(graph.size(), 0);

  for (int start = 0; start < static_cast<int>(graph.size()); ++start) {
    if (color[start] != 0) {
      continue;
    }

    std::queue<int> nodes;
    nodes.push(start);
    color[start] = 1;

    while (!nodes.empty()) {
      int vertex = nodes.front();
      nodes.pop();

      for (int neighbor : graph[vertex]) {
        if (color[neighbor] == 0) {
          color[neighbor] = -color[vertex];
          nodes.push(neighbor);
        } else if (color[neighbor] == color[vertex]) {
          return false;
        }
      }
    }
  }
  return true;
}
