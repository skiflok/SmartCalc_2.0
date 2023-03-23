QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller/controller.cc \
    model/kernel/calculators/calculator.cc \
    model/kernel/calculators/calculator_credit.cc \
    model/kernel/calculators/calculator_deposit.cc \
    model/kernel/calculators/calculator_plot.cc \
    model/kernel/parser.cc \
    model/kernel/validator.cc \
    model/model.cc \
    qcustomplot.cpp \
    main.cpp \
    view/credit_view/creditview.cpp \
    view/deposit_viev/depositview.cpp \
    view/mainwindow.cpp

HEADERS += \
    controller/controller.h \
    model/data/data_credit.h \
    model/data/data_deposit.h \
    model/data/data_plot.h \
    model/kernel/calculators/calculator.h \
    model/kernel/calculators/calculator_credit.h \
    model/kernel/calculators/calculator_deposit.h \
    model/kernel/calculators/calculator_plot.h \
    model/kernel/parser.h \
    model/kernel/validator.h \
    model/model.h \
    qcustomplot.h \
    view/credit_view/creditview.h \
    view/deposit_viev/depositview.h \
    view/mainwindow.h \

FORMS += \
    view/credit_view/creditview.ui \
    view/deposit_viev/depositview.ui \
    view/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
