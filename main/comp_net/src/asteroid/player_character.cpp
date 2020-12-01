/*
 MIT License

 Copyright (c) 2020 SAE Institute Switzerland AG

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */
#include "asteroid/player_character.h"
#include "asteroid/game_manager.h"

namespace neko::asteroid
{

PlayerCharacterManager::PlayerCharacterManager(EntityManager& entityManager, PhysicsManager& physicsManager, GameManager& gameManager) :
    ComponentManager(entityManager),
    physicsManager_(physicsManager),
    gameManager_(gameManager)
    
{

}

void PlayerCharacterManager::FixedUpdate(seconds dt)
{
    for(Entity playerEntity = 0; playerEntity < entityManager_.get().GetEntitiesSize(); playerEntity++)
    {
        if(!entityManager_.get().HasComponent(playerEntity, 
            EntityMask(ComponentType::PLAYER_CHARACTER)))
            continue;
        auto playerBody = physicsManager_.get().GetBody(playerEntity);
        auto playerCharacter = GetComponent(playerEntity);
        const auto input = playerCharacter.input;

        const bool right = input & PlayerInput::RIGHT;
        const bool left = input & PlayerInput::LEFT;
        const bool up = input & PlayerInput::UP;
        const bool down = input & PlayerInput::DOWN;

        Vec2f dir;

        if(playerBody.position.Magnitude() >= 8.0f)
        {
            playerCharacter.alivePlayer = false;
            SetComponent(playerEntity, playerCharacter);
        }
           	
        if(!playerCharacter.isCharging && !playerCharacter.isPushed)
		{
            dir = Vec2f::up;
        	
            const auto angularVelocity = ((left ? 2.0f : 0.0f) + (right ? -2.0f : 0.0f)) * playerAngularSpeed;

            playerBody.angularVelocity = angularVelocity;
        	
            dir = dir.Rotate(-(playerBody.rotation + playerBody.angularVelocity * dt.count()));
        	
            const auto velocity = ((down ? -2.0f : 0.0f) + (up ? 2.0f : 0.0f)) * dir;

            playerBody.velocity = velocity;

            physicsManager_.get().SetBody(playerEntity, playerBody);
        }
        

        if(playerCharacter.isPushed && playerCharacter.pushDuration < chargeDurationPeriod)
        {
            playerCharacter.pushDuration += dt.count();
            SetComponent(playerEntity, playerCharacter);
        }

        if(playerCharacter.pushDuration >= chargeDurationPeriod)
        {
            playerCharacter.isPushed = false;
            playerCharacter.pushDuration = 0.0f;
            SetComponent(playerEntity, playerCharacter);
        }
    	
        //Check if cannot charge, and increase charge cooldown
        if(playerCharacter.chargeCooldown < chargeCooldownPeriod)
        {
            playerCharacter.chargeCooldown += dt.count();
            SetComponent(playerEntity, playerCharacter);
            
        }

    	if(playerCharacter.isCharging && playerCharacter.chargeDuration < chargeDurationPeriod)
    	{
            playerCharacter.chargeDuration += dt.count();
            SetComponent(playerEntity, playerCharacter);
    	}

    	if(playerCharacter.isPreparingToCharge && playerCharacter.chargePreparation < chargePreparationPeriod)
    	{
            playerCharacter.chargePreparation += dt.count();
            SetComponent(playerEntity, playerCharacter);
    	}

    	

        if (playerCharacter.chargeDuration >= chargeDurationPeriod)
        {
            playerCharacter.chargeDuration = 0.0f;
            playerCharacter.chargeCooldown = 0.0f;
            playerCharacter.isCharging = false;

            SetComponent(playerEntity, playerCharacter);
        }

        if (playerCharacter.chargePreparation >= chargePreparationPeriod)
        {
            playerCharacter.isCharging = true;
            playerCharacter.isPreparingToCharge = false;
            playerCharacter.chargePreparation = 0.0f;

            playerBody.angularVelocity = degree_t(0);
            playerBody.velocity = 8.0f * dir;

            SetComponent(playerEntity, playerCharacter);
			physicsManager_.get().SetBody(playerEntity, playerBody);
        }
    	
        //Start the charge by the brief preparation leading to it
        if (playerCharacter.chargeCooldown >= chargeCooldownPeriod)
        {
            if((input & PlayerInput::SHOOT) && !playerCharacter.isCharging && !playerCharacter.isPreparingToCharge)
            {               
                playerCharacter.isPreparingToCharge = true;
                	
                playerBody.velocity = -2.0f * dir;
                playerBody.angularVelocity = degree_t(0);

                SetComponent(playerEntity, playerCharacter);
                physicsManager_.get().SetBody(playerEntity, playerBody);            	               
            }               
        }
    }
}

PlayerCharacterManager& PlayerCharacterManager::operator=(const PlayerCharacterManager& playerCharacterManager)
{
    gameManager_ = playerCharacterManager.gameManager_;
    components_ = playerCharacterManager.components_;
    //We do NOT copy the physics manager
    return *this;
}
}