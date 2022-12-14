#include <catch2/catch_test_macros.hpp>

#include "Note.h"

Key test_key = Key('C');
Key test_key_2 = Key('F');
Key test_key_3 = Key();

Note test_note = Note(test_key, 1);
Note test_note_2 = Note(test_key_2, 2);
Note test_note_3 = Note(test_key_3, 1);

TEST_CASE("Constructor-Key", "[weight=10][part1]")
{
	REQUIRE(test_note.key.key == 'C');
    REQUIRE(test_note_2.key.key == 'F');
    REQUIRE(test_note_3.key.key == 'X');
}

TEST_CASE("Constructor-Image Pixel", "[weight=10][part1]")
{
	cs225::HSLAPixel pixel(55, 0.5, 0.75);
    Note test_note_4 = Note(pixel);
    REQUIRE(test_note_4.key.key == 'G');
    REQUIRE(test_note_4.octave == 5);

    cs225::HSLAPixel pixel2(76, 0.85, 0.3);
    Note test_note_5 = Note(pixel2);
    REQUIRE(test_note_5.key.key != 'C');
    REQUIRE(test_note_5.octave != 2);
}

TEST_CASE("Constructor-Invalid Key", "[weight=10][part1]")
{
	REQUIRE_THROWS_AS(Note('P', 1), std::invalid_argument);
}

TEST_CASE("Constructor-octave", "[weight=10][part1]")
{
	REQUIRE(test_note.octave == 0);
    REQUIRE(test_note_2.octave == 1);
}

TEST_CASE("Distance", "[weight=10][part1]")
{
	REQUIRE(test_note.distance() == 0);
    REQUIRE(test_note_2.distance() == 17);
}


TEST_CASE("Get Octave", "[weight=10][part1]")
{
	cs225::HSLAPixel pixel(55, 0.5, 0.75);
    Note test_note_4 = Note(pixel);
    REQUIRE(test_note_4.getOctave(pixel) == 5);

    cs225::HSLAPixel pixel2(76, 0.85, 0.3);
    Note test_note_5 = Note(pixel2);
    REQUIRE(test_note_5.getOctave(pixel2) != 2);
}

TEST_CASE("empty()", "[weight=10][part1]")
{
	REQUIRE(test_note.empty() == false);
    REQUIRE(test_note_3.empty() == true);
}
