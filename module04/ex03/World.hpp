#pragma once
#ifndef WORLD_HPP
#define WORLD_HPP

#include <string>
#include "AMateria.hpp"
#define DEFAULT_SIZE 10

class World {
    private:
        int capacity;
        int len;
        AMateria **world;
    public:
        World();
        World(const World &w);
        ~World();
        World &operator=(const World &w);
        void setMateria(AMateria *m);
        AMateria *getMateria(int idx);
		void validateMateria(int idx);
};

#endif