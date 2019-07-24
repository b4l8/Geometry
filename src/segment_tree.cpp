#include "segment_tree.h"

namespace SegmentTree{

void SegmentTree::insert(int left,int right,Segment* node) {
  if (node == nullptr) {
    //LOG(ERROR) << "Empty input Node!";
    return;
  } else if (left <= node->left && right >= node->right) {
    node->covered++;
    return;
  } else {
    int mid = (node->left + node->right) >> 1;
    if (left < mid) {
      insert(left, right, node->lson);
    }
    if (right > mid) {
      insert(left, right, node->rson);
    }
  }
}

void SegmentTree::remove(int left,int right,Segment* node) {
  if (node == nullptr) {
    LOG(ERROR) << "Empty input Node!";
    return;
  } else if (left <= node->left && right >= node->right) {
    if(node->covered)
      node->covered--;
    return;
  } else {
    int mid = (right + left) >> 1;
    if (left < mid) {
      remove(left, right, node->lson);
    }
    if (right > mid) {
      remove(left, right, node->rson);
    }
  }
}

void SegmentTree::print(Segment* node,bool only_covered){
  if(node != nullptr){
    if((!only_covered) || (node->covered))
      LOG(INFO) << *node;
    print(node->lson,only_covered);
    print(node->rson,only_covered);
  }
}

Segment* SegmentTree::build(int left,int right) {
  if (right - left < 1) {
    //LOG(ERROR) << "Interval [" << left << " ," << right << "] invalid !!";
    return nullptr;
  } else {
    ++size_;
    Segment* node = new Segment(left,right);
    if (right -left == 1) {
      ++num_leaf_;
    } else {
      int mid = (right + left) >> 1;

      node->lson = build(left,mid);
      node->rson = build(mid,right);
    }
    return node;
  }
}

int SegmentTree::covered(Segment* node){
  int len = 0;
  if(node->covered)
    len += node->right - node->left;
  if(node->lson!= nullptr){
    len += covered(node->lson);
  }
  if(node->rson!= nullptr){
    len += covered(node->rson);
  }
  return len;
}

void SegmentTree::destroyTree(Segment* node){
  if(node!=nullptr){
    destroyTree(node->lson);
    destroyTree(node->rson);
    delete node;
    --size_;
  }
}
}