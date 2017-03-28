#-------------------------------------------------
#
# Project created by QtCreator 2017-03-08T11:01:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LSHMinHash6
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    Bucket.cpp \
    Buckets.cpp \
    Experiments.cpp \
    Parameters.cpp \
    Permutation.cpp \
    Permutations.cpp \
    Sequence.cpp \
    Sequences.cpp \
    SequenceSignatureGenerator.cpp \
    SequencesMap.cpp \
    SequencesSet.cpp \
    Signature.cpp \
    SimilaritySet.cpp \
    test.cpp \
    lsh_minhash.cpp \
    LSHHandler.cpp \
    lshminhashrunwidget.cpp \
    numberofhashesexperiment.cpp \
    numberofhashesexperimentinputwidget.cpp \
    Command.cpp \
    commandrun.cpp \
    LambertW.cpp

HEADERS  += mainwindow.h \
    Bucket.h \
    Buckets.h \
    Experiments.h \
    json.hpp \
    Parameters.h \
    Permutation.h \
    Permutations.h \
    Sequence.h \
    Sequences.h \
    SequenceSignatureGenerator.h \
    SequencesMap.h \
    SequencesSet.h \
    Signature.h \
    SimilaritySet.h \
    test.h \
    include/bchartdir.h \
    include/chartdir.h \
    include/FinanceChart.h \
    include/memblock.h \
    lsh_minhash.h \
    LSHHandler.h \
    lshminhashrunwidget.h \
    qchartviewer.h \
    numberofhashesexperiment.h \
    numberofhashesexperimentinputwidget.h \
    Command.h \
    commandrun.h \
    LambertW.h

FORMS    += mainwindow.ui \
    lsh_minhash.ui \
    lshminhashrunwidget.ui \
    numberofhashesexperimentinputwidget.ui

INCLUDEPATH += ./include/

DEFINES += CHARTDIR_HIDE_OBSOLETE _CRT_SECURE_NO_WARNINGS

#win32:DESTDIR = $$PWD
win32:LIBS += $$PWD/lib/chartdir60.lib
#win32:QMAKE_POST_LINK = copy /Y $$PWD\\lib\\chartdir60.dll $(DESTDIR)

#win32:QMAKE_POST_LINK += copy /Y $$PWD\\lib\\chartdir60.dll \"$$PWD\"

DISTFILES += \
    lib/chartdir60.lib \
    lib/chartdir60.dll \
    lib/chartdir.lic
