#include "./monitor.h"

#include "gtest/gtest.h"

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
 ASSERT_FALSE(vitalsOk(99, 102, 70));
 ASSERT_TRUE(vitalsOk(98.1, 70, 98));
 ASSERT_FALSE(vitalsOk(104, 70, 98));  // Temp upper range
 ASSERT_TRUE(vitalsOk(93, 70, 98));  // Temp Lower range
 ASSERT_FALSE(vitalsOk(93, 50, 98));  // Pulse Lower range
 ASSERT_FALSE(vitalsOk(93, 110, 98));  // Pulse Lower range
 ASSERT_FALSE(vitalsOk(93, 70, 40));  // Pulse Lower range
 ASSERT_TRUE(vitalsOk(93, 110, 112));  // Pulse Lower range
}
