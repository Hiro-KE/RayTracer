#pragma once

#include <cmath>
#include <iostream>

class vec4
{

public:

vec4() : e{0, 0, 0} {};

vec4(const double e0, const double e1, const double e2, const double e3) : e(e0, e1, e2, e3) {};

inline double x() const { return e[0]; }
inline double y() const { return e[1]; }
inline double z() const { return e[2]; }
inline double w() const { return e[3]; }

inline double r() const { return e[0]; }
inline double g() const { return e[1]; }
inline double b() const { return e[2]; }
inline double a() const { return e[3]; }

inline const vec4 operator-() const { return vec4(-e[0], -e[1], -e[2], -e[3]); };
inline const double operator[](int i) const { return e[i]; };
inline const double& operator[](int i) { return e[i]; };



private:

double e[4];
};