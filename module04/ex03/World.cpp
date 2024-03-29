#include "World.hpp"

World::World() {
    this->len = 0;
    this->capacity = 10;
    this->world = new AMateria*[DEFAULT_SIZE];
    for (int i = 0; i < this->capacity; i++) {
        this->world[i] = NULL;
    }
}

World::World(const World &r) {
    this->len = r.len;
    this->capacity = r.capacity;
    this->world = new AMateria*[r.capacity];
    for (int i = 0; i < r.capacity; i++) {
        if (r.world[i] != NULL)
            this->world[i] = r.world[i]->clone();
        else
            this->world[i] = NULL;
    }
}

World::~World() {
    for (int i = 0; i < capacity; i++) {
        if (world[i] != NULL)
            delete world[i];
    }
    delete world;
}

World &World::operator=(const World &r) {
    if (this == &r)
        return *this;

    for (int i = 0; i < this->capacity; i++) {
		if (this->world[i] != NULL) {
			delete this->world[i];
			this->world[i] = NULL;
		}
	}
    delete world;

	this->world = new AMateria*[r.capacity];
    this->len = r.len;
    this->capacity = r.capacity;

    for (int i = 0; i < r.capacity; i++) {
        if (r.world[i] != NULL)
            this->world[i] = r.world[i]->clone();
        else
            this->world[i] = NULL;
    }
    return *this;
}

void World::setMateria(AMateria *m) {
	if (m == NULL)
		return;
    if (this->len >= this->capacity) {
        this->capacity *= 2;
        AMateria **newWorld = new AMateria*[this->capacity];
        for (int i = 0; i < this->capacity; i++)
        {
            if (i < this->len)
                newWorld[i] = this->world[i];
            else
                newWorld[i] = NULL;
        }
        delete this->world;
        this->len++;
        newWorld[this->len - 1] = m;
        this->world = newWorld;
        return;
    } else {
        for (int i = 0; i < this->capacity; i++) {
            if (this->world[i] == NULL) {
                this->world[i] = m;
                this->len++;
                return;
            }
        }
    }
}

AMateria *World::getMateria(int idx) {
    if (idx < 0 || idx > this->capacity)
		return NULL;
	return this->world[idx];
}

void World::validateMateria(int idx) {
	if (idx < 0 || idx > this->capacity)
		return;
	if (this->world[idx] != NULL && this->world[idx]->getStatusEquip() == EQUIP) {
		this->world[idx] = NULL;
		return;
	}
}