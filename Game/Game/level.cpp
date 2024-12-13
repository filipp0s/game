#include "level.h"
#include "gamestate.h"
#include "player.h"
void Level::update(float dt)
{
	if (m_state->getPlayer()->isActive()) {
		m_state->getPlayer()->update(dt);
	}

	GameObject::update(dt);


}

void Level::init()
{
	m_brush_background.fill_color[0] = 1.0f;
	m_brush_background.fill_color[1] = 1.0f;
	m_brush_background.fill_color[2] = 1.0f;
	m_brush_background.outline_opacity = 0.0f;
	m_brush_background.texture = m_state->getAssetDir() + "background.png";

	for (GameObject* item : m_static_objects)
		if (item) item->init();

	for (GameObject* item : m_dynamic_objects)
		if (item) item->init();

}

void Level::draw()
{
	drawRect(m_state->getCanvasWidth() / 2.0f , m_state->getCanvasHeight()/ 2.0f ,
		m_state->getCanvasWidth(),m_state->getCanvasHeight(), m_brush_background); // σχεδιασμος background

	if (m_state->getPlayer()->isActive()) {
		m_state->getPlayer()->draw();
	}

	for (GameObject* item : m_static_objects)
		if (item) item->draw();

	for (GameObject* item : m_dynamic_objects)
		if (item) item->draw();
}

Level::Level(const std::string& name)
{
}

Level::~Level()
{
	for (GameObject* item : m_static_objects)
		if (item) delete item;

	for (GameObject* item : m_dynamic_objects)
		if (item) delete item;
}
