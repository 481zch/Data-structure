#pragma once
#include <iostream>
#include <vector>
#include <list>

/*
实现图的数据结构：
1. 邻接表
2. 邻接矩阵
顶点使用int进行表示
默认是有向图
*/

template <typename T>
class AdjacencyList {
public:
	AdjacencyList(int vertices) : m_vertices(vertices) {
		m_adjLists.resize(vertices);
	}

	void addEdge(int u, int v, T weight) {
		m_adjLists[u].push_back({ v, weight });

	}

	void print() const {
		for (int i = 0; i < m_vertices; ++i) {
			std::cout << "Vertex " << i << ": ";
			for (const auto& neighbor : m_adjList[i]) {
				std::cout << " -> (" << neighbor.first << ", " << neighbor.second << ")";
			}
			std::cout << std::endl;
		}
	}

private:
	int m_vertices;
	std::vector<std::list<std::pair<int, T>>> m_adjList;
};


// 实际上只能使用权重为-1的情况
class AdjacencyMatrix {
public:
	AdjacencyMatrix(int vertices) : m_vertices(vertices) {
		m_adjMatrix.resize(vertices, std::vector<int>(vertices, -1));
	}

	void addEdge(int u, int v, int weight) {
		m_adjMatrix[u][v] = weight;
	}

	void print() const {
		for (int i = 0; i < m_vertices; ++i) {
			for (int j = 0; j < m_vertices; ++j) {
				if (m_adjMatrix[i][j] == -1) {
					std::cout << "INF" << " ";
				}
				else {
					std::cout << m_adjMatrix[i][j] << " ";
				}
			}
			std::cout << std::endl;
		}
	}

private:
	int m_vertices;
	std::vector<std::vector<int>> m_adjMatrix;
};