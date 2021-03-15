#pragma once
#include "Decision.h"

///<summary>
/// A decision that has two children attached to it
///</summary>
class ABDecision :
	public Decision
{
public:
	ABDecision(Decision* leftChild = nullptr, Decision* rightChild = nullptr);

	///<summary>
	/// A decision that has two children attached to it
	///</summary>
	virtual void makeDecision(Agent* agent, float deltaTime) override;

	virtual bool checkCondition(Agent* agent, float deltaTime) { return false; }

private:
	Decision* m_leftChild;
	Decision* m_rightChild;
};

