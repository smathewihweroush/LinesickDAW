/*
Linesick: free and modern Digital Audio Workspace for electronic music
Copyright (C) 2026 smathewih

This file is part of Linesick.

Linesick is free software: you can redistribute it and/or modify it under the terms of the 
GNU General Public License as published by the Free Software Foundation, either 
version 3 of the License, or (at your option) any later version.

Linesick is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with Linesick. 
If not, see <https://www.gnu.org/licenses/>. 
*/

#include <RtAudio.h>
#include <iostream>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qurl.h>

using namespace std;

int main(int argc, char *argv[]) {
    cout << "its working :D\n";

    QGuiApplication app(argc, argv);
    
    QQmlApplicationEngine engine;
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
            &app, []() { QCoreApplication::exit(-1); },
            Qt::QueuedConnection);
    engine.loadFromModule("mainprob", "Main");

    return app.exec();
}