#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>
using namespace sf;
class Component;
class TransformComponent : public Component {
private:
	const string m_Type = "transform";
	Vector2f m_Location;
	float m_Height, m_Width;
public:
	TransformComponent(float width, float height, Vector2f location);
	Vector2f& getLocation();
	Vector2f getSize();
	/* From component interface */
	string Component::getType() { return m_Type; }
	string Component::getSpecificType() { return m_Type; }
	void Component::disableComponent() {}
	void Component::enableComponent() {}
	bool Component::enabled() { return false; }
	void Component::start(GameObjectSharer* gos, GameObject* self) {}
};