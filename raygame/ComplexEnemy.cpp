#include "ComplexEnemy.h"
#include "WanderBehavior.h"
#include "PursueBehavior.h"
#include "EvadeBehavior.h"
#include "Player.h"

void ComplexEnemy::start()
{
	Enemy::start();

	//Initializa behaviors
	m_wanderBavavior = getBehavior<WanderBehavior>();
	m_pursueBavavior = getBehavior<PursueBehavior>();
	m_evadeBavavior = getBehavior<EvadeBehavior>();


	//Set target to target given from base class
	setTarget(Enemy::getTarget());

}

void ComplexEnemy::setTarget(Actor* target)
{
	Enemy::setTarget(target);
	m_pursueBehavior->setTarget(target);
	m_evadeBehavior->setTarget(target);
}

void ComplexEnemy::onCollision(Actor* other)
{
	Enemy::onCollision(other);


	Player* player = dynamic_cast<Player*>(other);

	if (player)
	{
		player->takeDamage(getDamage());
		if (player->getHealth() <= 0)
		{
			setTarget(nullptr);
		}
	}
}
