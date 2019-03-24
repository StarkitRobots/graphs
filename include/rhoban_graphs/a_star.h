#pragma once

#include <functional>

#include "rhoban_geometry/point.h"

namespace rhoban_graphs
{
class AStar
{
public:
  struct Pos
  {
    Pos();
    Pos(int x, int y);

    double dist(const Pos& other) const;

    int x;
    int y;

    inline bool operator<(const Pos& other) const
    {
      if (x == other.x)
      {
        return y < other.y;
      }
      else
      {
        return x < other.x;
      }
    }
  };

  struct Box
  {
    double reachScore;
    double score;
    Pos pos;
    Pos parent;

    inline bool operator<(const Box& other) const
    {
      if (score == other.score)
      {
        return pos < other.pos;
      }
      else
      {
        return score < other.score;
      }
    }
  };

  static std::vector<Pos> solve(Pos start, Pos goal, std::function<bool(Pos)> reachable, size_t maxIter = 0,
                                double* score = NULL);

  static std::vector<rhoban_geometry::Point> solveCont(rhoban_geometry::Point start, rhoban_geometry::Point goal,
                                                       std::function<bool(rhoban_geometry::Point)> reachable,
                                                       double step, size_t maxIter = 0, double* score = NULL);
};

}  // namespace rhoban_graphs
