#pragma once
/*
* Brawler.h
*
* Version information v0.1
* Authors: <Insert group member names and IDs> of student(s) who write each class
* Date: 24/11/2017
* Description: header file for GameCharacter class
* Copyright notice
*/
#pragma once
#include "GameCharacter.h"
class Brawler :
    public GameCharacter
{
private:
    int punchDamage_;
    int strength_;
public:
    Brawler(std::string characterName, float health, float weightLimit, int food, CharacterState state, int punchDamage, int strength);
    ~Brawler();

    void SetPunchDamage(int punchDamage);
    int GetPunchDamage() const;

    void SetStrength(int strength);
    int GetStrength() const;
};