#pragma once

#include "MenuOption.hxx"
#include "WindowManager.hpp"

class InputManager;

class Menu {
public:
    Menu(WindowManager& windowManager);
    void draw();
    bool handleInput(const InputManager& inputManager);

    std::unique_ptr<MenuOption> & getOption(int index);
    size_t getOptionSize() const;
    int getSelectedOptionIndex() const;
    bool getIsMenuShown() const;

    void setIsMenuShown(bool);

    template<typename... Args>
    void addOptions(Args&&... args);

private:
    WindowManager& m_windowManager;
    std::vector<std::unique_ptr<MenuOption>> m_options;
    bool m_isMenuShown;
};
