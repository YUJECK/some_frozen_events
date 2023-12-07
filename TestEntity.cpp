//
// Created by destructive_crab on 12/6/23.
//

#include "apMoon/Entity.h"
#include "TestEntity.h"
#include "TestComponent.h"
#include<iostream>

void TestEntity::start_entity()
{
    add_component(new TestComponent);

}

void TestEntity::destroy_entity()
{

}

void TestEntity::update_entity()
{

}
