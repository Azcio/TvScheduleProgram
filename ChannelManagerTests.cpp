/** ChannelManagerTests.cpp
#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "channel.h"

// The ChannelManager class should be defined in Channel.h or included directly here if needed.

TEST_CASE("ChannelManager loads and displays channels", "[ChannelManager]") {
    ChannelManager channelManager;

    SECTION("loadChannels should handle non-existent files gracefully") {
        REQUIRE_FALSE(channelManager.loadChannels("non_existing_file.csv"));
        REQUIRE(channelManager.getChannelCount() == 0);
    }

    SECTION("loadChannels should successfully load channels from a valid file") {
        REQUIRE(channelManager.loadChannels("test_channels.csv"));
        REQUIRE(channelManager.getChannelCount() > 0);
    }

    SECTION("displayChannels should output channel names to cout") {
        channelManager.loadChannels("test_channels.csv");
        
        // Redirect cout to a stringstream
        std::streambuf* originalCout = std::cout.rdbuf();
        std::ostringstream capturedCout;
        std::cout.rdbuf(capturedCout.rdbuf());

        // Display channels
        channelManager.displayChannels();

        // Check the output
        std::string output = capturedCout.str();
        REQUIRE(!output.empty()); // Check that some output was captured
        REQUIRE(output.find("Channel:") != std::string::npos); // Check for a specific output format

        // Restore the original stream buffer so we don't interfere with further tests or any other output
        std::cout.rdbuf(originalCout);
    }
}
