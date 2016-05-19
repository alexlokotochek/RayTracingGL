#ifndef GLIB_BODY
#define GLIB_BODY

#include "../Image.hpp"
#include "../figures/Object.hpp"

struct Body {
    struct Properties {
        RGB color;
    };

    Properties properties;
    Object *figure;

    Body() {
        figure = NULL;
    }

    Body(const Properties &properties, Object *& figure)
        : properties(properties), figure(figure) {
    }

    ~Body() {
        delete figure;
    }
};

#endif
