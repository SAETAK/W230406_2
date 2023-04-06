#include <iostream>
#include "State.h"
#include "Transition.h"
#include <vector> //이게 젤 좋음
#include <list>
#include <map> //이것도 엄청 쓰임
#include <algorithm>

using namespace std;

int main()
{
	vector<FState*> States;

	States.push_back(new FState(1, "배회"));
	States.push_back(new FState(2, "추격"));
	States.push_back(new FState(3, "공격"));
	States.push_back(new FState(4, "죽음"));
	States.push_back(new FState(5, "필살기"));

	for (int i = 0; i < States.size(); ++i)
	{
		cout << States[i]->Name << endl;
	}

	for (auto iter = States.rbegin(); iter != States.rend(); ++iter)
	{
		cout << (*iter)->Name << endl;
	}

	list<FTransition*> Transitions;

	Transitions.push_back(new FTransition(1, "적 발견", 2));
	Transitions.push_back(new FTransition(2, "적 놓침", 2));
	Transitions.push_back(new FTransition(2, "사정거리 접근", 3));
	Transitions.push_back(new FTransition(3, "사정거리 이탈", 2));
	Transitions.push_back(new FTransition(3, "HP 없음", 4));

	for (auto iter = Transitions.rbegin(); iter != Transitions.rend(); ++iter) //rbegin, rend -> reverse
	{
		cout << (*iter)->Condition << endl;
	}

	map<int, FTransition*> TransitionsMap;

	TransitionsMap[1] = new FTransition(1, "적 발견", 2);
	TransitionsMap[2] = new FTransition(2, "적 놓침", 2);
	TransitionsMap[3] = new FTransition(2, "사정거리 접근", 3);
	TransitionsMap[4] = new FTransition(3, "사정거리 이탈", 2);
	TransitionsMap[5] = new FTransition(3, "HP 없음", 4);

	for (auto iter : TransitionsMap)
	{
		cout << iter.first << endl;
		cout << iter.second->Condition << endl;
	}
	
	int MonsterCurrenState = 3;
	std::string MonsterCondition = "적 발견";
	int MonsterNextState;

	for (auto Value : Transitions)
	{
		if (Value->CurrentState == MonsterCurrenState &&
			Value->Condition == MonsterCondition)
		{
			MonsterNextState = Value->NextState;
		}
	}

	cout << "현재 몬스터의 상태는 " << States[MonsterCurrenState - 1]->Name;
	cout << "이고 조건은 " << MonsterCondition << "을 해서 다음에는 ";
	cout << "몬스터가 다음에는 " << States[MonsterNextState - 1]->Name;
	cout << " 행동을 합니다." << endl;
	
	return 0;
}