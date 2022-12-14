#ifndef WLENTERSTRING_H
#define WLENTERSTRING_H

#include <QDialog>
#include "ui_wlenterstring.h"

class WLEnterString : public QDialog
{
	Q_OBJECT

public:
    WLEnterString(QWidget *parent = nullptr);
	~WLEnterString();

    QString getString(){return ui.lineEdit->text();}
       void setString(QString str){ui.lineEdit->setText(str);}

	void setLabel(QString str) {ui.label->setText(str);}
	void setHint(QString str)  {ui.lineEdit->setText(str); ui.lineEdit->selectAll();} 

private:
	Ui::WLEnterString ui;
};

#endif // WLENTERSTRING_H
