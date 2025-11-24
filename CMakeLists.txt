cmake_minimum_required(VERSION 3.30)
project(Coursework___Yaqub_Rahman)

set(CMAKE_CXX_STANDARD 14)

include_directories(classes)
include_directories(data)

add_executable(Coursework___Yaqub_Rahman
    classes/Student.cpp
    classes/Student.hpp
    classes/Term.cpp
    classes/Term.hpp
    data/grades.txt
    data/modules.txt
    data/requests.txt
    main.cpp)
