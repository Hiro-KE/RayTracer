#pragma once

#include <cmath>
#include <limits>
#include <memory>

// Usings

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions

inline double degree_to_redians(double degrees)
{
    return degrees * pi / 180.;
}

// Commong headers

#include <RayTracer/ray.h>
#include <RayTracer/vec4.h>