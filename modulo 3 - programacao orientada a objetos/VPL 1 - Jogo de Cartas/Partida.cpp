#include "Partida.hpp"
#include "Jogador.hpp"

Partida::Partida(int num_jogadores){
    this->_num_jogadores = num_jogadores;
    this->_atualSize = 0;
    this->_jogadores = new Jogador[num_jogadores];
}

Partida::~Partida(){
    delete this->_jogadores;
}

int Partida::getNumJogadores(){
    return this->_num_jogadores;
}

int Partida::getNumAtualJogadores(){
    return _atualSize;
}

void Partida::setJogadores(Jogador* jogadores){
    this->_jogadores = jogadores;
}

Jogador* Partida::getJogadores(){
    return this->_jogadores;
}

Jogador* Partida::getJogadoresOrdenados(){
    Jogador *jogadoresOrdenados = new Jogador;
    jogadoresOrdenados = this->_jogadores;
    
    Jogador jogadorAuxiliar;

    for(int i = 0; i < this->_num_jogadores; i++){
        for(int j = 0; j < this->_num_jogadores - 1; j++){
            if(jogadoresOrdenados[j].calcularPontuacao() > jogadoresOrdenados[j + 1].calcularPontuacao()){
                jogadorAuxiliar = jogadoresOrdenados[j];
                jogadoresOrdenados[j] = jogadoresOrdenados[j + 1];
                jogadoresOrdenados[j + 1] = jogadorAuxiliar;
            }
        }
    }

    return jogadoresOrdenados;
}

void Partida::imprimeJogadoresOrdenados(){
    Jogador* jogadoresOrdenados = getJogadoresOrdenados();

    for(int i = 0; i < this->_num_jogadores; i++){
        cout << jogadoresOrdenados[i].getNomeJogador() << " ";
        cout << jogadoresOrdenados[i].calcularPontuacao() << endl;
    }
}

Jogador Partida::getCampeao(){
    return this->_jogadores[this->_num_jogadores - 1];
}

void Partida::addJogadorCarta(string nomeJogador, int numero_pontos_carta, string naipe){
    Jogador* jogadorCarta;

    if(getNumAtualJogadores() != 0 && getJogadores()[getNumAtualJogadores() - 1].getNomeJogador() == nomeJogador){
        jogadorCarta = &getJogadores()[getNumAtualJogadores() - 1];
        jogadorCarta->adicionaCarta(*(new Carta(numero_pontos_carta, naipe)));
    }
    else{
        jogadorCarta = new Jogador();
        jogadorCarta->setNomeJogador(nomeJogador);
        jogadorCarta->adicionaCarta(*(new Carta(numero_pontos_carta, naipe)));
        getJogadores()[getNumAtualJogadores()] = *jogadorCarta;
        this->_atualSize++;
    }
}