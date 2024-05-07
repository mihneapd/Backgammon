#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <random>
#include <sstream>
#include <vector>

int main()
{
    sf::RenderWindow window{ sf::VideoMode(936, 720), "bomba" };
    sf::Texture t, photo1, photo2;

    std::string file1, file2, file3, file4, file5, file6, file7, file8, file9, file10;
    sf::Texture texture1, texture2, texture3, texture4, texture5, texture6, texture7, texture8, texture9, texture10;

    std::string file1w, file2w, file3w, file4w, file5w, file6w, file7w, file8w, file9w, file10w;
    sf::Texture texture1w, texture2w, texture3w, texture4w, texture5w, texture6w, texture7w, texture8w, texture9w, texture10w;

    t.loadFromFile("texture/board.jpg");
    sf::Sprite s(t);

    sf::RectangleShape container[2][12], player1_scos,player2_scos,scoase1,scoase2;
    sf::RectangleShape roll, dice1, dice2, jucator;

    sf::Vector2f size(64, 320);
    sf::Vector2f size2(128, 64);
    sf::Vector2f size3(64, 64);
    sf::Vector2f size4(32, 64);
    jucator.setSize(size3);
    player1_scos.setSize(size4);
    player2_scos.setSize(size4);
    roll.setSize(size2);
    dice1.setSize(size3);
    dice2.setSize(size3);
    scoase1.setSize(size);
    scoase2.setSize(size);
    std::vector <int> v;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 12; ++j) {
            container[i][j].setSize(size);
            
        }
    }
    int test_x = -1;
    float x = 72.0f;
    float y = 10.0f;
    int contor = 0;
    int mat[2][12], frv[24];
    int scos1 = 3;
    int scos2 = 0;
    int poti_scoate1 = -1;
    int poti_scoate2 = -1;
    frv[0] = 0;
    frv[1] = 0;

    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 12; j++) {
            mat[i][j] = 0;
        }
    }
    mat[0][0] = 2;
    mat[0][5] = -5;
    mat[0][7] = -3;
    mat[0][11] = 5;
    mat[1][0] = -2;
    mat[1][5] = 5;
    mat[1][7] = 3;
    mat[1][11] = -5;
    int win1 = 0;
    int win2 = 0;
    int ctr = 0;
    int player = 0;
    int apasat1 = -1;
    int apasat2 = -1;
    int number_of_container = -1, J = -1;
    int csz = -1;
    int ochei = 0;
    int contorut = 0;
    int Z = 0;
    int oke = 0;
    int valid = 0;
    bool rollButtonRed = false;
    int frev[2][12];

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> distribution(1, 6);

    sf::Clock rollClock;
    sf::Clock idleClock;

    jucator.setFillColor(sf::Color::Magenta);
    player1_scos.setFillColor(sf::Color::Yellow);
    player2_scos.setFillColor(sf::Color::Yellow);
    scoase1.setFillColor(sf::Color::Yellow);
    scoase2.setFillColor(sf::Color::Yellow);

    file1w = "texture/w1.png";
    file2w = "texture/w2.png";
    file3w = "texture/w3.png";
    file4w = "texture/w4.png";
    file5w = "texture/w5.png";
    file6w = "texture/w1 - Copy.png";
    file7w = "texture/w2 - Copy.png";
    file8w = "texture/w3 - Copy.png";
    file9w = "texture/w4 - Copy.png";
    file10w = "texture/w5 - Copy.png";

    texture1w.loadFromFile(file1w);
    texture2w.loadFromFile(file2w);
    texture3w.loadFromFile(file3w);
    texture4w.loadFromFile(file4w);
    texture5w.loadFromFile(file5w);
    texture6w.loadFromFile(file6w);
    texture7w.loadFromFile(file7w);
    texture8w.loadFromFile(file8w);
    texture9w.loadFromFile(file9w);
    texture10w.loadFromFile(file10w);
    bool truefalse = true;
    int ok = 0;
    int randomNumber1 = 0, randomNumber2 = 0;
    if (apasat1 == 1);
    else {
        if (win1 == 0) {
            scoase1.setFillColor(sf::Color::Transparent);
        }
        if (win1 > 0) {
            scoase1.setFillColor(sf::Color::White);
            if (win1 == 1)
                scoase1.setTexture(&texture1w);
            if (win1 == 2)
                scoase1.setTexture(&texture2w);
            if (win1 == 3)
                scoase1.setTexture(&texture3w);
            if (win1 == 4)
                scoase1.setTexture(&texture4w);
            if (win1 == 5)
                scoase1.setTexture(&texture5w);
        }
    }
    if (apasat2 == 1);
    else {
        if (win2 == 0) {
            scoase2.setFillColor(sf::Color::Transparent);
        }
        if (win2 > 0) {
            scoase2.setFillColor(sf::Color::Black);
            if (win2 == 1)
                scoase2.setTexture(&texture6w);
            if (win2 == 2)
                scoase2.setTexture(&texture7w);
            if (win2 == 3)
                scoase2.setTexture(&texture8w);
            if (win2 == 4)
                scoase2.setTexture(&texture9w);
            if (win2 == 5)
                scoase2.setTexture(&texture10w);
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 12; j++) {
            if (mat[i][j] == 0) {
                container[i][j].setFillColor(sf::Color::Transparent);
            }
            else if (mat[i][j] > 0) {
                container[i][j].setFillColor(sf::Color::Black);
                if (i == 0) {
                    if (mat[i][j] == 1)
                        container[i][j].setTexture(&texture1w);
                    if (mat[i][j] == 2)
                        container[i][j].setTexture(&texture2w);
                    if (mat[i][j] == 3)
                        container[i][j].setTexture(&texture3w);
                    if (mat[i][j] == 4)
                        container[i][j].setTexture(&texture4w);
                    if (mat[i][j] >= 5)
                        container[i][j].setTexture(&texture5w);
                }
                if (i == 1) {
                    if (mat[i][j] == 1)
                        container[i][j].setTexture(&texture6w);
                    if (mat[i][j] == 2)
                        container[i][j].setTexture(&texture7w);
                    if (mat[i][j] == 3)
                        container[i][j].setTexture(&texture8w);
                    if (mat[i][j] == 4)
                        container[i][j].setTexture(&texture9w);
                    if (mat[i][j] >= 5)
                        container[i][j].setTexture(&texture10w);
                }
            }
            else if (mat[i][j] < 0) {
                container[i][j].setFillColor(sf::Color::White);
                if (i == 0) {
                    if (mat[i][j] == -1)
                        container[i][j].setTexture(&texture1w);
                    if (mat[i][j] == -2)
                        container[i][j].setTexture(&texture2w);
                    if (mat[i][j] == -3)
                        container[i][j].setTexture(&texture3w);
                    if (mat[i][j] == -4)
                        container[i][j].setTexture(&texture4w);
                    if (mat[i][j] <= -5)
                        container[i][j].setTexture(&texture5w);
                }
                if (i == 1) {
                    if (mat[i][j] == -1)
                        container[i][j].setTexture(&texture6w);
                    if (mat[i][j] == -2)
                        container[i][j].setTexture(&texture7w);
                    if (mat[i][j] == -3)
                        container[i][j].setTexture(&texture8w);
                    if (mat[i][j] == -4)
                        container[i][j].setTexture(&texture9w);
                    if (mat[i][j] <= -5)
                        container[i][j].setTexture(&texture10w);
                }
            }
        }
    }
    sf::Text numberText, numberText1,numberText2,numberText3;
    sf::Font font;
    if (scos1 >= 0) {
        font.loadFromFile("fonts/QUIGLEYW.TTF");
        numberText3.setFont(font);
        numberText3.setCharacterSize(48);
        numberText3.setFillColor(sf::Color::Red);
        numberText3.setString(std::to_string(scos1));
        numberText3.setPosition(player1_scos.getPosition().x + player1_scos.getSize().x / 2.f - numberText3.getLocalBounds().width / 2.f,
            player1_scos.getPosition().y + player1_scos.getSize().y / 2.f - numberText3.getLocalBounds().height / 2.f);
      //  numberText3.setOrigin(numberText3.getLocalBounds().width / 2.f, numberText3.getLocalBounds().height / 2.f);

    }
    if (scos2 >= 0) {
        font.loadFromFile("fonts/QUIGLEYW.TTF");
        numberText2.setFont(font);
        numberText2.setCharacterSize(48);
        numberText2.setFillColor(sf::Color::Red);
        numberText2.setString(std::to_string(scos2));
        numberText2.setPosition(player2_scos.getPosition().x + player2_scos.getSize().x / 2.f - numberText2.getLocalBounds().width / 2.f,
            player2_scos.getPosition().y + player2_scos.getSize().y / 2.f - numberText2.getLocalBounds().height / 2.f);
       // numberText2.setOrigin(numberText2.getLocalBounds().width / 2.f, numberText2.getLocalBounds().height / 2.f);

    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 12; j++) {
            if (mat[i][j] > 5) {
                font.loadFromFile("fonts/QUIGLEYW.TTF");
                numberText.setFont(font);
                numberText.setCharacterSize(48);
                numberText.setFillColor(sf::Color::Blue);
                numberText.setString(std::to_string(mat[i][j]));
                numberText.setPosition(container[i][j].getPosition().x + container[i][j].getSize().x / 2.f - numberText.getLocalBounds().width / 2.f,
                    container[i][j].getPosition().y + container[i][j].getSize().y / 2.f - numberText.getLocalBounds().height / 2.f);
            }
            if (mat[i][j] < -5) {
                font.loadFromFile("fonts/QUIGLEYW.TTF");
                numberText1.setFont(font);
                numberText1.setCharacterSize(48);
                numberText1.setFillColor(sf::Color::Blue);
                numberText1.setString(std::to_string(mat[i][j] * (-1)));
                numberText1.setPosition(container[i][j].getPosition().x + container[i][j].getSize().x / 2.f - numberText.getLocalBounds().width / 2.f,
                    container[i][j].getPosition().y + container[i][j].getSize().y / 2.f - numberText.getLocalBounds().height / 2.f);
            }
        }
    }
    while (window.isOpen())
    {
        sf::Event windowEvent;
        while (window.pollEvent(windowEvent))
        {
            if (windowEvent.type == sf::Event::Closed)
                window.close();
        }
        
        if (rollClock.getElapsedTime().asSeconds() > 2.0f)
        {
            dice1.setFillColor(sf::Color::White);
            dice2.setFillColor(sf::Color::White);
        }
        
        if (rollClock.getElapsedTime().asSeconds() > 1.90f && rollClock.getElapsedTime().asSeconds() < 2.10f && ok == 0)
        {
            if (ok == 0) {
                std::cout << "DA" << "\n";
                roll.setFillColor(sf::Color::Red);

                if (randomNumber1 == randomNumber2)
                    valid = 4;
                else
                    valid = 2;
                if (player == 0 && randomNumber1 != randomNumber2) {
                    if (randomNumber1 > randomNumber2)
                        player = 2;
                    else
                        player = 1;
                } // n-am idee de ce merge asa smh

                ok = 1;
                if (player == 1)
                    player = 2;
                else if (player == 2)
                    player = 1;
                ctr++;

                std::cout << player << "\n";
                std::cout << "scos1 = " << scos1 << "\n";
                std::cout << "scos2 = " << scos2 << "\n";
                contor = 0;
                if (player == 2) {
                    jucator.setFillColor(sf::Color::White);
                }
                else if (player == 1) {
                    jucator.setFillColor(sf::Color::Black);
                }
            }
        }

        if (contor == valid || player == 0) {
            roll.setFillColor(sf::Color::Red);
        }
        else if (contor != valid) {
            roll.setFillColor(sf::Color::White);
        }
        if (roll.getFillColor() == sf::Color::Red) {
            rollButtonRed = true;
        }
        else {
            rollButtonRed = false;
        }
        if (windowEvent.type == sf::Event::MouseButtonPressed && windowEvent.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            sf::Vector2f worldPosition = window.mapPixelToCoords(mousePosition);
            if (roll.getGlobalBounds().contains(worldPosition) && rollClock.getElapsedTime().asSeconds() > 1.90f)
            {
                randomNumber1 = distribution(mt);
                randomNumber2 = distribution(mt);
                roll.setFillColor(sf::Color::White);
                ok = 0;
                rollClock.restart();
                idleClock.restart();
            }
            else {
                roll.setFillColor(sf::Color::White);
                std::string filename1 = "texture/" + std::to_string(randomNumber1) + ".png";
                std::string filename2 = "texture/" + std::to_string(randomNumber2) + ".png";

                photo1.loadFromFile(filename1);
                photo2.loadFromFile(filename2);

                dice1.setTexture(&photo1);
                dice2.setTexture(&photo2);
            }
            if (rollClock.getElapsedTime().asSeconds() > 1.90f) {
                roll.setFillColor(sf::Color::White);
            }
            number_of_container = -1;
            csz = -1;
            apasat1 = 0;
            apasat2 = 0;
            truefalse = true;
            J = 0;
            if (!rollButtonRed) {
            label:
                if (scoase1.getGlobalBounds().contains(worldPosition))
                    apasat1 = 1;
                if (scoase2.getGlobalBounds().contains(worldPosition))
                    apasat2 = 1;
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 12; j++) {
                        if (container[i][j].getGlobalBounds().contains(worldPosition)) {
                            number_of_container = 12 * i + j; // Calculate the index corresponding to container[i][j]
                            oke = 0;
                            J = i;
                            v.push_back(number_of_container);
                            ochei = 0;
                            contorut = 0;
                            Z = 0;
                        }
                        frev[i][j] = 0;
                        if (player1_scos.getGlobalBounds().contains(worldPosition) && scos1 > 0)
                            csz = 1;
                        if (player2_scos.getGlobalBounds().contains(worldPosition) && scos2 > 0)
                            csz = 2;
                    }
                }
                int mut_i = -55, mut_j = -55;
                if (apasat1 == 1);
                else {
                    if (win1 == 0) {
                        scoase1.setFillColor(sf::Color::Transparent);
                    }
                    if (win1 > 0) {
                        scoase1.setFillColor(sf::Color::White);
                        if (win1 == 1)
                            scoase1.setTexture(&texture1w);
                        if (win1 == 2)
                            scoase1.setTexture(&texture2w);
                        if (win1 == 3)
                            scoase1.setTexture(&texture3w);
                        if (win1 == 4)
                            scoase1.setTexture(&texture4w);
                        if (win1 == 5)
                            scoase1.setTexture(&texture5w);
                    }
                }
                if (apasat2 == 1);
                else {
                    if (win2 == 0) {
                        scoase2.setFillColor(sf::Color::Transparent);
                    }
                    if (win2 > 0) {
                        scoase2.setFillColor(sf::Color::Black);
                        if (win2 == 1)
                            scoase2.setTexture(&texture6w);
                        if (win2 == 2)
                            scoase2.setTexture(&texture7w);
                        if (win2 == 3)
                            scoase2.setTexture(&texture8w);
                        if (win2 == 4)
                            scoase2.setTexture(&texture9w);
                        if (win2 == 5)
                            scoase2.setTexture(&texture10w);
                    }
                }
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 12; j++) {
                        if (mat[i][j] == 0 && container[number_of_container / 12][number_of_container % 12].getFillColor() != sf::Color::Yellow) {
                            container[i][j].setFillColor(sf::Color::Transparent);
                        }
                        else if (mat[i][j] > 0) {
                            if (i == number_of_container / 12 && j == number_of_container % 12);
                            else
                                container[i][j].setFillColor(sf::Color::Black);
                            if (i == 0) {
                                if (mat[i][j] == 1)
                                    container[i][j].setTexture(&texture1w);
                                if (mat[i][j] == 2)
                                    container[i][j].setTexture(&texture2w);
                                if (mat[i][j] == 3)
                                    container[i][j].setTexture(&texture3w);
                                if (mat[i][j] == 4)
                                    container[i][j].setTexture(&texture4w);
                                if (mat[i][j] == 5)
                                    container[i][j].setTexture(&texture5w);
                            }
                            if (i == 1) {
                                if (mat[i][j] == 1)
                                    container[i][j].setTexture(&texture6w);
                                if (mat[i][j] == 2)
                                    container[i][j].setTexture(&texture7w);
                                if (mat[i][j] == 3)
                                    container[i][j].setTexture(&texture8w);
                                if (mat[i][j] == 4)
                                    container[i][j].setTexture(&texture9w);
                                if (mat[i][j] == 5)
                                    container[i][j].setTexture(&texture10w);
                            }
                        }
                        else if (mat[i][j] < 0) {

                            if (i == number_of_container / 12 && j == number_of_container % 12);
                            else
                                container[i][j].setFillColor(sf::Color::White);
                            if (i == 0) {
                                if (mat[i][j] == -1)
                                    container[i][j].setTexture(&texture1w);
                                if (mat[i][j] == -2)
                                    container[i][j].setTexture(&texture2w);
                                if (mat[i][j] == -3)
                                    container[i][j].setTexture(&texture3w);
                                if (mat[i][j] == -4)
                                    container[i][j].setTexture(&texture4w);
                                if (mat[i][j] == -5)
                                    container[i][j].setTexture(&texture5w);
                            }
                            if (i == 1) {
                                if (mat[i][j] == -1)
                                    container[i][j].setTexture(&texture6w);
                                if (mat[i][j] == -2)
                                    container[i][j].setTexture(&texture7w);
                                if (mat[i][j] == -3)
                                    container[i][j].setTexture(&texture8w);
                                if (mat[i][j] == -4)
                                    container[i][j].setTexture(&texture9w);
                                if (mat[i][j] == -5)
                                    container[i][j].setTexture(&texture10w);
                            }
                        }
                    }
                }
                if (scos1 >= 0) {
                    font.loadFromFile("fonts/QUIGLEYW.TTF");
                    numberText3.setFont(font);
                    numberText3.setCharacterSize(48);
                    numberText3.setFillColor(sf::Color::Red);
                    numberText3.setString(std::to_string(scos1));
                    numberText3.setPosition(player1_scos.getPosition().x + player1_scos.getSize().x / 2.f - numberText3.getLocalBounds().width / 2.f,
                        player1_scos.getPosition().y + player1_scos.getSize().y / 2.f - numberText3.getLocalBounds().height / 2.f);
                }
                if (scos2 >= 0) {
                    font.loadFromFile("fonts/QUIGLEYW.TTF");
                    numberText2.setFont(font);
                    numberText2.setCharacterSize(48);
                    numberText2.setFillColor(sf::Color::Red);
                    numberText2.setString(std::to_string(scos2));
                    numberText2.setPosition(player2_scos.getPosition().x + player2_scos.getSize().x / 2.f - numberText2.getLocalBounds().width / 2.f,
                        player2_scos.getPosition().y + player2_scos.getSize().y / 2.f - numberText2.getLocalBounds().height / 2.f);
                }
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 12; j++) {
                        if (mat[i][j] > 5) {
                            font.loadFromFile("fonts/QUIGLEYW.TTF");
                            numberText.setFont(font);
                            numberText.setCharacterSize(48);
                            numberText.setFillColor(sf::Color::Blue);
                            numberText.setString(std::to_string(mat[i][j]));
                            numberText.setPosition(container[i][j].getPosition().x + container[i][j].getSize().x / 2.f - numberText.getLocalBounds().width / 2.f,
                                container[i][j].getPosition().y + container[i][j].getSize().y / 2.f - numberText.getLocalBounds().height / 2.f);
                        }
                        if (mat[i][j] < -5) {
                            font.loadFromFile("fonts/QUIGLEYW.TTF");
                            numberText1.setFont(font);
                            numberText1.setCharacterSize(48);
                            numberText1.setFillColor(sf::Color::Blue);
                            numberText1.setString(std::to_string(mat[i][j] * (-1)));
                            numberText1.setPosition(container[i][j].getPosition().x + container[i][j].getSize().x / 2.f - numberText.getLocalBounds().width / 2.f,
                                container[i][j].getPosition().y + container[i][j].getSize().y / 2.f - numberText.getLocalBounds().height / 2.f);
                        }
                    }
                }
                if (csz != -1) {
                    if (player == 1 && scos1 > 0) {
                        if (frv[0] == 0) {
                            if (mat[0][randomNumber1 - 1] >= -1) {
                                container[0][randomNumber1 - 1].setFillColor(sf::Color::Yellow);
                                truefalse = false;
                            }
                        }
                        if (frv[1] == 0) {
                            if (mat[0][randomNumber2 - 1] >= -1) {
                                container[0][randomNumber2 - 1].setFillColor(sf::Color::Yellow);
                                truefalse = false;
                            }
                        }
                    }
                    if (player == 2 && scos2 != 0) {
                        if (frv[0] == 0) {
                            if (mat[1][randomNumber1 - 1] <= 1) {
                                container[1][randomNumber1 - 1].setFillColor(sf::Color::Yellow);
                                truefalse = false;
                            }
                        }
                        if (frv[1] == 0) {
                            if (mat[1][randomNumber2 - 1] <= 1) {
                                container[1][randomNumber2 - 1].setFillColor(sf::Color::Yellow);
                                truefalse = false;
                            }
                        }
                    }
                    if (truefalse == true) {
                        contor = valid;
                    }
                }
                else {
                    if (container[number_of_container / 12][number_of_container % 12].getFillColor() != sf::Color::Yellow) {
                        if (player == 2 && scos2 == 0 && container[number_of_container / 12][number_of_container % 12].getFillColor() == sf::Color::White) {
                            int ok_white = 0;
                            for (int j = 6; j < 12; j++) {
                                if (mat[0][j] < 0)
                                    ok_white = 1;
                            }
                            for (int j = 0; j < 12; j++) {
                                if (mat[1][j] < 0)
                                    ok_white = 1;
                            }
                            if (ok_white == 0) {
                                int j = number_of_container % 12;
                                int ultima_piesa = 0;
                                for (int i = j + 1; i < 6; i++) {
                                    if (mat[0][i] < 0)
                                        ultima_piesa = 1;
                                }
                                if (ultima_piesa == 0 && randomNumber1 - 1 >= j && frv[0] == 0)
                                    scoase1.setFillColor(sf::Color::Yellow);
                                if (ultima_piesa == 0 && randomNumber2 - 1 >= j && frv[1] == 0)
                                    scoase1.setFillColor(sf::Color::Yellow);
                                if (randomNumber1 == j + 1 && frv[0] == 0)
                                    scoase1.setFillColor(sf::Color::Yellow);
                                if (randomNumber2 == j + 1 && frv[1] == 0)
                                    scoase1.setFillColor(sf::Color::Yellow);

                            }
                        }
                        if (player == 1 && scos1 == 0 && container[number_of_container / 12][number_of_container % 12].getFillColor() == sf::Color::Black) {
                            int ok_black = 0;
                            for (int j = 0; j < 12; j++) {
                                if (mat[0][j] > 0)
                                    ok_black = 1;
                            }
                            for (int j = 6; j < 12; j++) {
                                if (mat[1][j] > 0)
                                    ok_black = 1;
                            }
                            if (ok_black == 0) {
                                int j = number_of_container % 12;
                                int ultima_piesa = 0;
                                for (int i = j + 1; i < 6; i++) {
                                    if (mat[1][i] > 0)
                                        ultima_piesa = 1;
                                }
                                if (ultima_piesa == 0 && randomNumber1 - 1 >= j && frv[0] == 0)
                                    scoase2.setFillColor(sf::Color::Yellow);
                                if (ultima_piesa == 0 && randomNumber2 - 1 >= j && frv[1] == 0)
                                    scoase2.setFillColor(sf::Color::Yellow);
                                if (randomNumber1 == j + 1 && frv[0] == 0)
                                    scoase2.setFillColor(sf::Color::Yellow);
                                if (randomNumber2 == j + 1 && frv[1] == 0)
                                    scoase2.setFillColor(sf::Color::Yellow);

                            }
                        }
                        if (player == 1 && scos1 == 0) {
                            if (valid == 4)
                                frv[1] = 0, frv[0] = 0;
                            int j = number_of_container % 12;

                            if (mat[0][j] > 0 && J == 0) {
                                if (frv[0] == 0) {
                                    if (j + randomNumber1 > 11) {
                                        mut_j = 24 - (j + randomNumber1) - 1;
                                        mut_i = 1;
                                    }
                                    else {
                                        mut_j = j + randomNumber1;
                                        mut_i = 0;
                                    }
                                    if (mat[mut_i][mut_j] >= 0 || mat[mut_i][mut_j] == -1 && frv[0] == 0) {
                                        container[mut_i][mut_j].setFillColor(sf::Color::Yellow);
                                    }
                                }
                                if (frv[1] == 0) {
                                    if (j + randomNumber2 > 11) {
                                        mut_j = 24 - (j + randomNumber2) - 1;
                                        mut_i = 1;
                                    }
                                    else {
                                        mut_j = j + randomNumber2;
                                        mut_i = 0;
                                    }
                                    if (mat[mut_i][mut_j] >= 0 || mat[mut_i][mut_j] == -1 && frv[1] == 0) {
                                        container[mut_i][mut_j].setFillColor(sf::Color::Yellow);
                                    }
                                }
                            }
                            if (mat[1][j] > 0 && J == 1) {
                                mut_i = 1;
                                if (frv[0] == 0) {
                                    if (j - randomNumber1 >= 0) {
                                        mut_j = j - randomNumber1;
                                        mut_i = 1;
                                    }
                                    if (mut_i != -55 && mut_j != -55)
                                        if (mat[mut_i][mut_j] >= 0 || mat[mut_i][mut_j] == -1 && frv[0] == 0) {
                                            container[mut_i][mut_j].setFillColor(sf::Color::Yellow);
                                        }
                                }
                                if (frv[1] == 0) {
                                    if (j - randomNumber2 >= 0) {
                                        mut_j = j - randomNumber2;
                                        mut_i = 1;
                                    }
                                    if (mut_i != -55 && mut_j != -55)
                                        if (mat[mut_i][mut_j] >= 0 || mat[mut_i][mut_j] == -1 && frv[1] == 0) {
                                            container[mut_i][mut_j].setFillColor(sf::Color::Yellow);
                                        }
                                }
                            }
                        }
                        if (player == 2 && scos2 == 0) {
                            if (valid == 4)
                                frv[1] = 0, frv[0] = 0;
                            int j = number_of_container % 12;

                            if (mat[1][j] < 0 && J == 1) {
                                if (frv[0] == 0) {
                                    if (j + randomNumber1 > 11) {
                                        mut_j = 24 - (j + randomNumber1) - 1;
                                        mut_i = 0;
                                    }
                                    else {
                                        mut_j = j + randomNumber1;
                                        mut_i = 1;
                                    }
                                    if (mat[mut_i][mut_j] <= 0 || mat[mut_i][mut_j] == 1 && frv[0] == 0) {
                                        container[mut_i][mut_j].setFillColor(sf::Color::Yellow);
                                    }
                                }
                                if (frv[1] == 0) {
                                    if (j + randomNumber2 > 11) {
                                        mut_j = 24 - (j + randomNumber2) - 1;
                                        mut_i = 0;
                                    }
                                    else {
                                        mut_j = j + randomNumber2;
                                        mut_i = 1;
                                    }
                                    if (mat[mut_i][mut_j] <= 0 || mat[mut_i][mut_j] == 1 && frv[1] == 0) {
                                        container[mut_i][mut_j].setFillColor(sf::Color::Yellow);
                                    }
                                }
                            }

                            if (mat[0][j] < 0 && J == 0) {
                                mut_i = 0;
                                if (frv[0] == 0) {
                                    if (j - randomNumber1 >= 0) {
                                        mut_j = j - randomNumber1;
                                        mut_i = 0;
                                    }
                                    if (mut_i != -55 && mut_j != -55)
                                        if (mat[mut_i][mut_j] <= 0 || mat[mut_i][mut_j] == 1 && frv[0] == 0) {
                                            container[mut_i][mut_j].setFillColor(sf::Color::Yellow);
                                        }
                                }
                                if (frv[1] == 0) {
                                    if (j - randomNumber2 >= 0) {
                                        mut_j = j - randomNumber2;
                                        mut_i = 0;
                                    }
                                    if (mut_i != -55 && mut_j != -55)
                                        if (mat[mut_i][mut_j] <= 0 || mat[mut_i][mut_j] == 1 && frv[1] == 0) {
                                            container[mut_i][mut_j].setFillColor(sf::Color::Yellow);
                                        }
                                }
                            }
                        }
                    }
                }

            } 
        }
        if (container[number_of_container / 12][number_of_container % 12].getFillColor() == sf::Color::Yellow) {
            if (contor != valid) {
                if (number_of_container != 0) {
                    if (player == 1 && scos1 == 0) {
                        if (mat[number_of_container / 12][number_of_container % 12] == -1) {
                            mat[number_of_container / 12][number_of_container % 12] = 1;
                            scos2++;
                        }
                        else if (mat[number_of_container / 12][number_of_container % 12] >= 0)
                            mat[number_of_container / 12][number_of_container % 12]++;
                        mat[v[v.size() - 2] / 12][v[v.size() - 2] % 12]--;
                        container[number_of_container / 12][number_of_container % 12].setFillColor(sf::Color::Black);
                        test_x = v[v.size() - 2];
                        frev[number_of_container / 12][number_of_container % 12] = 1;
                        frev[test_x / 12][test_x % 12] = 1;
                        for (int i = 0; i < 2 && Z == 0; i++) {
                            if (i == 0) {
                                for (int j = 0; j < 12 && Z == 0; j++) {
                                    if (ochei == 1)
                                        contorut++;
                                    if (frev[i][j] == 1 && ochei == 1)
                                        Z = contorut;
                                    if (frev[i][j] == 1 && ochei == 0)
                                        ochei = 1;
                                }
                            }
                            if (i == 1) {
                                for (int j = 11; j >= 0 && Z == 0; j--) {
                                    if (ochei == 1)
                                        contorut++;
                                    if (frev[i][j] == 1 && ochei == 1)
                                        Z = contorut;
                                    if (frev[i][j] == 1 && ochei == 0)
                                        ochei = 1;
                                }
                            }
                        }
                        if (Z == randomNumber1)
                            frv[0] = 1;
                        if (Z == randomNumber2)
                            frv[1] = 1;
                        contor++;
                    }
                    if (player == 2 && scos2 == 0) {
                        if (mat[number_of_container / 12][number_of_container % 12] == 1) {
                            mat[number_of_container / 12][number_of_container % 12] = -1;
                            scos1++;
                        }
                        else if (mat[number_of_container / 12][number_of_container % 12] <= 0)
                            mat[number_of_container / 12][number_of_container % 12]--;
                        mat[v[v.size() - 2] / 12][v[v.size() - 2] % 12]++;
                        container[number_of_container / 12][number_of_container % 12].setFillColor(sf::Color::White);
                        test_x = v[v.size() - 2];
                        frev[number_of_container / 12][number_of_container % 12] = 1;
                        frev[test_x / 12][test_x % 12] = 1;
                        for (int i = 0; i < 2 && Z == 0; i++) {
                            if (i == 0) {
                                for (int j = 0; j < 12 && Z == 0; j++) {
                                    if (ochei == 1)
                                        contorut++;
                                    if (frev[i][j] == 1 && ochei == 1)
                                        Z = contorut;
                                    if (frev[i][j] == 1 && ochei == 0)
                                        ochei = 1;
                                }
                            }
                            if (i == 1) {
                                for (int j = 11; j >= 0 && Z == 0; j--) {
                                    if (ochei == 1)
                                        contorut++;
                                    if (frev[i][j] == 1 && ochei == 1)
                                        Z = contorut;
                                    if (frev[i][j] == 1 && ochei == 0)
                                        ochei = 1;
                                }
                            }
                        }
                        if (Z == randomNumber1)
                            frv[0] = 1;
                        if (Z == randomNumber2)
                            frv[1] = 1;
                        contor++;
                    }
                }
                else {
                    if (player == 1 && scos1 == 0) {
                        if (mat[number_of_container / 12][0] == -1) {
                            mat[number_of_container / 12][0] = 1;
                            scos2++;
                        }
                        else if (mat[number_of_container / 12][0] >= 0 && scos1 != 0)
                            mat[number_of_container / 12][0]++;
                        mat[v[v.size() - 2] / 12][v[v.size() - 2] % 12]--;
                        container[number_of_container / 12][number_of_container % 12].setFillColor(sf::Color::Black);
                        test_x = v[v.size() - 2];
                        frev[number_of_container / 12][number_of_container % 12] = 1;
                        frev[test_x / 12][test_x % 12] = 1;
                        for (int i = 0; i < 2 && Z == 0; i++) {
                            if (i == 0) {
                                for (int j = 0; j < 12 && Z == 0; j++) {
                                    if (ochei == 1)
                                        contorut++;
                                    if (frev[i][j] == 1 && ochei == 1)
                                        Z = contorut;
                                    if (frev[i][j] == 1 && ochei == 0)
                                        ochei = 1;
                                }
                            }
                            if (i == 1) {
                                for (int j = 11; j >= 0 && Z == 0; j--) {
                                    if (ochei == 1)
                                        contorut++;
                                    if (frev[i][j] == 1 && ochei == 1)
                                        Z = contorut;
                                    if (frev[i][j] == 1 && ochei == 0)
                                        ochei = 1;
                                }
                            }
                        }
                        if (Z == randomNumber1)
                            frv[0] = 1;
                        if (Z == randomNumber2)
                            frv[1] = 1;
                        contor++;
                    }
                    if (player == 2 && scos2 == 0) {
                        if (mat[number_of_container / 12][0] == 1) {
                            mat[number_of_container / 12][0] = -1;
                            scos1++;
                        }
                        else if (mat[number_of_container / 12][0] <= 0)
                            mat[number_of_container / 12][0]--;
                        mat[v[v.size() - 2] / 12][v[v.size() - 2] % 12]++;
                        container[number_of_container / 12][number_of_container % 12].setFillColor(sf::Color::White);
                        test_x = v[v.size() - 2];
                        frev[number_of_container / 12][number_of_container % 12] = 1;
                        frev[test_x / 12][test_x % 12] = 1;

                        for (int i = 0; i < 2 && Z == 0; i++) {
                            if (i == 0) {
                                for (int j = 0; j < 12 && Z == 0; j++) {
                                    if (ochei == 1)
                                        contorut++;
                                    if (frev[i][j] == 1 && ochei == 1)
                                        Z = contorut;
                                    if (frev[i][j] == 1 && ochei == 0)
                                        ochei = 1;
                                }
                            }
                            if (i == 1) {
                                for (int j = 11; j >= 0 && Z == 0; j--) {
                                    if (ochei == 1)
                                        contorut++;
                                    if (frev[i][j] == 1 && ochei == 1)
                                        Z = contorut;
                                    if (frev[i][j] == 1 && ochei == 0)
                                        ochei = 1;
                                }
                            }
                        }
                        if (Z == randomNumber1)
                            frv[0] = 1;
                        if (Z == randomNumber2)
                            frv[1] = 1;
                        contor++;
                    }
                }
                if (player == 1 && scos1 != 0) {
                    int Ja = 0;
                    if (number_of_container == 0)
                        Ja = 0;
                    else
                        Ja = number_of_container % 12;
                    if (mat[0][Ja] >= 0)
                        mat[0][Ja]++;
                    if (mat[0][Ja] == -1) {
                        mat[0][Ja] = 1;
                        scos2++;
                    }
                    if (Ja == randomNumber1 - 1)
                        frv[0] = 1;
                    if (Ja == randomNumber2 - 1)
                        frv[1] = 1;
                    contor++;
                    scos1--;
                    container[0][Ja].setFillColor(sf::Color::Black);
                }
                if (player == 2 && scos2 != 0) {
                    int Ja = 0;
                    if (number_of_container == 0)
                        Ja = 0;
                    else
                        Ja = number_of_container % 12;
                    if (mat[1][Ja] <= 0)
                        mat[1][Ja]--;
                    if (mat[1][Ja] == 1) {
                        mat[1][Ja] = -1;
                        scos1++;
                    }
                    if (Ja == randomNumber1 - 1)
                        frv[0] = 1;
                    if (Ja == randomNumber2 - 1)
                        frv[1] = 1;
                    contor++;
                    scos2--;
                    container[1][Ja].setFillColor(sf::Color::White);
                }
            }
        }
        if (scoase1.getFillColor() == sf::Color::Yellow){
            if (apasat1 == 1) {
                contor++;
                win1++;
                mat[0][v[v.size() - 2] % 12]++;
                if (win1 > 0) {
                    scoase1.setFillColor(sf::Color::White);
                    if (win1 == 1)
                        scoase1.setTexture(&texture1w);
                    if (win1 == 2)
                        scoase1.setTexture(&texture2w);
                    if (win1 == 3)
                        scoase1.setTexture(&texture3w);
                    if (win1 == 4)
                        scoase1.setTexture(&texture4w);
                    if (win1 == 5)
                        scoase1.setTexture(&texture5w);
                }
            }
        }
        if (scoase2.getFillColor() == sf::Color::Yellow) {
            if (apasat2 == 1) {
                contor++;
                win2++;
                mat[1][v[v.size() - 2] % 12]--;
                if (win2 > 0) {
                    scoase2.setFillColor(sf::Color::Black);
                    if (win2 == 1)
                        scoase2.setTexture(&texture6w);
                    if (win2 == 2)
                        scoase2.setTexture(&texture7w);
                    if (win2 == 3)
                        scoase2.setTexture(&texture8w);
                    if (win2 == 4)
                        scoase2.setTexture(&texture9w);
                    if (win2 == 5)
                        scoase2.setTexture(&texture10w);
                }
            }
        }
        if (contor == valid) {
            frv[0] = 0;
            frv[1] = 0;
            if (apasat1 == 1);
            else {
                if (win1 == 0) {
                    scoase1.setFillColor(sf::Color::Transparent);
                }
                if (win1 > 0) {
                    scoase1.setFillColor(sf::Color::White);
                    if (win1 == 1)
                        scoase1.setTexture(&texture1w);
                    if (win1 == 2)
                        scoase1.setTexture(&texture2w);
                    if (win1 == 3)
                        scoase1.setTexture(&texture3w);
                    if (win1 == 4)
                        scoase1.setTexture(&texture4w);
                    if (win1 == 5)
                        scoase1.setTexture(&texture5w);
                }
            }
            if (apasat2 == 1);
            else {
                if (win2 == 0) {
                    scoase2.setFillColor(sf::Color::Transparent);
                }
                if (win2 > 0) {
                    scoase2.setFillColor(sf::Color::Black);
                    if (win2 == 1)
                        scoase2.setTexture(&texture6w);
                    if (win2 == 2)
                        scoase2.setTexture(&texture7w);
                    if (win2 == 3)
                        scoase2.setTexture(&texture8w);
                    if (win2 == 4)
                        scoase2.setTexture(&texture9w);
                    if (win2 == 5)
                        scoase2.setTexture(&texture10w);
                }
            }
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 12; j++) {
                    if (mat[i][j] == 0 && container[number_of_container / 12][number_of_container % 12].getFillColor() != sf::Color::Yellow) {
                        container[i][j].setFillColor(sf::Color::Transparent);
                    }
                    else if (mat[i][j] > 0) {
                        if (i == number_of_container / 12 && j == number_of_container % 12);
                        else
                            container[i][j].setFillColor(sf::Color::Black);
                        if (i == 0) {
                            if (mat[i][j] == 1)
                                container[i][j].setTexture(&texture1w);
                            if (mat[i][j] == 2)
                                container[i][j].setTexture(&texture2w);
                            if (mat[i][j] == 3)
                                container[i][j].setTexture(&texture3w);
                            if (mat[i][j] == 4)
                                container[i][j].setTexture(&texture4w);
                            if (mat[i][j] == 5)
                                container[i][j].setTexture(&texture5w);
                        }
                        if (i == 1) {
                            if (mat[i][j] == 1)
                                container[i][j].setTexture(&texture6w);
                            if (mat[i][j] == 2)
                                container[i][j].setTexture(&texture7w);
                            if (mat[i][j] == 3)
                                container[i][j].setTexture(&texture8w);
                            if (mat[i][j] == 4)
                                container[i][j].setTexture(&texture9w);
                            if (mat[i][j] == 5)
                                container[i][j].setTexture(&texture10w);
                        }
                    }
                    else if (mat[i][j] < 0) {

                        if (i == number_of_container / 12 && j == number_of_container % 12);
                        else
                            container[i][j].setFillColor(sf::Color::White);
                        if (i == 0) {
                            if (mat[i][j] == -1)
                                container[i][j].setTexture(&texture1w);
                            if (mat[i][j] == -2)
                                container[i][j].setTexture(&texture2w);
                            if (mat[i][j] == -3)
                                container[i][j].setTexture(&texture3w);
                            if (mat[i][j] == -4)
                                container[i][j].setTexture(&texture4w);
                            if (mat[i][j] == -5)
                                container[i][j].setTexture(&texture5w);
                        }
                        if (i == 1) {
                            if (mat[i][j] == -1)
                                container[i][j].setTexture(&texture6w);
                            if (mat[i][j] == -2)
                                container[i][j].setTexture(&texture7w);
                            if (mat[i][j] == -3)
                                container[i][j].setTexture(&texture8w);
                            if (mat[i][j] == -4)
                                container[i][j].setTexture(&texture9w);
                            if (mat[i][j] == -5)
                                container[i][j].setTexture(&texture10w);

                        }
                    }
                }
            }
            if (scos1 >= 0) {
                font.loadFromFile("fonts/QUIGLEYW.TTF");
                numberText3.setFont(font);
                numberText3.setCharacterSize(48);
                numberText3.setFillColor(sf::Color::Red);
                numberText3.setString(std::to_string(scos1));
                numberText3.setPosition(player1_scos.getPosition().x + player1_scos.getSize().x / 2.f - numberText3.getLocalBounds().width / 2.f,
                    player1_scos.getPosition().y + player1_scos.getSize().y / 2.f - numberText3.getLocalBounds().height / 2.f);
            }
            if (scos2 >= 0) {
                font.loadFromFile("fonts/QUIGLEYW.TTF");
                numberText2.setFont(font);
                numberText2.setCharacterSize(48);
                numberText2.setFillColor(sf::Color::Red);
                numberText2.setString(std::to_string(scos2));
                numberText2.setPosition(player2_scos.getPosition().x + player2_scos.getSize().x / 2.f - numberText2.getLocalBounds().width / 2.f,
                    player2_scos.getPosition().y + player2_scos.getSize().y / 2.f - numberText2.getLocalBounds().height / 2.f);
                
            }
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 12; j++) {
                    if (mat[i][j] > 5) {
                        font.loadFromFile("fonts/QUIGLEYW.TTF");
                        numberText.setFont(font);
                        numberText.setCharacterSize(48);
                        numberText.setFillColor(sf::Color::Blue);
                        numberText.setString(std::to_string(mat[i][j]));
                        numberText.setPosition(container[i][j].getPosition().x + container[i][j].getSize().x / 2.f - numberText.getLocalBounds().width / 2.f,
                            container[i][j].getPosition().y + container[i][j].getSize().y / 2.f - numberText.getLocalBounds().height / 2.f);
                    }
                    if (mat[i][j] < -5) {
                        font.loadFromFile("fonts/QUIGLEYW.TTF");
                        numberText1.setFont(font);
                        numberText1.setCharacterSize(48);
                        numberText1.setFillColor(sf::Color::Blue);
                        numberText1.setString(std::to_string(mat[i][j] * (-1)));
                        numberText1.setPosition(container[i][j].getPosition().x + container[i][j].getSize().x / 2.f - numberText.getLocalBounds().width / 2.f,
                            container[i][j].getPosition().y + container[i][j].getSize().y / 2.f - numberText.getLocalBounds().height / 2.f);
                    }
                }
            }
        }
        window.clear(sf::Color::White);
        window.draw(s);

        x = 72.0f;
        for (int i = 0; i < 6; ++i) {
            container[0][i].setPosition(x, y);
            window.draw(container[0][i]);
            container[1][i].setPosition(x, y + 360);
            window.draw(container[1][i]);
            x += 64.0f;
        }
        x = 490.0f;
        for (int i = 6; i < 12; ++i) {
            container[0][i].setPosition(x, y);
            window.draw(container[0][i]);
            container[1][i].setPosition(x, y + 360);
            window.draw(container[1][i]);
            x += 64.0f;
        }
        scoase1.setPosition(10.0f, 25.0f);
        scoase2.setPosition(10.0f, 385.0f);

        roll.setPosition(500.0f, 300.0f);
        dice1.setPosition(700.0f, 300.0f);
        dice2.setPosition(800.0f, 300.0f);

        jucator.setPosition(450.0f, 300.0f);
        player1_scos.setPosition(460.0f, 25.0f);
        player2_scos.setPosition(460.0f,630.0f); //capatos

        window.draw(scoase1);
        window.draw(scoase2);
        window.draw(jucator);
        window.draw(player1_scos);
        window.draw(player2_scos);
        window.draw(roll);
        window.draw(dice1);
        window.draw(dice2);
        window.draw(numberText);
        window.draw(numberText1);
        window.draw(numberText2);
        window.draw(numberText3);

        window.display();
    }

    return 0;
}