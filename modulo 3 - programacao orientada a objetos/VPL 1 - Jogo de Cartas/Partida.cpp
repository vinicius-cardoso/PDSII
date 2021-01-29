#include "Partida.hpp"
#include "Jogador.hpp"

Partida::Partida(int num_jogadores){
    this->_num_jogadores = num_jogadores;
    this->_jogadores = new Jogador[num_jogadores];
}

Partida::~Partida(){
    delete this->_jogadores;
}

int Partida::getNumJogadores(){
    return this->_num_jogadores;
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
        if(jogadoresOrdenados[i].calcularPontuacao() < jogadoresOrdenados[i + 1].calcularPontuacao()){
            jogadorAuxiliar = jogadoresOrdenados[i];
            jogadoresOrdenados[i] = jogadoresOrdenados[i + 1];
            jogadoresOrdenados[i + 1] = jogadorAuxiliar;
        }
    }

    return jogadoresOrdenados;
}

void Partida::imprimeJogadoresOrdenados(){
    /* this->_jogadores.getNomeJogador();
    this->_jogadores.calcularPontuacao(); */

    for(int i = 0; i < this->_num_jogadores; i++){
        cout << getJogadoresOrdenados();
    }
}

Jogador Partida::getCampeao(){
    Jogador reserva;

    for(int i = 0; i < this->_num_jogadores; i++){
        if(this->_jogadores[i].calcularPontuacao() < this->_jogadores[i + 1].calcularPontuacao()){
            reserva = this->_jogadores[i];
            this->_jogadores[i] = this->_jogadores[i + 1];
            this->_jogadores[i + 1] = reserva;
        }
    }

    return this->_jogadores[this->_num_jogadores];
}

void Partida::addJogadorCarta(string nomeJogador, int numero_pontos_carta, string naipe){
    Jogador* jog = new Jogador();
    jog->setNomeJogador(nomeJogador);
    jog->adicionaCarta(*(new Carta(numero_pontos_carta,naipe)));
    jog->getJogadores()[getNumAtualJogadores()] = *jog;
    this->_atualSize++;
}