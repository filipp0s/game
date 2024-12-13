#include "gameobject.h"
#include "gamestate.h"


GameObject::GameObject(const std::string& name, float pos_x, float pos_y)
    : m_name(name), m_pos_x(pos_x), m_pos_y(pos_y), m_state(GameState::getInstance()), m_id(m_next_id)
{
    m_next_id++;  
}

int GameObject::m_next_id = 1;  
