cmake_minimum_required(VERSION 3.31)
project(Yazdahtaei)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

include_directories(.)

add_executable(Yazdahtaei
        Background.cpp
        Background.h
        Card.cpp
        Card.h
        CardsInHand.cpp
        CardsInHand.h
        CollectedCards.cpp
        CollectedCards.h
        DeckOfCards.h
        DemonstrableCards.h
        Game.cpp
        Game.h
        getPasswordFromUser.h
        main.cpp
        Player.cpp
        Player.h
        Repository.cpp
        Repository.h
        seeHistory.h
        sumOfNumberOfCards.h
        seeHistory.cpp
        sumOfNumberOfCards.cpp
        getPasswordFromUser.cpp)
