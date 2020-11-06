//
// Created by xhy on 2020/10/22.
//

#include "BlockPos.h"

bool BlockPos::operator==(const BlockPos &v) const {
    return x == v.x && y == v.y && z == v.z;
}

bool BlockPos::operator!=(const BlockPos &v) const {
    return x != v.x || y != v.y || z != v.z;
}

bool BlockPos::operator<(const BlockPos &rhs) const {
    if (x < rhs.x)
        return true;
    if (rhs.x < x)
        return false;
    if (y < rhs.y)
        return true;
    if (rhs.y < y)
        return false;
    return z < rhs.z;
}

float BlockPos::distanceTo(const BlockPos &blockPos) const {
    return (float) ((blockPos.x - x) * (blockPos.x - x) +
                    (blockPos.y - y) * (blockPos.y - y) +
                    (blockPos.z - z) * (blockPos.z - z));
}

std::ostream &operator<<(std::ostream &os, const BlockPos &vec3) {
    os << "[" << vec3.x << "," << vec3.y << "," << vec3.z << "]";
    return os;
}

Vec3 BlockPos::toVec3() const {
    return {x, y, z};
}

std::string BlockPos::toString() const {
    return "["
           + std::to_string(x) + ","
           + std::to_string(y) + ","
           + std::to_string(z) + "]";
}

std::vector<BlockPos> BlockPos::getNeighbourPos() {
    return {
            {x + 1, y,     z},
            {x - 1, y,     z},
            {x,     y + 1, z},
            {x,     y - 1, z},
            {x,     y,     z + 1},
            {x,     y,     z - 1}
    };
}
