#include <catch2/catch_test_macros.hpp>

#include "Key.h"

using namespace cs225;
/** ADD TESTS HERE **/

TEST_CASE("Initializing Key Object Using Invalid Key", "[weight=1]") {
    REQUIRE_THROWS_AS( Key('S'), std::invalid_argument );
}

TEST_CASE("Correct Output Key From Pixel", "[weight=1]") {
    HSLAPixel pixel(180, 0.5, 0.5);
    Key key(pixel);
    REQUIRE(key.key == key.getKey(pixel));
    REQUIRE(key.value == key.getValue(key.getKey(pixel)));
}

TEST_CASE("isSharp Getting None Sharps", "[weight=1]") {
    Key key('c');
    Key key1('f');
    REQUIRE(key.isSharp() == true);
    REQUIRE(key1.isSharp() == true);
}

TEST_CASE("isSharp Getting Sharps", "[weight=1]") {
    Key key('C');
    Key key1 ('F');
    REQUIRE(key.isSharp() == false);
    REQUIRE(key1.isSharp() == false);
}

TEST_CASE("Uninitialized Key Is Empty", "[weight=1]") {
    Key key;
    REQUIRE(key.empty() == true);
}

TEST_CASE("Initialized Key Is Not Empty", "[weight=1]") {
    Key key('c');
    Key key1('F');
    REQUIRE(key.empty() == false);
    REQUIRE(key1.empty() == false);
}