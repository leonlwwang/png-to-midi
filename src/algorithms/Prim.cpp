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
    int edge = 0, V = (int) graph.noteTable().size();
    matrix MSTdata(V, std::vector<int>(V, -1));
    matrix G = graph.graph();
    std::vector<bool> visited(V, false);
    visited[0] = true;
    //std::cout<<"Edge : Weight\n";
    while (edge < (V-1)) {
        int minimum = 121; // 120 is max edge-to-edge distance
        int edgeA = 0, edgeB = 0;
        for (int i = 0; i < V; i++) {
            if (visited[i]) {
                for (int j = 0; j < V; j++) {
                    if (!visited[j] && G[i][j] != -1) {
                        if (minimum > G[i][j]) {
                            minimum = G[i][j];
                            edgeA = i;
                            edgeB = j;
                        }
                    }
                }
            }
        }
        MSTdata[edgeA][edgeB] = G[edgeA][edgeB];
        MSTdata[edgeB][edgeA] = G[edgeA][edgeB];
        visited[edgeB] = true;
        edge++;
        //std::cout<<edgeA<<" - "<<edgeB<<" : "<<G[edgeA][edgeB]<<"\n";
    }
    NoteGraph MST = graph;
    MST.setGraph(MSTdata);
    return MST;
}
