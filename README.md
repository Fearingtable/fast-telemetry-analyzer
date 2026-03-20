# 🏭 Fast IoT Telemetry Analyzer

A high-performance C++ tool designed to process massive IoT telemetry datasets (CSV) in seconds. 

## 🎯 The Business Problem
Companies collecting sensor data often rely on scripting languages (like Python) for data aggregation. As data grows to millions of rows per day, these scripts become bottlenecks, taking minutes or hours to run and consuming excessive RAM.

## 💡 The Solution
This tool is written in modern C++17 and optimized for speed (`-O3`). It reads large CSV streams and calculates aggregations (Min, Max, Average) in real-time using highly efficient Hash Maps (`std::unordered_map`). 

It turns a 40-minute Python processing job into a 3-second C++ execution, saving compute costs and enabling near real-time analytics.
