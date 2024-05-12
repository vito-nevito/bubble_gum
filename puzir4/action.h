#ifndef ACTION_H
#define ACTION_H

#include<vector>
#include "Room.h"
#include "Puzir.h"

void calcCord(double deltaT, Room room, Puzir& p);

void calcVel(double deltaT, Puzir& p);

void calcAccel(std::vector<Puzir> array, Puzir& p, Room room);

#endif
