#pragma once
#ifndef __START_SCENE__
#define __START_SCENE__

#include "Scene.h"
#include "Label.h"
#include "ship.h"
#include <cmath>

class StartScene : public Scene
{
public:
	StartScene();
	~StartScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

private:
	/*Label* m_pStartLabel;
	Label* m_pInstructionsLabel;*/
	Ship* m_pShip; 

	glm::vec2 m_mousePosition;

	// ImGui menu variables
	bool m_exitApp = false;
	bool m_displayAbout = false;
	bool m_displayUI = true;

	// ImGui utility functions
	void m_ImGuiKeyMap();
	void m_ImGuiSetStyle();
	void m_updateUI();

	// Physics Variables
	const float Deg2Rad = 0.0174532925f;
	const float Rad2Deg = 57.2957795130f;
	bool m_isGravityEnabled = false;
	float m_Gravity = 9.8f;
	float m_HorizontalWind = 0.0f;
	float m_PPM = 10; // pixels per meter
	glm::vec2 m_initialPosition = glm::vec2(0.0f, 0.0f);
	float m_velocity = 0.0f;
	float m_velocityX = 0.0f;
	float m_velocityY = 0.0f;
	glm::vec2 m_acceleration = glm::vec2(0.0f, 0.0f);
	glm::vec2 m_finalPosition = glm::vec2(0.0f, 0.0f);
	float m_time = 0.016667f; // approx 16 ms
	float m_ATime = 0.016667f; // accumulated time

	float m_angle = 0.0f; // the kicking angle

	//Physics functions
	void m_move();

};

#endif /* defined (__START_SCENE__) */