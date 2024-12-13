#include "player.h"
#include <sgg/\graphics.h>
#include "gamestate.h"

void Player::update(float dt)
{
	float time = dt / 1000.0f;

	const float velocite = 8.0f;

	if (graphics::getKeyState(graphics::SCANCODE_LEFT))
		m_pos_x -= time*velocite;
	if (graphics::getKeyState(graphics::SCANCODE_RIGHT))
		m_pos_x += time*velocite;

}

void Player::init()
{
	m_pos_x = 3.0f;
	m_pos_y = 5.5f;

	m_brush_player.fill_color[0] = 1.0f;
	m_brush_player.fill_color[1] = 1.0f;
	m_brush_player.fill_color[2] = 1.0f;
	m_brush_player.fill_opacity = 1.0f;
	m_brush_player.outline_opacity = 0.0f;
	m_brush_player.texture = m_state->getAssetDir() + "player.png";
}

void Player::draw()
{
	graphics::drawRect(m_pos_x,m_pos_y,0.5f,0.5f, m_brush_player); // σχεδιασμος παικτη

}
