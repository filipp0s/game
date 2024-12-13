#pragma once

#include <string>

class GameObject
{
	static int m_next_id;

protected:
	class GameState* m_state;
	std::string m_name;
	int m_id = 0;
	bool m_active = true;
	float m_pos_x;
	float m_pos_y;
public:
	GameObject(const std::string& name = "",float m_pos_x=0.0f, float m_pos_y=0);
	virtual void update(float dt) {}
	virtual void init() {}
	virtual void draw() {}
	virtual ~GameObject() {}
	bool isActive() { return m_active; }
	void setActive(bool a) { m_active = a; }
};