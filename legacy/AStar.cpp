/**
 * @file AStar.cpp
 *
 * Implementation for A* Algorithm run on a NoteGraph.
 *
 * @author Leon Wang
 * @author Johnson Chiang
 * @author Patrick Han
 * @date Fall 2022
 */

#include "AStar.h"

/**
* Custom Manhattan distance calculator that
calculates the Manhattan distance on a NoteGraph
from one vertex to another. 
* The graph that is provided MUST be in a grid format, meaning
that every node will have either TWO or FOUR edges.
* For invalid inputs, this will return -1.
* @param start starting vertex
* @param end destination vertex
* @param graph the NoteGraph
* @return the sum of the edges that the path traverses 
        through between the two vertices, -1 if invalid
*/
int manh(int start, int end, const NoteGraph &graph);

NoteGraph notealgorithm::aStar(const NoteGraph &graph) {
    int node = 0, V = graph.graph().size(), width = graph.width();
    matrix MSTdata(V, std::vector<int>(V, -1));
    matrix G = graph.graph();
    std::vector<bool> visited(V, false);
    visited[0] = true;
    //std::cout<<"Edge : Weight\n";
    while (node != (V-1)) {
        int minF = -1;
        int nodeA = 0, nodeB = 0;
        for (int i = 0; i < V; i++) {
            // check for an edge
            if (!visited[i] && G[node][i] != -1) {
                // calculate F = (G+H)
                int g = G[node][i];
                int h = manh(i, (V-1), graph);  // see below
                if (h == -1) {
                    std::cout << "WARNING: Invalid inputs.\n";
                }
                int F = g+h;
                // check if F is lower than minimum F
                if (minF == -1 || minF > F) {
                    minF = F;
                    nodeA = node;
                    nodeB = i;
                }
            }
        }
        // add the minimum value edge to MST
        MSTdata[nodeA][nodeB] = G[nodeA][nodeB];
        MSTdata[nodeB][nodeA] = G[nodeA][nodeB];
        visited[nodeB] = true;
        node = nodeB; // next node
        //std::cout<<nodeA<<" - "<<nodeB<<" : "<<G[nodeA][nodeB]<<"\n";
    }
    NoteGraph MST = graph;
    MST.setGraph(MSTdata);
    return MST;
}

int manh(int start, int end, const NoteGraph &graph) {
    int V = graph.noteTable().size();
    matrix G = graph.graph();
    if (start > end || start >= V || end >= V) {
        return -1;
    }
    if (start == end) {
        return 0;
    }
    int width = graph.width(), curr = start, distance = 0;
    while (curr != end) {           // loop until start reaches end
        if (curr + width <= end) {  // adjust y
            if (G[curr][curr+width] == -1) {
                return -1;
            }
            distance += G[curr][curr+width];
            curr += width;
        }
        else {                      // adjust x
            if (G[curr][curr+1] == -1) {
                return -1;
            }
            distance += G[curr][curr+1];
            curr++;
        }
    }
    return distance;
}
