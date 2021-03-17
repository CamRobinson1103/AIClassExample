#pragma once
#include "SteeringBehavior.h"
class WanderBehavior : public SteeringBehavior
{
public:
	WanderBehavior();
	WanderBehavior(float circleDistance, float circleRadius, float seekForce);

	void update(Agent* agent, float deltaTime) override;
	MathLibrary::Vector2 calculateForce(Agent* agent) override;

	MathLibrary::Vector2 getPointOnCircle(MathLibrary::Vector2 position, int radius);

	float getCircleDistance() { return m_circleDistance; }
	void setCircleDistance(float value) { m_circleDistance = value; }
	float getCircleRadius() { return m_circleRadius; }
	void setCircleRadius(float value) { m_circleRadius = value; }

private:
	float m_circleDistance;
	float m_circleRadius;
};

