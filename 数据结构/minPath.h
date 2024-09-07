#pragma once
#include "graph.h"
#include <queue>

/*
实现最短路算法:
1. dijkstra
2. floyd
3. bellman-floyd
4. spfa
*/

using PII = std::pair<int, int>;
const int INF = INT_MAX;

// 使用模板统一邻接表和邻接矩阵的写法
template <typename T>
std::vector<int> dijkstra(int vertices, const T& adjMatrix, int start)
{
	std::vector<int> dist(vertices, INT_MAX);
	dist[start] = 0;

	// 距离和顶点索引
	std::priority_queue<PII, std::vector<PII>, std::greater<>> pq;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		// 用到了C++17的新特性
		auto [currentDist, u] = pq.top();
		pq.pop();

		if (currentDist > dist[u]) continue;

		for (const auto& [v, weight] : adjMatrix[u]) {
			int newDist = currentDist + weight;

			if (newDist < dist[v]) {
				dist[v] = newDist;
				pq.push({ newDist, v });
			}
		}
	}

	return dist;
}

// 不可达为INT_MAX
template <typename T>
std::vector<std::vector<T>> floyd(const std::vector<std::vector<int>> graph)
{
	std::vector<std::vector<T>> dist = graph;
	int vertices = graph.size();

	for (int k = 0; k < vertices; ++k) {
		for (int i = 0; i < vertices; ++i) {
			for (int j = 0; j < vertices; ++j) {
				if (dist[i][k] == INF || dist[k][j] == INF) continue;
				dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	return dist;
}  
