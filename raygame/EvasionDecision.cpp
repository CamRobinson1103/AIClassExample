#include "EvasionDecision.h"
#include "ComplexEnemy.h"
#include "WanderBehavior.h"
#include "PursueBehavior.h"
#include "EvadeBehavior.h"

void EvasionDecision::makeDecision(Agent* agent, float deltaTime)
{
	ComplexEnemy* enemy = dynamic_cast<ComplexEnemy*>(agent);

	if (!enemy)
		return;

	enemy->getPursue()->setEnabled(false);
	enemy->getWander()->setEnabled(false);
	enemy->getEvade()->setEnabled(true);
}
