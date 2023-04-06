#include "Transition.h"

FTransition::FTransition(int NewCurrentState, std::string NewCondition, int NewNextState)
{
	CurrentState = NewCurrentState;
	Condition = NewCondition;
	NextState = NewNextState;
}
