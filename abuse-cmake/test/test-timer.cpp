#include "catch.hpp"
#include "../src/lol/timer.h"

using namespace lol;

TEST_CASE("Constructeur, destructeur TIMER")
{
    Timer *test;
    //test Constructeur
    REQUIRE(test != nullptr);
    REQUIRE_NOTHROW(test = new Timer());
    //test Destructeur
    REQUIRE_NOTHROW(delete(test));
}

TEST_CASE("GET, POLL, WAIT MS")
{
    Timer *test = new Timer();

    //test WAIT
    REQUIRE_NOTHROW(test -> WaitMs(0));
    //test POLL avec GET
    REQUIRE(test -> GetMs() > test -> PollMs());
    //test GET
    REQUIRE(test -> GetMs() < 1);
    //test POLL
    REQUIRE(test -> PollMs() < 1);

    delete(test);
}
