#include "point.h"

bool operator==(const POINT& left, const POINT& right) {
    return (left.x == right.x)&&(left.y == right.y);
}