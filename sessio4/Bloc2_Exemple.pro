TEMPLATE    = app
QT         += opengl 

INCLUDEPATH +=  /usr/include/glm

INCLUDEPATH += /Users/agallofre/Desktop/sessio4/Model
SOURCES += /Users/agallofre/Desktop/sessio4/Model/model.cpp

FORMS += MyForm.ui

HEADERS += MyForm.h MyGLWidget.h

SOURCES += main.cpp MyForm.cpp \
        MyGLWidget.cpp 
