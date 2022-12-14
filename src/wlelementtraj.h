#ifndef WLELEMENTTRAJ_H
#define WLELEMENTTRAJ_H

#include <QList>

#include <QtGui>

#include "wl3dpoint.h"
#include "wlgcode.h"
#include "wlgmodel.h"
#include "wlframe.h"
#include "wlflags.h"

#define ULINE_MAXERRORPOINTR 0.1

struct WLElementCirc
{
bool CCW=false;
int plane=0;

WLGPoint   startPoint;
WLGPoint  centerPoint;
WLGPoint     endPoint;

double R;
bool spiral;

bool isSpiral() {return spiral;}
};

struct WLElementLine
{
bool backlash=false;
bool G93=false;

WLGPoint   startPoint;
WLGPoint     endPoint;
};

struct WLElementULine
{
WLGPoint   startPoint;
WLGPoint     midPoint;
WLGPoint     endPoint;
};

struct WLElementDelay
{
quint32   time;
WLGPoint point;
};

struct WLElementMCode
{
int MCode=0;
WLGPoint point;
};

struct WLElementEmpty
{
WLGPoint point;
};

union WLElementData{

struct WLElementCirc  arc;
struct WLElementLine  line;
struct WLElementULine uline;
struct WLElementMCode mcode;
struct WLElementDelay delay;
struct WLElementEmpty empty;

 WLElementData(){}
~WLElementData(){}
};

struct WLElementTraj 
{
private:
    bool m_stopMode   =false;
    bool m_preBacklah =false;

    double m_smoothP = 0.0;
    double m_smoothQ = 0.0;
public:
    enum TypeElement {empty,line,arc,uline,delay,mcode};

    union WLElementData data;

public:    

    QString toString();

inline bool isEqFS(WLElementTraj ET);

public:
     WLElementTraj();
	~WLElementTraj();

bool setLine(WLGPoint _startPoint,WLGPoint _endPoint);
bool setArc(WLGPoint _startPoint,WLGPoint _centerPoint,WLGPoint endPoint,bool ccw,int plane);
bool setULine(WLGPoint _startPoint,WLGPoint _midPoint,WLGPoint _endPoint);
bool setDelay(WLGPoint _Point,quint32 ms);
bool setMCode(WLGPoint _Point,int _MCode);

void setS(double _S) {S=_S;}
void setF(double _F) {F=_F;}

void setFast() {setF(-1.0);}
bool isFast() {return F==-1.0;}

void setPreBacklash(bool enable=true) {m_preBacklah=enable;}
bool isPreBacklash() {return m_preBacklah;}

void setStopMode(bool enable) {m_stopMode=enable;}

bool isStopMode(){return m_stopMode;}
bool isSmooth() {return !isStopMode();}

void setSmooth(double P,double Q) {if(P>=0&&Q>=0) {m_smoothP=P; m_smoothQ=Q; m_stopMode=false;}}

double getSmoothP() {return m_smoothP;}
double getSmoothQ() {return m_smoothQ;}

QList<WL6DPoint> calcPoints(bool *ok,WLGModel *GModel,double delta=0);

WLGPoint getStartPoint();
void setStartPoint(WLGPoint point);

WLGPoint getEndPoint();
void setEndPoint(WLGPoint point);

QList <WLElementTraj> calcModelPoints(bool *ok,WLGModel *GModel,double delta);

TypeElement getType() {return type;}

void reset(bool all=true);

inline bool isArc()  {return type==arc;}
inline bool isLine()  {return type==line;}
inline bool isULine() {return type==uline;}
inline bool isMCode() {return type==mcode;}
inline bool isEmpty() {return type==empty;}

float movDistanceXYZ;

float movDistanceIJ;
float movDistanceK;

WLGPoint   startV;
WLGPoint   endV;

TypeElement type;

QString str;

quint32  index=0;

double F=0;
double S=0;

bool useHMap =true;

public:

static void addBacklah(QList<WLElementTraj> &Traj,WL3DPoint lastBL,bool nextMov);
static void removeEmpty(QList<WLElementTraj> &Traj);
static bool detectMCode(QList<WLElementTraj> &Traj);
static  int simpliTrajectory(QList<WLElementTraj> &simpliTraj,QList<WLElementTraj> baseTraj,float simpliDist ,bool oneSimpli=false,float simpliAngle=0,int Ar=0,int Br=0,int Cr=0);
static void updateFS(QList<WLElementTraj> &Traj);
static void calcPoints(QList<WLElementTraj> &Traj,WLGModel *GModel,double delta=0);

bool calcVector(WL3DPoint &startV,WL3DPoint &endV);


private:

QList <WL6DPoint> calcArcPoints(bool *ok,WLGModel *GModel,double delta);
QList <WL6DPoint> calcLinePoints(bool *ok,WLGModel *GModel,double delta);
QList <WL6DPoint> calcULinePoints(bool *ok,WLGModel *GModel,double delta);
QList <WL6DPoint> calcMCodePoints(bool *ok,WLGModel *GModel);


void update();
};



#endif // WLELEMENTTRAJ_H
