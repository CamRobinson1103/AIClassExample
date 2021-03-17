#pragma once
#include "Actor.h"
#include <vector>

class Behavior;

class Agent : public Actor
{
public:
    Agent();
    /// <param name="x">Position on the x axis</param>
    /// <param name="y">Position on the y axis</param>
    /// <param name="icon">The symbol that will appear when drawn</param>
    /// <param name="maxForce">The largest the magintude of the force vector can be</param>
    Agent(float x, float y, float collisionRadius, char icon, float maxSpeed, float maxForce);

    /// <param name="x">Position on the x axis</param>
    /// <param name="y">Position on the y axis</param>
    /// <param name="icon">The symbol that will appear when drawn</param>
    /// <param name="maxForce">The largest the magintude of the force vector can be</param>
    Agent(float x, float y, float collisionRadius, Sprite* sprite, float maxSpeed, float maxForce);

    /// <param name="x">Position on the x axis</param>
    /// <param name="y">Position on the y axis</param>
    /// <param name="icon">The symbol that will appear when drawn</param>
    /// <param name="maxForce">The largest the magintude of the force vector can be</param>
    Agent(float x, float y, float collisionRadius, const char* spriteFilePath, float maxSpeed, float maxForce);

    void update(float deltatime) override;

    float getMaxForce() { return m_maxForce; }
    void setMaxForce(float maxForce) { m_maxForce = maxForce; }

    //Add the given force to the total force that is being applied to the agent.
    void addForce(MathLibrary::Vector2 force);
    void addBehavior(Behavior* behavior);

    ///<summary>
    /// Returns the first behaviour that matches the given type.
    /// If no behaviour matches the type, returns null.
    ///</summary>
    template<typename BehaviorType>
    BehaviorType* getBehavior();


private:
    MathLibrary::Vector2 m_force;
    float m_maxForce;
    std::vector<Behavior*> m_behaviors;
};

template<typename BehaviorType>
inline BehaviorType* Agent::getBehavior()
{
    //Iterate through the list of behaviors
    for (int i = 0; i < m_behaviors.size(); i++)
    {
        //Attempt to cast behaviour at the current index as the given type
        BehaviorType* behavior = dynamic_cast<BehaviorType*>(m_behaviors[i]);

        //If the cast is successful return the behaviour that was found
        if (behavior)
            return behavior;
    }

    //If no behaviours were found to match the type, return nullptr
    return nullptr;
}

