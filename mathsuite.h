/******************************************************************************
**
**  mathsuite - an collecton of apps that exercise basic arithmetic skills.
**
**  Tony Camuso
**  November, 2011
**
**  Version 0.1
**
**    mathsuite is free software: you can redistribute it and/or modify
**    it under the terms of the GNU General Public License as published by
**    the Free Software Foundation, either version 3 of the License, or
**    (at your option) any later version.
**
**    This program is distributed in the hope that it will be useful,
**    but WITHOUT ANY WARRANTY; without even the implied warranty of
**    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**    GNU General Public License for more details.
**
**  GNU General Public License http://www.gnu.org/licenses/gpl.html
**
**  Copyright 2011 by Tony Camuso.
**
******************************************************************************/

#ifndef MATHSUITE_H
#define MATHSUITE_H

#include <QMainWindow>
#include <QDialog>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGridLayout>

QT_BEGIN_NAMESPACE
class MathTest;
class QLabel;
class QWidget;
class QPushButton;
class QVBoxLayout;
class QGridLayout;
class QLineEdit;
QT_END_NAMESPACE

class MathSuite : public QWidget
{
    Q_OBJECT

public:
    explicit MathSuite(QDialog *parent = 0);
    ~MathSuite();

private slots:
    void onMathTest();
    void onFracTest();
    void onPercTest();

private:
    QLineEdit* nameEdit;
    QGridLayout *pTestGrid;
    QLabel *pMtNumber;
    QLabel *pFtNumber;
    QLabel *pPtNumber;
    QLabel *pMtScore;
    QLabel *pFtScore;
    QLabel *pPtScore;
};

typedef void (*SLOT_PTR)();

typedef struct {
    QWidget *pb;        // A pushbutton
    SLOT_PTR slotPtr;   // Pointer to the pushbutton's slot
    QLabel *text;       // Any associated text
}
MSWidget;

#endif // MATHSUITE_H
