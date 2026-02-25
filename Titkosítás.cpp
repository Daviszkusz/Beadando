#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<char> xorCipher(const vector<char>& data, const string& key) {
    vector<char> result(data.size());
    
    for (size_t i = 0; i < data.size(); i++) {
        result[i] = data[i] ^ key[i % key.size()];
    }
    
    return result;
}

int main() {
    string inputFile, outputFile, key;

    cout << "--- XOR Fajltitkosito Program ---" << endl;
    
    cout << "Add meg a bemeneti fajl nevet (pl. titkos.txt): ";
    cin >> inputFile;

    cout << "Add meg a kimeneti fajl nevet (pl. eredmeny.bin): ";
    cin >> outputFile;

    cout << "Add meg a titkositasi jelszot: ";
    cin >> key;

    ifstream input(inputFile, ios::binary);
    
    if (!input) {
        cerr << "Hiba: Nem sikerult megnyitni a bemeneti fajlt! Ellenorizd a nevet." << endl;
        return 1; 
    }

    vector<char> data((istreambuf_iterator<char>(input)), istreambuf_iterator<char>());
    input.close();

    vector<char> processedData = xorCipher(data, key);

    ofstream output(outputFile, ios::binary);
    
    if (!output) {
        cerr << "Hiba: Nem sikerult letrehozni a kimeneti fajlt!" << endl;
        return 1;
    }

    output.write(processedData.data(), processedData.size());
    output.close();

    cout << "A muvelet sikeresen befejezodott! Kimenet: " << outputFile << endl;

    return 0; // Sikeres kilépés
}