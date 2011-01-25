VERSION = 0.1.1


# Note: Remember to run:
#      >qmake -spec macx-g++       [ regen the make file ]
#  OR  >qmake -spec linux-g++
#
#      >make                       [ build ]


# set where to get the Minc libs and includes
# ... there really *must* be a better way of doing this
#MINCDIR = /projects/mice/share/arch/linux64
#MINCDIR = /usr/local/minc2
MINCDIR = /usr/local/bic


QUARTERDIR = /usr/local

COINLIBS = $$system(coin-config --ldflags)
COININCLUDE = $$system(coin-config --includedir)
CONFIG += qt
CONFIG += debug
QT += opengl
INCLUDEPATH += $$COININCLUDE
LIBS += $$COINLIBS
!macx { 
    LIBS += -lCoin
    LIBS += -L$${QUARTERDIR} \
        -lQuarter
    INCLUDEPATH += $${MINCDIR}/include
    INCLUDEPATH += $${QUARTERDIR}/include
    LIBS += -L$${MINCDIR}/lib/ \
        -loobicpl \
        -lpcre++ \
        -lpcre \
        -lbicpl \
        -lvolume_io2 \
        -lminc2 \
        -lhdf5 \
        -lnetcdf
}
macx { 
    LIBS += -Wl,-framework \
        -Wl,Quarter
    LIBS += -L$${MINCDIR}/lib \
        -loobicpl \
        -lpcre++ \
        -lpcre \
        -lbicpl \
        -lvolume_io2 \
        -lminc2 \
        -lhdf5 \
        -lnetcdf
    INCLUDEPATH += $${MINCDIR}/include
}
INCLUDEPATH += /usr/local/include
FORMS = textureColumnForm.ui \
    resourceForm.ui \
    geometryProps.ui
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
    tagPointItem.h
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
    tagPointItem.cpp
RESOURCES += colourbars.qrc
