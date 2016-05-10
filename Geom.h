//
// Created by Lokotochek on 11.05.16.
//

#ifndef RAYTRACINGGL_GEOM_H
#define RAYTRACINGGL_GEOM_H

#include <cmath>
#include <algorithm>

const double EPS = 0.0001;

class CPoint3D {
private:

    double m_x;
    double m_y;
    double m_z;

public:

    CPoint3D() : m_x(0.0), m_y(0.0), m_z(0.0) {}
    CPoint3D(double x, double y, double z) : m_x(x), m_y(y), m_z(z) {}
    CPoint3D(const CPoint3D& point);

    double get_x() const { return m_x; }
    double get_y() const { return m_y; }
    double get_z() const { return m_z; }

    void set_x(double x) { m_x = x; }
    void set_y(double y) { m_y = y; }
    void set_z(double z) { m_z = z; }

    double get_distance(const CPoint3D& p) const;

    void operator=(const CPoint3D& point);
    CPoint3D operator+(const CPoint3D& point);
    CPoint3D operator-(const CPoint3D& point);
    void operator/=(double div);
};

class CVector3D {

private:

    CPoint3D m_begin;
    CPoint3D m_end;
    CPoint3D m_coordinates;

public:
    CVector3D() : m_begin(CPoint3D()), m_end(CPoint3D()), m_coordinates(CPoint3D()) {}
    CVector3D(const CPoint3D& b, const CPoint3D& e) : m_begin(b),
                                                      m_end(e),
                                                      m_coordinates(m_end - m_begin) {}
    CVector3D(const CVector3D& v) : m_begin(v.get_begin()),
                                    m_end(v.get_end()),
                                    m_coordinates(v.get_coordinates()) {}

    CPoint3D get_begin() const { return m_begin; }
    CPoint3D get_end() const { return m_end; }
    CPoint3D get_coordinates() const { return m_coordinates; }

    void set_begin(const CPoint3D& begin);
    void set_end(const CPoint3D& end);

    void normalize() { m_coordinates /= m_begin.get_distance(m_end); }

    void operator=(const CVector3D& v);

};

class CColor {

private:

    unsigned short m_red;
    unsigned short m_green;
    unsigned short m_blue;

public:

    CColor() : m_red(0),
               m_green(0),
               m_blue(0) {}
    CColor(unsigned short red,
           unsigned short green,
           unsigned short blue) : m_red(red),
                                  m_green(green),
                                  m_blue(blue) {}
    CColor(const CColor& c) : m_red(c.get_red()),
                              m_green(c.get_green()),
                              m_blue(c.get_blue()) {}

    unsigned short get_red() const { return m_red; }
    unsigned short get_green() const { return m_green; }
    unsigned short get_blue() const { return m_blue; }

    void operator=(const CColor& color);

};


#endif //RAYTRACINGGL_GEOM_H
