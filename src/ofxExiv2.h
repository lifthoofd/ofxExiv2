#ifndef OFX_EXIV2_H
#define OFX_EXIV2_H

#include "ofxExiv2Constants.h"

class ofxExiv2{

    public:
        ofxExiv2();
        ~ofxExiv2();

        void loadImage(string filePath);
        void getMetaData(ofxMetaDataType metaDataType);

    private:
        Exiv2::Image::AutoPtr image;
};

#endif
