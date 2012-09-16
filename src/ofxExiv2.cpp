#include "ofxExiv2.h"

//--------------------------------------------------------------------------------
ofxExiv2::ofxExiv2(){
    //initialize ofxExif
}

//--------------------------------------------------------------------------------
ofxExiv2::~ofxExiv2(){
    //destoy ofxExif
}

//--------------------------------------------------------------------------------
void ofxExiv2::loadImage(string filePath){
    //load an image to an exiv2 image container
    image = Exiv2::ImageFactory::open(filePath);
    assert(image.get() != 0);
    image->readMetadata();
}

//--------------------------------------------------------------------------------
void ofxExiv2::getMetaData(ofxMetaDataType metaDataType){
    //gets the metadata per data protocol -> EXIF,IPTC or XMP
    if(metaDataType == OFX_EXIV2_EXIF){
        Exiv2::ExifData &exifData = image->exifData();
        if (exifData.empty()) {
            std::cout<<"No Exif data found in the file"<<endl;
        }

        Exiv2::ExifData::const_iterator end = exifData.end();
        for (Exiv2::ExifData::const_iterator i = exifData.begin(); i != end; ++i) {
            const char* tn = i->typeName();
            std::cout << std::setw(44) << std::setfill(' ') << std::left
                      << i->key() << " "
                      //<< "0x" << std::setw(4) << std::setfill('0') << std::right
        //                  << std::dec << i->tag() << " "
                      << std::setw(9) << std::setfill(' ') << std::left
                      << (tn ? tn : "Unknown") << " "
                      << std::dec << std::setw(3)
                      << std::setfill(' ') << std::right
        //                  << i->count() << "  "
                      << std::dec << i->value()
                      << "\n";
        }
    }else if(metaDataType == OFX_EXIV2_IPTC){
        cout<<"IPTC metadata"<<endl;
    }else if(metaDataType == OFX_EXIV2_XMP){
        cout<<"XMP metadata"<<endl;
    }
}
