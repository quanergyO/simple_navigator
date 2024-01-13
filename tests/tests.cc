#include <gtest/gtest.h>

#include "test_graph.cc"
#include "test_algorithms.cc"


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

