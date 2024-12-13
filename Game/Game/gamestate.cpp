#include "gamestate.h"
#include "level.h"
#include "player.h"
GameState::GameState()
{
}

void GameState::init()
{
	m_current_level = new Level();
	m_current_level->init();
	m_player = new Player("myPlayer");
	m_player->init();
}

void GameState::draw()
{
	if (!m_current_level) return;

	m_current_level->draw();
}

void GameState::update(float dt)
{
	if (dt > 500) return;

	if (!m_current_level) return;

	m_current_level->update(dt);
}

GameState* GameState::getInstance()
{
	if (m_instance == nullptr) {
		m_instance = new GameState();
	}
	return m_instance;
}

GameState::~GameState()
{
	if (m_player)
		delete m_player;
	if (m_current_level)
		delete m_current_level;
}

std::string GameState::getAssetDir()
{
	return m_asset_path;
}

GameState* GameState::m_instance = nullptr;
