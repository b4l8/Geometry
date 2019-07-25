#pragma once

#include <glog/logging.h>
#include <iostream>

namespace DCEL{
struct Vertex{
  Vertex(int id,double x,double y) : id_(id1),x_(x1),y_(y1),inc_edge_(nullptr) {}
  int id_;
  double x_;
  double y_;
  Edge* inc_edge_;
};

struct Edge {
  Edge(int id):id_(id),ori_(nullptr),end_(nullptr),left_(nullptr),right_(nullptr),p1_(nullptr),p2_(nullptr){}
  int id_;
  // origin of edge
  Vertex* ori_;
  // end of edge
  Vertex* end_;
  // left/ down face divided by this edge
  Face* left_;
  // right/up face divided by this edge
  Face* right_;
  // assign first edge from ori in counter clock wise
  Edge* p1_;
  // assign first edge from end in counter clock wise
  Edge* p2_;
};

struct Face {
  Face(int id): id_(id),inc_edge_(nullptr){}
  int id_;
  Edge* inc_edge_;
};


}