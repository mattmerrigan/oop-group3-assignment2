#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Assignment_UnitTests
// See https://martinfowler.com/bliki/GivenWhenThen.html for GIVEN WHEN THEN
// Setup (GIVEN), Exercise (WHEN), Verify (THEN) and Teardown
{
    TEST_CLASS(CharacterManagement)
    {
    public:

        TEST_METHOD(TestBrawlerConstructor)
        {
            //GIVEN I construct a brawler called Jim
            std::string expectedName{ "Jim" };
            float expectedHealth = 100;
            float expectedWeightLimit = 120;
            int expectedFood = 50;
            CharacterState expectedState = CharacterState::Idle;
            int expectedPunchDamage = 60;
            int expectedStrength = 80;
            Brawler brawler{ "Jim", 100, 120, 50, CharacterState::Idle, 60, 80 };

            //WHEN I get the brawlers attributes
            std::string characterName = brawler.GetName();
            float health = brawler.GetHealth();
            float weightLimit = brawler.GetWeightLimit();
            int food = brawler.GetFood();
            //CharacterState state = brawler.GetState();
            int punchDamage = brawler.GetPunchDamage();
            int strength = brawler.GetStrength();

            //THEN they are equal to the values initialized in the constructor 
            Assert::AreEqual(expectedName, characterName);
            Assert::AreEqual(expectedHealth, health);
            Assert::AreEqual(expectedWeightLimit, weightLimit);
            Assert::AreEqual(expectedFood, food);
            //Assert::AreEqual(expectedState, state);
            Assert::AreEqual(expectedPunchDamage, punchDamage);
            Assert::AreEqual(expectedStrength, strength);
        }
        /*
        TEST_METHOD(TestEatConsumesFood)
        {
        //Tests that food gets consumed by eat function
        //Arrange the data
        int expectedFood{ 16 }, actualFood;
        Brawler brawler{ "Jim", 100, 120, 20, CharacterState::Idle, 60, 80 };

        //Act
        brawler.Eat();
        actualFood = brawler.GetFood();

        //Assert
        Assert::AreEqual(expectedFood, actualFood);
        }

        TEST_METHOD(TestEatIncreasesHealth)
        {

        //	Consumes 20% of the available food. Each unit (1) of food consumed will add 0.25 units of health to the character.
        //Tests that health increases correctly by eat function
        //Arrange the data
        float expectedHealth{ 52.5f }, actualHealth; //(health should not exceed 100)
        Brawler brawler{ "Jim", 50, 120, 50, CharacterState::Idle, 60, 80 };

        //Act
        brawler.Eat();
        actualHealth = brawler.GetHealth();

        //Assert
        Assert::AreEqual(expectedHealth, actualHealth);
        }

        TEST_METHOD(TestHealthCapped)
        {
        //Tests that health does not exceed 100 by eat function
        //Arrange the data
        float expectedHealth{ 100.0f }, actualHealth; //(health should not exceed 100)
        Brawler brawler{ "Jim", 100, 120, 50, CharacterState::Idle, 60, 80 };

        //Act
        brawler.Eat();
        actualHealth = brawler.GetHealth();

        //Assert
        Assert::AreEqual(expectedHealth, actualHealth);
        }

        };

        }


        namespace Conflict_UnitTests
        {
        TEST_CLASS(Conflict)
        {
        public:
        TEST_METHOD(Defend1)
        {
        //Test that the character enters defending state
        //Arrange the data
        int expectedState{ 4 }, actualState;
        Brawler brawler{ "Jim", 100, 120, 50, CharacterState::Idle, 60, 80 };

        //Act
        brawler.Defend(1); //invalid index! no armour in vector
        actualState = brawler.GetState();

        //Assert
        Assert::AreEqual(expectedState, actualState);
        }

        TEST_METHOD(Defend2)
        {
        //Test that the character selected armour remains -1
        //Arrange the data
        int expectedIndex{ -1 }, actualIndex;
        Brawler brawler{ "Jim", 100, 120, 50, CharacterState::Idle, 60, 80 };

        //Act
        brawler.Defend(0); //invalid index! no armour in vector
        actualIndex = brawler.GetEqippedArmour();

        //Assert
        Assert::AreEqual(expectedIndex, actualIndex);
        }
        };
        }

        namespace Inventory_UnitTests
        {
        TEST_CLASS(InventoryManagement)
        {
        public:

        TEST_METHOD(TestAddItemWeight)
        {
        //Test that adding items above weight limit fails
        //Arrange the data
        bool addItemResult;
        //No point initialising vectors as character should start off with no items.
        Brawler brawler{ "Jim", 100, 10, 0, CharacterState::Idle, 60, 80 };
        Weapon spear{ "spear", 15, 25, 100, 6.0f };
        Armour glove{ "Leather glove", 3, 0.25f, 1, 100, ArmourType::Leather };
        Armour chainMail{ "Chain Mail", 45, 85, 200, 100, ArmourType::Steel };


        //Act
        addItemResult = brawler.PickUpWeapon(spear);
        addItemResult = brawler.PickUpArmour(glove);
        addItemResult = brawler.PickUpArmour(chainMail);

        //Assert - add weapon should be false as the weight exceeds the limit
        Assert::IsFalse(addItemResult);
        }

        TEST_METHOD(TestAddWeaponWeight)
        {
        //Test that adding items above weight limit fails
        //Arrange the data
        bool addWeaponResult;
        //No point initialising vectors as character should start off with no items.
        Brawler brawler{ "Jim", 100, 10, 0, CharacterState::Idle, 60, 80 };
        Weapon spear{ "spear", 15, 25, 100, 6.0f };
        Weapon bow{ "bow", 15, 25, 100, 6.0f };


        //Act
        addWeaponResult = brawler.PickUpWeapon(spear);
        addWeaponResult = brawler.PickUpWeapon(bow);

        //Assert - add weapon should be false as the weight exceeds
        Assert::IsFalse(addWeaponResult);
        }

        TEST_METHOD(TestAddArmourWeight)
        {
        //Test that adding items above weight limit fails
        //Arrange the data
        bool addArmourResult;
        //No point initialising vectors as character should start off with no items.
        Brawler brawler{ "Jim", 100, 40, 0, CharacterState::Idle, 60, 80 };
        Armour shield{ "Shield", 40, 40, 50, 100, ArmourType::Leather };
        Armour hat{ "Tinfoil Hat", 2, 0.5, 1, 100, ArmourType::Cardboard };

        //Act
        addArmourResult = brawler.PickUpArmour(shield);
        addArmourResult = brawler.PickUpArmour(hat);

        //Assert - add weapon should be false as the weight exceeds
        Assert::IsFalse(addArmourResult);
        }

        TEST_METHOD(TestAddWeapons)
        {
        //Arrange the data
        Brawler brawler{ "Jim", 100, 120, 0, CharacterState::Idle, 60, 80 };
        Weapon spear{ "spear", 15, 25, 100, 6.0f };
        Weapon bow{ "bow", 15, 25, 100, 3.0f };
        Weapon spear2{ "Lance of Longinus", 10, 2, 70, 2.0f };
        Weapon arrow{ "arrow", 15, 25, 100, 6.0f };

        brawler.PickUpWeapon(spear);
        brawler.PickUpWeapon(bow);
        brawler.PickUpWeapon(spear2);
        brawler.PickUpWeapon(arrow);
        brawler.PickUpWeapon(arrow);
        brawler.PickUpWeapon(arrow);
        brawler.PickUpWeapon(arrow);

        std::string expectedWeaponName{ "Lance of Longinus" };

        //Act
        Weapon tempWeapon = brawler.GetWeapon(2);
        std::string weaponName = tempWeapon.GetItemName();

        //Assert
        Assert::AreEqual(expectedWeaponName, weaponName);
        }

        TEST_METHOD(TestDropWeapon)
        {
        //Test Drop weapon
        //Arrange the data
        std::string expectedWeaponName{ "spear" };
        Brawler brawler{ "Jim", 100, 120, 0, CharacterState::Idle, 60, 80 };
        Weapon spear1{ "spear", 15, 25, 100, 6.0f };
        Weapon bow{ "bow", 15, 25, 100, 3.0f };
        Weapon spear2{ "spear", 10, 2, 70, 2.0f };

        brawler.PickUpWeapon(spear1);
        brawler.PickUpWeapon(bow);
        brawler.PickUpWeapon(spear2);

        //Act

        brawler.DropItem(spear2); //Weapon spear2 should be removed not spear2 - same name different attributes!

        Weapon tempWeapon = brawler.GetWeapon(0);
        std::string actualWeaponName = tempWeapon.GetItemName();

        //Assert
        Assert::AreEqual(expectedWeaponName, actualWeaponName);
        }

        TEST_METHOD(TestDropArmour)
        {
        //Test Drop weapon
        //Arrange the data
        std::string expectedArmourName{ "Cardboard suit of armour" };
        Brawler brawler{ "Jim", 100, 120, 0, CharacterState::Idle, 60, 80 };
        Armour shield{ "Shield", 40, 40, 50, 100, ArmourType::Leather };
        Armour hat{ "Tinfoil Hat", 2, 0.5f, 1, 100, ArmourType::Cardboard };
        Armour glove1{ "Leather glove", 1, 0.23f, 1, 100, ArmourType::Leather };
        Armour suit{ "Cardboard suit of armour", 10, 2.0f, 15, 100, ArmourType::Cardboard };
        Armour glove2{ "Leather glove", 1, 0.2f, 1, 75, ArmourType::Leather };

        brawler.PickUpArmour(shield);
        brawler.PickUpArmour(hat);
        brawler.PickUpArmour(glove1);
        brawler.PickUpArmour(suit);
        brawler.PickUpArmour(glove2);

        //Act
        brawler.DropItem(glove1); //Weapon spear2 should be removed not spear2 - same name different attributes!

        Armour tempArmour = brawler.GetArmour(2);
        std::string actualArmourName = tempArmour.GetItemName();

        //Assert
        Assert::AreEqual(expectedArmourName, actualArmourName);

        }
        */

    };
}