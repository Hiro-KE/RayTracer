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

    inline bool near_zero() const
    {
        // Return true if the vector is close to zero in all dimensions
        const auto s = 1e-8;
        return (fabs(e[0] < s) && fabs(e[1] < s) && fabs(e[2] < s) && fabs(e[3] < s));
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

inline vec4 random_in_hemisphere(const vec4& normal)
{
    vec4 in_unit_sphere = random_in_unit_sphere();
    if (dot(in_unit_sphere, normal) > 0.) // In the same hemisphere as the normal
    {
        return in_unit_sphere;
    }
    else
    {
        return -in_unit_sphere;
    }
}

inline vec4 reflect(const vec4& v, const vec4& n)
{
    return v - 2*dot(v, n) * n;
}

inline vec4 refract(const vec4& uv, const vec4& n, double etai_over_etat)
{
    auto cos_theta = fmin(dot(-uv, n), 1.);
    vec4 r_out_perp = etai_over_etat * (uv + cos_theta * n);
    vec4 r_out_parallel = -sqrt(fabs(1. - r_out_perp.length_squared())) * n;
    return r_out_perp + r_out_parallel;
}