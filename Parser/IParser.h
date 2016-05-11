//
// Created by Lokotochek on 11.05.16.
//

#ifndef RAYTRACINGGL_IPARSER_H
#define RAYTRACINGGL_IPARSER_H

#include "../Objects/IObject3D.h"
#include "../View/CCamera.h"
#include "../Light/CLighter.h"

class IParser {
	public:
		virtual void parse(const std::string& filename) = 0;
		virtual std::vector<IObject3D*>& get_objects() = 0;
		virtual CCamera get_camera() const = 0;
		virtual std::vector<CLighter>& get_lighters() = 0;
		virtual ~IParser() {}
};


#endif //RAYTRACINGGL_IPARSER_H
