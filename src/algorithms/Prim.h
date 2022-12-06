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

class Prim : public NoteGraph {
    public:
        /**
         * Run Prim's algorithm on a graph.
         * @param graph the NoteGraph
         * @return the Minimum Spanning Tree (MST)
         */
        NoteGraph prim(const NoteGraph &graph);

    private:
        // @todo!
};
