#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <limits>
#include <sstream>

// Struttura per mantenere le statistiche di un singolo sensore
struct SensorStats {
    int count = 0;
    double sum = 0.0;
    double min_val = std::numeric_limits<double>::max();
    double max_val = std::numeric_limits<double>::lowest();

    void update(double value) {
        count++;
        sum += value;
        if (value < min_val) min_val = value;
        if (value > max_val) max_val = value;
    }

    double getAverage() const {
        return count > 0 ? sum / count : 0.0;
    }
};

class TelemetryAnalyzer {
public:
    // Analizza un file CSV nel formato: "sensor_id,temperature"
    bool analyzeFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Errore: impossibile aprire il file " << filename << "\n";
            return false;
        }

        std::string line;
        // Salta l'intestazione (header)
        std::getline(file, line);

        while (std::getline(file, line)) {
            size_t comma_pos = line.find(',');
            if (comma_pos == std::string::npos) continue;

            std::string sensor_id = line.substr(0, comma_pos);
            double temperature = std::stod(line.substr(comma_pos + 1));

            // Aggiorna le statistiche in tempo reale (O(1) lookup)
            stats[sensor_id].update(temperature);
        }

        return true;
    }

    void printResults() const {
        std::cout << "--- Statistiche Sensori ---\n";
        for (const auto& [sensor_id, sensor_stats] : stats) {
            std::cout << "Sensore: " << sensor_id 
                      << " | Media: " << sensor_stats.getAverage()
                      << " | Min: " << sensor_stats.min_val
                      << " | Max: " << sensor_stats.max_val 
                      << " | Letture: " << sensor_stats.count << "\n";
        }
    }

private:
    std::unordered_map<std::string, SensorStats> stats;
};
