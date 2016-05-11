//
// Created by Lokotochek on 11.05.16.
//

#ifndef RAYTRACINGGL_CPARSER_H
#define RAYTRACINGGL_CPARSER_H

#include <fstream>
#include <sstream>
#include "IParser.h"
#include "../Objects/CSphere.h"
#include "ccamera.hpp"
#include "clighter.hpp"

class CCustomParser : public IParser {
private:
    std::vector<IObject3D*> m_objects;
    CCamera m_camera;
    std::vector<CLighter> m_lighters;
    double m_backlight;
public:
    CCustomParser() : m_camera(CCamera(CPoint3D(0, 0, 0), CPoint3D(1, 0, 0))) {}
    virtual void parse(const std::string& filename);
    virtual std::vector<IObject3D*>& get_objects();
    virtual CCamera get_camera() const;
    virtual std::vector<CLighter>& get_lighters();
};

#endif //RAYTRACINGGL_CPARSER_H