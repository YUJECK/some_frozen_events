//
// Created by destructive_crab on 12/6/23.
//

#include <iostream>
#include "TestComponent.h"

void TestComponent::update_component() {

}

void TestComponent::start_component()
{
    std::cout << "Start" << std::endl;
}

void TestComponent::destroy_component() {
    std::cout << "Destroy";
}
