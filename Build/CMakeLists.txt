cmake_minimum_required(VERSION 3.10)
project(SeminarskiRad)

set(CXX_STANDARD 14)
SET(COMPLEX_SOURCE_FILES
    ../Code/Teams/finance.cpp
    ../Code/Teams/hr.cpp
    ../Code/Teams/sales.cpp
    ../Code/Teams/operations.cpp
    ../Code/Teams/engineering.cpp
    ../Code/Persons/teamLeader.cpp
    ../Code/Persons/director.cpp
    ../Code/Other/task.cpp
    ../Code/Persons/worker.cpp
    ../Code/Teams/team.cpp
    ../Code/Persons/person.cpp
    ../Code/Other/project.cpp
    ../Code/Other/date.cpp
    ../Code/main.cpp
)

add_executable(exe ${COMPLEX_SOURCE_FILES})
