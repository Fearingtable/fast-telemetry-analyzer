#include <iostream>
#include <chrono>
#include "TelemetryAnalyzer.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <percorso_file_csv>\n";
        return 1;
    }

    std::string filename = argv[1];
    TelemetryAnalyzer analyzer;

    std::cout << "Analisi del file " << filename << " in corso...\n";

    auto start = std::chrono::high_resolution_clock::now();

    if (!analyzer.analyzeFile(filename)) {
        return 1;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    analyzer.printResults();
    
    std::cout << "\nElaborazione completata in " << elapsed.count() << " secondi.\n";

    return 0;
}
