#include "wlgmodel.h"

static double calcRotaryInfEndPosition(double startPos, double endPos)
{
double sP,sPC,eP,ePC;

sP=modf(startPos/360.0,&sPC);
eP=modf(endPos/360.0,&ePC);

if(qAbs(eP-sP)>0.5)
 {
 if(eP>sP)
     eP-=1.0;
 else
     eP+=1.0;
 }

return (sPC+eP)*360.0;
}

WLGModel::WLGModel(QObject *parent) : QObject(parent)
{
}

WLFrame WLGModel::getFrame(WLGPoint GPoint)
{
QMutexLocker locker(&Mutex);

WLFrame ret;

QMatrix4x4 posM;

posM.setToIdentity();

m_data.axisX.value=GPoint.x;
m_data.axisY.value=GPoint.y;
m_data.axisZ.value=GPoint.z;

if(m_data.axisA.rotary)
   GPoint.a-=((int)(GPoint.a/360.0))*360;

if(m_data.axisA.rotary)
   GPoint.b-=((int)(GPoint.b/360.0))*360;

if(m_data.axisA.rotary)
   GPoint.c-=((int)(GPoint.c/360.0))*360;

m_data.axisA.value=GPoint.a;
m_data.axisB.value=GPoint.b;
m_data.axisC.value=GPoint.c;

posM=m_data.offsetFrame.toM().inverted()*posM;

QStringList List=m_data.strAxis.split(",");

foreach(QString name,List)
 {
      if(name=="X") posM=m_data.axisX.getPosM(posM);
 else if(name=="Y") posM=m_data.axisY.getPosM(posM);
 else if(name=="Z") posM=m_data.axisZ.getPosM(posM);
 else if(name=="A") posM=m_data.axisA.getPosM(posM);
 else if(name=="B") posM=m_data.axisB.getPosM(posM);
 else if(name=="C") posM=m_data.axisC.getPosM(posM);
 }

ret.fromM(m_data.offsetFrame.toM()*posM);

return ret;
}

WLGPoint WLGModel::getGPoint(WLFrame Frame)
{
QMutexLocker locker(&Mutex);

WLGPoint ret;

return ret;
}

void WLGModel::writeXMLData(QXmlStreamWriter &stream)
{
stream.writeAttribute("list",getStrAxis());

stream.writeAttribute("axisX",m_data.axisX.toString());
stream.writeAttribute("axisY",m_data.axisY.toString());
stream.writeAttribute("axisZ",m_data.axisZ.toString());
stream.writeAttribute("axisA",m_data.axisA.toString());
stream.writeAttribute("axisB",m_data.axisB.toString());
stream.writeAttribute("axisC",m_data.axisC.toString());
}

void WLGModel::readXMLData(QXmlStreamReader &stream)
{
if(!stream.attributes().value("axisX").isEmpty()) m_data.axisX.fromString(stream.attributes().value("axisX").toString());
if(!stream.attributes().value("axisY").isEmpty()) m_data.axisY.fromString(stream.attributes().value("axisY").toString());
if(!stream.attributes().value("axisZ").isEmpty()) m_data.axisZ.fromString(stream.attributes().value("axisZ").toString());
if(!stream.attributes().value("axisA").isEmpty()) m_data.axisA.fromString(stream.attributes().value("axisA").toString());
if(!stream.attributes().value("axisB").isEmpty()) m_data.axisB.fromString(stream.attributes().value("axisB").toString());
if(!stream.attributes().value("axisC").isEmpty()) m_data.axisC.fromString(stream.attributes().value("axisC").toString());

if(!stream.attributes().value("list").isEmpty())  setStrAxis(stream.attributes().value("list").toString());
}

WLGModelData WLGModel::getData()
{
return m_data;
}

void WLGModel::setData(WLGModelData data)
{
Mutex.lock();
m_data=data;
Mutex.unlock();
}

void WLGModel::setStrAxis(QString str)
{
m_data.strAxis=str;
}

QString WLGModel::getStrAxis()
{
    return m_data.strAxis;
}

void WLGModel::setOffsetFrame(WLFrame ofst)
{
m_data.offsetFrame=ofst;
}

void WLGModel::addRotaryPosition(WLGPoint &startPoint, WLGPoint &endPoint)
{
if(m_data.axisA.rotary
 &&m_data.axisA.inf)
    endPoint.a=calcRotaryInfEndPosition(startPoint.a,endPoint.a);

if(m_data.axisB.rotary
 &&m_data.axisB.inf)
    endPoint.b=calcRotaryInfEndPosition(startPoint.b,endPoint.b);

if(m_data.axisC.rotary
 &&m_data.axisC.inf)
    endPoint.c=calcRotaryInfEndPosition(startPoint.c,endPoint.c);
}

