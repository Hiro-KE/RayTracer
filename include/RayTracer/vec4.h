#pragma once

#include <cmath>
#include <iostream>
#include <RayTracer/utility.h>

class vec4
{

public:

    vec4() : e{0, 0, 0, 0} {}
    vec4(const double e) : e{e, e, e, e} {};
    vec4(const double e0, const double e1, const double e2) : e{e0, e1, e2, 0.f} {};
    vec4(const double e0, const double e1, const double e2, const double e3) : e{e0, e1, e2, e3} {};

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

    inline vec4& operator+=(const vec4 &v)
    {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        e[3] += v.e[3];
        return *this;
    }

    inline vec4& operator*=(const double t)
    {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        e[3] *= t;
        return *this;
    }

    inline vec4& operator/=(const double t)
    {
        return *this *= 1/t;
    }

    inline double length_squared() const 
    {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2] + e[3]*e[3];
    }

    inline double length() const 
    {
        return std::sqrt(length_squared());
    }

    inline static vec4 random()
    {
        return vec4(random_double(), random_double(), random_double(), random_double());
    }

    inline static vec4 random(const double min, const double max)
    {
        return vec4(random_double(min,max), random_double(min,max), random_double(min,max), random_double(min,max));
    }    

public:
    double e[4];

};

// Aliases
using location = vec4;
using color = vec4;


inline std::ostream& operator<<(std::ostream &out, const vec4 &v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2] << ' ' << v.e[3];
}

inline vec4 operator+(const vec4 &u, const vec4 &v) {
    return vec4(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2], u.e[3] + v.e[3]);
}

inline vec4 operator-(const vec4 &u, const vec4 &v) {
    return vec4(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2], u.e[3] - v.e[3]);
}

inline vec4 operator*(const vec4 &u, const vec4 &v) {
    return vec4(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2], u.e[3] * v.e[3]);
}

inline vec4 operator*(const double t, const vec4 &v) {
    return vec4(t*v.e[0], t*v.e[1], t*v.e[2], t*v.e[3]);
}

inline vec4 operator*(const vec4 &v, const double t) {
    return t * v;
}

inline vec4 operator/(const vec4 &v, const double t) {
    return v * (1 / t);
}

inline double dot(const vec4 &v, const vec4 &u) {
    return u.e[0] * v.e[0]
        + u.e[1] * v.e[1]
        + u.e[2] * v.e[2]
        + u.e[3] * v.e[3];
}

/** returns the cross product of the 2 vectors considering only the x, y and z values. No use case is needed for cross product 4D vectors*/
inline vec4 cross(const vec4 &u, const vec4 &v) {
    return vec4(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0],
                1.);
}

inline vec4 unit_vector(const vec4 v)
{
    return v / v.length();
}

inline vec4 random_in_unit_sphere()
{
    while (true)
    {
        auto p = vec4::random(-1., 1.);
        if (p.length_squared() >= 1)
        {
            continue;
        }
        return p;
    }
    return vec4(.5, .5, .5, .5);
}

inline vec4 random_unit_vector()
{
    return unit_vector(random_in_unit_sphere());
}