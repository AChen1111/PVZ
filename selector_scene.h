#pragma once
#include "scene.h"
#include "scene_manager.h"
#include "animation.h"
using namespace std;

#pragma region{资源加载代码}
extern IMAGE img_VS; // VS 艺术字图片
extern IMAGE img_1P; // 1P 文本图片 
extern IMAGE img_2P; // 2P 文本图片
extern IMAGE img_1P_desc; // 1P 键位描述图片
extern IMAGE img_2P_desc; // 2P 键位描述图片
extern IMAGE img_gravestone_left; // 朝向左的墓碑图片
extern IMAGE img_gravestone_right; // 朝向右的墓碑图片
extern IMAGE img_selector_tip; // 选角界面提示文本图片
extern IMAGE img_selector_background; // 选角界面背景图片
extern IMAGE img_1P_selector_btn_idle_left; // 1P 向左选择按钮默认状态图片
extern IMAGE img_1P_selector_btn_idle_right; // 1P 向右选择按钮默认状态图片
extern IMAGE img_1P_selector_btn_down_left; // 1P 向左选择按钮按下状态图片
extern IMAGE img_1P_selector_btn_down_right; // 1P 向右选择按钮按下状态图片
extern IMAGE img_2P_selector_btn_idle_left; // 2P 向左选择按钮默认状态图片
extern IMAGE img_2P_selector_btn_idle_right; // 2P 向右选择按钮默认状态图片
extern IMAGE img_2P_selector_btn_down_left; // 2P 向左选择按钮按下状态图片
extern IMAGE img_2P_selector_btn_down_right; // 2P 向右选择按钮按下状态图片
extern IMAGE img_peashooter_selector_background_left; // 选角界面朝向左的婉逗射手背景图片
extern IMAGE img_peashooter_selector_background_right; // 选角界面朝向右的婉逗射手背景图片
extern IMAGE img_sunflower_selector_background_left; // 选角界面朝向左的龙日葵背景图片
extern IMAGE img_sunflower_selector_background_right; // 选角界面朝向右的龙日葵背景图片

extern Atlas atlas_peashooter_idle_right;
extern Atlas atlas_sunflower_idle_right;
extern IMAGE img_avatar_peashooter;
extern IMAGE img_avatar_sunflower;
#pragma endregion
extern SceneManager scene_manager;
class SelectorScene : public Scene {
public:
	SelectorScene() = default;
	~SelectorScene() = default;
	void on_enter()
	{
		animation_peashooter.set_atlas(&atlas_peashooter_idle_right);
		animation_sunflower.set_atlas(&atlas_sunflower_idle_right);
		animation_peashooter.set_interval(100);
		animation_sunflower.set_interval(100);
		static const int OFFSET_X = 50;
		pos_img_VS.x = (getwidth() - img_VS.getwidth()) / 2;

		pos_img_VS.y = (getheight() - img_VS.getheight()) / 2;

		pos_img_tip.x = (getwidth() - img_selector_tip.getwidth()) / 2;

		pos_img_tip.y = getheight() - 125;

		pos_img_1P.x = (getwidth() / 2 - img_1P.getwidth()) / 2 - OFFSET_X;

		pos_img_1P.y = 35;

		pos_img_2P.x = getwidth() / 2 + (getwidth() / 2 - img_2P.getwidth()) / 2 + OFFSET_X;

		pos_img_2P.y = pos_img_1P.y;

		pos_img_1P_desc.x = (getwidth() / 2 - img_1P_desc.getwidth()) / 2 - OFFSET_X;

		pos_img_1P_desc.y = getheight() - 150;

		pos_img_2P_desc.x = getwidth() / 2 + (getwidth() / 2 - img_2P_desc.getwidth()) / 2 + OFFSET_X;

		pos_img_2P_desc.y = pos_img_1P_desc.y;

		pos_img_1P_gravestone.x = (getwidth() / 2 - img_gravestone_right.getwidth()) / 2 - OFFSET_X;
		pos_img_1P_gravestone.y = pos_img_1P.y + img_1P.getheight() + 35;

		pos_img_2P_gravestone.x = getwidth() / 2 + (getwidth() / 2 - img_gravestone_left.getwidth()) / 2 + OFFSET_X;
		pos_img_2P_gravestone.y = pos_img_1P_gravestone.y;
		pos_animation_1P.x = (getwidth() / 2 - atlas_peashooter_idle_right.get_image(0)->getwidth()) / 2 - OFFSET_X;

		pos_animation_1P.y = pos_img_1P_gravestone.y + 80;

		pos_animation_2P.x = getwidth() / 2 + (getwidth() / 2 - atlas_peashooter_idle_right.get_image(0)->getwidth()) / 2 + OFFSET_X;

		pos_animation_2P.y = pos_animation_1P.y;

		pos_img_1P_name.y = pos_animation_1P.y + 155;

		pos_img_2P_name.y = pos_img_1P_name.y;
		pos_1P_selector_btn_left.x = pos_img_1P_gravestone.x - img_1P_selector_btn_idle_left.getwidth();

		pos_1P_selector_btn_left.y = pos_img_1P_gravestone.y + (img_gravestone_right.getheight() - img_1P_selector_btn_idle_left.getheight()) / 2;

		pos_1P_selector_btn_right.x = pos_img_1P_gravestone.x + img_gravestone_right.getwidth();

		pos_1P_selector_btn_right.y = pos_1P_selector_btn_left.y;

		pos_2P_selector_btn_left.x = pos_img_2P_gravestone.x - img_2P_selector_btn_idle_left.getwidth();

		pos_2P_selector_btn_left.y = pos_1P_selector_btn_left.y;

		pos_2P_selector_btn_right.x = pos_img_2P_gravestone.x + img_gravestone_left.getwidth();

		pos_2P_selector_btn_right.y = pos_1P_selector_btn_left.y;
	}
	void on_update(int delta)
	{
	};
	void on_draw(const Camera& camera)
	{
		putimage(0, 0, &img_selector_background);
		putimage_alpha(pos_img_VS.x, pos_img_VS.y, &img_VS);
		putimage_alpha(pos_img_1P.x, pos_img_1P.y, &img_1P);
		putimage_alpha(pos_img_2P.x, pos_img_2P.y, &img_2P);
		putimage_alpha(pos_img_1P_gravestone.x, pos_img_1P_gravestone.y, &img_gravestone_right);
		putimage_alpha(pos_img_2P_gravestone.x, pos_img_2P_gravestone.y, &img_gravestone_left);
		putimage_alpha(pos_img_1P_desc.x, pos_img_1P_desc.y, &img_1P_desc);
		putimage_alpha(pos_img_2P_desc.x, pos_img_2P_desc.y, &img_2P_desc);
		putimage_alpha(pos_img_tip.x, pos_img_tip.y, &img_selector_tip);
	};
	void on_input(const ExMessage& msg)
	{
		if (msg.message == WM_KEYDOWN)
		{
			scene_manager.switch_to(SceneManager::SceneType::Menu);
		}
	};
	void on_exit()
	{
	};
private:
	POINT pos_img_VS = { 0 };//VS艺术字图片位置
	POINT pos_img_tip = { 0 };//提示信息文本图片位置
	POINT pos_img_1P = { 0 };//1P 文本图片位置
	POINT pos_img_2P = { 0 };//2P 文本图片位置
	POINT pos_img_1P_desc = { 0 };//1P 键位描述图片位置
	POINT pos_img_2P_desc = { 0 };//2P 键位描述图片位置
	POINT pos_img_1P_name = { 0 };//1P 角色姓名图片位置
	POINT pos_img_2P_name = { 0 };//2P 角色姓名图片位置
	POINT pos_animation_1P = { 0 };//1P 动画位置
	POINT pos_animation_2P = { 0 };//2P 动画位置
	POINT pos_img_1P_gravestone = { 0 };//1P 墓碑图片位置
	POINT pos_img_2P_gravestone = { 0 };//2P 墓碑图片位置
	POINT pos_1P_selector_btn_left = { 0 };//1P 向左切换按钮位置
	POINT pos_2P_selector_btn_left = { 0 };//2P 向左切换按钮位置
	POINT pos_1P_selector_btn_right = { 0 };//1P 向右切换按钮位置
	POINT pos_2P_selector_btn_right = { 0 };//2P 向右切换按钮位置

	Animation animation_peashooter;
	Animation animation_sunflower;
};