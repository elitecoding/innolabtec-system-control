#include "parameter_factory.h"
#include <QFile>
#include <iostream>

parameter_factory::parameter_factory()
{

}
void parameter_factory::loadParameter(std::string path)
{
    QFile file("Inno-TT-Positions.xml");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QXmlStreamReader xml(&file);

    std::string currRack = "";
    bool addToRack = false;
    point_3d_list* r;
    double currX;
    double currY;
    double currZ;
    double* posPointer;
    std::string currPosName;

    while(!xml.atEnd())
    {
        QXmlStreamReader::TokenType type = xml.readNext();
        std::cout<<"token: "<<type<<"("<<xml.tokenString().toStdString()
                 <<") name: "<<xml.name().toString().toStdString()
                 <<" attr: "<<xml.attributes().value("id").toString().toStdString()
                   <<" text: "<<xml.text().toString().toStdString()
                 <<std::endl;
        std::cout<<xml.error()<<std::endl;

        if(type==3)
        {
            break;
        }

        if(xml.name() == "Rack"&&xml.tokenType()==4)
        {
            currRack=xml.attributes().value("id").toString().toStdString();
            addToRack = true;
            r = new point_3d_list(currRack);
            parameter.push_back(r);
        }

        if(xml.name() == "position" && xml.tokenType()==4 && addToRack)
        {
            currPosName=xml.attributes().value("id").toString().toStdString();
        }
        if(xml.name() == "position" && xml.tokenType()==5 && addToRack)
        {
            r->addPoint(new point_3d(currPosName,currX,currY,currZ));
        }

        if(xml.name() == "X" && xml.tokenType()==4)
        {
           posPointer = &currX;
        }
        if(xml.name() == "Y" && xml.tokenType()==4)
        {
           posPointer = &currY;
        }
        if(xml.name() == "Z" && xml.tokenType()==4)
        {
           posPointer = &currZ;
        }

        if(xml.tokenType()==6)
        {
           *posPointer=xml.text().toDouble();
        }

    }

    file.close();
}
