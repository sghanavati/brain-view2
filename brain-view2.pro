VERSION = 0.1.1


# Note: Remember to run:
#      >qmake -spec macx-g++       [ regen the make file ]
#  OR  >qmake -spec linux-g++
#
#      >make                       [ build ]


# set where to get the Minc libs and includes, bicInventor, Quarter, hdf5
# ... there really *must* be a better way of doing this
#Example:
#QUARTERDIR = /projects/mice/share/arch/linux-x86_64-eglibc2_11_1/
#MINCDIR = /projects/mice/share/arch/linux-x86_64-eglibc2_11_1/
#INVENTORDIR = /projects/mice/share/arch/linux-x86_64-eglibc2_11_1/
#HDF5DIR = /projects/mice/share/arch/linux-x86_64-eglibc2_11_1/
#qmake-qt4 MINCDIR=/projects/mice/share/arch/linux-x86_64-eglibc2_11_1/ INVENTORDIR=/projects/mice/share/arch/linux-x86_64-eglibc2_11_1/ QUARTERDIR=/projects/mice/share/arch/linux-x86_64-eglibc2_11_1/ HDF5DIR=/projects/mice/share/arch/linux-x86_64-eglibc2_11_1/ brain-view2.pro
#or: qmake MINCDIR=/usr/local/ INVENTORDIR=/usr/local/ QUARTERDIR=/usr/local/ HDF5DIR=/usr/local/hdf5/ brain-view2.pro

COINLIBS = $$system(coin-config --ldflags)
COININCLUDE = $$system(coin-config --includedir)
CONFIG += qt
CONFIG += debug
QT += opengl
QT += widgets

INCLUDEPATH += $${QUARTERDIR}/include
INCLUDEPATH += $${QUARTERDIR}/include/Quarter/
INCLUDEPATH += $${MINCDIR}/include
INCLUDEPATH += $${INVENTORDIR}/Inventor
INCLUDEPATH += $${INVENTORDIR}/include/bicInventor/
INCLUDEPATH += $$COININCLUDE
INCLUDEPATH += $${HDF5DIR}/include

LIBS += $$COINLIBS
LIBS += -L$${MINCDIR}/lib
!macx { 
    LIBS += -lCoin
    LIBS += -L$${QUARTERDIR}/lib/ \
        -lQuarter 
}
macx { 
    LIBS += -Wl,-framework \
        -Wl,Quarter
}

LIBS += -L$${MINCDIR}/lib \
        -loobicpl \
        -lpcre++ \
        -lpcre \
        -lbicpl \
        -lminc2

LIBS += -L$${INVENTORDIR}/lib \
        -lbicInventor

LIBS += -L$${HDF5DIR}/lib/ \
        -lhdf5 \
        -lhdf5_cpp \
        -lnetcdf



FORMS = textureColumnForm.ui \
    resourceForm.ui \
    geometryProps.ui \
    tagProps.ui \
    labelProps.ui
HEADERS = MainWindow.h \
    BrainQuarter.h \
    TreeItem.h \
    TreeModel.h \
    GeometryScene.h \
    ResourceForm.h \
    GeometryNode.h \
    textureColumn.h \
    textureFileItem.h \
    tagFileItem.h \
    tagPointItem.h \
    mniVertstatsFile.h
SOURCES = MainWindow.cpp \
    BrainQuarter.cpp \
    TreeItem.cpp \
    TreeModel.cpp \
    ResourceForm.cpp \
    GeometryScene.cpp \
    GeometryNode.cpp \
    main.cpp \
    textureColumn.cpp \
    textureFileItem.cpp \
    tagFileItem.cpp \
    tagPointItem.cpp \
    mniVertstatsFile.cc
RESOURCES += colourbars.qrc
