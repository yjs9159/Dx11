#include "yjsScene.h"



namespace yjs
{
    Scene::Scene()
    {
    }

    Scene::~Scene()
    {
    }

    void Scene::Initialize()
    {
        for (Layer& layer : mLayers)
        {
            layer.Initialize();
        }
    }

    void Scene::Update()
    {
        for (Layer& layer : mLayers)
        {
            layer.Update();
        }
    }

    void Scene::LateUpdate()
    {
        for (Layer& layer : mLayers)
        {
            layer.LateUpdate();
        }
    }

    void Scene::Render()
    {
        for (Layer& layer : mLayers)
        {
            layer.Render();
        }
    }

    void Scene::AddGameObject(GameObject* gameObject, UINT layerIndex)
    {
        mLayers[layerIndex].AddGameObject(gameObject);
    }
}