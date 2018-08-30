#include "Game.h"

Game::Game() : m_window("Snake", sf::Vector2u(800, 600)),
               m_snake(m_world.GetBlockSize()),
               m_world(sf::Vector2u(800, 600))
{
    m_clock.restart();
    srand(time(nullptr));

	m_textbox.Setup(5, 14, 350, sf::Vector2f(225, 0));
	m_elapsed = sf::Time::Zero;
}

Game::~Game()
{
}

Window *Game::getWindow()
{
    return &m_window;
}

void Game::handleInput()
{
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        && m_snake.GetPhysicalDirection() != Direction::Down)
    {
        m_snake.SetDirection(Direction::Up);
    }
    else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        && m_snake.GetPhysicalDirection() != Direction::Up)
    {
        m_snake.SetDirection(Direction::Down);
    }
    else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        && m_snake.GetPhysicalDirection() != Direction::Right)
    {
        m_snake.SetDirection(Direction::Left);
    }
    else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        && m_snake.GetPhysicalDirection() != Direction::Left)
    {
        m_snake.SetDirection(Direction::Right);
    }
}

void Game::update()
{
    m_window.update();
    sf::Time timestep = sf::seconds(1.0f) / m_snake.GetSpeed();
    if (m_elapsed >= timestep)
    {
        m_snake.Tick();
        m_world.Update(m_snake);
        m_elapsed -= timestep;
        if (m_snake.HasLost())
        {
			m_textbox.Add("GAME OVER! Score: " + std::to_string((long long)m_snake.GetScore()));
            m_snake.Reset();
        }
    }
}

void Game::render()
{
    m_window.beginDraw();
    m_world.Render(*m_window.getRenderWindow());
    m_snake.Render(*m_window.getRenderWindow());
	m_textbox.Render(*m_window.getRenderWindow());
    m_window.endDraw();
}

sf::Time Game::getElapsed()
{
    return m_elapsed;
}

void Game::restartClock()
{
    m_elapsed += m_clock.restart();
}