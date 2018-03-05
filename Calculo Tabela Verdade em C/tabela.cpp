#include <iostream>
#include <locale.h>

#define NEG(a)    (!a)      //Nega��o
#define CON(a, b) (a && b)  //Conjun��o
#define DIS(a, b) (a || b)  //Disjun��o
#define IMP(a, b) (!a || b) //Implica��o
#define BIP(a, b) (a == b)  //Bi-implica��o

using namespace std;

void menu();
char exibe(bool);
void operacao(char);
int fat(int);

int main() {
    setlocale(LC_ALL, "Portuguese");

    int n;

    do {
        menu();

        cout << "Digite a opera��o desejada: ";
        cin >> n;

        switch(n) {
            case 1:
                operacao('n');
                break;

            case 2:
                operacao('c');
                break;

            case 3:
                operacao('d');
                break;

            case 4:
                operacao('i');
                break;

            case 5:
                operacao('b');
                break;

            case 6:
                cout << "Digite o valor a ser calculado: ";
                cin >> n;

                cout << endl << "Fatorial de " << n << " �: " << fat(n) << endl << endl;

                break;

            case 0:
                cout << endl << "Saindo..." << endl << endl;
                return 1;

            default:
                cout << endl << "Digite um valor entre 0 e 6." << endl << endl;
                break;
        }
    }while(1);

    return 0;
}

//Exibe o Menu
void menu() {
    cout << "1 - Nega��o"       << endl;
    cout << "2 - Conju��o"      << endl;
    cout << "3 - Disjun��o"     << endl;
    cout << "4 - Condicional"   << endl;
    cout << "5 - Bicondicional" << endl;
    cout << "6 - Fatorial"      << endl;
    cout << "0 - Sair"          << endl << endl;
}

//Converte booleano para um char equivalente
char exibe(bool a) {
    if(a)
        return 'V';

    return 'F';
}

//Realiza os testes da tabela verdade e a exibe
void operacao(char op) {
    switch(op) {
        case 'n':
            cout << endl << "===== x =====" << endl;
            cout << "= P = |  ~P =" << endl;
            cout << "= " << exibe(false) << " = |  " << exibe(NEG(false)) << "  =" << endl;
            cout << "= " << exibe(true) << " = |  " << exibe(NEG(true)) << "  =" << endl;
            cout << "===== x =====" << endl << endl;

            break;

        case 'c':
            cout << endl << "===== x ===== x =========" << endl;
            cout << "= P = |   Q   |  P ^ Q  =" << endl;
            cout << "= " << exibe(false) << " = |   " << exibe(false) << "   |    " << exibe(CON(false, false)) << "    =" << endl;
            cout << "= " << exibe(false) << " = |   " << exibe(true) << "   |    " << exibe(CON(false, true)) << "    =" << endl;
            cout << "= " << exibe(true) << " = |   " << exibe(false) << "   |    " << exibe(CON(true, false)) << "    =" << endl;
            cout << "= " << exibe(true) << " = |   " << exibe(true) << "   |    " << exibe(CON(true, true)) << "    =" << endl;
            cout << "===== x ===== x =========" << endl << endl;

            break;

        case 'd':
            cout << endl << "===== x ===== x =========" << endl;
            cout << "= P = |   Q   |  P v Q  =" << endl;
            cout << "= " << exibe(false) << " = |   " << exibe(false) << "   |    " << exibe(DIS(false, false)) << "    =" << endl;
            cout << "= " << exibe(false) << " = |   " << exibe(true) << "   |    " << exibe(DIS(false, true)) << "    =" << endl;
            cout << "= " << exibe(true) << " = |   " << exibe(false) << "   |    " << exibe(DIS(true, false)) << "    =" << endl;
            cout << "= " << exibe(true) << " = |   " << exibe(true) << "   |    " << exibe(DIS(true, true)) << "    =" << endl;
            cout << "===== x ===== x =========" << endl << endl;

            break;

        case 'i':
            cout << endl << "===== x ===== x =========" << endl;
            cout << "= P = |   Q   |  P -> Q =" << endl;
            cout << "= " << exibe(false) << " = |   " << exibe(false) << "   |    " << exibe(IMP(false, false)) << "    =" << endl;
            cout << "= " << exibe(false) << " = |   " << exibe(true) << "   |    " << exibe(IMP(false, true)) << "    =" << endl;
            cout << "= " << exibe(true) << " = |   " << exibe(false) << "   |    " << exibe(IMP(true, false)) << "    =" << endl;
            cout << "= " << exibe(true) << " = |   " << exibe(true) << "   |    " << exibe(IMP(true, true)) << "    =" << endl;
            cout << "===== x ===== x =========" << endl << endl;

            break;

        case 'b':
            cout << endl << "===== x ===== x ==========" << endl;
            cout << "= P = |   Q   |  P <-> Q =" << endl;
            cout << "= " << exibe(false) << " = |   " << exibe(false) << "   |     " << exibe(BIP(false, false)) << "    =" << endl;
            cout << "= " << exibe(false) << " = |   " << exibe(true) << "   |     " << exibe(BIP(false, true)) << "    =" << endl;
            cout << "= " << exibe(true) << " = |   " << exibe(false) << "   |     " << exibe(BIP(true, false)) << "    =" << endl;
            cout << "= " << exibe(true) << " = |   " << exibe(true) << "   |     " << exibe(BIP(true, true)) << "    =" << endl;
            cout << "===== x ===== x ==========" << endl << endl;

            break;
    }
}

//Calcula o Fatorial
int fat(int a) {
    if(!a || a == 1)
        return 1;

    return fat(a-1) * a;
}
