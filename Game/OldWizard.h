//
// Created by wasil on 12.12.2023.
//

#ifndef ROGUELIKE_OLDWIZARD_H
#define ROGUELIKE_OLDWIZARD_H


#include "Entity.h"

class OldWizard : public Entity{
public:
    OldWizard() : Entity(0,0,'W',"wizzo",100,50,12,100,0,1,40,1,{}) {}
};


#endif //ROGUELIKE_OLDWIZARD_H
