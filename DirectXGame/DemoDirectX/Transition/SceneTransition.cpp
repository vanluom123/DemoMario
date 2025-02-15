#include "SceneTransition.h"

SceneTransition* SceneTransition::instance = nullptr;

SceneTransition::SceneTransition()
{
}

SceneTransition::~SceneTransition()
{
}

SceneTransition* SceneTransition::GetInstance()
{
	if (SceneTransition::instance == nullptr)
	{
		SceneTransition::instance = new SceneTransition();
		SceneTransition::instance->transition = nullptr;
	}

	return SceneTransition::instance;
}

void SceneTransition::Update(float dt)
{
	if (this->instance->transition != nullptr)
	{
		this->instance->transition->Update(dt);
	}
}

bool SceneTransition::IsFinishTransition()
{
	bool isFinishTransition = false;

	if (this->instance->transition != nullptr)
		isFinishTransition = this->instance->transition->IsFinish();

	return isFinishTransition;
}

void SceneTransition::SetTransition(Scene* source, Scene* dest, TransitionEffect* transition)
{
	this->instance->transition = transition;
	this->instance->transition->SetScenes(source, dest);
}

