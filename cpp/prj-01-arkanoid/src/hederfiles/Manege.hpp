// #include "Ball.hpp"
// #include "Brick.hpp"
// #include "Border.hpp"
// #include "Paddle.hpp"
// #include "ArrowMovement.hpp"
// #include "Collision.hpp"
// #include "WindowAdapter.hpp"

// class WindowManager {
// public:
//     WindowManager(const sf::Vector2u& windowSize, const std::string& windowTitle);
//     bool isOpen() const;
//     void clear();
//     void display();
//     void pollEvent(sf::Event& event);
//     void draw(const sf::Drawable& drawable);
//     void draw(const sf::Vertex* vertices, std::size_t vertexCount, sf::PrimitiveType type);
//     sf::RenderWindow &getRenderWindow();
// private:
//     sf::RenderWindow m_window;
// };

// class InputManager {
// public:
//     InputManager();
//     bool isKeyPressed(sf::Keyboard::Key key) const;
//     bool isKeyReleased(sf::Keyboard::Key key) const;
//     bool isMouseButtonPressed(sf::Mouse::Button button) const;
//     bool isMouseButtonReleased(sf::Mouse::Button button) const;
//     sf::Vector2f getMousePosition() const;
// private:
//     std::unordered_set<sf::Keyboard::Key> m_pressedKeys;
//     std::unordered_set<sf::Keyboard::Key> m_releasedKeys;
//     std::unordered_set<sf::Mouse::Button> m_pressedMouseButtons;
//     std::unordered_set<sf::Mouse::Button> m_releasedMouseButtons;
//     sf::Vector2f m_mousePosition;
// };

// class PhysicsManager {
// public:
//     PhysicsManager();
//     void update(float deltaTime, Ball& ball, Paddle& paddle, Brick& brick, Border& border);
// private:
//     void checkPaddleCollision(Ball& ball, Paddle& paddle);
//     void checkBrickCollision(Ball& ball, Brick& brick);
//     void checkBorderCollision(Ball& ball, Border& border);
//     float m_ballSpeed;
// };

// class GameManager {
// public:
//     GameManager(WindowManager& windowManager, InputManager& inputManager);
//     void run();
// private:
//     void handleInput();
//     void update(float deltaTime);
//     void render();
//     void reset();
// private:
//     WindowManager& m_windowManager;
//     InputManager& m_inputManager;
//     PhysicsManager m_physicsManager;
//     Ball m_ball;
//     Paddle m_paddle;
//     Brick m_brick;
//     Border m_border;
//     float m_ballSpeed;
// };

// // WindowManager--------------------------------------------------------

// class WindowManager {
// public:
//     WindowManager(const sf::Vector2u& windowSize, const std::string& windowTitle)
//     : m_window(sf::VideoMode(windowSize.x, windowSize.y), windowTitle)
//     {}
    
//     bool isOpen() const {
//         return m_window.isOpen();
//     }
    
//     void clear() {
//         m_window.clear();
//     }
    
//     void display() {
//         m_window.display();
//     }
    
//     void pollEvent(sf::Event& event) {
//         m_window.pollEvent(event);
//     }
    
//     void draw(const sf::Drawable& drawable) {
//         m_window.draw(drawable);
//     }
    
//     void draw(const sf::Vertex* vertices, std::size_t vertexCount, sf::PrimitiveType type) {
//         m_window.draw(vertices, vertexCount, type);
//     }

//     sf::RenderWindow &WindowManager::getRenderWindow()
//     {
//         return m_window;
//     }
// private:
//     sf::RenderWindow m_window;
// };

// // InputManager-------------------------------------------------

// #include <unordered_set>

// class InputManager {
// public:
//     InputManager() {}

//     bool isKeyPressed(sf::Keyboard::Key key) const {
//         return m_pressedKeys.count(key) > 0;
//     }

//     bool isKeyReleased(sf::Keyboard::Key key) const {
//         return m_releasedKeys.count(key) > 0;
//     }

//     bool isMouseButtonPressed(sf::Mouse::Button button) const {
//         return m_pressedMouseButtons.count(button) > 0;
//     }

//     bool isMouseButtonReleased(sf::Mouse::Button button) const {
//         return m_releasedMouseButtons.count(button) > 0;
//     }

//     sf::Vector2f getMousePosition() const {
//         return m_mousePosition;
//     }

//     void pollEvent(sf::RenderWindow& window) {
//         m_pressedKeys.clear();
//         m_releasedKeys.clear();
//         m_pressedMouseButtons.clear();
//         m_releasedMouseButtons.clear();

//         sf::Event event;
//         while (window.pollEvent(event)) {
//             switch (event.type) {
//                 case sf::Event::Closed:
//                     window.close();
//                     break;
//                 case sf::Event::KeyPressed:
//                     m_pressedKeys.insert(event.key.code);
//                     break;
//                 case sf::Event::KeyReleased:
//                     m_releasedKeys.insert(event.key.code);
//                     break;
//                 case sf::Event::MouseButtonPressed:
//                     m_pressedMouseButtons.insert(event.mouseButton.button);
//                     break;
//                 case sf::Event::MouseButtonReleased:
//                     m_releasedMouseButtons.insert(event.mouseButton.button);
//                     break;
//                 case sf::Event::MouseMoved:
//                     m_mousePosition = window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
//                     break;
//                 default:
//                     break;
//             }
//         }
//     }

// private:
//     std::unordered_set<sf::Keyboard::Key> m_pressedKeys;
//     std::unordered_set<sf::Keyboard::Key> m_releasedKeys;
//     std::unordered_set<sf::Mouse::Button> m_pressedMouseButtons;
//     std::unordered_set<sf::Mouse::Button> m_releasedMouseButtons;
//     sf::Vector2f m_mousePosition;
// };


// // PhysicsManager-----------------------------------------------

// #define MAX_BOUNCE_ANGLE 0.3

// PhysicsManager::PhysicsManager() {}

// void PhysicsManager::update(float deltaTime, Ball& ball, Paddle& paddle, Brick& brick, Border& border) {
//     checkPaddleCollision(ball, paddle);
//     checkBrickCollision(ball, brick);
//     checkBorderCollision(ball, border);

//     ball.move(ball.getDirection().x * m_ballSpeed * deltaTime,ball.getDirection().y * m_ballSpeed * deltaTime);
// }

// void PhysicsManager::checkPaddleCollision(Ball& ball, Paddle& paddle) {
//     if (ball.getShape()->getGlobalBounds().intersects(paddle.getShape()->getGlobalBounds())) {
//         float ballCenterX = ball.getShape()->getPosition().x + ball.getShape()->getRadius();
//         float paddleCenterX = paddle.getShape()->getPosition().x + paddle.getShape()->getSize().x / 2.f;
//         float relativeIntersectX = ballCenterX - paddleCenterX;
//         float normalizedRelativeIntersectX = relativeIntersectX / (paddle.getShape()->getSize().x / 2.f);

//         // Calculate bounce angle
//         float angle = normalizedRelativeIntersectX * MAX_BOUNCE_ANGLE;
//         ball.setDirection(sf::Vector2f(std::sin(angle), -std::cos(angle)));
//     }
// }

// void PhysicsManager::checkBrickCollision(Ball& ball, Brick& brick) {
//     for (int i = 0; i < Brick::ROW_COUNT; i++) {
//         for (int j = 0; j < Brick::COLUMN_COUNT; j++) {
//             if (ball.getShape()->getGlobalBounds().intersects(brick.getBrick(i).getGlobalBounds())) {
//                 // Collision with brick detected, change direction of ball
//                 float ballCenterX = ball.getShape()->getPosition().x + ball.getShape()->getRadius();
//                 float brickCenterX = brick.getBrick(i).getPosition().x + brick.getBrick(i).getSize().x / 2.f;
//                 float relativeIntersectX = ballCenterX - brickCenterX;
//                 float normalizedRelativeIntersectX = relativeIntersectX / (brick.getBrick(i).getSize().x / 2.f);

//                 // Calculate bounce angle
//                 float angle = normalizedRelativeIntersectX * MAX_BOUNCE_ANGLE;
//                 ball.setDirection(sf::Vector2f(std::sin(angle), -std::cos(angle)));

//                 // Destroy brick
//                 brick.deleteBrick(i);
//             }
//         }
//     }
// }

// void PhysicsManager::checkBorderCollision(Ball& ball, Border& border) {
//     if (ball.getShape()->getPosition().x - ball.getShape()->getRadius() <= border.getShape()->getGlobalBounds().left || 
//         ball.getShape()->getPosition().x + ball.getShape()->getRadius() >= border.getShape()->getGlobalBounds().width) {
//         ball.setDirection(sf::Vector2f(-ball.getDirection().x, ball.getDirection().y));
//     }
//     if (ball.getShape()->getPosition().y - ball.getShape()->getRadius() <= border.getShape()->getGlobalBounds().top) {
//         ball.setDirection(sf::Vector2f(ball.getDirection().x, -ball.getDirection().y));
//     }
// }

// // GameManager--------------------------------------------------


// GameManager::GameManager(WindowManager& windowManager, InputManager& inputManager)
//     : m_windowManager(windowManager), m_inputManager(inputManager), m_ball(), m_paddle(), m_brick(), m_border(), m_ballSpeed(200.f)
// {
//     // Initialize game objects
//     m_ball.setPosition(m_paddle.getShape()->getGlobalBounds().left + 50, m_paddle.getShape()->getGlobalBounds().top - 13);
//     m_ball.setDirection(sf::Vector2f(std::rand() % 200 - 100, std::rand() % 200 - 100));
//     m_physicsManager = PhysicsManager();
// }

// void GameManager::run()
// {
//     sf::Clock clock;
//     while (m_windowManager.isOpen()) {
//         float deltaTime = clock.restart().asSeconds();
//         handleInput();
//         update(deltaTime);
//         render();
//     }
// }

// void GameManager::handleInput()
// {
//     m_inputManager.pollEvent(m_windowManager.getRenderWindow());
//     if (m_inputManager.isKeyPressed(sf::Keyboard::Escape)) {
//         m_windowManager.getRenderWindow().close();
//     }
//     m_paddle.setIsPressed(m_inputManager.isKeyPressed(sf::Keyboard::Left) || m_inputManager.isKeyPressed(sf::Keyboard::Right));
// }

// void GameManager::update(float deltaTime)
// {
//     m_physicsManager.update(deltaTime, m_ball, m_paddle, m_brick, m_border);

//     if (m_brick.isEmpty()) {
//         m_brick.init();
//     }
//     if (m_ball.getPosition().y > m_windowManager.getRenderWindow().getSize().y) {
//         reset();
//     }
// }

// void GameManager::render()
// {
//     m_windowManager.clear();
//     m_windowManager.draw(*m_paddle.getShape());
//     m_windowManager.draw(*m_ball.getShape());
//     m_windowManager.draw(*m_brick.getShape());
//     m_windowManager.draw(*m_border.getShape());
//     m_windowManager.display();
// }
// // m_brick.draw(m_windowManager);
// // m_border.draw(m_windowManager);

// void GameManager::reset()
// {
//     m_brick.init();
//     m_paddle.setIsPressed(false);
//     m_ball.setPosition(m_paddle.getShape()->getGlobalBounds().left + 50, m_paddle.getShape()->getGlobalBounds().top - 13);
//     m_ball.setDirection(sf::Vector2f(std::rand() % 200 - 100, std::rand() % 200 - 100));
// }


// class GameManager {
// public:
//     GameManager();
//     ~GameManager();
//     // Getter functions
//     WindowManager& getWindowManager() const;
//     InputManager& getInputManager() const;
//     Ball& getBall() const;
//     Paddle& getPaddle() const;
//     Brick& getBrick() const;
//     Border& getBorder() const;
//     GameState& getGameState();
//     const GameState& getGameState() const;
//     HUD& getHUD();
//     const HUD& getHUD() const;
//     Menu& getMenu();
//     const Menu& getMenu() const;
//     float getBallSpeed() const;
//     // Setter functions
//     void setWindowManager(WindowManager& windowManager);
//     void setInputManager(InputManager& inputManager);
//     void setBall(Ball& ball);
//     void setPaddle(Paddle& paddle);
//     void setBrick(Brick& brick);
//     void setBorder(Border& border);
//     void setGameState(const GameState& gameState);
//     void setBallSpeed(float ballSpeed);
//     // Other member functions
//     void run();
//     std::size_t hash() const;
//     void reset();
// private:
//     WindowManager* m_windowManager;
//     InputManager* m_inputManager;
//     Ball* m_ball;
//     Paddle* m_paddle;
//     Brick* m_brick;
//     Border* m_border;
//     GameState m_gameState;
//     HUD m_hud;
//     Menu m_menu;
//     float m_ballSpeed;
//     PhysicsManager m_physicsManager;
//     // Helper function to combine hash values
//     template <typename T>
//     static std::size_t hash_combine(std::size_t seed, const T& val);
// };

// #include "GameLoop.hpp"
// #include "InputHandler.hpp"
// #include "GameStateUpdater.hpp"
// #include "Renderer.hpp"
// #include "GameResetter.hpp"

// class GameManager {
// public:
//     GameManager(
//         WindowManager& windowManager
//         , InputManager& inputManager
//         , Ball &ball
//         , Brick &brick
//         , Paddle &paddle
//         , Border &border
//     ) : m_windowManager(windowManager)
//       , m_inputHandler(inputManager)
//       , m_gameLoop(m_windowManager, std::bind(&GameManager::update, this, std::placeholders::_1))
//       , m_gameStateUpdater(ball, brick, paddle, border, m_gameResetter)
//       , m_renderer(m_windowManager, ball, brick, paddle, border, m_hud, m_menu)
//       , m_gameResetter(ball, brick, paddle, border)
//       , m_ball(ball)
//       , m_brick(brick)
//       , m_paddle(paddle)
//       , m_border(border)
//       , m_hud()
//       , m_menu(m_inputHandler, m_gameLoop)
//       , m_highScoreManager()
//       , m_gameState(GameState::MENU)
//     {
//         m_gameStateUpdater.setBrickEmptyCallback(std::bind(&GameManager::onBrickEmpty, this));
//         m_gameStateUpdater.setBallOutOfBoundsCallback(std::bind(&GameManager::onBallOutOfBounds, this));
//         m_gameStateUpdater.setNoHealthCallback(std::bind(&GameManager::onNoHealth, this));
//         m_gameStateUpdater.setUpdateHighScoreCallback(std::bind(&GameManager::onUpdateHighScore, this));
//     }
//     void run() {
//         m_gameLoop.run();
//     }
// private:
//     void onBrickEmpty() {
//         m_gameState = GameState::BRICK_EMPTY;
//     }
//     void onBallOutOfBounds() {
//         m_gameState = GameState::BALL_OUT_OF_BOUNDS;
//     }
//     void onNoHealth() {
//         m_gameState = GameState::NO_HEALTH;
//     }
//     void onUpdateHighScore() {
//         m_gameState = GameState::UPDATE_HIGH_SCORE;
//     }
//     void update(float deltaTime) {
//         switch (m_gameState) {
//             case GameState::MENU:
//                 m_inputHandler.handleInput();
//                 m_renderer.render();
//                 break;
//             case GameState::PLAY:
//                 m_gameStateUpdater.update(deltaTime);
//                 m_inputHandler.handleInput();
//                 m_renderer.render();
//                 break;
//             case GameState::BRICK_EMPTY:
//                 m_gameStateUpdater.brickEmpty();
//                 m_inputHandler.handleInput();
//                 m_renderer.render();
//                 break;
//             case GameState::BALL_OUT_OF_BOUNDS:
//                 m_gameStateUpdater.ballOutOfBounds();
//                 m_inputHandler.handleInput();
//                 m_renderer.render();
//                 break;
//             case GameState::NO_HEALTH:
//                 m_gameStateUpdater.noHealth();
//                 m_inputHandler.handleInput();
//                 m_renderer.render();
//                 break;
//             case GameState::UPDATE_HIGH_SCORE:
//                 m_highScoreManager.updateHighScore();
//                 m_inputHandler.handleInput();
//                 m_renderer.render();
//                 break;
//             case GameState::QUIT:
//                 m_gameLoop.quit();
//                 break;
//         }
//     }

// private:
//     WindowManager &m_windowManager;
//     InputHandler m_inputHandler;
//     GameLoop m_gameLoop;
//     GameStateUpdater m_gameStateUpdater;
//     Renderer m_renderer;
//     GameResetter m_gameResetter;
//     Ball &m_ball;
//     Brick &m_brick;
//     Paddle &m_paddle;
//     Border
