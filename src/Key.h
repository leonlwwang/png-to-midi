/**
 * @file Key.h
 *
 * Implementation of a data structure that defines a piano key as a subset of the
 * primitive character datatype with a custom conversion method to integer.
 *
 * @author Leon Wang
 * @author Johnson Chiang
 * @author Patrick Han
 * @date Fall 2022
 */

#pragma once

#include <map>
#include <set>
#include <cmath>
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include "cs225/HSLAPixel.h"

struct Key 
{
   char key;
   int value;

   /**
    * Default constructor
    */
   Key() : key('C'), value(getValue('C')) {}

   /**
    * Constructor
    * @param c the character
    */
   Key(char c) : key(isKey(c)), value(getValue(c)) {}

   /**
    * Constructor
    * @param pixel the HSLAPixel
    */
   Key(const cs225::HSLAPixel &pixel) : key(getKey(pixel)), 
                                        value(getValue(getKey(pixel))) {}

   /**
    * Checks if input character is a valid key
    * @param c the character
    * @return the character if it was a valid key 
    */ 
   char isKey(char c) {
     std::map<char,int> toInt = {
                                {'C',0},{'c',1},{'D',2},{'d',3},{'E',4},{'F',5},
                                {'f',6},{'G',7},{'g',8},{'A',9},{'a',10},{'B',11}
                                }; 
     if (toInt.find(c) == toInt.end()) {
        throw std::invalid_argument("Not a valid Key");
     }
     return c;
   }

   /**
    * Character-to-integer conversion method
    * @param c the character
    * @return the integer form of the char based on conversion tables
    */
   int getValue(char c) {
      std::map<char,int> toInt = {
                                 {'C',0},{'c',1},{'D',2},{'d',3},{'E',4},{'F',5},
                                 {'f',6},{'G',7},{'g',8},{'A',9},{'a',10},{'B',11}
                                 };
      return toInt[c];
   }

   /**
    * Pixel-to-key conversion method
    * @param pixel the HSLAPixel
    * @return the char (Key) representation of the pixel
    */ 
   char getKey(const cs225::HSLAPixel &pixel) {
      std::map<int,char> toChar = {
                                  {0,'C'},{1,'c'},{2,'D'},{3,'d'},{4,'E'},{5,'F'},
                                  {6,'f'},{7,'G'},{8,'g'},{9,'A'},{10,'a'},{11,'B'}
                                  };
      return isKey(toChar[(int) std::fmod(pixel.h, 12)]);
   }

   /**
    * Sharp checker
    * @return whether the Key is a sharp
    */
   bool isSharp() const {
      std::set<char> sharps = {'c','d','f','g','a'};
      if (sharps.find(key) != sharps.end()) {
         return true;
      }
      return false;
   }
};

   /**
    * Overload operator <<
    * @param out Output stream
    * @param thisKey The Key to print
    * @return Output stream
    */
inline std::ostream & operator<<(std::ostream &out, Key const &thisKey) {
   std::map<char,std::string> sharps = {
                                       {'c',"C#"},{'d',"D#"},{'f',"F#"},{'g',"G#"},{'a',"A#"}
                                       };
   if (sharps.find(thisKey.key) != sharps.end()) {
      out << sharps[thisKey.key];
   }
   else {
      out << thisKey.key;
   }
   return out;
}
