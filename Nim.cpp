#include <iostream>
#include <cstdlib>

using namespace std;

void Tabunim(int *npalitos){ //cria o método que imprime o tabuleiro do Nim no terminal

for(int loop = 0;loop<*npalitos;loop++){ //imprime a quantidade de palitos que foi escolhido
   cout<<"| ";
}
cout<<"\n"<<"Numero de palitos restantes: "<<*npalitos<<"\n";
}
///////////////////////////////////////////////////////////////////////////////////

void jogador1(int *npalitos){ //os métodos para o jogador 1
int tpalitos; //recebe a quantidade de palitos que vão ser retirados

cout<<"Digite quantos palitos pegar (1,2 ou 3): ";
cin>>tpalitos;
if(tpalitos >0 && tpalitos<=3){ //verifica se a quantidade de palitos que vão ser retirados está entre (1,2 ou 3)
 if(tpalitos <= *npalitos){ //redundância para que o número de palitos que vão ser retirados não seja maior que o a quantidade palitos que há no jogo
   *npalitos=*npalitos-tpalitos; //retira os palitos
 }else{ //caso o numero de palitos retirado seja maior que a quantidade de palitos que sobraram no jogo
   cout<<"\n"<<"Quantidade indevida, sobrou apenas "<<*npalitos<<" palito(s) no jogo"<<"\n"<<"\n";
   Tabunim(npalitos); //mostra de novo o tabuleiro pro jogador não se perder
   jogador1(npalitos); //função recursiva
 }
}else{ //caso o número de palitos retirados não esteja no intervalo [1,3]
   cout<<"\n"<<"Quantidade invalida, pode retirar apenas (1,2 ou 3) palitos de uma vez "<<"\n"<<"\n";
   Tabunim(npalitos); //mostra de novo o tabuleiro pro jogador não se perder
   jogador1(npalitos); //função recursiva
}
}
///////////////////////////////////////////////////////////////////////////////////

void bot(int *npalitos){//os métodos para o bot

if(*npalitos%4 == 0){//verifica se a quantidade de palitos que sobrou da vez do jogador1 é multiplo de 4
   int aleatorio = rand() % 3 + 1;//Pega um número aleatório entre 1 e 3
   *npalitos = *npalitos - aleatorio; //tira uma quantidade aleatória de palitos
   cout<<"O computador pegou "<<aleatorio<<" palito(s)"<<"\n";
}else{ //verifica quando a quantidade de palito que sobrou da vez do jogador1 não é multiplo de 4
   int loop = 0;

if(*npalitos>4){ //verifica se há mais de 4 palitos
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

 int JogoNim(int *npalitos) { //Junta todos os métodos numa função só
 Tabunim(npalitos); //inicia o tabuleiro
 jogador1(npalitos); //Inicia o método do jogador
 if(*npalitos==0){ //Verifica-se o jogador já venceu
    cout<<"Fim de jogo -> O Jogador1 Venceu ";
    return 0;
 }
 Tabunim(npalitos); //atualiza o tabuleiro
 bot(npalitos); //inicia o método do bot
 if(*npalitos==0){ //Verifica-se o Bot já venceu
    cout<<"Fim de jogo -> O Computador Venceu ";
    return 0;
 }
 JogoNim(npalitos);//função recursiva caso o jogo ainda não tenha terminado
 }
///////////////////////////////////////////////////////////////////////////////////

int main(){
int npalitos = 0;  //variavel que recebe a quantidade de palitos do jogo
cout<<"Digite a quantidade inicial de palitos: "; //pergunta ao jogador o número de palitos
cin>>npalitos; cout<<"\n";
while (npalitos <= 0 || cin.fail()) {  // redundância para que a quantidade de palitos necessaria pra começar o jogo seja >0
  cout <<"Quantidade invalida, digite um numero > 0 para iniciar o jogo"<<"\n";
  cout<<"Digite a quantidade inicial de palitos: ";
  cin >> npalitos;  cout<<"\n";
}
JogoNim(&npalitos); //chama a função JogoNIm

string reiniciar;
cout<<"\n"<<"\n"<<"Jogar Novamente? ";
cin>>reiniciar;
if(reiniciar == "sim" || reiniciar == "SIM"){ // da a opção do jogador reiniciar o jogo sem ter que fechar o terminal
   system("cls"); //limpa o terminal, funciona apenas em Windows, Apple ou Linux usar system("clear")
   main(); //função recursiva
}
return 0;
}
