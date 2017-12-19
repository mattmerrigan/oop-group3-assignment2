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

void Brawler::Sleep() {

}

void Brawler::Brawl(GameCharacter &character) {

    float currentHealth = character.GetHealth();
    float healthLoss = 0.0f;
    switch (character.GetState()) {
    case CharacterState::Defending:
        healthLoss = 0.05f * currentHealth;
        break;
    case CharacterState::Sleeping:
        healthLoss = 0.5f * currentHealth;
        break;
    case CharacterState::Running: //Fall Through
    case CharacterState::Walking: //Fall Through
    case CharacterState::Idle:
        healthLoss = 0.1f * currentHealth;
        break;
    case CharacterState::Dead: //Fall Through 
    default:
        break;
    }
    
    

    float newHealth = currentHealth - healthLoss;
    character.SetHealth(newHealth);
}