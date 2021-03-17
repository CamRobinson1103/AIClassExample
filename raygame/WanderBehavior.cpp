#include "WanderBehavior.h"
#include "Agent.h"
#include "raylib.h"

WanderBehavior::WanderBehavior()
{
	m_circleDistance = 1;
	m_circleRadius = 1;
	setForceScale(1);
}

WanderBehavior::WanderBehavior(float circleDistance, float circleRadius, float seekForce)
{
	m_circleDistance = circleDistance;
	m_circleRadius = circleRadius;
	setForceScale(seekForce);
}

void WanderBehavior::update(Agent* agent, float deltaTime)
{
	// Check if agent is null
	if (!agent)
		return;

	// Calculate new force and add it to agent
	agent->addForce(calculateForce(agent));
}

MathLibrary::Vector2 WanderBehavior::calculateForce(Agent* agent)
{
	// Get a point on a circle around m_circleDistance with a radius of m_circleRadius
	MathLibrary::Vector2 circlePosition = getPointOnCircle(agent->getWorldPosition() + (agent->getForward() * getCircleDistance()), getCircleRadius());

	// Find the direction to move
	MathLibrary::Vector2 direction = (circlePosition - agent->getWorldPosition()).getNormalized();

	// Scale the direction vector by seekForce
	MathLibrary::Vector2 desiredVelocity = direction * getForceScale();

	// Subtract current velocity from desired velocity to find steering force
	MathLibrary::Vector2 steeringForce = desiredVelocity - agent->getVelocity();

	return steeringForce;
}

MathLibrary::Vector2 WanderBehavior::getPointOnCircle(MathLibrary::Vector2 position, int radius)
{
	// Get random values for x and y
	float x = (rand() % (radius * 2)) - radius;
	float y = (rand() % (radius * 2)) - radius;

	// Create a new vector at origin normalized to the radius
	MathLibrary::Vector2 point = MathLibrary::Vector2(x, y).getNormalized() * radius;

	// Move point to position
	return point + position;
}