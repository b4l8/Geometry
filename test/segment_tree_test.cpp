#include <gtest/gtest.h>
#include "segment_tree.h"
#include <cstdlib>
#include <time.h>

using namespace std;

TEST(SegmentTreeTest,TestMemoryLeak){
  int n = 0;
  srand (time(NULL));
  while(n<1000){
    SegmentTree::SegmentTree stree(1,213);
    int left = rand()%100+1;
    int right = rand()%100+100;
    stree.insert(left,right);
    stree.print(true);
    ASSERT_EQ(stree.covered(), right-left);
    ++n;
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}