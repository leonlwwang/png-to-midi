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

NoteGraph::NoteGraph() : graph_({{}}) {}

NoteGraph::NoteGraph(matrix graph) : graph_(graph) {}

NoteGraph::NoteGraph(const PNG &png) : graph_({{}}) {
   pngToGraph(png);
}

NoteGraph::NoteGraph(const std::string &fileName) : graph_({{}}) {
   PNG png = PNG();
   png.readFromFile(fileName);
   pngToGraph(png);
}

void NoteGraph::pngToGraph(const PNG &png) {
   graph_.clear();
   graph_.resize(png.width(), std::vector<NoteNode>(png.height()));
   // initialize nodes (x is column, y is row)
   for (unsigned y = 0; y < png.height(); y++) {
      for (unsigned x = 0; x < png.width(); x++) {
         graph_[y][x] = NoteNode(Note(png.getPixel(x,y)));
      }
   }
   // add edges
   for (unsigned y = 0; y < png.height(); y++) {
      for (unsigned x = 0; x < png.width(); x++) {
         addEdges(x, y, png);
      }
   }
   return;
}

void NoteGraph::addEdges(unsigned int x, unsigned int y, const PNG &png) {
   /* WARNING: changing the order of this can mess up the output. See line 87.*/
   // right
   if (x+1 < png.width()) {
      graph_[y][x].addEdge(graph_[y][x+1]);
   }
   // down
   if (y+1 < png.height()) {
      graph_[y][x].addEdge(graph_[y+1][x]);
   }
   // left
   if ((int)(x-1) >= 0) {
      graph_[y][x].addEdge(graph_[y][x-1]);
   }
   // up
   if ((int)(y-1) >= 0) {
      graph_[y][x].addEdge(graph_[y-1][x]);
   }
}

matrix NoteGraph::graph() {
   return graph_;
}

void NoteGraph::setGraph(matrix newGraph) {
   graph_ = newGraph;
}

void NoteGraph::printGraph() {
   /* PRINT LIMITS */
   unsigned row = graph_.size();
   if (row > 31) {
      row = 31;
   }
   unsigned col = graph_[0].size();
   if (col > 11) {
      col = 11;
   }

   for (unsigned i = 0; i < row; i++) {
      std::vector<int> downs;
      for (unsigned j = 0; j < col; j++) {
         /* PRINT NODES */
         std::cout << "[";
         Note n = graph_[i][j].note;
         if (n.octave+1 < 10 || (!n.key.isSharp())) {
            std::cout << "  ";
         } else {
            std::cout << " ";
         }
         std::cout << n;
         if (n.octave+1 < 10) {
            std::cout << " ";
         }
         if (!n.key.isSharp()) {
            std::cout << " ";
         }
         if (n.octave+1 > 10 && n.key.isSharp()) {
            std::cout << " ";
         }
         std::cout << "]";

         /* PRINT RIGHT EDGES */
         std::list<NoteNode::edge> copy = graph_[i][j].edges;
         // no edges
         if (copy.empty()) {
            std::cout << '\t';
         }
         // edges exist but node is on the x boundary (aka no right edge)
         else if (j == graph_[i].size()-1) {
            // special case: last node (on both boundaries), no right or down edges
            if (i != graph_.size()-1) {
               // save the down edge if it exists
               NoteNode::edge down = copy.front();
               if (down.first != -1) {
                  downs.push_back(down.first);
               }
            }
         }
         // edges exist (only want first TWO listed edges, right & down)
         else {
            // print the right edge
            NoteNode::edge right = copy.front();
            copy.pop_front();
            if (right.first != -1) {
               if (right.first < 10) {
                  std::cout << "---";
               } else if (right.first > 99) {
                  std::cout << "-";
               } else {
                  std::cout << "--";
               }
               std::cout << right.first << "--";
            }
            else {
               std::cout << "\t";
            }
            // save down edge if exists or NOT on y boundary (aka no down edge)
            if (!copy.empty() && i != graph_.size()-1) {
               NoteNode::edge down = copy.front();
               if (down.first != -1) {
                  downs.push_back(down.first);
               }
            }
         }
      }

      /* PRINT DOWN EDGES */
      if (downs.empty()) {
         std::cout << "\n\n\n\n";
      }
      else {
         std::cout << '\n';
         for (unsigned i = 0; i < downs.size(); i++) {
            if (i==0) { std::cout << "   |        "; }
            else { std::cout << "     |        "; }
         }
         std::cout << '\n';
         for (unsigned i = 0; i < downs.size(); i++) {
            if (i==0) { std::cout << "   " << downs[i] << "         "; }
            else { std::cout << "   " << downs[i] << "         "; }
         }
         std::cout << '\n';
         for (unsigned i = 0; i < downs.size(); i++) {
            if (i==0) { std::cout << "   |        "; }
            else { std::cout << "     |        "; }
         }
         std::cout << '\n';
      }
      downs.clear();
   }
   std::cout << '\n';
}

bool NoteGraph::operator==(const NoteGraph &rhs) const {
   return (graph_ == rhs.graph_);
}
