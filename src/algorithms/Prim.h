/**
 * @file Prim.h
 *
 * Definition for Prim's Algorithm run on a NoteGraph.
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
     * Run Prim's algorithm on a NoteGraph and constructs
       a minimum spanning tree out of the pathway. 
     * @param graph the NoteGraph
     * @return the Minimum Spanning Tree (MST)
     */
    NoteGraph prim(const NoteGraph &graph);
}
