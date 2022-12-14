/**
 * @file Note.h
 *
 * Implementation of a data structure that represents piano notes as a superset of the
 * Key data type, adding a range of ten octave levels and distance measurement. 
 *
 * @author Leon Wang
 * @author Johnson Chiang
 * @author Patrick Han
 * @date Fall 2022
 */

#pragma once

#include "Key.h"

struct Note : public Key
{

   Key key;
   unsigned int octave;

   /**
    * Default constructor, set at 5C (C key on 5th octave)
    */
   Note() : key(Key()), octave(5-1) {}

   /**
    * Key constructor
    * @param key on the piano roll
    * @param octave level the note is in (limit 10 octaves)
    */
   Note(Key key, unsigned int octave) : key(key), octave((octave-1)%10) {}

   /**
    * Character constructor
    * @param c the character
    * @param octave level the note is in (limit 10 octaves)
    */
   Note(char c, unsigned int octave) : key(Key(c)), octave((octave-1)%10) {}

   /**
    * HSLAPixel constructor
    * @param pixel the HSLAPixel
    */
   Note(const cs225::HSLAPixel &pixel) : key(Key(pixel)), 
                                         octave(getOctave(pixel)) {}

   /**
    * Distance method
    * @return the number of keys from C0 (0) to the Key
    */
   int distance() const {
      return key.value + (octave*12);
   }

   /**
    * Pixel-to-octave conversion method
    * @param pixel the HSLAPixel
    * @return the octave representation of the pixel
    */
   int getOctave(const cs225::HSLAPixel &pixel) {
      return (int) std::fmod(pixel.s*10, 10);
   }

   /**
    * Overload operator -
    * @param rhs The other Note
    * @return interval between two Notes (UNSCALED, scale to one octave using mod 10)
    */
   int operator-(const Note &rhs) {
      if (this->distance() == rhs.distance()) {
         return 0;
      }
      return std::abs(this->distance() - rhs.distance()) - 1;
   }

   /**
    * Overload operator ==
    * @param rhs The other Note
    * @return whether the Notes are equal
    */
   bool operator==(const Note &rhs) const {
      return (key == rhs.key && octave == rhs.octave);
   }
};

   /**
    * Overload operator <<
    * @param out Output stream
    * @param note The Note to print
    * @return Output stream
    */
inline std::ostream & operator<<(std::ostream &out, Note const &note) {
   out << note.octave+1 << note.key;
   return out;
}
