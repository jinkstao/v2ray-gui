CMAKE_MINIMUM_REQUIRED(VERSION 3.13)

PROJECT(V2Ray-GUI)

# Add Module MainForm
TARGET_SOURCES(${PROJECT_NAME} PRIVATE main.cpp)

ADD_SUBDIRECTORY(Services)
ADD_SUBDIRECTORY(ConfigForm)
