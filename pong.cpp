//
// Created by Claudio on 21/07/2024.
//

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <sstream>

// Constantes del juego
const int VentanaAncho = 800;
const int VentanaLargo = 600;
const float paletaAncho = 25.0f;
const float paletaLargo = 100.0f;
const float RadioDePelota = 10.0f;
const float Vpaleta = 0.5f;
const float Vpelota = 0.4f;

int main() {
    sf::RenderWindow window(sf::VideoMode(VentanaAncho, VentanaLargo), "Pong BUEEEEEEEEEEE");

    // Crear las paletas
    sf::RectangleShape paleta1(sf::Vector2f(paletaAncho, paletaLargo));
    paleta1.setPosition(50.0f, VentanaLargo / 2 - paletaLargo / 2);
    sf::RectangleShape paleta2(sf::Vector2f(paletaAncho, paletaLargo));
    paleta2.setPosition(VentanaAncho - 50.0f - paletaAncho, VentanaLargo / 2 - paletaLargo / 2);

    // Crear la pelota
    sf::CircleShape pelota(RadioDePelota);
    pelota.setPosition(VentanaAncho / 2 - RadioDePelota, VentanaLargo / 2 - RadioDePelota);

    // Velocidad inicial de la pelota
    sf::Vector2f Rpelota(Vpelota, Vpelota);

    // Cargar la fuente para el marcador
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return -1; // Error al cargar la fuente
    }

    // Crear el texto del marcador
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(windowWidth / 2 - 50, 10);

    // Puntaje de los jugadores
    int score1 = 0;
    int score2 = 0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Mover la paleta 1
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && paleta1.getPosition().y > 0) {
            paleta1.move(0, -Vpaleta);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && paleta1.getPosition().y + paletaLargo < VentanaLargo) {
            paleta1.move(0, Vpaleta);
        }

        // Mover la paleta 2
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && paleta2.getPosition().y > 0) {
            paleta2.move(0, -Vpaleta);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && paleta2.getPosition().y + paletaLargo < VentanaLargo) {
            paleta2.move(0, Vpaleta);
        }

        // Mover la pelota
        pelota.move(Vpelota);

        // Comprobar colisiones con las paredes superior e inferior
        if (pelota.getPosition().y <= 0 || pelota.getPosition().y + RadioDePelota * 2 >= VentanaLargo) {
            Rpelota.y = -Rpelota.y;
        }

        // Comprobar colisiones con las paletas
        if (pelota.getGlobalBounds().intersects(paleta1.getGlobalBounds()) || pelota.getGlobalBounds().intersects(paleta2.getGlobalBounds())) {
            Rpelota.x = -Rpelota.x;
        }

        // Comprobar si la pelota sale de los límites de la pantalla
        if (pelota.getPosition().x <= 0) {
            // Incrementar el puntaje del jugador 2
            score2++;
            // Reiniciar la posición de la pelota
            pelota.setPosition(VentanaAncho / 2 - ballRadius, VentanaLargo / 2 - RadioDePelota);
            Rpelota.x = Vpelota;
            Rpelota.y = Vpelota;
        }
        if (ball.getPosition().x + ballRadius * 2 >= windowWidth) {
            // Incrementar el puntaje del jugador 1
            score1++;
            // Reiniciar la posición de la pelota
            ball.setPosition(windowWidth / 2 - ballRadius, windowHeight / 2 - ballRadius);
            Rpelota.x = -Vpelota;
            Rpelota.y = Vpelota;
        }

        // Actualizar el texto del marcador
        std::stringstream ss;
        ss << score1 << " - " << score2;
        scoreText.setString(ss.str());

        // Limpiar la ventana
        window.clear(sf::Color::Black);

        // Dibujar las paletas, la pelota y el marcador
        window.draw(paleta1);
        window.draw(paleta2);
        window.draw(pelota);
        window.draw(Puntuacion);

        // Mostrar lo que se ha dibujado en la ventana
        window.display();
    }

    return 0;
}
