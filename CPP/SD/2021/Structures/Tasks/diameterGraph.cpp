#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

const long long MAX_N = 1000;
long long n;
long long m;

struct Edge {
    int end;
    long long weight;

    Edge() {}
    Edge(int end, long long weight) : end(end), weight(weight) {}
};

std::vector<Edge> graph[MAX_N];
bool visited[MAX_N];
long long distance[MAX_N];

std::queue<long long > level;
long long breadFirstSearchMaxWeight(const long long & s)  {
    long long maxWeight = 0;
    long long farthestVertex = -1;
    visited[s] = true;
    level.push(s);

    while(!level.empty()) {
        long long u = level.front();
        level.pop();

        for (const Edge &v : graph[u])
        {
            if(!visited[v.end]) {
                distance[v.end] = distance[u] + v.weight;
                visited[v.end] = true;
                level.push(v.end);
                if(distance[v.end] > maxWeight) {
                    maxWeight = distance[v.end];
                    farthestVertex = v.end;
                }
            }
        }
    }
    return farthestVertex;
}
int main() {
    //scanf("%lld", &n);
    std::cin >> n;
    for (long long  i = 1; i != n; i++)
    {
        long long u, v, weight;
        //scanf( "%lld %lld %lld", &u, &v, &weight);
        std::cin >> u >> v >> weight;
        graph[u].push_back(Edge(v, weight));
        graph[v].push_back(Edge(u, weight));
    }
    long long farthestVertex = breadFirstSearchMaxWeight(1);
    std::cout << farthestVertex;
    std::cout << distance[farthestVertex];
    std::memset(visited, false, n + 1);
    std::fill(distance, distance + n + 1, 0);

    farthestVertex = breadFirstSearchMaxWeight(farthestVertex);
    std::cout << farthestVertex;
    std::cout << distance[farthestVertex];
}