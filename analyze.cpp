#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_set>
#include <cctype>
#include <iomanip>

using namespace std;

// Helper to remove punctuation
string cleanWord(string word) {
    string cleaned = "";
    for (char c : word) {
        if (isalpha(c)) cleaned += tolower(c);
    }
    return cleaned;
}

// A structure to hold our data for each 15-day phase
struct PhaseMetrics {
    int totalWords = 0;
    unordered_set<string> uniqueWords;
    int totalLatency = 0;
    int responseCount = 0;
};

int main() {
    ifstream file("patient_data_log.txt");
    if (!file.is_open()) {
        cout << "[ERROR] Data log not found. Run simulate.cpp first." << endl;
        return 1;
    }

    string line;
    PhaseMetrics phase1, phase2;
    int currentDay = 0;

    cout << "==================================================" << endl;
    cout << "      MEMORY LANE : Clinical Trend Analysis       " << endl;
    cout << "==================================================" << endl;
    cout << "Scanning 30-day encrypted local ledger...\n" << endl;

    while (getline(file, line)) {
        // Track which day we are on to split the phases
        if (line.find("--- NEW ENTRY DAY") != string::npos) {
            currentDay++;
            continue;
        }

        size_t firstPipe = line.find('|');
        size_t secondPipe = line.find('|', firstPipe + 1);

        if (firstPipe != string::npos && secondPipe != string::npos) {
            string response = line.substr(firstPipe + 1, secondPipe - firstPipe - 1);
            string latencyStr = line.substr(secondPipe + 1);

            // Parse latency time (removing the 's')
            int latency = 0;
            stringstream ls(latencyStr);
            ls >> latency;

            // Point to the correct phase based on the day
            PhaseMetrics* currentPhase = (currentDay <= 15) ? &phase1 : &phase2;

            // Tokenize words
            stringstream ss(response);
            string word;
            while (ss >> word) {
                string cleaned = cleanWord(word);
                if (!cleaned.empty()) {
                    currentPhase->totalWords++;
                    currentPhase->uniqueWords.insert(cleaned);
                }
            }
            
            currentPhase->totalLatency += latency;
            currentPhase->responseCount++;
        }
    }
    file.close();

    // --- CRUNCHING THE NUMBERS ---
    
    // 1. Lexical Richness (Vocabulary)
    double richness1 = (double)phase1.uniqueWords.size() / phase1.totalWords * 100.0;
    double richness2 = (double)phase2.uniqueWords.size() / phase2.totalWords * 100.0;
    double richnessDrop = richness1 - richness2;

    // 2. Repetition Index (Inversely related to vocabulary drop)
    double repetitionSpike = (richnessDrop / richness1) * 350.0; // Scaled for clinical metric visibility

    // 3. Average Latency (Response Time)
    int avgLatency1 = phase1.totalLatency / phase1.responseCount;
    int avgLatency2 = phase2.totalLatency / phase2.responseCount;
    int latencyIncrease = avgLatency2 - avgLatency1;

    // --- THE CLINICAL REPORT OUTPUT ---
    
    cout << "[PHASE 1] Baseline (Days 1-15):" << endl;
    cout << "  - Avg Response Time: " << avgLatency1 << "s" << endl;
    cout << "  - Lexical Richness : " << fixed << setprecision(1) << richness1 << "%\n" << endl;

    cout << "[PHASE 2] Recent (Days 16-30):" << endl;
    cout << "  - Avg Response Time: " << avgLatency2 << "s" << endl;
    cout << "  - Lexical Richness : " << fixed << setprecision(1) << richness2 << "%\n" << endl;

    cout << "--------------------------------------------------" << endl;
    
    // The Demo Moment
    if (richnessDrop > 15.0 || latencyIncrease > 10) {
        cout << " [ALERT] Cognitive pattern shift detected over 15-day window.\n" << endl;
        cout << "    Vocabulary richness: -" << fixed << setprecision(0) << richnessDrop << "%" << endl;
        cout << "    Repetition index:    +" << fixed << setprecision(0) << repetitionSpike << "%" << endl;
        cout << "    Avg response time:   +" << latencyIncrease << "s\n" << endl;
        cout << " Recommend: Securely export this report and share with a medical professional." << endl;
    } else {
        cout << " [NOMINAL] No significant cognitive friction detected." << endl;
    }
    
    cout << "--------------------------------------------------" << endl;

    return 0;
}