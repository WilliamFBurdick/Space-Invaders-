#include <sstream>
#include "InputHandler.h"
using namespace sf;
using namespace std;

void InputHandler::initializeInputHandler(ScreenManagerRemoteControl* sw, vector<shared_ptr<Button>> buttons, View* pointerToUIView, Screen* parentScreen)
{
	m_ScreenManagerRemoteControl = sw;
	m_Buttons = buttons;
	m_PointerToUIPanelView = pointerToUIView;
	m_ParentScreen = parentScreen;
}

void InputHandler::handleInput(RenderWindow& window, Event& event)
{
	//handle any key presses
	if (event.type == Event::KeyPressed) handleKeyPressed(event, window);
	if (event.type == Event::KeyReleased) handleKeyReleased(event, window);
	//handle any left mouse click release
	if (event.type == Event::MouseButtonReleased)
	{
		auto end = m_Buttons.end();
		for (auto i = m_Buttons.begin(); i != end; ++i)
		{
			if ((*i)->m_Collider.contains(window.mapPixelToCoords(Mouse::getPosition(), (*getPointerToUIView()))))
			{
				//capture the text of the button that was interacted with and pass to the specialized version of the class
				handleLeftClick((*i)->m_Text, window);
				break;
			}
		}
	}
	handleGamepad();
}

void InputHandler::handleGamepad() {}
void InputHandler::handleKeyPressed(Event& event, RenderWindow& window) {}
void InputHandler::handleKeyReleased(Event& event, RenderWindow& window) {}
void InputHandler::handleLeftClick(std::string& buttonInteractedWith, RenderWindow& window) {}
View* InputHandler::getPointerToUIView() { return m_PointerToUIPanelView; }
ScreenManagerRemoteControl* InputHandler::getPointerToScreenManagerRemoteControl() { return m_ScreenManagerRemoteControl; }
Screen* InputHandler::getmParentScreen() { return m_ParentScreen; }