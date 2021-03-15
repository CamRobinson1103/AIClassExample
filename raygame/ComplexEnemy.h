#pragma once
#include "Enemy.h"

class WanderBehavior;
class PursueBehavior;
class EvadeBehavior;

class ComplexEnemy :
	public Enemy
{
public:
	using Enemy::Enemy;
	void start() override;
	void setTarget(Actor* target) override;
	void onCollision(Actor* other) override;
	WanderBehavior* getWander() { return m_wanderBehavior;  }
	PursueBehavior* getPursue() { return m_pursueBehavior; }
	EvadeBehavior* getEvade() { return m_evadeBehavior; }

	bool checkTargetInSight(float angle = 2);
	bool checkTargetInRange(float range);

private:
	WanderBehavior* m_wanderBahavior;
	PursueBehavior* m_pursueBehavior;
	EvadeBehavior* m_evadeBehavior;
};
	

