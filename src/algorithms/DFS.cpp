/**
 * @file DFS.cpp
 *
 * Implementation for DFS traversal through a graph.
 *
 * @author Leon Wang
 * @author Johnson Chiang
 * @author Patrick Han
 * @date Fall 2022
 */

#include "DFS.h"

std::list<int> notealgorithm::DFS(const NoteGraph &graph) {
    std::list<int> list;
    std::stack<std::pair<int,int>> stack;
    matrix grid = graph.graph();
    int h = grid.size(), l = grid[0].size();
    std::vector<std::vector<bool>> visited(h, std::vector<bool>(l, false));
    stack.push({0, 0});
    while (!stack.empty()) {
        std::pair<int,int> curr = stack.top();
        stack.pop();
        int row = curr.first;
        int col = curr.second;
        if (row < 0 || col < 0 || row >= h || col >= l || visited[row][col]) {
            continue;
        }
        visited[row][col] = true;
        if (grid[row][col] != -1) {
            list.push_back(grid[row][col]);
        }
        stack.push({row, col+1});
        stack.push({row, col-1});
        stack.push({row+1, col});
        stack.push({row-1, col});
    }
    return list;
}