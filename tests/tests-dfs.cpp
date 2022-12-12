#include <catch2/catch_test_macros.hpp>

#include "algorithms/DFS.h"

/** ADD TESTS HERE **/


using namespace cs225;

TEST_CASE("DFS Works On 2x2 NoteGraph", "[weight=1]") {
    NoteGraph tbt = NoteGraph("../images/basic/2x2.png");
    std::list<int> dfs = notealgorithm::DFS(tbt);
    std::list<int> correct_dfs = { 36, 29, 22, 36, 29, 15, 15 ,22 };
    REQUIRE(dfs == correct_dfs);
}

TEST_CASE("DFS Works On 3x3 NoteGraph", "[weight=1]") {
    NoteGraph thbth = NoteGraph("../images/basic/3x3.png");
    std::list<int> dfs = notealgorithm::DFS(thbth);
    std::list<int> correct_dfs = { 13, 18, 48, 47, 13, 47, 48, 13, 53, 18, 48, 53, 47,
                                   72, 15, 47, 48, 13, 4, 8, 4, 72, 15, 8};
    REQUIRE(dfs == correct_dfs);
}