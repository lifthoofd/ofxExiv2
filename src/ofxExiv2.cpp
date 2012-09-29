#include "ofxExiv2.h"

//--------------------------------------------------------------------------------
ofxExiv2::ofxExiv2(){
    //initialize ofxExif
    bIsImageLoaded = false;
}

//--------------------------------------------------------------------------------
ofxExiv2::~ofxExiv2(){
    //destoy ofxExif
}

//--------------------------------------------------------------------------------
void ofxExiv2::loadImage(string filePath){
    //load an image to an exiv2 image container
    Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(filePath);
    assert(image.get() != 0);
    image->readMetadata();

    allMetaData.clear();

    //--------------------------------
    //get and store all EXIF data
    Exiv2::ExifData &exifData = image->exifData();
    if (exifData.empty()) {
        std::cout<<"No Exif data found in the file"<<endl;
        vector<dataField> exif;
        dataField data;
        data.name = "No.Exif.Data";
        data.datatype = "int";
        data.value = "-1";
        exif.push_back(data);
        allMetaData.push_back(exif);
    }else{
        vector<dataField> exif;
        Exiv2::ExifData::const_iterator end = exifData.end();
        for (Exiv2::ExifData::const_iterator i = exifData.begin(); i != end; ++i) {
            dataField data;
            data.name = ofToString(i->key());
            data.datatype = ofToString(i->typeName());
            data.value = ofToString(i->value());
            exif.push_back(data);
        }
        allMetaData.push_back(exif);
    }
    //--------------------------------

    //--------------------------------
    //get and store all IPTC data
    Exiv2::IptcData &iptcData = image->iptcData();
    if (iptcData.empty()) {
        std::cout<<"No IPTC data found in the file"<<endl;
        vector<dataField> iptc;
        dataField data;
        data.name = "No.Iptc.Data";
        data.datatype = "int";
        data.value = "-1";
        iptc.push_back(data);
        allMetaData.push_back(iptc);
    }else{
        vector<dataField> iptc;
        Exiv2::IptcData::const_iterator end = iptcData.end();
        for (Exiv2::IptcData::const_iterator i = iptcData.begin(); i != end; ++i) {
            dataField data;
            data.name = ofToString(i->key());
            data.datatype = ofToString(i->typeName());
            data.value = ofToString(i->value());
            iptc.push_back(data);
        }
        allMetaData.push_back(iptc);
    }
    //--------------------------------

    //--------------------------------
    //get and store all XMP data
    Exiv2::XmpData &xmpData = image->xmpData();
    if (xmpData.empty()) {
        std::cout<<"No XMP data found in the file"<<endl;
        vector<dataField> xmp;
        dataField data;
        data.name = "No.Xmp.Data";
        data.datatype = "int";
        data.value = "-1";
        xmp.push_back(data);
        allMetaData.push_back(xmp);
    }else{
        vector<dataField> xmp;
        Exiv2::XmpData::const_iterator end = xmpData.end();
        for (Exiv2::XmpData::const_iterator i = xmpData.begin(); i != end; ++i) {
            dataField data;
            data.name = ofToString(i->key());
            data.datatype = ofToString(i->typeName());
            data.value = ofToString(i->value());
            xmp.push_back(data);
        }
        allMetaData.push_back(xmp);
    }
    //--------------------------------

    bIsImageLoaded = true;
}

//--------------------------------------------------------------------------------
int ofxExiv2::getDataFieldSize(ofxMetaDataType metaDataType){
    return allMetaData[metaDataType].size();
}

//--------------------------------------------------------------------------------
dataField ofxExiv2::getDataField(int index, ofxMetaDataType metaDataType){
    if(bIsImageLoaded){
        return allMetaData[metaDataType][index];
    }else{
        cout<<"load an image first"<<endl;
    }
}

//*--------
//* moet er nog iets bij?
//* Voor dat wat ik ermee wil, nee
//* Maar als je een complete addon wil leveren moet je de
//* Metadata ook kunnen bewerken
//--------*/
