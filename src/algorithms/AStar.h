/**
 * @file AStar.h
 *
 * Definition for A* Algorithm run on a NoteGraph.
 *
 * @author Leon Wang
 * @author Johnson Chiang
 * @author Patrick Han
 * @date Fall 2022
 */

#pragma once

#include "NoteGraph.h"

namespace notealgorithm {
    /**
     * Runs A* algorithm on a graph and constructs
       a minimum spanning tree out of the pathway.
     * Since a NoteGraph is a grid-like graph with a maximum of four directions 
       from each node, we opted to use Manhattan Distance as the heuristic.
     * @param graph the NoteGraph
     * @return the Minimum Spanning Tree (MST)
     */
    NoteGraph aStar(const NoteGraph &graph);

    /**
     * Custom Manhattan distance calculator that
       calculates the Manhattan distance on a weighted
       graph from one vertex to another.
     * @param start starting vertex
     * @param end destination vertex
     * @param graph the NoteGraph
     * @return the sum of the edges that the path traverses 
               through between the two vertices
     */
    int manh(int start, int end, const NoteGraph &graph);
}
