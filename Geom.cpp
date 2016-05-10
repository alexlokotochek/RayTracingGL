//
// Created by Lokotochek on 11.05.16.
//

#include "Geom.h"

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

CPoint3D operator+(const CPoint3D& point) {
    return CPoint3D(m_x + point.get_x(),
                    m_y + point.get_y(),
                    m_z + point.get_z());
}

CPoint3D operator-(const CPoint3D& point) {
    return CPoint3D(m_x - point.get_x(),
                    m_y - point.get_y(),
                    m_z -  point.get_z());
}

void CPoint3D::operator/=(double div) {
    m_x /= div;
    m_y /= div;
    m_z /= div;
}

CPoint3D::CPoint3D(const CPoint3D& point) {
    m_x = point.get_x();
    m_y = point.get_y();
    m_z = point.get_z();
}

void CVector3D::set_end(const CPoint3D& end) {
    m_end = end;
    m_coordinates = m_end - m_begin;
}

void CVector3D::set_begin(const CPoint3D& begin) {
    m_begin = begin;
    m_coordinates = m_end - m_begin;
}

void operator=(const CVector3D& v) {
    m_begin = v.get_begin();
    m_end = v.get_end();
    m_coordinates = v.get_coordinates();
}

void operator=(const CColor& color) {
    m_red = color.get_red();
    m_green = color.get_green();
    m_blue = color.get_blue();
}