#include "Board.hpp"
#include "Direction.hpp"
#include "doctest.h"
#include <iostream>

using namespace std;
using namespace ariel;

Direction h = Direction::Horizontal;
Direction v = Direction::Vertical;
Board board1;
Board board2;

//Checks an empty board
TEST_CASE("Empty Board") {
    CHECK_THROWS(board1.read(0,0,h,1));
}

//Checks throws of the read function
TEST_CASE("Bad Read Cases") {
    board1.post(0,4,h,"hello");
    board1.post(1,4,v,"ello");
    // spacebars used for better output readability
    // "h e l l o 
    // "e _ _ _ _ 
    // "l _ _ _ _ 
    // "l _ _ _ _ 
    // "o _ _ _ _ 

    CHECK_THROWS(board1.read(0,0,h,0)); // bad word length
    CHECK_THROWS(board1.read(6,0,h,1)); // row out of range
    CHECK_THROWS(board1.read(0,6,v,1)); // coll out of range
    CHECK_THROWS(board1.read(0,4,h,10)); // wrong word length(row)
    CHECK_THROWS(board1.read(1,4,v,10));// wrong word length(coll)
}

TEST_CASE("Good Post and Read Cases") {
    board1.post(0,0,h,"hello");
    CHECK(board1.read(0,0,h,4) == "hello");
    board1.post(1,0,v,"ello");
    CHECK(board1.read(1,0,v,4) == "hello");
    board1.post(0,1,v,"hello");
    CHECK(board1.read(0,1,v,4) == "hello");
    board1.post(0,2,v,"HELLO");
    CHECK(board1.read(0,2,v,4) == "HELLO");
    board1.post(0,3,v,"hello");
    CHECK(board1.read(0,3,v,4) == "hello");
    board1.post(0,4,v,"hello");
    CHECK(board1.read(0,4,v,4) == "hello");
    // "h h H h h _
    // "e e E e e _
    // "l l L l l _
    // "l l L l l _
    // "o o O o o _
}

TEST_CASE("Board Growth") {
    board2.post(0,1,h,"growth");
    board2.post(1,2,h,"growth");
    board2.post(2,3,h,"growth");
    board2.post(3,4,h,"growth");
    board2.post(4,5,h,"growth");
    CHECK(board2.read(0,0,h,1) == "_");
    CHECK(board2.read(1,2,h,2) == "__");
    CHECK(board2.read(2,3,h,3) == "___");
    CHECK(board2.read(3,4,h,4) == "____");
    CHECK(board2.read(4,5,h,5) == "_____");
    CHECK(board2.read(0,0,v,5) == "_____");
    CHECK(board2.read(0,1,v,5) == "g____");
    CHECK(board2.read(0,2,v,5) == "rg___");
    CHECK(board2.read(0,3,v,5) == "org__");
    CHECK(board2.read(0,4,v,5) == "worg_");
    CHECK(board2.read(0,5,v,5) == "tworg");
    CHECK(board2.read(0,11,v,5) == "_____");
    // _ g r o w t h _ _ _ _ _
    // _ _ g r o w t h _ _ _ _
    // _ _ _ g r o w t h _ _ _
    // _ _ _ _ g r o w t h _ _
    // _ _ _ _ _ g r o w t h _
}




