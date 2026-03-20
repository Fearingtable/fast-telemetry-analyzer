# 🏭 Fast IoT Telemetry Analyzer

![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg)
![CMake](https://img.shields.io/badge/CMake-3.14%2B-brightgreen.svg)
![License](https://img.shields.io/badge/License-MIT-yellow.svg)
![Zero Dependencies](https://img.shields.io/badge/Dependencies-None-success.svg)

A high-performance, zero-dependency C++ engine designed to parse and aggregate massive IoT telemetry datasets (CSV) in real-time.

## 🎯 The Business Case
### The Problem
In industrial IoT environments, sensor networks generate gigabytes of telemetry data daily. Traditional data aggregation scripts (often written in Python or Node.js) struggle with these volumes, creating severe bottlenecks. Loading million-row CSVs into memory causes high RAM consumption and takes minutes or even hours to process, delaying critical business analytics.

### The Solution
This project acts as a high-speed drop-in replacement for slow aggregation scripts. Written in **Modern C++17**, it streams data sequentially without loading the entire file into RAM, updating statistics (Min, Max, Average) on the fly. It reduces processing time from minutes to mere seconds.

## 🧠 Technical Highlights
As a portfolio project, this repository demonstrates proficiency in modern systems programming:
* **Memory Efficiency:** Uses sequential file reading (`std::ifstream`) to maintain a constant, minimal memory footprint (O(1) space complexity relative to file size), regardless of how large the CSV grows.
* **Optimal Data Structures:** Utilizes `std::unordered_map` for O(1) average time complexity when looking up and updating individual sensor statistics.
* **Modern C++ Practices:** Employs RAII for resource management, structured bindings, and standard algorithms.
* **Industry Standard Build:** Configured with modern **CMake** for cross-platform compilation and easy integration into CI/CD pipelines. Optimized out-of-the-box with `-O3` flags.

## 📊 Benchmarks (Python vs C++)
*Tests performed locally on a generated dataset of 10,000,000 rows (~200 MB).*

| Language/Method | Execution Time | Peak RAM Usage |
| :--- | :--- | :--- |
| **Python (Standard CSV)** | ~25.0 seconds | ~50 MB |
| **C++17 (This Engine)** | **~4.9 seconds** | **< 5 MB** |

*(Note: The C++ implementation parses and aggregates ~2 million rows per second utilizing standard I/O streams and `std::unordered_map` for O(1) lookups).*

## 🚀 Getting Started

### Prerequisites
* A C++17 compatible compiler (GCC, Clang, or MSVC)
* CMake 3.14 or higher

### Build Instructions
This project uses CMake for building. Run the following commands in the root directory:

```bash
# 1. Create a build directory
mkdir build && cd build

# 2. Configure the project
cmake ..

# 3. Compile the executable
cmake --build . --config Release
