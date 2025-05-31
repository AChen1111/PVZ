#pragma once
#include "scene.h"
#include "scene_manager.h"
#include <iostream>
using namespace std;
extern SceneManager scene_manager;
class GameScene : public Scene {
public:
	GameScene() = default;
	~GameScene() = default;
	void on_enter()
	{
	}
	void on_update(int delta)
	{
	};
	void on_draw(const Camera& camera)
	{
		outtextxy(10, 10, _T("ÓÎÏ·»æÍ¼ÄÚÈİ"));
	};
	void on_input(const ExMessage& msg) 
	{
		if (msg.message == WM_KEYDOWN)
		{
			scene_manager.switch_to(SceneManager::SceneType::Selector);
		}
	};
	void on_exit()
	{
	};
};