#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

int main() {
    // 1. Define our cognitive baseline questions
    vector<string> questions = {
        "1. Describe what you did this morning in a few sentences.",
        "2. Name three distinct animals you might see in a zoo.",
        "3. Briefly explain a problem you solved recently and how you did it."
    };

    // 2. Open our local flat file for saving (append mode so we don't delete past days)
    ofstream journalFile("patient_data_log.txt", ios::app);

    if (!journalFile.is_open()) {
        cout << "[ERROR] Could not secure local storage file." << endl;
        return 1;
    }

    cout << "==================================================" << endl;
    cout << "            MEMORY LANE : Daily Check-in          " << endl;
    cout << "==================================================" << endl;
    cout << "SYSTEM: All data is stored locally. Zero cloud transmission.\n" << endl;

    // Write a visual separator in the file for a new entry
    journalFile << "--- NEW ENTRY ---" << endl;

    // 3. The Prompt Loop
    string response;
    for (const string& q : questions) {
        cout << q << "\n> ";

        // Start the latency timer
        auto start_time = steady_clock::now();

        // Get the user's full sentence response
        getline(cin, response);

        // Stop the timer
        auto end_time = steady_clock::now();
        auto duration = duration_cast<seconds>(end_time - start_time);

        // 4. Save to our offline text file
        // Format: Question | Response | Latency (seconds)
        journalFile << q << " | " << response << " | " << duration.count() << "s" << endl;

        cout << "[System Log: Response recorded in " << duration.count() << " seconds]\n" << endl;
    }

    journalFile.close();
    cout << "Check-in complete. All data secured locally." << endl;

    return 0;
}