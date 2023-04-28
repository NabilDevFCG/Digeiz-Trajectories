# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)

# Notre projet est étiqueté hello
project(CPPDiz)

# Crée des variables avec les fichiers à compiler
set(SRCS
    main.cpp
    point.cpp
    trajectory.cpp
    trajManager.cpp

    )
    
set(HEADERS
    point.hpp
    trajectory.hpp
    trajManager.hpp

    )

# On indique que l'on veut un exécutable "hello" compilé à partir des fichiers décrits par les variables SRCS et HEADERS
add_executable(CPPDiz ${SRCS} ${HEADERS})