#include <cmath>
#include <iostream>
#include "rhoban_graphs/a_star.h"

using namespace rhoban_graphs;
using rhoban_geometry::Point;

int main()
{
    auto result = AStar::solveCont(Point(0, 0), Point(2, 0),
            [](Point point) -> bool {
                Point obstacle(1, 0);
                return (point-obstacle).getLength() > 0.5;
            },
            0.02
            );

    for (auto pos : result) {
        std::cout << pos.x << " " << pos.y << std::endl;
    }
}
