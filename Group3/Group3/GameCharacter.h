/*
* GameCharacter.h
*
* Version information v0.1
* Authors: <Insert group member names and IDs> of student(s) who write each class
* Date: 24/11/2017
* Description: header file for GameCharacter class
* Copyright notice
*/


#pragma once
#include <string>
enum CharacterState { Idle, Running, Sleeping, Walking, Defending, Dead };
class GameCharacter
{
private:
    std::string characterName_;
    float health_;
    float weightLimit_;
    int equippedWeapon_;
    int equippedArmour_;
    int food_;
    CharacterState state_;
public:
    GameCharacter(std::string characterName, float health, float weightLimit, int food, CharacterState state);
    ~GameCharacter();

    void SetName(std::string characterName);
    std::string GetName() const;
    void SetHealth(float health);
    float GetHealth() const;
    void SetWeightLimit(float health);
    float GetWeightLimit() const;
    void SetFood(int food);
    int GetFood() const;
    void SetState(CharacterState state);
    CharacterState GetState() const;
    void Eat();
    void Walk();
    void Run();
    virtual void Sleep()=0;

};
