#pragma once

#include <glog/logging.h>
#include <iostream>

namespace SegmentTree{

struct Segment{
  int left;
  int right;
  int covered;
  Segment* lson;
  Segment* rson;
  Segment(): left(0), right(0), covered(0), lson(nullptr), rson(nullptr){}
  Segment(int l,int r): left(l),right(r),covered(0),lson(nullptr), rson(nullptr){}
};

inline std::ostream& operator<< (std::ostream& o,const Segment& seg){
  o<< "[Segment]: ("<< seg.left << ", "<< seg.right << "): " << seg.covered;
  return o;
}

class SegmentTree {
 public:
  SegmentTree(int left,int right){
    root = build(left,right);
  }

  ~SegmentTree(){
    destroyTree(root);
  }

  void insert(int left,int right) {
    insert(left,right,root);
  }

  void remove(int left,int right) {
    remove(left,right,root);
  }

  void print(bool only_covered = false){
    print(root,only_covered);
  }

  int covered(){
    return covered(root);
  }

  void insert(int left,int right,Segment* node);


  void remove(int left,int right,Segment* node);


  void print(Segment* node,bool only_covered = false);


  int covered(Segment* node);

 private:

  Segment* build(int left,int right);

  void destroyTree(Segment* node);

 private:
  Segment* root = nullptr;
  size_t size_ = 0;
  size_t num_leaf_ = 0;
};
}