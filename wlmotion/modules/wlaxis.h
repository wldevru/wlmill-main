#ifndef WLAXIS_H
#define WLAXIS_H

#include <QObject>
#include <QDataStream>
#include <QTimer>

#include "wlflags.h"
#include "wlmodule.h"
#include "wlmoduleioput.h"
#include "wlmoduleencoder.h"

#define xPD 4

#define errorAxis_setdata    1
#define errorAxis_setinput   2
#define errorAxis_dataSCurve 3
#define errorAxis_emg 4
#define errorAxis_sd  5
#define errorAxis_alm 6
#define errorAxis_pel 7
#define errorAxis_mel 8
#define errorAxis_limit 9
#define errorAxis_nomov 10 
#define errorAxis_modestatus 11
#define errorAxis_fma   12
#define errorAxis_fcalc  13
#define errorAxis_poscalc 14
#define errorAxis_bufactiv 15
#define errorAxis_aad 16
#define errorAxis_fst 17
#define errorAxis_dma 35

const QString errorAxis("0,no error\
,1,set data\
,2,set input\
,3,set S curve\
,4,wrong state(in inEMGStop 1\
,5,wrong state(in inSDStop\
,6,wrong state(in inALM\
,7,wrong state(in inPEL\
,8,wrong state(in inMEL\
,9,out limit position\
,10,no mov\
,11,wrong mode or status\
,12,wrong Fmax\
,13,error calc F\
,14,error calc Position\
,15,error servo period\
,16,wrong accel/decel\
,17,wrong Fstart\
,18,wrong Fmov\
,19,wrong type par mov\
,35,error DMA\
,36,error sub Axis\
,37,error float MPar\
,38,error wait stop\
,39,error ready\
,40,error pid");

//Axis coonect
#define MASK_abs       1<<1 //absolute coordinate
#define MASK_ccw       1<<3 //counter clock wise
#define MASK_fline     1<<4 //fast line
#define MASK_ensmooth  1<<5 //enable smooth
#define MASK_dir       1<<6 //dir vel mode
#define MASK_disubaxis 1<<7 //disable mov subaxis

//Axis
#define comAxis_movPos      1 //mov position mode Axis
#define comAxis_sdStop      2 //slow down stop
#define comAxis_emgStop     3 //emergency stop
#define comAxis_addSyhData  4
#define comAxis_setKSTCurve 5
#define comAxis_reset       6 //reset
#define comAxis_acc         7 //start acceleration to Fmov
#define comAxis_newF        8 //set new Fmov
#define comAxis_setKF       9 //set K(sclae (0...1]) Fmov
#define comAxis_setFlim     10//set Flimit
#define comAxis_setInput    11//set inputs Axis(inPEL..,inORG...)
#define comAxis_pause       12//start decel Axis F=0
#define comAxis_setKGear    13//set program Gear Axis
#define comAxis_setParMov   16//set parametr moving
#define comAxis_setActIn    17//set action on input

#define comAxis_setMinMaxPos 18 //set limit position
#define comAxis_setTypePulse 19 //set type output pulse
#define comAxis_setInputM    20 //set input moduleAxis (inEMG,inSD)
#define comAxis_setPos           21 //set position Axis

#define comAxis_setDisableLimit  23 //disable limit Axis
#define comAxis_setLatchSrc      24 //set latch source Axis

#define comAxis_setOutput     25//set output Axis (outEN,outRALM...)
#define comAxis_setEnable     26//enable Axis

#define comAxis_setDelaySCurve     27//set inertion time (S curve)
#define comAxis_movVel             28 //mov vellocity mode Axis

#define comAxis_setModeSub        29 //set Sub Axis
#define comAxis_setDisableManual  30//disable manual control Axis
#define comAxis_setEncoder        31//set encoder
#define comAxis_setTypeMotor      32//set typeMotor
#define comAxis_setPid            33//set pid
#define comAxis_setErrPid         34//set error pid

#define comAxis_getDataAxis   100 //call data Axis

#define comAxis_setData 128
#define comAxis_getData 129

#define sendAxis_signal 200

enum typeDataAxis{
     dataAxis_pos
    ,dataAxis_F
    ,dataAxis_latch2
    ,dataAxis_latch3
  };



#define sendAxis_data          202 //send data Axis

#define errorAxis_setdata    1
#define errorAxis_setinput   2
#define errorAxis_dataSCurve 3
#define errorAxis_emg 4
#define errorAxis_sd  5
#define errorAxis_alm 6
#define errorAxis_pel 7
#define errorAxis_mel 8
#define errorAxis_limit 9
#define errorAxis_nomov 10 
#define errorAxis_modestatus 11
#define errorAxis_fma   12
#define errorAxis_fcalc  13
#define errorAxis_poscalc 14
#define errorAxis_bufactiv 15
#define errorAxis_aad 16
#define errorAxis_fst 17
#define errorAxis_fmov 18
#define errorAxis_typeMPar 19
#define errorAxis_dma 35

//Axis flags
#define AF_dir           1<<0  //direction
#define AF_disableManual 1<<1  //disable manual mov (whell,input)

//#define AF_update        1<<3  //update state
#define AF_enable        1<<4  //enable
#define AF_sdstop        1<<5  //stop when F=Fst
#define AF_typePulseABxx 1<<6  //type out AB_ (AB,ABx2,ABx4)
#define AF_disableLimit  1<<7  //no use limit


#define MAF_invStep  1<<1
#define MAF_invDir   1<<0

enum typeIOPutAXIS{IO_inEMGStop,IO_inSDStop};

enum typeInputAxis{AXIS_inORG,AXIS_inALM,AXIS_inPEL,AXIS_inMEL,AXIS_inLATCH};//_inEMG
enum typeOutputAxis{AXIS_outENB,AXIS_outRALM};//

enum  statusAxis{AXIS_stop,AXIS_acc,AXIS_fconst,AXIS_dec,AXIS_wait};
enum   stateAxis{AXIS_standby,AXIS_pos,AXIS_vel} ;
enum    modeAxis{AXIS_alone,AXIS_slave,AXIS_sub,AXIS_track};

enum   typeMotorAxis{AXIS_noMotor,AXIS_stepMotor,AXIS_encoderStepMotor};

enum   typeMParAxis{AXIS_MParAll
                   ,AXIS_MParPlus
                   ,AXIS_MParMinus
                   ,AXIS_StepMotorMParAll
                   ,AXIS_StepMotorMParPlus
                   ,AXIS_StepMotorMParMinus};

enum   typePulseAxis{AXIS_pulse_SD
                    ,AXIS_pulse_CWCCW
                    ,AXIS_pulse_ABx1
                    ,AXIS_pulse_ABx2
                    ,AXIS_pulse_ABx4
                    ,AXIS_pulse_SDx2
                    ,AXIS_pulse_CWCCWx2};

enum   typeFindAxis{AXIS_findNO
                   ,AXIS_findPEL
                   ,AXIS_findMEL
				   ,AXIS_findORG};

struct WLMParAxis
{
float Aacc;
float Adec;
float Fst;
float Fmax;

WLMParAxis(float _Aacc=1
          ,float _Adec=-1
          ,float _Fst=0
          ,float _Fmax=1)
{
Aacc=_Aacc;
Adec=_Adec;
Fst =_Fst;
Fmax=_Fmax;
}

bool isValid(){
return  Fst>=0
      &&Fmax>=0&&Fmax>=Fst
      &&Aacc>=0
      &&Adec<=0;
}

QString toString(){
 return QString("%1,%2,%3,%4").arg(Aacc,0,'f',5)
                              .arg(Adec,0,'f',5)
                              .arg(Fst,0,'f',5)
                              .arg(Fmax,0,'f',5);
 }

bool fromString(QString str)
 {
 QStringList list=str.split(",");

 if(list.size()!=4) return false;

 Aacc=list.at(0).toFloat();
 Adec=list.at(1).toFloat();
 Fst =list.at(2).toFloat();
 Fmax=list.at(3).toFloat();

 return true;
 }

bool operator!=(WLMParAxis B)
{
return Aacc!=B.Aacc
     ||Adec!=B.Adec
     ||Fst !=B.Fst
     ||Fmax!=B.Fmax;
}

};

struct WLPidData{
float ffp=0;
float ffd=0;

float p=1;
float i=0;
float d=0;

WLPidData(float _p=1,float _i=0,float _d=0,float _ffp=0,float _ffd=0)
     {
     ffp=_ffp;
     ffd=_ffd;

     p=_p;
     i=_i;
     d=_d;
     }

bool isValid() {
 return  ffp>=0
       &&ffd>=0
       &&p>=0
       &&i>=0
       &&d>=0;
 }

QString toString(){
 return QString("%1,%2,%3,%4,%5").arg(p,0,'f',5)
                                 .arg(i,0,'f',5)
                                 .arg(d,0,'f',5)
                                 .arg(ffp,0,'f',5)
                                 .arg(ffd,0,'f',5);
 }

bool fromString(QString str)
 {
 QStringList list=str.split(",");

 if(list.size()<3) return false;

 p=list.at(0).toFloat();
 i=list.at(1).toFloat();
 d=list.at(2).toFloat();

 if(list.size()>=5) {
   ffp=list.at(3).toFloat();
   ffd=list.at(4).toFloat();
   }
   else {
   ffp=0;
   ffd=0;
   }

 return true;
 }
};

class WLModuleAxis;

class WLAxis : public WLElement
{
    Q_OBJECT

public:	
 WLAxis(WLModuleAxis *_ModuleAxis);
~WLAxis();

private:
 qint32 nowPosition;
 qint32 maxPosition;
 qint32 minPosition;

statusAxis status;
  modeAxis mode;
   WLFlags Flags;

  float Freq;
 qint32 m_latchPos2;
 qint32 m_latchPos3;

 qint32 homePosition;
 qint32 orgSize;

quint8 error;

quint8 m_iMasterAxis=0;

float kSTCurve;
float delaySCurve;

float kGear;

quint8 typePulse;
quint8 outSDinv;

WLIOPut *inORG;
WLIOPut *inPEL;
WLIOPut *inMEL; 
WLIOPut *inALM;

WLIOPut *outENB;
WLIOPut *outRALM;

quint8 iEncoder=255;

typeActionInput actIn[4];

bool m_validLatch2;
bool m_validLatch3;

typeMotorAxis typeMotor=AXIS_stepMotor;

WLPidData m_pidData;

WLMParAxis stepMotorMParPlus;
WLMParAxis stepMotorMParMinus;

quint16 m_errPidMax=100;

private:
QMutex mutex;

public:

enum modeAxis   getMode()   {return mode;}
enum statusAxis getStatus() {return status;}

 quint8 getEncoder() {return iEncoder;}

 void resetLatch() {m_validLatch2=m_validLatch3=false;}

 typeMotorAxis getTypeMotor() {return typeMotor;}

 bool isUsePid() {return typeMotor==AXIS_encoderStepMotor;}

 bool isLatch2() {return m_validLatch2;}
 bool isLatch3() {return m_validLatch3;}

 bool isEnable() {return Flags.get(AF_enable);}
 //void setIOPut(int index);
 void setInORG(int index);
 void setInPEL(int index);
 void setInMEL(int index);
 void setInALM(int index);
  
 void setOutENB(int m_index);
 void setOutRALM(int m_index);

 long getLatch2() {return m_latchPos2;}
 long getLatch3() {return m_latchPos3;}

 void setError(quint8 err)  {emit changedError(error=err);}

 int getTypePulse(){return typePulse;}
 int getOutSDInv() {return outSDinv;}

float getDelaySCurve() {return delaySCurve;}
float getKSTCurve() {return kSTCurve;}

typeActionInput getActIn(quint8 typeIn) {return actIn[typeIn];}
          float getKGear() {return kGear;}

WLIOPut*  getInput(typeInputAxis);
WLIOPut*  getOutput(typeOutputAxis);

qint32 getMaxPos()  {return maxPosition;}
qint32 getMinPos()  {return minPosition;}
qint32 getNowPos()  {return nowPosition;}
qint32 getHomePos() {return homePosition;}
qint32 getORGSize() {return orgSize;}

void setORGSize(qint32 size) {if(size>0) orgSize=size;}
bool setHomePos(qint32 pos) {if(minPosition<=pos&&pos<=maxPosition) {homePosition=pos; return true;} else return false;}
bool isMotion() {return status!=AXIS_stop;}

void setDataAxis(quint8 statMode,quint8 flags,qint32 pos,float F); //old function

void setData(QDataStream &data);
void getData(typeDataAxis type);

WLMParAxis getStepMotorMParPlus()  {return stepMotorMParPlus;}
WLMParAxis getStepMotorMParMinus() {return stepMotorMParMinus;}

WLPidData getPidData() {return m_pidData;}

quint16 getErrPidMax() {return m_errPidMax;}

signals:

 void changedLatch2(qint32);
 void changedLatch3(qint32);
 void changedError(quint8);
 void changedPosition(qint32);
 void changedStatus(statusAxis);
 void changedMode(modeAxis);
 void changedFreq(float);
 void changedInALM();

 void finished();
 void started();

private:
    bool setInput(typeInputAxis type,quint8 num);
    bool setOutput(typeOutputAxis type,quint8 num);

public:
    bool sendGetDataAxis();
    bool setMPar(float Aac,float Ade,float Fst,float Fma,typeMParAxis type=typeMParAxis::AXIS_MParAll);
    bool setMPar(WLMParAxis MPar,typeMParAxis type=typeMParAxis::AXIS_MParAll);
    bool movPos(quint8 mask,qint32 Dist,float Fmov);
    bool movVel(quint8 mask,float Fmov);
	bool acc();
	bool pause();
	bool sdStop();
	bool setNewF(float newF);
	bool emgStop();
	bool addSyhData(qint32 pos);
	bool setPos(qint32 pos);
	bool setMinMaxPos(qint32 minpos,qint32 maxpos);
    bool setKF(float _KFA=1.0f);
	void reset();	
	bool setDisableLimit(bool dis);
    bool setDisableManual(bool dis);
    bool setInLatch(quint8 index);
    bool setActIn(typeInputAxis type,typeActionInput typeAct);
	bool setTypePulse(typePulseAxis type,quint8 SDinv);
	bool setKSTCurve(float kSTcurve);
    bool setDelaySCurve(float delayScurve=0,bool save=true);
    bool restoreDelaySCurve() {return setDelaySCurve(delaySCurve);}
    bool setKGear(float kGear);
    bool setEnable(bool _enable);
    bool setModeSub(quint8 imasterAxis);
    bool setEncoder(quint8 _iEncoder);
    bool setPidData(WLPidData _pidData);
    bool setTypeMotor(typeMotorAxis _typeMotor);
    bool setErrPid(quint16 err);

public:
//static qint32 calcI32Pos(double pos);

public slots:
virtual void update(); //get current data
virtual void backup(); //backup current data

public:
virtual void writeXMLData(QXmlStreamWriter &stream);
virtual void  readXMLData(QXmlStreamReader &stream);
};



#endif // WLAXIS_H
