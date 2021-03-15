#pragma once
#include "ABDecision.h"
class PursueDecision :
	public ABDecision
{
	using ABDecision::ABDecision;
	void makeDecision(Agent* agent, float deltaTime) override;
};

