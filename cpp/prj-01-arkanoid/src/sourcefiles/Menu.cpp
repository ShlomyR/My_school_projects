#include "../hederfiles/Menu.hpp"
#include "../hederfiles/PlayOption.hpp"
#include "../hederfiles/HighScoreOption.hpp"
#include "../hederfiles/ExitOption.hpp"

#include <memory>

Menu::Menu(WindowManager& windowManager)
    : m_windowManager(windowManager)
    , m_isMenuShown(true)
{
    addOptions(std::make_unique<PlayOption>(),std::make_unique<HighScoreOption>(),std::make_unique<ExitOption>());
}

void Menu::draw()
{
    for (const auto& option : m_options) {
        option->draw(m_windowManager.getRenderWindow());
    }
}

bool Menu::handleInput(const InputManager& inputManager)
{
    for (const auto& option : m_options) {
        if (option->handleInput(inputManager)) {
            m_isMenuShown = false;
            return true;
        }
    }
    return false;
}

std::unique_ptr<MenuOption> &Menu::getOption(int index)
{
    return m_options.at(index);
}

size_t Menu::getOptionSize() const
{
    return m_options.size();
}

bool Menu::getIsMenuShown() const
{
    return m_isMenuShown;
}

int Menu::getSelectedOptionIndex() const
{
    for (size_t i = 0; i < m_options.size(); ++i) {
        if (m_options[i]->isSelected()) {
            return i;
        }
    }
    return -1;
}

void Menu::setIsMenuShown(bool value)
{
    m_isMenuShown = value;
}

template<typename... Args>
void Menu::addOptions(Args&&... args)
{
    (m_options.emplace_back(std::forward<Args>(args)), ...);
}
