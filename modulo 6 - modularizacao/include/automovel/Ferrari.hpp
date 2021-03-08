#ifndef FERRARI_H
#define FERRARI_H

#include "Carro.hpp"

namespace Carro {

  class Ferrari : public CarroAbstrato {

    public:
      void start();
      void drive();
      void stop();

  };

}

#endif
