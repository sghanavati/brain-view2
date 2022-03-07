/****************************************************************************
**
** Copyright (C) 2005-2008 Trolltech ASA. All rights reserved.
**
** This file is part of the example classes of the Qt Toolkit.
**
** This file may be used under the terms of the GNU General Public
** License versions 2.0 or 3.0 as published by the Free Software
** Foundation and appearing in the files LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file.  Alternatively you may (at
** your option) use any later version of the GNU General Public
** License if such license has been publicly approved by Trolltech ASA
** (or its successors, if any) and the KDE Free Qt Foundation. In
** addition, as a special exception, Trolltech gives you certain
** additional rights. These rights are described in the Trolltech GPL
** Exception version 1.2, which can be found at
** http://www.trolltech.com/products/qt/gplexception/ and in the file
** GPL_EXCEPTION.txt in this package.
**
** Please review the following information to ensure GNU General
** Public Licensing requirements will be met:
** http://trolltech.com/products/qt/licenses/licensing/opensource/. If
** you are unsure which license is appropriate for your use, please
** review the following information:
** http://trolltech.com/products/qt/licenses/licensing/licensingoverview
** or contact the sales department at sales@trolltech.com.
**
** In addition, as a special exception, Trolltech, as the sole
** copyright holder for Qt Designer, grants users of the Qt/Eclipse
** Integration plug-in the right for the Qt/Eclipse Integration to
** link to functionality provided by Qt Designer and its related
** libraries.
**
** This file is provided "AS IS" with NO WARRANTY OF ANY KIND,
** INCLUDING THE WARRANTIES OF DESIGN, MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE. Trolltech reserves all rights not expressly
** granted herein.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
****************************************************************************/

#ifndef TREEITEM_H
#define TREEITEM_H

//#include <QList>
//#include <QVariant>
//#include <QVector>
#include <QtGui>
#include <QColorDialog>
#include "BrainQuarter.h"
#include "ResourceForm.h"

#include <iostream>
//! [0]
class TreeItem : public QObject {
	Q_OBJECT
public:
    TreeItem(const QVector<QVariant> &data,
    		ResourceForm *rf, TreeItem *parent = 0);
    virtual ~TreeItem();

    TreeItem *child(int number);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    bool insertChildren(int position, int count, int columns);
    bool insertColumns(int position, int columns);
    TreeItem *parent();
    bool removeChildren(int position, int count);
    bool removeColumns(int position, int columns);
    int childNumber() const;
    bool setData(int column, const QVariant &value);
//     GeometryScene * insertGeometry(QFile &file, bool cylinder_flag=false,char* dbfile=NULL);
//     GeometryScene * insertGeometry(QFile &file);
    bool insertGeometry(QFile &file);
	bool insertTags(QFile &file);
	bool createTag(float *tagpoint);
	bool createRootSeparator();
    bool insertCone();
    void setViewer(BrainQuarter *quarterViewer); 
	double currentTagSize;
	float currTagR;float currTagG;float currTagB;
    virtual QWidget* createForm();
    virtual void destroyForm();
    virtual bool havePropForm() { return haveProps; };

    // this method is called every time the user selectes the particular item in the GUI.
    // subclasses can reimplement to do something useful here
    virtual void wasSelected() { /*std::cout << "Eeeek " << parent()->childNumber() << std::endl;*/ };

    signals:
        void propertyFormInstantiated(QWidget *widget);
        void setPickedItem(int);
        void setPickedPoint(int);
// 		void valueChanged(int);
        void localPointPicked(int);
public slots:
        // only used by geometryScene, but QT appears to need it in the superclass too for some oddreason
        virtual void pickReceived(int index, int id,int real_id, float x, float y, float z, SoType objtype) { /* nothing */ };
		virtual void noPointReceived() { /* nothing */ };
        virtual void pickedPointReceived(int) { /* do nothing */ };
		virtual void getUserLabel() { /* do nothing */ };
		virtual void saveLabel() { /* do nothing */ };
		virtual void saveasLabel() { /* do nothing */ };
		virtual void createNewEdge() { /* do nothing */ };
		virtual void addNewEdge() { /* do nothing */ };
		virtual void deleteThisEdge(){ /* do nothing */};
		virtual void updateRadiusTransparency(int newVal){/* do nothing */};
		//virtual void bckgrncolourDialog(){/* do nothing */};
		void updateTagSize(double newsize);
		void TagcolourDialog();
        // ditto
        //virtual void localPointPicked(int index);

protected:
	bool haveProps;
    QList<TreeItem*> childItems;
    QVector<QVariant> itemData;
    TreeItem *parentItem;
    BrainQuarter *viewer;
    ResourceForm *form;
    QWidget *formWidget;
    bool formInstantiated;
};
//! [0]

#endif
