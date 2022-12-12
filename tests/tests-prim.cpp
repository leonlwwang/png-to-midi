#include <catch2/catch_test_macros.hpp>

#include "algorithms/Prim.h"

/** ADD TESTS HERE **/

using namespace cs225;


TEST_CASE("Prim Works On 2x2 NoteGraph", "[weight=1]") {
    NoteGraph tbt = NoteGraph("../images/basic/2x2.png");
    NoteGraph mst = notealgorithm::prim(tbt);
    matrix correct_prim = {{-1, -1, 29, -1},
                           {-1, -1, -1, 22},
                           {29, -1, -1, 15},
                           {-1, 22, 15, -1}};
    std::map<int, Note> octaves = {{0, Note('A', 3)},
                                   {1, Note('f', 7)},
                                   {2, Note('A', 6)},
                                   {3, Note('d', 5)}};
    REQUIRE(mst.graph() == correct_prim);
    REQUIRE(mst.noteTable() == octaves);
    REQUIRE(mst.width() == 2);
}

TEST_CASE("Prim Works On 3x3 NoteGraph", "[weight=1]") {
    NoteGraph thbth = NoteGraph("../images/basic/3x3.png");
    NoteGraph mst = notealgorithm::prim(thbth);
    matrix correct_prim = {{-1, 13, -1, 18, -1 ,-1 ,-1 ,-1 ,-1},
                           {13, -1 ,47, -1 ,-1 ,-1 ,-1 ,-1 ,-1},
                           {-1, 47, -1, -1, -1, -1, -1, -1, -1},
                           {18, -1, -1, -1, -1, -1, 13, -1, -1},
                           {-1, -1, -1, -1, -1, 47, -1, -1, -1},
                           {-1, -1, -1, -1, 47, -1, -1, -1, 15},
                           {-1, -1, -1, 13, -1, -1, -1, 4, -1},
                           {-1, -1, -1, -1, -1, -1, 4, -1, 8},
                           {-1, -1, -1, -1, -1, 15, -1, 8, -1}};
    std::map<int, Note> octaves = {{0, Note('G', 4)},
                                   {1, Note('B', 5)},
                                   {2, Note('A', 10)},
                                   {3, Note('f', 6)},
                                   {4, Note('D', 1)},
                                   {5, Note('C', 6)},
                                   {6, Note('C', 8)},
                                   {7, Note('F', 8)},
                                   {8, Note('f', 7)}};
                                   
    REQUIRE(mst.graph() == correct_prim);
    REQUIRE(mst.noteTable() == octaves);
    REQUIRE(mst.width() == 3);
}
