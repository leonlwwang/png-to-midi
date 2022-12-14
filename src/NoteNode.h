/**
 * @file NoteNode.h
 *
 * Implementation of a node that encapsulates a Note object and provides 
 * weighted edges to make a graph of nodes.
 *
 * @author Leon Wang
 * @date Fall 2022
 */

#pragma once

#include "Note.h"
#include <list>

struct NoteNode 
{
   typedef std::pair<int,NoteNode> edge;
   Note note;
   std::list<edge> edges;
   /**
    * Default constructor (uninitialized node)
    */
   NoteNode() : note(Note()), edges({}) {}

   /**
    * Note constructor (initialized node)
    */
   NoteNode(Note n) : note(n), edges({}) {}

   /**
    * Edge add function
    * @param node the connecting node
    */
   void addEdge(NoteNode node) {
     int weight = this->note - node.note;
     edges.push_back(edge(weight, node));
   }

   /**
    * Null checker
    * @return whether a NoteNode is initialized
    */
   bool empty() const {
      return note.empty();
   }

   /**
   * Overload operator ==
   * @param rhs The other NoteNode
   * @return whether the NoteNodes are equal
   */
   bool operator==(const NoteNode &rhs) const {
     return (note == rhs.note && edges == rhs.edges);
   }
};

   /**
    * Overload operator <<
    * @param out Output stream
    * @param node The NoteNode to print
    * @return Output stream
    */
inline std::ostream & operator<<(std::ostream &out, NoteNode const &node) {
   if (node.empty()) {
      out << "NULL";
      return out;
   }
   out << node.note;
   for (const NoteNode::edge &e : node.edges) {
      // check if the edge is valid (not connected to an uninitialized node)
      if (e.first != -1) {
         out << " ---> " << e.first << " ---> " << e.second.note;
      }
   }
   return out;
}
