cmake_minimum_required(VERSION 3.29)
project(2048_Game)

set(CMAKE_CXX_STANDARD 20)

add_executable(2048_Game main.cpp
        src/game2048.cpp
        src/include/game2048.h
        src/include/Board.h
        src/Board.cpp
        src/gamewindow.cpp
        src/gamewindow.h
        src/leaderboard.cpp
        src/leaderboard.h
        src/mainmenu.cpp
        src/mainmenu.h
        src/pausemenu.cpp
        src/pausemenu.h
)
