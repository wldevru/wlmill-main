#ifndef WLPAMWIDGET_H
#define WLPAMWIDGET_H

#include <QDialog>
#include <QPainter>
#include <QLineEdit>
#include "wlpad.h"
#include "ui_wlpamwidget.h"


class WLPamWidget : public QDialog
{
	Q_OBJECT

public:
    WLPamWidget(dataPad Pad,float Vmax,QWidget *parent = nullptr);
	~WLPamWidget();

dataPad getPad();

private:
Ui::WLPamWidget ui;

dataPad curPad;
QString m_unit;

protected:

void  paintEvent(QPaintEvent *);

private slots:

 void updateAccelLabel(int index);

 void updateVstLabel(double val);
 void updateVmaLabel(double val);

 void updateFminutes();
 void updateAtime();

    void onAccept() {done(1);}
    void onReject() {done(0);}

public slots:
  void setEnabledEditName(bool enable) {ui.cbEditName->setEnabled(enable);}
  void setEnabledEditVst(bool enable)  {ui.sbVst->setEnabled(enable);}

  void setUnit(QString);

  void setFminutes(bool enable) {ui.cbFMinutes->setChecked(enable);}
  void setAtime(bool enable)    {ui.cbATime->setChecked(enable);}


};

#endif // WLPAMWIDGET_H
