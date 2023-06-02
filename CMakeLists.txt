cmake_minimum_required(VERSION 3.5)
project(TP1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(.)

add_executable(TP1
        Case.cpp
        Case.h
        File.h
        File.hpp
        GenerateurAleatoireJeuSerpentsEtEchelles.cpp
        GenerateurAleatoireJeuSerpentsEtEchelles.h
        GenerateurNombresAleatoires.cpp
        GenerateurNombresAleatoires.h
        JeuSerpentsEtEchelles.cpp
        JeuSerpentsEtEchelles.h
        ListeCirculaire.h
        ListeCirculaire.hpp
        ListeDeCases.cpp
        ListeDeCases.h
        Principal.cpp)
