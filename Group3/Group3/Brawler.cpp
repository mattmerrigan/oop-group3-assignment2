#include "stdafx.h"
#include "Brawler.h"


Brawler::Brawler(std::string characterName, float health, float weightLimit, int food, CharacterState state, int punchDamage, int strength) : GameCharacter(characterName, health, weightLimit, food, state)
{
    punchDamage_ = punchDamage;
    strength_ = strength;
}


Brawler::~Brawler()
{
}

void Brawler::SetPunchDamage(int punchDamage) {
    punchDamage_ = punchDamage;
}

int Brawler::GetPunchDamage() const {
    return punchDamage_;
}

void Brawler::SetStrength(int strength) {
    strength_ = strength;
}

int Brawler::GetStrength() const {
    return strength_;
}