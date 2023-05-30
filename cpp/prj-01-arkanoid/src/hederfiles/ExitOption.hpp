#pragma once

#include "MenuOption.hxx"

class ExitOption : public MenuOption {
public:
    void draw(sf::RenderWindow& window) override;
    bool handleInput(const InputManager& inputManager) override;
    void makeButton(sf::RenderWindow&) override;
    bool isSelected() const override;
private:
    sf::Text m_exitText;
    bool m_isSelected = false;
};