#include "SceneManager.h"

Scene* SceneManager::m_ActiveScene = nullptr;
Scene* SceneManager::m_QueuedScene = nullptr;

void SceneManager::Update(double deltaTime)
{
	if (m_ActiveScene)
	{
		m_ActiveScene->Update(deltaTime);
	}
}

void SceneManager::FixedUpdate()
{
	if (m_ActiveScene)
	{
		m_ActiveScene->FixedUpdate();
	}
}

void SceneManager::Render()
{
	if (m_ActiveScene)
	{
		m_ActiveScene->Render();
	}
}

void SceneManager::QueueSwitchScene(Scene* scene)
{
	if (scene)
	{
		m_QueuedScene = scene;
	}
}

void SceneManager::SwitchSceneNow()
{
	if (m_ActiveScene)
	{
		m_ActiveScene->Destroy();
		delete m_ActiveScene;
	}

	if (!m_QueuedScene)
	{
		return;
	}

	m_ActiveScene = m_QueuedScene;
	if (m_ActiveScene)
	{
		m_ActiveScene->Init();
	}

	delete m_QueuedScene;
	m_QueuedScene = nullptr;
}

Scene* SceneManager::GetActiveScene()
{
	return m_ActiveScene;
}

void SceneManager::Destroy()
{
	if (m_ActiveScene)
	{
		m_ActiveScene->Destroy();
		delete m_ActiveScene;
		m_ActiveScene = nullptr;
	}
}
