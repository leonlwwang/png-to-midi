#include <catch2/catch_test_macros.hpp>

#include "algorithms/AStar.h"

NoteGraph n = NoteGraph("../images/basic/3x3.png");
NoteGraph n_2 = NoteGraph("../images/basic/2x2.png");
NoteGraph n_3 = NoteGraph();


TEST_CASE("AStar-Test-Output-1-3x3-Matrix", "[weight=10][part1]")
{
    NoteGraph aStarMST = notealgorithm::aStar(n);
    matrix m = {{-1, -1, -1, 22, -1, -1, -1, -1, -1}, \
                {-1, -1, -1, -1, -1, -1, -1, -1, -1}, \
                {-1, -1, -1, -1, -1, -1, -1, -1, -1}, \
                {22, -1, -1, -1, -1, -1, 17, -1, -1}, \
                {-1, -1, -1, -1, -1, -1, -1, -1, -1}, \
                {-1, -1, -1, -1, -1, -1, -1, -1, -1}, \
                {-1, -1, -1, 17, -1, -1, -1, 4 , -1}, \
                {-1, -1, -1, -1, -1, -1, 4 , -1, 10}, \
                {-1, -1, -1, -1, -1, -1, -1, 10, -1}};

    std::map<int, Note> t = {{0, Note('G', 4)}, \
                             {1, Note('B', 5)}, \
                             {2, Note('A', 10)}, \
                             {3, Note('f', 6)}, \
                             {4, Note('D', 1)}, \
                             {5, Note('C', 6)}, \
                             {6, Note('C', 8)}, \
                             {7, Note('F', 8)}, \
                             {8, Note('f', 7)}};
    
	REQUIRE(aStarMST.graph() == m);
    REQUIRE(aStarMST.noteTable() == t);
    REQUIRE(aStarMST.width() == 3);
}

TEST_CASE("AStar-Test-Output-2-2x2-Matrix", "[weight=10][part1]")
{
    NoteGraph aStarMST = notealgorithm::aStar(n_2);
    matrix m_2 = {{-1, -1, 35, -1}, \
                  {-1, -1, -1, -1}, \
                  {35, -1, -1, 17}, \
                  {-1, -1, 17, -1}};

    std::map<int, Note> t_2 = {{0, Note('A', 3)}, \
                               {1, Note('f', 7)}, \
                               {2, Note('A', 6)}, \
                               {3, Note('d', 5)}};
    
	REQUIRE(aStarMST.graph() == m_2);
    REQUIRE(aStarMST.noteTable() == t_2);
    REQUIRE(aStarMST.width() == 2);
}

TEST_CASE("AStar-Test-Output-3-Empty-NoteGraph", "[weight=10][part1]")
{
    NoteGraph aStarMST = notealgorithm::aStar(n_3);
    matrix m_3 = {{-1}};

    std::map<int, Note> t_3 = {};
    
	REQUIRE(aStarMST.graph() == m_3);
    REQUIRE(aStarMST.noteTable() == t_3);
    REQUIRE(aStarMST.width() == 0);
}
