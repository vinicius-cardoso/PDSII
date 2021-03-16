#include <iostream>

class IndiceNaoInicializado {};
class IndiceNegativo {};
class IndiceMaiorQueArranjo {};

template <class T, int N> class BoundedArray{

public:
    BoundedArray(){
        for(int i = 0; i < N; i++){
            index_ref[i] = false;
        }
    }

    void set(int index, T value){
        if(index >= N) throw IndiceMaiorQueArranjo();
        if(index < 0) throw IndiceNegativo();

        index_ref[index] = true;
        buf[index] = value;
    }
    T get(int index){
        if(index >= N) throw IndiceMaiorQueArranjo();
        if(index < 0) throw IndiceNegativo();
        if(index_ref[index] == false) throw IndiceNaoInicializado();

        return buf[index];
    }

private:
    T buf[N];
    bool index_ref[N];
};

template <class T>
void testArray(){
    BoundedArray<T, 8> a;
    char action;
    while (std::cin >> action){
        int index;
        std::cin >> index;
        try{
            if (action == 's'){
                T value;
                std::cin >> value;
                a.set(index, value);
            }
            else if (action == 'g'){
                std::cout << a.get(index) << std::endl;
            }
        } catch (IndiceNaoInicializado){
            std::cerr << "Erro: indice nao inicializado." << std::endl;
        } catch (IndiceNegativo){
            std::cerr << "Erro: indice negativo." << std::endl;
        } catch (IndiceMaiorQueArranjo){
            std::cerr << "Erro: indice maior que arranjo." << std::endl;
        }

    }
}

int main(){
    char type;
    std::cin >> type;
    switch (type){
    case 'd':
        testArray<double>();
        break;
    case 'i':
        testArray<int>();
        break;
    case 's':
        testArray<std::string>();
        break;
    }
    return 0;
}