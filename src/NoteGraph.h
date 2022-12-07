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

#include "Note.h"
#include "cs225/PNG.h"
#include <map>
#include <string>
#include <vector>
#include <iostream>

typedef std::vector<std::vector<int>> matrix;

class NoteGraph 
{
    public:
        /**
         * Constructors
         */
        NoteGraph();
        NoteGraph(matrix graph, std::map<int,Note> noteTable, int width);
        NoteGraph(const cs225::PNG &png);
        NoteGraph(const std::string &fileName);

        /**
         * Creates a graph of Notes using a PNG file and
           erases previous data loaded in the graph and table.
         * Non-default constructors internally call this.
         * @param png the PNG file
         */
        void pngToGraph(const cs225::PNG &png);

        /**
         * Getters
         */
        matrix graph() const;
        std::map<int,Note> noteTable() const;
        int width() const;

        /**
         * Graph output function with proper spacing and organization.
         * NOTE that there is a set limit to row/col prints because it can
           overflow the terminal. You can override it, but it's not recommended.
         * @param threshold limit to number of row/cols printed, default=20
         */
        void printGraph(const unsigned int threshold = 20);

        /**
         * Overload operator ==
         * @param rhs the other NoteGraph
         * @return whether the NoteGraphs are equal
         */
        bool operator==(const NoteGraph &rhs) const;

    private:
        matrix graph_;
        std::map<int,Note> noteTable_;
        int width_;

        /**
         * Resets the state of the NoteGraph object and
           clears private instance variables.
         * @param resolution the new PNG resolution (x*y)
         */
        void reset(int resolution);

        /**
         * Given x,y coordinates for an HSLAPixel, converts it into a 
           Note and adds it as a vertex to the note table, then checks 
           for adjacent HSLAPixels which are added as weighted edges to the graph.
         * @param x coordinate of pixel (row)
         * @param y coordinate of pixel (col)
         * @param i ith pixel out of (x*y)
         * @param png the PNG file
         */
        void addToGraph(unsigned int x, unsigned int y, int i, const cs225::PNG &png);
};
