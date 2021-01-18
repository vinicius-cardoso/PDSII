#include "Partida.hpp"
#include "Jogador.hpp"

#include <algorithm>

// **construtor**, **getNumJogadores**, **setJogadores**, **getJogadores**, getCampeao, getJogadoresOrdenados, imprimeJogadoresOrdenados

Partida::Partida(int num_jogadores){
    this->_num_jogadores = num_jogadores;
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

Jogador Partida::getCampeao(){
    
}

Jogador* Partida::getJogadoresOrdenados(){
    
}

void Partida::imprimeJogadoresOrdenados(){

}

