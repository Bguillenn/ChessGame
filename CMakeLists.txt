cmake_minimum_required(VERSION 3.5)

project(ChessGame LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

file(GLOB files "*.cpp" "*.h" "*.ui" "*.qrc")

if(ANDROID)
  add_library(ChessGame SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    Board.h
    Board.cpp
    Board.ui
    Piece.h
    Piece.cpp
    Knight.h
    Knight.cpp
    Queen.h
    Queen.cpp
    King.h
    King.cpp
    Rook.h
    Rook.cpp
    Bishop.h
    Bishop.cpp
    Pawn.h
    Pawn.cpp
  )
else()
  add_executable(ChessGame
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    resource.qrc
    Board.h
    Board.cpp
    Board.ui
    Piece.h
    Piece.cpp
    Knight.h
    Knight.cpp
    Queen.h
    Queen.cpp
    King.h
    King.cpp
    Rook.h
    Rook.cpp
    Bishop.h
    Bishop.cpp
    Pawn.h
    Pawn.cpp
  )
endif()

target_link_libraries(ChessGame PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
