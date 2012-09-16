#ifndef OFX_EXIV2_CONSTANTS_H
#define OFX_EXIV2_CONSTANTS_H

#include <exiv2.hpp>

#include <iostream>
#include <iomanip>
#include <cassert>

#include "ofMain.h"

enum ofxMetaDataType {
    OFX_EXIV2_EXIF,
    OFX_EXIV2_IPTC,
    OFX_EXIV2_XMP
};

#endif
