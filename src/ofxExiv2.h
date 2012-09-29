/*  ofxExiv2
*   version: 0.01
*   by Erik Overmeire
*
*   openframeworks addon for extracting metadat from images
*   using the exiv2 library
*/

#ifndef OFX_EXIV2_H
#define OFX_EXIV2_H

#include <exiv2.hpp>

#include <iostream>
#include <iomanip>
#include <cassert>

#include "ofConstants.h"
#include "ofUtils.h"

enum ofxMetaDataType {
    OFX_EXIV2_EXIF = 0,
    OFX_EXIV2_IPTC = 1,
    OFX_EXIV2_XMP = 2
};

struct dataField{
    string name;
    string datatype;
    string value;
};

class ofxExiv2{

    public:
        ofxExiv2();
        ~ofxExiv2();

        void loadImage(string filePath);

        int getDataFieldSize(ofxMetaDataType metaDataType);

        dataField getDataField(int index, ofxMetaDataType metaDataType);

    private:
        bool bIsImageLoaded;

        vector< vector<dataField> > allMetaData;
};

#endif
