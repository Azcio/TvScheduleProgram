#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Schedule.h"

TEST_CASE("Data Handling", "[ProgrammeSchedule]") {
       ProgrammeSchedule ps1;
    ps1.ProgramID = "001";
    ps1.Name = "Planet Earth";
    ps1.Duration = "60 minutes";
    ps1.Genre = "Documentary";
    ps1.Channel = "Channel X"; 

        SECTION("Check Program Data Storage") {
        REQUIRE(ps1.ProgramID == "001");
        REQUIRE(ps1.Name == "Planet Earth");
        REQUIRE(ps1.Duration == "60 minutes");
        REQUIRE(ps1.Genre == "Documentary");
        REQUIRE(ps1.Channel == "Channel X");

        ProgrammeSchedule ps2;
    ps2.ProgramID = "002";
    ps2.Name = "The Big Bang Theory";
    ps2.Duration = "30 minutes";
    ps2.Genre = "Comedy";
    ps2.Channel = "Comedy Central";

    SECTION("Check Different Program Types") {
        REQUIRE(ps2.ProgramID == "002");
        REQUIRE(ps2.Name == "The Big Bang Theory");
        REQUIRE(ps2.Duration == "30 minutes");
        REQUIRE(ps2.Genre == "Comedy");
        REQUIRE(ps2.Channel == "Comedy Central");
    }
}
}