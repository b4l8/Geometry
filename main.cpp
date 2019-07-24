#include <iostream>
#include "segment_tree.h"
int main(int argc, char* argv[]) {
  google::InitGoogleLogging(argv[0]);
  FLAGS_alsologtostderr = true;
  FLAGS_colorlogtostderr = true;
  int n = 0;
  while(n<1000){
    SegmentTree::SegmentTree stree(1,213);
    stree.insert(62,87);
    stree.print(true);
    ++n;
  }
  return 0;
}