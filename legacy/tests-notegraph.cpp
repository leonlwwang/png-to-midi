#include <catch2/catch_test_macros.hpp>

#include "NoteGraph.h"

TEST_CASE("NoteGraph Default Constructor")
{
    NoteGraph test_graph = NoteGraph();
    matrix m = {{}};
    std::map<int,Note> t = {};
    int w = 0;

    REQUIRE(test_graph.graph() == m);
}

TEST_CASE("NoteGraph Manual Constructor")
{
    matrix m = {{-1, 40, -1, 16},
                {32, 15, -1, -1},
                {6, 67, 69, -1},
                {-1, -1, 3, 43}};
    std::map<int,Note> t = {{0,Note('A',5)},
                            {1,Note('F',1)},
                            {2,Note('E',7)}};
    NoteGraph test_graph = NoteGraph(m, t, 2);

    REQUIRE(test_graph.graph() == m);
    REQUIRE(test_graph.noteTable() == t);
    REQUIRE(test_graph.width() == 2);

    m = {{}};
    t = {};
    NoteGraph test_graph2 = NoteGraph(m, t, -1);

    REQUIRE(test_graph2.graph() == m);
    REQUIRE(test_graph2.noteTable() == t);
    REQUIRE(test_graph2.width() == -1);

    m = {{-1, -1, -1, -1, -1, -1, -1, -1}};
    t = {{-1,Note('f',4)}};
    NoteGraph test_graph3 = NoteGraph(m, t, 100);

    REQUIRE(test_graph3.graph() == m);
    REQUIRE(test_graph3.noteTable() == t);
    REQUIRE(test_graph3.width() == 100); 
}

TEST_CASE("NoteGraph PNG Constructor")
{
    cs225::PNG p = cs225::PNG();
    p.readFromFile("../images/basic/3x3.png");
    NoteGraph test_graph = NoteGraph(p);
    matrix m = {{-1, 15, -1, 22, -1, -1, -1, -1, -1},
                {15, -1, 57, -1, 56, -1, -1, -1, -1},
                {-1, 57, -1, -1, -1, 56, -1, -1, -1},
                {22, -1, -1, -1, 63, -1, 17, -1, -1},
                {-1, 56, -1, 63, -1, 57, -1, 86, -1},
                {-1, -1, 56, -1, 57, -1, -1, -1, 17},
                {-1, -1, -1, 17, -1, -1, -1, 4, -1},
                {-1, -1, -1, -1, 86, -1, 4, -1, 10},
                {-1, -1, -1, -1, -1, 17, -1, 10, -1}};
    std::map<int,Note> t = {{0,Note('G',4)},
                            {1,Note('B',5)},
                            {2,Note('A',10)},
                            {3,Note('f',6)},
                            {4,Note('D',1)},
                            {5,Note('C',6)},
                            {6,Note('C',8)},
                            {7,Note('F',8)},
                            {8,Note('f',7)}};
    int w = 3;

    REQUIRE(test_graph.graph() == m);
    REQUIRE(test_graph.noteTable() == t);
    REQUIRE(test_graph.width() == w);

    p.readFromFile("../images/basic/2x2.png");
    NoteGraph test_graph2 = NoteGraph(p);
    m = {{-1, 44, 35, -1},
         {44, -1, -1, 26},
         {35, -1, -1, 17},
         {-1, 26, 17, -1}};
    t = {{0,Note('A',3)},
         {1,Note('f',7)},
         {2,Note('A',6)},
         {3,Note('d',5)}};
    w = 2;

    REQUIRE(test_graph2.graph() == m);
    REQUIRE(test_graph2.noteTable() == t);
    REQUIRE(test_graph2.width() == w);
}

TEST_CASE("NoteGraph PNG Filename Constructor")
{
    // if the filename is invalid it's an issue with the PNG class which we aren't testing
    NoteGraph test_graph = NoteGraph("../images/basic/3x3.png");
    matrix m = {{-1, 15, -1, 22, -1, -1, -1, -1, -1},
                {15, -1, 57, -1, 56, -1, -1, -1, -1},
                {-1, 57, -1, -1, -1, 56, -1, -1, -1},
                {22, -1, -1, -1, 63, -1, 17, -1, -1},
                {-1, 56, -1, 63, -1, 57, -1, 86, -1},
                {-1, -1, 56, -1, 57, -1, -1, -1, 17},
                {-1, -1, -1, 17, -1, -1, -1, 4, -1},
                {-1, -1, -1, -1, 86, -1, 4, -1, 10},
                {-1, -1, -1, -1, -1, 17, -1, 10, -1}};
    std::map<int,Note> t = {{0,Note('G',4)},
                            {1,Note('B',5)},
                            {2,Note('A',10)},
                            {3,Note('f',6)},
                            {4,Note('D',1)},
                            {5,Note('C',6)},
                            {6,Note('C',8)},
                            {7,Note('F',8)},
                            {8,Note('f',7)}};
    int w = 3;

    REQUIRE(test_graph.graph() == m);
    REQUIRE(test_graph.noteTable() == t);
    REQUIRE(test_graph.width() == w);

    NoteGraph test_graph2 = NoteGraph("../images/basic/2x2.png");
    m = {{-1, 44, 35, -1},
         {44, -1, -1, 26},
         {35, -1, -1, 17},
         {-1, 26, 17, -1}};
    t = {{0,Note('A',3)},
         {1,Note('f',7)},
         {2,Note('A',6)},
         {3,Note('d',5)}};
    w = 2;

    REQUIRE(test_graph2.graph() == m);
    REQUIRE(test_graph2.noteTable() == t);
    REQUIRE(test_graph2.width() == w);
}

TEST_CASE("NoteGraph Setters")
{
    NoteGraph test_graph = NoteGraph();
    matrix m = {{-1, -1, -1}};
    test_graph.setGraph(m);

    REQUIRE(test_graph.graph() == m);

    std::map<int,Note> t = {{0, Note('D',3)}, {1, Note('C',7)}};
    test_graph.setNoteTable(t);

    REQUIRE(test_graph.noteTable() == t);

    test_graph.setWidth(11);

    REQUIRE(test_graph.width() == 11);
}

TEST_CASE("NoteGraph operator overload ==")
{
    NoteGraph test_graph = NoteGraph("../images/basic/3x3.png");
    NoteGraph test_graph2 = NoteGraph("../images/basic/5x5.png");
    bool b = (test_graph == test_graph2);

    REQUIRE(b == false);

    cs225::PNG p = cs225::PNG();
    p.readFromFile("../images/basic/3x3.png");
    test_graph2.pngToGraph(p);
    b = (test_graph == test_graph2);

    REQUIRE(b == true);

    NoteGraph test_graph3 = NoteGraph("../images/small/bunny.png");
    NoteGraph test_graph4 = NoteGraph("../images/small/guide.png");
    b = (test_graph3 == test_graph4);

    REQUIRE(b == false);

    p.readFromFile("../images/small/bunny.png");
    test_graph4.pngToGraph(p);
    b = (test_graph3 == test_graph4);

    REQUIRE(b == true);

    NoteGraph test_graph5 = NoteGraph();
    b = (test_graph5 == test_graph4);

    REQUIRE(b == false);

    NoteGraph test_graph6 = NoteGraph();
    b = (test_graph5 == test_graph6);

    REQUIRE(b == true);
}

/**
 * @note pngToGraph() is internally called in the PNG and filename 
    constructor test cases so it is also tested there.
 * @note the getters, graph(), noteTable(), and width() are called
    in the test cases so it is also tested there.
 * @note the private functions reset() and addToGraph() are called
    internally in the constructor test cases so it is tested there.
 * @note the printGraph() function prints to std out and is void.
 */