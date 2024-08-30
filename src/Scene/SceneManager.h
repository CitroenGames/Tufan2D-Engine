#pragma once

#include "Scene.h"

class SceneManager
{
	friend class Application;
public:
	static void Update(double deltaTime);
	static void FixedUpdate();
	static void Render();
	static void QueueSwitchScene(Scene* scene);
	static Scene* GetActiveScene();
	static void Destroy();

private:
	static void SwitchSceneNow();
	static Scene* m_ActiveScene;
	static Scene* m_QueuedScene;
};