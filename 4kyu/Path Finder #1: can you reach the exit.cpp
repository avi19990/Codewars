#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <math.h>
#include <algorithm>
#include <map>
#include <sstream>

int coordToInt(int x, int y, int gridSize)
{
    return x + y * gridSize;
}

std::pair<int, int> directions[] = { std::make_pair(-1, 0), std::make_pair(0, -1), std::make_pair(1, 0), std::make_pair(0, 1) };
std::vector<int> getNeighbours(int node, int gridSize)
{
    std::vector<int> neighbours;

    for (size_t i = 0; i < 4; ++i)
    {
        std::pair<int, int> neighbour(node % gridSize + directions[i].first, node / gridSize + directions[i].second);

        if (neighbour.first < 0 || neighbour.first >= gridSize || neighbour.second < 0 || neighbour.second >= gridSize)
            continue;

        neighbours.push_back(coordToInt(neighbour.first, neighbour.second, gridSize));
    }

    return neighbours;
}

bool path_finder(std::string mazeString)
{
    std::istringstream input(mazeString);
    std::vector<bool> maze;

    char node;
    while (input >> node)
        maze.push_back(node == '.' ? true : false);

    int mazeSize = sqrt(maze.size());

    std::map <int, bool> visited;
    std::queue<int> toVisit;

    toVisit.push(coordToInt(0, 0, mazeSize));
    while (!toVisit.empty())
    {
        int current = toVisit.front();
        visited[current] = true;
        toVisit.pop();

        if (current == coordToInt(mazeSize - 1, mazeSize - 1, mazeSize))
            return true;

        for (int neighbour : getNeighbours(current, mazeSize))
            if (maze[neighbour])
                if (!visited[neighbour])
                {
                    toVisit.push(neighbour);
                    visited[neighbour] = true;
                }
    }

    return false;
}
