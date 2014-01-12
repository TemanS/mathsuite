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

/******************************************************************************
**
**      APPLICATION WINDOW LAYOUT
**      =========================
**
**      +--------------------------------------------------+
**      |    Username                                      |
**      +--------------------------------------------------+
**
**                          Number of
**      Select Test         Problems        Final Score
**      +--------------+    +--------+      +--------------+
**      |  MathTest    |    |        |      |              |
**      +--------------+    +--------+      +--------------+
**      +--------------+    +--------+      +--------------+
**      |  Fractions   |    |        |      |              |
**      +--------------+    +--------+      +--------------+
**      +--------------+    +--------+      +--------------+
**      |  Percents    |    |        |      |              |
**      +--------------+    +--------+      +--------------+
**
******************************************************************************/

#include <QtGui>
#include <mathtest.h>
#include <fractest.h>
#include "mathsuite.h"

enum {ms_math, ms_frac, ms_perc, ms_boundary };

const char *columnLabel[] = { "Select", "Number of\nProblems", "Your Score" };
const char *pbLabel[] = {"Mat Test", "Fractions", "Percents" };

const int iMaxWid = 100;

MathSuite::MathSuite(QDialog *parent) :
    QWidget(parent)
{
    // We set the size of the window here, but the caller of this
    // constructor can set the origin with a move().
    //
    // Default origin is 100, 100.
    //
    setGeometry(100, 100, 340, 120);

    QpAppStyle styleSheet;
    setStyleSheet(*styleSheet.getAppStyle());
    int reportFrameStyle = QFrame::Sunken | QFrame::Panel;

    // Create the name edit box and its label
    //
    nameEdit = new QLineEdit;
    QLabel* nameLabel = new QLabel("Your Name:");
    nameLabel->setMaximumHeight(24);

    // Create the main layout container and add the name edit and its label.
    //
    QVBoxLayout* pMainLayout = new QVBoxLayout;
    pMainLayout->addWidget(nameLabel, Qt::AlignTop);
    pMainLayout->addWidget(nameEdit, Qt::AlignTop);

    // Create a grid layout for the test pushbuttons and their report
    // boxes.
    //
    pTestGrid = new QGridLayout;

    // Create the column labels and add them to the grid layout.
    //
    QLabel* pSelectLabel = new QLabel("Select");
    QLabel* pNumberLabel = new QLabel("Number of\nProblems");
    QLabel* pScoreLabel  = new QLabel("Your Score");
    pTestGrid->addWidget(pSelectLabel, 0, 0, Qt::AlignHCenter | Qt::AlignBottom);
    pTestGrid->addWidget(pNumberLabel, 0, 1, Qt::AlignHCenter | Qt::AlignBottom);
    pTestGrid->addWidget(pScoreLabel, 0, 2, Qt::AlignHCenter | Qt::AlignBottom);
    pNumberLabel->setMaximumWidth(iMaxWid);

    // Create the push buttons, add them to the grid layout, and connect
    // them to their slot handlers.
    //
    QPushButton* pbMathTest = new QPushButton(" MathTest  ");
    QPushButton* pbFracTest = new QPushButton(" Fractions   ");
    QPushButton* pbPercTest = new QPushButton(" Percents    ");
    pTestGrid->addWidget(pbMathTest, 1, 0);
    pTestGrid->addWidget(pbFracTest, 2, 0);
    pTestGrid->addWidget(pbPercTest, 3, 0);
    connect(pbMathTest, SIGNAL(clicked()), this, SLOT(onMathTest()));
    connect(pbFracTest, SIGNAL(clicked()), this, SLOT(onFracTest()));
    connect(pbPercTest, SIGNAL(clicked()), this, SLOT(onPercTest()));

    // Create the report Labels and add them to the grid layout.
    //
    pMtNumber = new QLabel;
    pFtNumber = new QLabel;
    pPtNumber = new QLabel;
    pMtNumber->setFrameStyle(reportFrameStyle);
    pFtNumber->setFrameStyle(reportFrameStyle);
    pPtNumber->setFrameStyle(reportFrameStyle);
    pMtNumber->setMaximumWidth(iMaxWid);
    pFtNumber->setMaximumWidth(iMaxWid);
    pPtNumber->setMaximumWidth(iMaxWid);
    pMtNumber->setAlignment(Qt::AlignHCenter);
    pFtNumber->setAlignment(Qt::AlignHCenter);
    pPtNumber->setAlignment(Qt::AlignHCenter);
    pTestGrid->addWidget(pMtNumber, 1, 1);
    pTestGrid->addWidget(pFtNumber, 2, 1);
    pTestGrid->addWidget(pPtNumber, 3, 1);

    pMtScore = new QLabel;
    pFtScore = new QLabel;
    pPtScore = new QLabel;
    pMtScore->setFrameStyle(reportFrameStyle);
    pFtScore->setFrameStyle(reportFrameStyle);
    pPtScore->setFrameStyle(reportFrameStyle);
    pTestGrid->addWidget(pMtScore, 1, 2);
    pTestGrid->addWidget(pFtScore, 2, 2);
    pTestGrid->addWidget(pPtScore, 3, 2);

    pMainLayout->addLayout(pTestGrid);
    setLayout(pMainLayout);
}


MathSuite::~MathSuite()
{
}

void MathSuite::onMathTest()
{
    // Get the absolute coordinates of this widget and use them to set
    // the position of the MathTest widget.
    //
    QPoint origin = this->mapToGlobal(this->rect().topLeft());
    origin.rx() += 40;
    origin.ry() -= 80;
    MathTest mathtest(origin, this);
    if(nameEdit->text() != "")
        mathtest.setUserName(nameEdit->text());
    mathtest.exec();

    // Publish the results
    //
    if(mathtest.getProblemCount() > 0) {
        QString tempStr = QString("%1").arg(mathtest.getProblemCount(), 3);
        pMtNumber->setText(tempStr);
        tempStr = QString("%1%  %2 ")
                .arg(mathtest.getPercentGrade(), 3)
                .arg(mathtest.getLetterGrade());
        pMtScore->setText(tempStr);
    }
}

void MathSuite::onFracTest()
{
    // Get the absolute coordinates of this widget and use them to set
    // the position of the FracTest widget.
    //
    QPoint origin = this->mapToGlobal(this->rect().topLeft());
    origin.rx() += 40;
    origin.ry() -= 80;
    FracTest fractest(origin);
    if( ! nameEdit->text().isEmpty())
        fractest.setUserName(nameEdit->text());
    fractest.exec();

    if(fractest.getProblemCount() > 0) {
        QString temp = QString("%1").arg(fractest.getProblemCount(), 3);
        pFtNumber->setText(temp);
        pFtScore->setText(fractest.getFinalScore());
    }
}

void MathSuite::onPercTest()
{

}
