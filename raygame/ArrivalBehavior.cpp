#include "ArrivalBehavior.h"
#include "Agent.h"

ArrivalBehavior::ArrivalBehavior()
{
	m_target = nullptr;
	setForceScale(1);
}

ArrivalBehavior::ArrivalBehavior(Actor* target, float seekForce)
{
	m_target = target;
	setForceScale(seekForce);
}

void ArrivalBehavior::update(Agent* agent, float deltaTime)
{
	// Check if agent is null
	if (!agent)
		return;

	// Calculate new force and add it to agent
	agent->addForce(calculateForce(agent));
}

MathLibrary::Vector2 ArrivalBehavior::calculateForce(Agent* agent)
{
	// Find the direction to move
	MathLibrary::Vector2 direction = (m_target->getWorldPosition() - agent->getWorldPosition()).getNormalized();

	// Get distance to target
	float distanceToTarget = (m_target->getWorldPosition() - agent->getWorldPosition()).getMagnitude();

	// Scale the direction vector by seekForce
	MathLibrary::Vector2 desiredVelocity;
	float radius = 5;
	if (distanceToTarget > radius)
		desiredVelocity = direction * getForceScale();
	else
		desiredVelocity = direction * getForceScale() * (distanceToTarget / radius);

	// Subtract current velocity from desired velocity to find steering force
	MathLibrary::Vector2 steeringForce = desiredVelocity - agent->getVelocity();


	return steeringForce;
}
