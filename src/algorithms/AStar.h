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
     * Runs A* algorithm on a graph.
     * @param graph the NoteGraph
     * @return the Minimum Spanning Tree (MST)
     */
    NoteGraph aStar(const NoteGraph &graph);
}
