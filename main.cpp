#include <iostream>
#include <fstream>
#include "DiskSimulator.h"
#include "FCFSScheduler.h"
#include "ScanScheduler.h"
#include "CScanScheduler.h"

using namespace std;

int main() {
    try {
        DiskSimulator sim;
        DiskInput data = sim.loadRequests("entrada1.txt");

        FCFSScheduler fcfs;
        ScanScheduler scan;
        CScanScheduler cscan;

        long long total_fcfs  = fcfs.schedule(data);
        long long total_scan  = scan.schedule(data);
        long long total_cscan = cscan.schedule(data);

        cout << "Movimiento total FCFS : " << total_fcfs  << " cilindros\n";
        cout << "Movimiento total SCAN : " << total_scan  << " cilindros\n";
        cout << "Movimiento total C-SCAN: " << total_cscan << " cilindros\n";

        // Guardar resúmenes individuales (si quieres mantenerlos)
        sim.saveResults("salida_fcfs.txt",  total_fcfs, 0, 0);
        sim.saveResults("salida_scan.txt",  0, total_scan, 0);
        sim.saveResults("salida_cscan.txt", 0, 0, total_cscan);

        // === Archivo especial para gráficas ===
        ofstream out("resultados_graficas.txt");
        if (!out.is_open()) {
            cerr << "No se pudo abrir resultados_graficas.txt\n";
            return 1;
        }
        // Formato simple: ALGORITMO VALOR
        out << "FCFS "   << total_fcfs  << "\n";
        out << "SCAN "   << total_scan  << "\n";
        out << "C-SCAN " << total_cscan << "\n";
        out.close();

    } catch (const std::exception &ex) {
        cerr << "Error: " << ex.what() << endl;
        return 1;
    }

    return 0;
}
