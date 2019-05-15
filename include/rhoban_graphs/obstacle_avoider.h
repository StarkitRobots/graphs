#pragma once

#include <functional>

#include "starkit_geometry/circle.h"
#include "starkit_geometry/point.h"

namespace starkit_graphs
{
class ObstacleAvoider
{
public:
  void addObstacle(starkit_geometry::Point center, double radius);

  std::vector<starkit_geometry::Point>
  findPath(starkit_geometry::Point start, starkit_geometry::Point goal, double accuracy = 20, double* score = NULL,
           std::function<bool(starkit_geometry::Point)> filter = [](starkit_geometry::Point) { return true; });

protected:
  std::vector<starkit_geometry::Circle> obstacles;
};

}  // namespace starkit_graphs
