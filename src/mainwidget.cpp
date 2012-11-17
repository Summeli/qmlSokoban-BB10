/***************************************************************************
 *   Copyright (C) 2011 by Glad Deschrijver                                *
 *     <glad.deschrijver@gmail.com>                                        *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, see <http://www.gnu.org/licenses/>.  *
 ***************************************************************************/

#include "mainwidget.h"

#include <QApplication>
#include <QDeclarativeContext>
#include <QDeclarativeView>


MainWidget::MainWidget(QWidget *parent)
    : QDeclarativeView(parent)
{
	setResizeMode(QDeclarativeView::SizeRootObjectToView);
	m_orientation = "Landscape";
	QDeclarativeContext *context = rootContext();
	context->setContextProperty("mainWidget", this);
	context->setContextProperty("Orientation", m_orientation);

	connect((QObject*)engine(), SIGNAL(quit()), qApp, SLOT(quit())); // grab the Qt.quit() signal in the QML files

	setSource(QUrl("qrc:/qmlsokoban.qml"));
}

MainWidget::~MainWidget()
{
}
