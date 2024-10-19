#include <iostream>
#include <cstdlib>

using namespace std;

void Tabunim(int *npalitos){ //cria o m�todo que imprime o tabuleiro do Nim no terminal

for(int loop = 0;loop<*npalitos;loop++){ //imprime a quantidade de palitos que foi escolhido
   cout<<"| ";
}
cout<<"\n"<<"Numero de palitos restantes: "<<*npalitos<<"\n";
}
///////////////////////////////////////////////////////////////////////////////////

void jogador1(int *npalitos){ //os m�todos para o jogador 1
int tpalitos; //recebe a quantidade de palitos que v�o ser retirados

cout<<"Digite quantos palitos pegar (1,2 ou 3): ";
cin>>tpalitos;
if(tpalitos >0 && tpalitos<=3){ //verifica se a quantidade de palitos que v�o ser retirados est� entre (1,2 ou 3)
 if(tpalitos <= *npalitos){ //redund�ncia para que o n�mero de palitos que v�o ser retirados n�o seja maior que o a quantidade palitos que h� no jogo
   *npalitos=*npalitos-tpalitos; //retira os palitos
 }else{ //caso o numero de palitos retirado seja maior que a quantidade de palitos que sobraram no jogo
   cout<<"\n"<<"Quantidade indevida, sobrou apenas "<<*npalitos<<" palito(s) no jogo"<<"\n"<<"\n";
   Tabunim(npalitos); //mostra de novo o tabuleiro pro jogador n�o se perder
   jogador1(npalitos); //fun��o recursiva
 }
}else{ //caso o n�mero de palitos retirados n�o esteja no intervalo [1,3]
   cout<<"\n"<<"Quantidade invalida, pode retirar apenas (1,2 ou 3) palitos de uma vez "<<"\n"<<"\n";
   Tabunim(npalitos); //mostra de novo o tabuleiro pro jogador n�o se perder
   jogador1(npalitos); //fun��o recursiva
}
}
///////////////////////////////////////////////////////////////////////////////////

void bot(int *npalitos){//os m�todos para o bot

if(*npalitos%4 == 0){//verifica se a quantidade de palitos que sobrou da vez do jogador1 � multiplo de 4
   int aleatorio = rand() % 3 + 1;//Pega um n�mero aleat�rio entre 1 e 3
   *npalitos = *npalitos - aleatorio; //tira uma quantidade aleat�ria de palitos
   cout<<"O computador pegou "<<aleatorio<<" palito(s)"<<"\n";
}else{ //verifica quando a quantidade de palito que sobrou da vez do jogador1 n�o � multiplo de 4
   int loop = 0;

if(*npalitos>4){ //verifica se h� mais de 4 palitos
   while((*npalitos-loop)%4 != 0){ //verifica quantos palitos precisa tirar para sobrar um multiplo de 4
   loop++;
}
}else{ //quando sobra menos de 4 palitos
   while((*npalitos-loop) != 0){ //verifica quantos palitos precisa tirar para acabar com o jogo
   loop++;
}
}
*npalitos = *npalitos - loop; //tira os palitos
cout<<"O computador pegou "<<loop<<" palito(s)"<<"\n";
}
}
///////////////////////////////////////////////////////////////////////////////////

 int JogoNim(int *npalitos) { //Junta todos os m�todos numa fun��o s�
 Tabunim(npalitos); //inicia o tabuleiro
 jogador1(npalitos); //Inicia o m�todo do jogador
 if(*npalitos==0){ //Verifica-se o jogador j� venceu
    cout<<"Fim de jogo -> O Jogador1 Venceu ";
    return 0;
 }
 Tabunim(npalitos); //atualiza o tabuleiro
 bot(npalitos); //inicia o m�todo do bot
 if(*npalitos==0){ //Verifica-se o Bot j� venceu
    cout<<"Fim de jogo -> O Computador Venceu ";
    return 0;
 }
 JogoNim(npalitos);//fun��o recursiva caso o jogo ainda n�o tenha terminado
 }
///////////////////////////////////////////////////////////////////////////////////

int main(){
int npalitos = 0;  //variavel que recebe a quantidade de palitos do jogo
cout<<"Digite a quantidade inicial de palitos: "; //pergunta ao jogador o n�mero de palitos
cin>>npalitos; cout<<"\n";
while (npalitos <= 0 || cin.fail()) {  // redund�ncia para que a quantidade de palitos necessaria pra come�ar o jogo seja >0
  cout <<"Quantidade invalida, digite um numero > 0 para iniciar o jogo"<<"\n";
  cout<<"Digite a quantidade inicial de palitos: ";
  cin >> npalitos;  cout<<"\n";
}
JogoNim(&npalitos); //chama a fun��o JogoNIm

string reiniciar;
cout<<"\n"<<"\n"<<"Jogar Novamente? ";
cin>>reiniciar;
if(reiniciar == "sim" || reiniciar == "SIM"){ // da a op��o do jogador reiniciar o jogo sem ter que fechar o terminal
   system("cls"); //limpa o terminal, funciona apenas em Windows, Apple ou Linux usar system("clear")
   main(); //fun��o recursiva
}
return 0;
}
