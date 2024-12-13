#pragma once
#include "sgg/graphics.h"
#include <string>



class GameState {

private:
	std::string m_asset_path = "assets\\";
	float m_canvas_width = 8.0f;
	float m_canvas_height = 8.0f;

	static GameState* m_instance;
	GameState();

	class Player* m_player = 0;
	class Level* m_current_level = 0;

public:

	float m_global_offset_x = 0.0f;  
	float m_global_offset_y = 0.0f;
	bool m_debugging = false;

	void init();
	void draw();
	void update(float dt);

	static GameState* getInstance();
	~GameState();

	class Player* getPlayer() { return m_player; }

	float getCanvasWidth() { return m_canvas_width; }
	float getCanvasHeight() { return m_canvas_height; }
	std::string getAssetDir();
};