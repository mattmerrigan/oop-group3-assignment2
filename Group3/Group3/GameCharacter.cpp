/*
* GameCharacter
*
* Version information v0.1
* Authors: <Insert group member names and IDs> of student(s) who write each class
* Date: 24/11/2017
* Description:
* Copyright notice
*/

#include "stdafx.h"
#include "GameCharacter.h"


GameCharacter::GameCharacter(std::string characterName, float health, float weightLimit, int food, CharacterState state)
{
    characterName_ = characterName;
    equippedWeapon_ = -1;
    equippedArmour_ = -1;
    health_ = health;
    weightLimit_ = weightLimit;
    food_ = food;
    state_ = state;
}

GameCharacter::~GameCharacter()
{
}

void GameCharacter::SetName(std::string characterName) {
    characterName_ = characterName;
}

std::string GameCharacter::GetName() const {
    return characterName_;
}

void GameCharacter::SetHealth(float health) {
    health_ = health;
}
float GameCharacter::GetHealth() const {
    return health_;
}

void GameCharacter::SetWeightLimit(float weightLimit) {
    weightLimit_ = weightLimit;
}
float GameCharacter::GetWeightLimit() const {
    return weightLimit_;
}

void GameCharacter::SetFood(int food) {
    food_ = food;
}
int GameCharacter::GetFood() const {
    return food_;
}

void GameCharacter::SetState(CharacterState state) {
    state_ = state;
}

CharacterState GameCharacter::GetState() const {
    return state_;
}

void GameCharacter::Eat() {
    int unitsConsumed = (food_ * 20) / 100;

    health_ += (float) 0.25 * unitsConsumed;
    food_ -= unitsConsumed;

    if (health_ > 100.0f) {
        health_ = 100.0f;
    }
}

void GameCharacter::Run() {
    state_ = CharacterState::Running;
}

void GameCharacter::Walk() {
    state_ = CharacterState::Walking;
}