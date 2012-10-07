//ofxExiv2 addon example

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
    ofBackground(0,0,0);
    ofSetFrameRate(60);

    bImageIsLoaded = false;

    font.loadFont("DIN.otf", 32);
    font2.loadFont("DIN.otf", 16);
}

//--------------------------------------------------------------
void testApp::update()
{

}

//--------------------------------------------------------------
void testApp::draw()
{
    if(bImageIsLoaded)
    {
        ofSetColor(0, 255, 0);

        string str = "| press 'q' to print EXIF data |";
        font2.drawString(str, (ofGetWidth() - font2.stringWidth(str)) * 0.5, 20);

        str = "| press 'w' to print IPTC data |";
        font2.drawString(str, (ofGetWidth() - font2.stringWidth(str)) * 0.5, 52);

        str = "| press 'e' to print XMP data |";
        font2.drawString(str, (ofGetWidth() - font2.stringWidth(str)) * 0.5, 84);

        ofSetColor(255, 255, 255);
        img.draw(0, 100, 800, 600);
    }
    else
    {
        string str = "PRESS 'a' TO LOAD AN IMAGE";
        ofSetColor(0, 255, 0);
        font.drawString(str, (ofGetWidth() - font.stringWidth(str)) * 0.5, 48);
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
    if(key == 'a')
    {
        ofFileDialogResult loadFileResult = ofSystemLoadDialog("open an image with metadata!");
        if(loadFileResult.bSuccess)
        {
            //load image to the special exiv2 image container
            metaData.loadImage(loadFileResult.filePath);

            //we also load the same image in an ofImage container so we can draw it to our screen
            img.loadImage(loadFileResult.filePath);

            bImageIsLoaded = true;
        }
    }
    else if(key == 'q')
    {
        cout<<"----------------------------------------------"<<endl;
        for(int i = 0; i < metaData.getDataFieldSize(OFX_EXIV2_EXIF); i++)
        {
            dataField exif = metaData.getDataField(i, OFX_EXIV2_EXIF);
            cout<<exif.name<<"  |  "<<exif.datatype<<"  |  "<<exif.value<<endl;
        }
    }
    else if(key == 'w')
    {
        cout<<"----------------------------------------------"<<endl;
        for(int i = 0; i < metaData.getDataFieldSize(OFX_EXIV2_IPTC); i++)
        {
            dataField iptc = metaData.getDataField(i, OFX_EXIV2_IPTC);
            cout<<iptc.name<<"  |  "<<iptc.datatype<<"  |  "<<iptc.value<<endl;
        }
    }
    else if(key == 'e')
    {
        cout<<"----------------------------------------------"<<endl;
        for(int i = 0; i < metaData.getDataFieldSize(OFX_EXIV2_XMP); i++)
        {
            dataField xmp = metaData.getDataField(i, OFX_EXIV2_XMP);
            cout<<xmp.name<<"  |  "<<xmp.datatype<<"  |  "<<xmp.value<<endl;
        }
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo)
{

}
