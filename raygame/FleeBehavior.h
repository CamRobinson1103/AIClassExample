#pragma once
#include "SteeringBehavior.h"
class Actor;
class FleeBehavior : public SteeringBehavior
{
public:
	FleeBehavior();
	FleeBehavior(Actor* target, float seekForce = 1);

	void update(Agent* agent, float deltaTime) override;
	MathLibrary::Vector2 calculateForce(Agent* agent) override;

	Actor* getTarget() { return m_target; }
	void setTarget(Actor* target) { m_target = target; }

private:
	// Agent the behaviour is seeking
	Actor* m_target;
};

