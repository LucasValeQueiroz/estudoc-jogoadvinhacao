
#include <iostream>
using namespace std;

int main () {
    
    cout << "**************************************" << endl;
    cout << "* Bem-vindos ao jogo da adivinhacao! *" << endl;
    cout << "**************************************" << endl;
    
    //Constante para o copilador indentificar que nunca vai mudar o valor no codigo
    const int NUMERO_SECRETO = 42;
    
    //guardando as condicionais com o bool (continua o loop caso a condição é verdadeira)(true)
    bool nao_acertou = true;
    int tentativas = 0;

    //PONTUACAO
    double pontos = 1000.0 ;
    double diferenca;   
    
    while(nao_acertou){
        tentativas++;
        int chute;
        cout << "Tentativa: " << tentativas << endl;

        // cout imprimir valores (USUARIO << MAQUINA) (MAQUINA PARA USUARIO)
        cout << "Qual é o seu chute? ";

        //cin receber valores (USUARIO >> MAQUINA) (USUARIO PARA MAQUINA)
        cin >> chute;
        cout << "Você chutou " << chute << endl;

        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;
        if(acertou){
            int aux;
            cout << "Parabéns, você acertou!" << endl;
            cout.precision(2);
            cout << fixed;
            cout << "Você fez " << pontos << " pontos" << endl << "***********************"<< endl << "*QUER JOGAR NOVAMENTE?*"<< endl << "***********************" << endl << endl;
            cout << "1 para SIM | 2 para NAO : ";
            cin >> aux;                                
            if(aux == 2)nao_acertou = false; //Finaliza o loop
            else if (aux == 1){
                cout << endl << "REINICIANDO O JOGO" << endl;
                tentativas = 0;
                pontos = 1000.0;
            }
    
        }else if (maior){
            diferenca = ((chute - NUMERO_SECRETO))/2.0;
            pontos = pontos - diferenca;
            cout << "O seu chute foi maior que o numero secreto!" << endl;
        }else {
            diferenca = ((NUMERO_SECRETO - chute))/2.0;
            pontos = pontos - diferenca;
            cout << "O seu chute foi menor que o numero secreto!" << endl;
        }
        

    }
    cout << "Fim de jogo!" << endl;
    cout << "Você acertou o número secreto em " << tentativas << " tentativas" << endl;
}