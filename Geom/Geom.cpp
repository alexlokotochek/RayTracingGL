//
// Created by Lokotochek on 11.05.16.
//

#include "Geom.h"

CPoint3D::CPoint3D() {
    m_x = 0.;
    m_y = 0.;
    m_z = 0.;
}

CPoint3D::CPoint3D(double x, double y, double z) {
    m_x = x;
    m_y = y;
    m_z = z;
}

CPoint3D::CPoint3D(const CPoint3D& point) {
    m_x = point.get_x();
    m_y = point.get_y();
    m_z = point.get_z();
}

double CPoint3D::get_x() const {
    return m_x;
}

double CPoint3D::get_y() const {
    return m_y;
}

double CPoint3D::get_z() const {
    return m_z;
}

void CPoint3D::set_x(double x) {
    m_x = x;
}

void CPoint3D::set_y(double y) {
    m_y = y;
}

void CPoint3D::set_z(double z) {
    m_z = z;
}

double CPoint3D::get_distance(const CPoint3D& p) const {
    double dx = (m_x - p.get_x()) * (m_x - p.get_x());
    double dy = (m_y - p.get_y()) * (m_y - p.get_y());
    double dz = (m_z - p.get_z()) * (m_z - p.get_z());
    return std::sqrt(dx + dy + dz);
}

void CPoint3D::operator=(const CPoint3D& point) {
    m_x = point.get_x();
    m_y = point.get_y();
    m_z = point.get_z();
}

CPoint3D CPoint3D::operator+(const CPoint3D& point) {
    return CPoint3D(m_x + point.get_x(),
                    m_y + point.get_y(),
                    m_z + point.get_z());
}

CPoint3D CPoint3D::operator-(const CPoint3D& point) {
    return CPoint3D(m_x - point.get_x(),
                    m_y - point.get_y(),
                    m_z -  point.get_z());
}

void CPoint3D::operator/=(double div) {
    m_x /= div;
    m_y /= div;
    m_z /= div;
}

void CPoint3D::operator+=(double a) {
    m_x += a;
    m_y += a;
    m_z += a;
}

void CPoint3D::operator-=(double a) {
    m_x -= a;
    m_y -= a;
    m_z -= a;
}

void CVector3D::set_end(const CPoint3D& end) {
    m_end = end;
    m_coordinates = m_end - m_begin;
}

void CVector3D::set_begin(const CPoint3D& begin) {
    m_begin = begin;
    m_coordinates = m_end - m_begin;
}

void CVector3D::operator=(const CVector3D& v) {
    m_begin = v.get_begin();
    m_end = v.get_end();
    m_coordinates = v.get_coordinates();
}

void CColor::operator=(const CColor& color) {
    m_red = color.get_red();
    m_green = color.get_green();
    m_blue = color.get_blue();
}

void CPoint3D::operator+=(double a) {
    m_x += a;
    m_y += a;
    m_z += a;
}
void CPoint3D::operator-=(double a) {
    m_x -= a;
    m_y -= a;
    m_z -= a;
}