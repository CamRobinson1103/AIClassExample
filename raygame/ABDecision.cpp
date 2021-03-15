
#include "ABDecision.h"

ABDecision::ABDecision(Decision* leftChild, Decision* rightChild)
{
	m_leftChild = leftChild;
	m_rightChild = rightChild;

}

void ABDecision::makeDecision(Agent* agent, float deltaTime)
{
	//Call in checkCondition function for this decision
	if (checkCondition(agent, deltaTime))
	{
		//If the function returns true and the left child isn't null,
		//move to left node
		if (m_leftChild)
		{
			m_leftChild->makeDecision(agent, deltaTime);
		}
	}
	else
	{
		//If the function returns false and the left child isn't null,
		//move to the left node
		if (m_rightChild)
		{
			m_rightChild->makeDecision(agent, deltaTime);
		}
	}
}
