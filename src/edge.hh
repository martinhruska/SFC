#ifndef ACO_EDGE
#define ACO_EDGE

namespace ACO
{
  class Vertex;
}

namespace ACO
{
  class Edge;
}

class ACO::Edge
{
private:
  Vertex& v1_;
  Vertex& v2_;
  int distance_;

public: // constructor
  Edge(Vertex& v1, Vertex& v2, int distance) : v1_(v1), v2_(v2),
    distance_(distance) {}

public: // public methods
  Vertex& getSecondVertex(Vertex& v);
};

#endif
