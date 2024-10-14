#include "./monitor.h"

#include "gtest/gtest.h"

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
    ASSERT_FALSE(vitalsOk(103, 105, 70));
    ASSERT_TRUE(vitalsOk(98.1f, 70, 98));
    ASSERT_FALSE(vitalsOk(99, 102, 70));  // Temp upper range
    ASSERT_FALSE(vitalsOk(103, 80, 94));  // Temp Lower range
    ASSERT_FALSE(vitalsOk(98, 105, 94));  // Pulse Lower range
    ASSERT_FALSE(vitalsOk(98, 80, 70));  // Pulse Lower range
    ASSERT_FALSE(vitalsOk(103, 105, 94));  // Pulse Lower range
    ASSERT_FALSE(vitalsOk(103, 80, 70));  // Pulse Lower range
}
