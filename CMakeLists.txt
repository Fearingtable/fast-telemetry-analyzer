cmake_minimum_required(VERSION 3.14)
project(FastTelemetryAnalyzer VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ottimizzazione per la massima velocità (O3)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

include_directories(include)

add_executable(telemetry_analyzer src/main.cpp)
