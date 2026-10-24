#include <iostream>

using namespace std;

class Buffer {
private:
    char* data; 
    int taille; 

public:
    Buffer() {
        data = nullptr;
        taille = 0;
    }
    Buffer(int t) {
        taille = t;
        data = new char[taille];
        cout << "Buffer cree avec succes (Taille: " << taille << ")" << endl;
    }
    ~Buffer() {
        delete[] data; 
        cout << "Buffer supprime et memoire liberee." << endl;
    }

    int getTaille() {
        return taille;
    }
};

int main() {
    Buffer b1(100);
    cout << "Taille du buffer : " << b1.getTaille() << endl;

    return 0;
}