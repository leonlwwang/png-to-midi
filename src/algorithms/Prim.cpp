/**
 * @file Prim.cpp
 *
 * Implementation for Prim's Algorithm run on a NoteGraph.
 *
 * @author Leon Wang
 * @author Johnson Chiang
 * @author Patrick Han
 * @date Fall 2022
 */

#include "Prim.h"

NoteGraph notealgorithm::prim(const NoteGraph &graph) {
    int node = 0, V = (int) graph.noteTable().size();
    matrix MSTdata(V, std::vector<int>(V, -1));
    matrix G = graph.graph();
    std::vector<bool> visited(V, false);
    visited[0] = true;
    //std::cout<<"Edge : Weight\n";
    while (node < (V-1)) {
        int minimum = 121; // 120 is max edge value
        int nodeA = 0, nodeB = 0;
        for (int i = 0; i < V; i++) {
            // check the current MST tree
            if (visited[i]) {
                for (int j = 0; j < V; j++) {  
                    // check for an edge
                    if (!visited[j] && G[i][j] != -1) {
                        // check if edge is smaller than current min
                        if (minimum > G[i][j]) {
                            minimum = G[i][j];
                            nodeA = i;
                            nodeB = j;
                        }
                    }
                }
            }
        }
        // add the minimum value edge to MST
        MSTdata[nodeA][nodeB] = G[nodeA][nodeB];
        MSTdata[nodeB][nodeA] = G[nodeA][nodeB];
        visited[nodeB] = true;
        node++; // next node
        //std::cout<<nodeA<<" - "<<nodeB<<" : "<<G[nodeA][nodeB]<<"\n";
    }
    NoteGraph MST = graph;
    MST.setGraph(MSTdata);
    return MST;
}
