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
  Edge(int id):id_(id),twin_(nullptr),pre_(nullptr),succ_(nullptr),ori_(nullptr),inc_face_(nullptr){}
  int id_;
  Edge* twin_;
  Edge* pre_;
  Edge* succ_;
  Vertex* ori_;
  Face* inc_face_;
};

struct Face {
  Face(int id): id_(id),inc_edge_(nullptr){}
  int id_;
  Edge* inc_edge_;
};


}