#pragma once
class Agent;

//Abstract class for all behaviors.
class Behavior
{
public:
	virtual void update(Agent* owner, float deltaTime) = 0;
	virtual void draw(Agent* agent) {};
	bool getEnabled() { return m_enabled; }
	bool setEnabled(bool enabled) (m_enabled = enabled; )

private:
	bool m_behavior = true;
};