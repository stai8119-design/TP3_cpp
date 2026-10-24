#include <iostream>
#include <string>

using namespace std;

class CompteBancaire {
private:
    string numero;
    double solde;
    string* historique;
    int capacite;
    int nbOps;

public:
    CompteBancaire() {
        numero = "0000";
        solde = 0.0;
        capacite = 5;
        nbOps = 0;
        historique = new string[capacite];
        historique[nbOps++] = "Creation du compte par defaut";
    }

    CompteBancaire(string num, double s) {
        numero = num;
        solde = s;
        capacite = 5;
        nbOps = 0;
        historique = new string[capacite];
        historique[nbOps++] = "Creation du compte : " + num;
    }

    ~CompteBancaire() {
        delete[] historique;
    }

    void deposer(double montant) {
        if (montant > 0) {
            solde += montant;
            historique[nbOps++] = "Depot d'argent";
        }
    }

    void afficher() {
        cout << "Compte : " << numero << " | Solde : " << solde << " DH" << endl;
        cout << "Historique :" << endl;
        for (int i = 0; i < nbOps; i++) {
            cout << " - " << historique[i] << endl;
        }
    }
};

int main() {
    CompteBancaire c1("MA123", 500.0);
    c1.deposer(200.0);
    c1.afficher();

    return 0;
}