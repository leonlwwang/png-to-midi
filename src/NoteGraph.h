/**
 * @file NoteGraph.h
 *
 * Definition for a graph of Notes represented by an adjacency matrix.
 * Graph is constructed with a PNG image using UIUC CS225 libraries.
 *
 * @author Leon Wang
 * @author Johnson Chiang
 * @author Patrick Han
 * @date Fall 2022
 */

#pragma once

#include "NoteNode.h"
#include "cs225/PNG.h"
#include <map>
#include <string>
#include <vector>
#include <iostream>

typedef std::vector<std::vector<NoteNode>> matrix;

class NoteGraph 
{
    public:
        /**
         * Constructors
         */
        NoteGraph();
        NoteGraph(matrix graph);
        NoteGraph(const cs225::PNG &png);
        NoteGraph(const std::string &fileName);

        /**
         * Creates a graph of Notes using a PNG file and
           erases previous data loaded in the graph and table.
         * PNG constructors internally call this but can also
           be called explicitly to replace the current graph.
         * @param png the PNG file
         */
        void pngToGraph(const cs225::PNG &png);

        /**
         * Getter
         */
        matrix graph();

        /**
         * Setter
         */
        void setGraph(matrix newGraph);

        /**
         * Graph output function with proper spacing and organization.
         */
        void printGraph();

        /**
         * Overload operator ==
         * @param rhs the other NoteGraph
         * @return whether the NoteGraphs are equal
         */
        bool operator==(const NoteGraph &rhs) const;

    private:
        matrix graph_;

        /**
         * Given x,y coordinates for an HSLAPixel, converts it into a 
           Note and inserts it into a NoteNode container, then checks 
           for adjacent HSLAPixels which are added as connecting edges.
         * See NoteNode.h for more details.
         * @param x coordinate of pixel (row)
         * @param y coordinate of pixel (col)
         * @param png the PNG file
         */
        void addEdges(unsigned int x, unsigned int y, const cs225::PNG &png);
};
