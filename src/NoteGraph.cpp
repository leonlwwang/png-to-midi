/**
 * @file NoteGraph.h
 *
 * Implementation for a graph of Notes represented by an adjacency matrix.
 * Graph is constructed with a PNG image using UIUC CS225 libraries.
 *
 * @author Leon Wang
 * @author Johnson Chiang
 * @author Patrick Han
 * @date Fall 2022
 */

#include "NoteGraph.h"

using namespace cs225;

NoteGraph::NoteGraph() : graph_({{}}), noteTable_({}) {}

NoteGraph::NoteGraph(const PNG &png) : graph_({{}}), noteTable_({}) {
   pngToGraph(png);
}

NoteGraph::NoteGraph(const std::string &fileName) : graph_({{}}), 
                                                    noteTable_({}) {
   PNG png = PNG();
   png.readFromFile(fileName);
   pngToGraph(png);
}

void NoteGraph::pngToGraph(const PNG &png) {
   reset(png.width()*png.height());
   unsigned int i = 0;
   for (unsigned y = 0; y < png.height(); y++) {
      for (unsigned x = 0; x < png.width(); x++) {
         addToGraph(x,y,i,png);
         i++;
      }
   }
   return;
}

void NoteGraph::reset(int resolution) {
   graph_.clear();
   noteTable_.clear();
   graph_.resize(resolution, std::vector<int>(resolution));
}

void NoteGraph::addToGraph(unsigned int x, unsigned int y, int i, const PNG &png) {
   // std::cout<<"("<<x<<","<<y<<")\t["<<i<<"/"<<png.height()*png.width()-1<<"]\n";
   noteTable_[i] = Note(png.getPixel(x,y));
   if (x+1 < png.width()) {
      int interval = Note(png.getPixel(x,y)) - Note(png.getPixel(x+1,y));
      graph_[i][i+1] = interval;
      graph_[i+1][i] = interval;
   }
   if ((int)(x-1) >= 0) {
      int interval = Note(png.getPixel(x,y)) - Note(png.getPixel(x-1,y));
      graph_[i][i-1] = interval;
      graph_[i-1][i] = interval;
   }
   if (y+1 < png.height()) {
      int interval = Note(png.getPixel(x,y)) - Note(png.getPixel(x,y+1));
      graph_[i][i+png.width()] = interval;
      graph_[i+png.width()][i] = interval;
   }
   if ((int)(y-1) >= 0) {
      int interval = Note(png.getPixel(x,y)) - Note(png.getPixel(x,y-1));
      graph_[i][i-png.width()] = interval;
      graph_[i-png.width()][i] = interval;
   }
}

matrix NoteGraph::graph() const {
   return graph_;
}

std::map<int,Note> NoteGraph::noteTable() const {
   return noteTable_;
}

void NoteGraph::printGraph(const unsigned int threshold) {
   // output size limiter
   unsigned limit = 0, remainder = 0;
   if (graph_.size() > threshold) { 
       limit = threshold; 
       remainder = graph_.size() - threshold;
   }
   else { limit = graph_.size(); }
   // header
   std::cout << "     ";
   for (size_t i = 0; i < limit; i++) {
       std::cout << noteTable_[i] << " ";
       if (!noteTable_[i].key.isSharp()) {
           std::cout << " ";
       }
   }
   std::cout << "\n";
   // row by row
   for (size_t i = 0; i < limit; i++) {
       if (!noteTable_[i].key.isSharp()) {
           std::cout << noteTable_[i] << "   ";
       } else {
           std::cout << noteTable_[i] << "  ";
       }
       for (size_t j = 0; j < limit; j++) {
           if (graph_[i][j] == 0) {
               std::cout << "-   ";
           } else {
               std::cout << graph_[i][j];
               int n = graph_[i][j] / 10;
               if (n < 1) { std::cout << "   "; }
               else if (n < 10) { std::cout << "  "; }
               else { std::cout << " "; }
           }
       }
       std::cout << "\n";
   }
   if (remainder != 0) {
       std::cout << "<and " << remainder << " more rows>\n";
   }
}
