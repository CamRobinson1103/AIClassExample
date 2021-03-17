#pragma once
#include "ABDecision.h"
class EvasionDecision : public ABDecision
{
public:
	using ABDecision::ABDecision;

	virtual void makeDecision(Agent* agent, float deltaTime) override;
};

