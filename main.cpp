#include <iostream>
#include <string>
using namespace std;
#define ALNS 5
#define NTS 3

// Função para calcular a média
float calcularMedia(float n1, float n2, float n3) {
    return (n1 + n2 + n3) / 3;
}

int main() {
   
    string nomes[ALNS];
    float notas[ALNS][NTS];
    float medias[ALNS];
    string situacao[ALNS];
    int qtdAlunos;
   int indiceMaior = 0;

    cout << "Quantos alunos deseja cadastrar? (max " << ALNS << "): ";
    cin >> qtdAlunos;

    if (qtdAlunos > ALNS) qtdAlunos = ALNS;

    // Entrada de dados
    for (int i = 0; i < qtdAlunos; i++) {
        cout << "\nAluno " << i + 1 << ":\nNome: ";
        cin >> nomes[i];
          for (int j = 0; j < NTS; j++) {
            cout << "Nota " << j + 1 << ": ";
            cin >> notas[i][j];
        }

        medias[i] = calcularMedia(notas[i][0], notas[i][1], notas[i][2]);

        if (medias[i] >= 7.0)
            situacao[i] = "Aprovado";
        else
            situacao[i] = "Reprovado";

       if (medias[i] > medias[indiceMaior]) {
             indiceMaior = i;
         }
    }

    // Exibição da tabela
    cout << "\n----------------------------------------------\n";
    cout << "Nome\t\tN1\tN2\tN3\tMedia\tSituacao\n";
    cout << "----------------------------------------------\n";


    for (int i = 0; i < qtdAlunos; i++) {
        cout << nomes[i] << "\t\t"
             << notas[i][0] << "\t"
             << notas[i][1] << "\t"
             << notas[i][2] << "\t"
             << medias[i] << "\t"
             << situacao[i] << endl;
    }

    cout << "----------------------------------------------\n";
    cout << "Aluno com maior media: " << nomes[indiceMaior] 
         << " (Media = " << medias[indiceMaior] << ")\n";

    return 0;
}
