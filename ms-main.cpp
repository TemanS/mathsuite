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

#include <QApplication>
#include <QDesktopWidget>
#include "mathsuite.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MathSuite w;

    // This code centers the app on the desktop.
    //
    QDesktopWidget *desktop = a.desktop();
    int screenWidth, width;
    int screenHeight, height;
    int x, y;
    QSize windowSize;

    screenWidth = desktop->width();
    screenHeight = desktop->height();

    windowSize = w.size();
    width = windowSize.width();
    height = windowSize.height();

    x = (screenWidth - width) / 2;
    y = (screenHeight - height) / 2;
    //
    // Offset for task bar at bottom of screen
    //
    y -= 50;

    w.move( x, y );
    w.show();

    return a.exec();
}
