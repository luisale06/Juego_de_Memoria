#include <SFML/Graphics.hpp>
#include <winsock2.h>
#include <windows.h>
#include <iostream>

/**
 * Client program. Generates the GUI for the players, and follows the Server messages to maintain the order in the board.
 * @author Luis Alejandro Barreda Acevedo
 */

using namespace sf;
using namespace std;

/**
 * Main function. Initializes the socket with the IP address and specific port, keeps the socket information in a char array[],
 * sends the information to the server with the positions of the cards in the list, creates the images of the cards that are being selected,
 * and mark with a different image the cards that matched
 * @return
 */
int main()
{
    string nameP1, nameP2;
    cout << "Enter the name of player 1: " << endl;
    cin >> nameP1;
    cout << "Enter the name of player 2: " << endl;
    cin >> nameP2;
    RenderWindow window(VideoMode(1000, 800), "Juego de Memoria", Style:: Close);
    Font font;
    font.loadFromFile("E:/TEC/Datos 2/Proyecto 1/Fonts/HartoneSofted.ttf");
    int selected_card_pos[2];
    int selected_cards = 0;
    string zero = "0", one = "1", two = "2", three = "3", four = "4", types[2];
    vector<int> matches = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                           0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                           0, 0, 0, 0, 0, 0, 0, 0, 0};

    Texture textureB;
    Sprite imageB;
    if (!textureB.loadFromFile("Photos//Black.jpeg"))
    {
        cout << "Could not load Black Card" << endl;
    }
    imageB.setTexture(textureB);

    Text title;
    title.setFont(font);
    title.setCharacterSize(75);
    title.setOutlineColor(Color::Red);
    title.setString("Juego de Memoria");
    title.setPosition(90.f, 1.f);


    Text Player1Name;
    Player1Name.setFont(font);
    Player1Name.setCharacterSize(50);
    Player1Name.setOutlineColor(Color::Red);
    Player1Name.setString("Player 1: " + nameP1);
    Player1Name.setPosition(650.f, 100.f);

    Text Player2Name;
    Player2Name.setFont(font);
    Player2Name.setCharacterSize(50);
    Player2Name.setOutlineColor(Color::Red);
    Player2Name.setString("Player 2: " + nameP2);
    Player2Name.setPosition(650.f, 200.f);

    RectangleShape square0;
    RectangleShape square1;
    RectangleShape square2;
    RectangleShape square3;
    RectangleShape square4;
    RectangleShape square5;
    RectangleShape square6;
    RectangleShape square7;
    RectangleShape square8;
    RectangleShape square9;
    RectangleShape square10;
    RectangleShape square11;
    RectangleShape square12;
    RectangleShape square13;
    RectangleShape square14;
    RectangleShape square15;
    RectangleShape square16;
    RectangleShape square17;
    RectangleShape square18;
    RectangleShape square19;
    RectangleShape square20;
    RectangleShape square21;
    RectangleShape square22;
    RectangleShape square23;
    RectangleShape square24;
    RectangleShape square25;
    RectangleShape square26;
    RectangleShape square27;
    RectangleShape square28;
    RectangleShape square29;

    square0.setSize(Vector2f(70, 70));
    square1.setSize(Vector2f(70, 70));
    square2.setSize(Vector2f(70, 70));
    square3.setSize(Vector2f(70, 70));
    square4.setSize(Vector2f(70, 70));
    square5.setSize(Vector2f(70, 70));
    square6.setSize(Vector2f(70, 70));
    square7.setSize(Vector2f(70, 70));
    square8.setSize(Vector2f(70, 70));
    square9.setSize(Vector2f(70, 70));
    square10.setSize(Vector2f(70, 70));
    square11.setSize(Vector2f(70,70));
    square12.setSize(Vector2f(70, 70));
    square13.setSize(Vector2f(70, 70));
    square14.setSize(Vector2f(70, 70));
    square15.setSize(Vector2f(70, 70));
    square16.setSize(Vector2f(70, 70));
    square17.setSize(Vector2f(70, 70));
    square18.setSize(Vector2f(70, 70));
    square19.setSize(Vector2f(70, 70));
    square20.setSize(Vector2f(70, 70));
    square21.setSize(Vector2f(70, 70));
    square22.setSize(Vector2f(70, 70));
    square23.setSize(Vector2f(70, 70));
    square24.setSize(Vector2f(70, 70));
    square25.setSize(Vector2f(70, 70));
    square26.setSize(Vector2f(70, 70));
    square27.setSize(Vector2f(70, 70));
    square28.setSize(Vector2f(70, 70));
    square29.setSize(Vector2f(70, 70));

    square0.setPosition(50.f, 100.f);
    square0.setFillColor(Color::White);
    square1.setPosition(150.f, 100.f);
    square1.setFillColor(Color::White);
    square2.setPosition(250.f, 100.f);
    square2.setFillColor(Color::White);
    square3.setPosition(350.f, 100.f);
    square3.setFillColor(Color::White);
    square4.setPosition(450.f, 100.f);
    square4.setFillColor(Color::White);
    square5.setPosition(550.f, 100.f);
    square5.setFillColor(Color::White);
    square6.setPosition(50.f, 200.f);
    square6.setFillColor(Color::White);
    square7.setPosition(150.f, 200.f);
    square7.setFillColor(Color::White);
    square8.setPosition(250.f, 200.f);
    square8.setFillColor(Color::White);
    square9.setPosition(350.f, 200.f);
    square9.setFillColor(Color::White);
    square10.setPosition(450.f, 200.f);
    square10.setFillColor(Color::White);
    square11.setPosition(550.f, 200.f);
    square11.setFillColor(Color::White);
    square12.setPosition(50.f, 300.f);
    square12.setFillColor(Color::White);
    square13.setPosition(150.f, 300.f);
    square13.setFillColor(Color::White);
    square14.setPosition(250.f, 300.f);
    square14.setFillColor(Color::White);
    square15.setPosition(350.f, 300.f);
    square15.setFillColor(Color::White);
    square16.setPosition(450.f, 300.f);
    square16.setFillColor(Color::White);
    square17.setPosition(550.f, 300.f);
    square17.setFillColor(Color::White);
    square18.setPosition(50.f, 400.f);
    square18.setFillColor(Color::White);
    square19.setPosition(150.f, 400.f);
    square19.setFillColor(Color::White);
    square20.setPosition(250.f, 400.f);
    square20.setFillColor(Color::White);
    square21.setPosition(350.f, 400.f);
    square21.setFillColor(Color::White);
    square22.setPosition(450.f, 400.f);
    square22.setFillColor(Color::White);
    square23.setPosition(550.f, 400.f);
    square23.setFillColor(Color::White);
    square24.setPosition(50.f, 500.f);
    square24.setFillColor(Color::White);
    square25.setPosition(150.f, 500.f);
    square25.setFillColor(Color::White);
    square26.setPosition(250.f, 500.f);
    square26.setFillColor(Color::White);
    square27.setPosition(350.f, 500.f);
    square27.setFillColor(Color::White);
    square28.setPosition(450.f, 500.f);
    square28.setFillColor(Color::White);
    square29.setPosition(550.f, 500.f);
    square29.setFillColor(Color::White);

    float square0x = square0.getGlobalBounds().left;
    float square0y = square0.getGlobalBounds().top;
    float square1x = square1.getGlobalBounds().left;
    float square1y = square1.getGlobalBounds().top;
    float square2x = square2.getGlobalBounds().left;
    float square2y = square2.getGlobalBounds().top;
    float square3x = square3.getGlobalBounds().left;
    float square3y = square3.getGlobalBounds().top;
    float square4x = square4.getGlobalBounds().left;
    float square4y = square4.getGlobalBounds().top;
    float square5x = square5.getGlobalBounds().left;
    float square5y = square5.getGlobalBounds().top;
    float square6x = square6.getGlobalBounds().left;
    float square6y = square6.getGlobalBounds().top;
    float square7x = square7.getGlobalBounds().left;
    float square7y = square7.getGlobalBounds().top;
    float square8x = square8.getGlobalBounds().left;
    float square8y = square8.getGlobalBounds().top;
    float square9x = square9.getGlobalBounds().left;
    float square9y = square9.getGlobalBounds().top;
    float square10x = square10.getGlobalBounds().left;
    float square10y = square10.getGlobalBounds().top;
    float square11x = square11.getGlobalBounds().left;
    float square11y = square11.getGlobalBounds().top;
    float square12x = square12.getGlobalBounds().left;
    float square12y = square12.getGlobalBounds().top;
    float square13x = square13.getGlobalBounds().left;
    float square13y = square13.getGlobalBounds().top;
    float square14x = square14.getGlobalBounds().left;
    float square14y = square14.getGlobalBounds().top;
    float square15x = square15.getGlobalBounds().left;
    float square15y = square15.getGlobalBounds().top;
    float square16x = square16.getGlobalBounds().left;
    float square16y = square16.getGlobalBounds().top;
    float square17x = square17.getGlobalBounds().left;
    float square17y = square17.getGlobalBounds().top;
    float square18x = square18.getGlobalBounds().left;
    float square18y = square18.getGlobalBounds().top;
    float square19x = square19.getGlobalBounds().left;
    float square19y = square19.getGlobalBounds().top;
    float square20x = square20.getGlobalBounds().left;
    float square20y = square20.getGlobalBounds().top;
    float square21x = square21.getGlobalBounds().left;
    float square21y = square21.getGlobalBounds().top;
    float square22x = square22.getGlobalBounds().left;
    float square22y = square22.getGlobalBounds().top;
    float square23x = square23.getGlobalBounds().left;
    float square23y = square23.getGlobalBounds().top;
    float square24x = square24.getGlobalBounds().left;
    float square24y = square24.getGlobalBounds().top;
    float square25x = square25.getGlobalBounds().left;
    float square25y = square25.getGlobalBounds().top;
    float square26x = square26.getGlobalBounds().left;
    float square26y = square26.getGlobalBounds().top;
    float square27x = square27.getGlobalBounds().left;
    float square27y = square27.getGlobalBounds().top;
    float square28x = square28.getGlobalBounds().left;
    float square28y = square28.getGlobalBounds().top;
    float square29x = square29.getGlobalBounds().left;
    float square29y = square29.getGlobalBounds().top;

    RectangleShape cards_list[30] = { square0,  square1,   square2,   square3,   square4,  square5,
                                      square6,  square7,   square8,   square9,  square10, square11,
                                      square12, square13, square14, square15, square16, square17,
                                      square18, square19, square20, square21, square22, square23,
                                      square24, square25, square26, square27, square28, square29};

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if (GetAsyncKeyState(VK_LBUTTON))
        {
            const Vector2i &vector_pos_mouse = Mouse::getPosition(window);
            float mouse_x = vector_pos_mouse.x, mouse_y = vector_pos_mouse.y;

            if ((mouse_x >= square0x && mouse_x <=  square0x + 70) && (mouse_y >= square0y && mouse_y <=  square0y + 70))
            {
                selected_cards++;
                selected_card_pos[selected_cards - 1] = 0;
                cout << selected_card_pos[selected_cards - 1] << endl;

                if (selected_cards == 2)
                {
                    WSADATA WSAData;
                    SOCKET server;
                    SOCKADDR_IN addr;
                    char buffer[200000];

                    WSAStartup(MAKEWORD(2,0), &WSAData);
                    server = socket(AF_INET, SOCK_STREAM, 0);
                    addr.sin_addr.s_addr = inet_addr("192.168.100.108");
                    addr.sin_family = AF_INET;
                    addr.sin_port = htons(5001);
                    connect(server, (SOCKADDR *)&addr, sizeof(addr));

                    for (int i = 0; i <= sizeof(selected_card_pos); i++)
                    {
                        buffer[i] = selected_card_pos[i];
                    }
                    send(server, buffer, sizeof(buffer), 0);
                    memset(buffer, 0, sizeof(buffer));

                    recv(server, buffer, sizeof(buffer), 0);
                    if (buffer[2] == one[0])
                    {
                        cout << "Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                        matches[selected_card_pos[0]] = 1;
                        matches[selected_card_pos[1]] = 1;
                    }
                    else if (buffer[2] == zero[0])
                    {
                        cout << "Not Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                    }
                    memset(buffer, 0, sizeof(buffer));

                    closesocket(server);
                    WSACleanup();
                    cout << "Socket closed." << endl << endl;

                    selected_cards = 0;
                }
            }

            else if ((mouse_x >= square1x && mouse_x <=  square1x + 70) && (mouse_y >= square1y && mouse_y <=  square1y + 70))
            {
                selected_cards++;
                selected_card_pos[selected_cards - 1] = 1;
                cout << selected_card_pos[selected_cards - 1] << endl;

                if (selected_cards == 2)
                {
                    WSADATA WSAData;
                    SOCKET server;
                    SOCKADDR_IN addr;
                    char buffer[200000];

                    WSAStartup(MAKEWORD(2,0), &WSAData);
                    server = socket(AF_INET, SOCK_STREAM, 0);
                    addr.sin_addr.s_addr = inet_addr("192.168.100.108");
                    addr.sin_family = AF_INET;
                    addr.sin_port = htons(5001);
                    connect(server, (SOCKADDR *)&addr, sizeof(addr));

                    for (int i = 0; i <= sizeof(selected_card_pos); i++)
                    {
                        buffer[i] = selected_card_pos[i];
                    }
                    send(server, buffer, sizeof(buffer), 0);
                    memset(buffer, 0, sizeof(buffer));

                    recv(server, buffer, sizeof(buffer), 0);
                    if (buffer[2] == one[0])
                    {
                        cout << "Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                        matches[selected_card_pos[0]] = 1;
                        matches[selected_card_pos[1]] = 1;
                    }
                    else if (buffer[2] == zero[0])
                    {
                        cout << "Not Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                    }
                    memset(buffer, 0, sizeof(buffer));

                    closesocket(server);
                    WSACleanup();
                    cout << "Socket closed." << endl << endl;

                    selected_cards = 0;
                }
            }

            else if ((mouse_x >= square2x && mouse_x <=  square2x + 70) && (mouse_y >= square2y && mouse_y <=  square2y + 70))
            {
                selected_cards++;
                selected_card_pos[selected_cards - 1] = 2;
                cout << selected_card_pos[selected_cards - 1] << endl;

                if (selected_cards == 2)
                {
                    WSADATA WSAData;
                    SOCKET server;
                    SOCKADDR_IN addr;
                    char buffer[200000];

                    WSAStartup(MAKEWORD(2,0), &WSAData);
                    server = socket(AF_INET, SOCK_STREAM, 0);
                    addr.sin_addr.s_addr = inet_addr("192.168.100.108");
                    addr.sin_family = AF_INET;
                    addr.sin_port = htons(5001);
                    connect(server, (SOCKADDR *)&addr, sizeof(addr));

                    for (int i = 0; i <= sizeof(selected_card_pos); i++)
                    {
                        buffer[i] = selected_card_pos[i];
                    }
                    send(server, buffer, sizeof(buffer), 0);
                    memset(buffer, 0, sizeof(buffer));

                    recv(server, buffer, sizeof(buffer), 0);
                    if (buffer[2] == one[0])
                    {
                        cout << "Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                        matches[selected_card_pos[0]] = 1;
                        matches[selected_card_pos[1]] = 1;
                    }
                    else if (buffer[2] == zero[0])
                    {
                        cout << "Not Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                    }
                    memset(buffer, 0, sizeof(buffer));

                    closesocket(server);
                    WSACleanup();
                    cout << "Socket closed." << endl << endl;

                    selected_cards = 0;
                }
            }

            else if ((mouse_x >= square3x && mouse_x <=  square3x + 70) && (mouse_y >= square3y && mouse_y <=  square3y + 70))
            {
                selected_cards++;
                selected_card_pos[selected_cards - 1] = 3;
                cout << selected_card_pos[selected_cards - 1] << endl;

                if (selected_cards == 2)
                {
                    WSADATA WSAData;
                    SOCKET server;
                    SOCKADDR_IN addr;
                    char buffer[200000];

                    WSAStartup(MAKEWORD(2,0), &WSAData);
                    server = socket(AF_INET, SOCK_STREAM, 0);
                    addr.sin_addr.s_addr = inet_addr("192.168.100.108");
                    addr.sin_family = AF_INET;
                    addr.sin_port = htons(5001);
                    connect(server, (SOCKADDR *)&addr, sizeof(addr));

                    for (int i = 0; i <= sizeof(selected_card_pos); i++)
                    {
                        buffer[i] = selected_card_pos[i];
                    }
                    send(server, buffer, sizeof(buffer), 0);
                    memset(buffer, 0, sizeof(buffer));

                    recv(server, buffer, sizeof(buffer), 0);
                    if (buffer[2] == one[0])
                    {
                        cout << "Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                        matches[selected_card_pos[0]] = 1;
                        matches[selected_card_pos[1]] = 1;
                    }
                    else if (buffer[2] == zero[0])
                    {
                        cout << "Not Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                    }
                    memset(buffer, 0, sizeof(buffer));

                    closesocket(server);
                    WSACleanup();
                    cout << "Socket closed." << endl << endl;

                    selected_cards = 0;
                }
            }

            else if ((mouse_x >= square4x && mouse_x <=  square4x + 70) && (mouse_y >= square4y && mouse_y <=  square4y + 70))
            {
                selected_cards++;
                selected_card_pos[selected_cards - 1] = 4;
                cout << selected_card_pos[selected_cards - 1] << endl;

                if (selected_cards == 2)
                {
                    WSADATA WSAData;
                    SOCKET server;
                    SOCKADDR_IN addr;
                    char buffer[200000];

                    WSAStartup(MAKEWORD(2,0), &WSAData);
                    server = socket(AF_INET, SOCK_STREAM, 0);
                    addr.sin_addr.s_addr = inet_addr("192.168.100.108");
                    addr.sin_family = AF_INET;
                    addr.sin_port = htons(5001);
                    connect(server, (SOCKADDR *)&addr, sizeof(addr));

                    for (int i = 0; i <= sizeof(selected_card_pos); i++)
                    {
                        buffer[i] = selected_card_pos[i];
                    }
                    send(server, buffer, sizeof(buffer), 0);
                    memset(buffer, 0, sizeof(buffer));

                    recv(server, buffer, sizeof(buffer), 0);
                    if (buffer[2] == one[0])
                    {
                        cout << "Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                        matches[selected_card_pos[0]] = 1;
                        matches[selected_card_pos[1]] = 1;
                    }
                    else if (buffer[2] == zero[0])
                    {
                        cout << "Not Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                    }
                    memset(buffer, 0, sizeof(buffer));

                    closesocket(server);
                    WSACleanup();
                    cout << "Socket closed." << endl << endl;

                    selected_cards = 0;
                }
            }

            else if ((mouse_x >= square5x && mouse_x <=  square5x + 70) && (mouse_y >= square5y && mouse_y <=  square5y + 70))
            {
                selected_cards++;
                selected_card_pos[selected_cards - 1] = 5;
                cout << selected_card_pos[selected_cards - 1] << endl;

                if (selected_cards == 2)
                {
                    WSADATA WSAData;
                    SOCKET server;
                    SOCKADDR_IN addr;
                    char buffer[200000];

                    WSAStartup(MAKEWORD(2,0), &WSAData);
                    server = socket(AF_INET, SOCK_STREAM, 0);
                    addr.sin_addr.s_addr = inet_addr("192.168.100.108");
                    addr.sin_family = AF_INET;
                    addr.sin_port = htons(5001);
                    connect(server, (SOCKADDR *)&addr, sizeof(addr));

                    for (int i = 0; i <= sizeof(selected_card_pos); i++)
                    {
                        buffer[i] = selected_card_pos[i];
                    }
                    send(server, buffer, sizeof(buffer), 0);
                    memset(buffer, 0, sizeof(buffer));

                    recv(server, buffer, sizeof(buffer), 0);
                    if (buffer[2] == one[0])
                    {
                        cout << "Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                        matches[selected_card_pos[0]] = 1;
                        matches[selected_card_pos[1]] = 1;
                    }
                    else if (buffer[2] == zero[0])
                    {
                        cout << "Not Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                    }
                    memset(buffer, 0, sizeof(buffer));

                    closesocket(server);
                    WSACleanup();
                    cout << "Socket closed." << endl << endl;

                    selected_cards = 0;
                }
            }

            else if ((mouse_x >= square6x && mouse_x <=  square6x + 70) && (mouse_y >= square6y && mouse_y <=  square6y + 70))
            {
                selected_cards++;
                selected_card_pos[selected_cards - 1] = 6;
                cout << selected_card_pos[selected_cards - 1] << endl;

                if (selected_cards == 2)
                {
                    WSADATA WSAData;
                    SOCKET server;
                    SOCKADDR_IN addr;
                    char buffer[200000];

                    WSAStartup(MAKEWORD(2,0), &WSAData);
                    server = socket(AF_INET, SOCK_STREAM, 0);
                    addr.sin_addr.s_addr = inet_addr("192.168.100.108");
                    addr.sin_family = AF_INET;
                    addr.sin_port = htons(5001);
                    connect(server, (SOCKADDR *)&addr, sizeof(addr));

                    for (int i = 0; i <= sizeof(selected_card_pos); i++)
                    {
                        buffer[i] = selected_card_pos[i];
                    }
                    send(server, buffer, sizeof(buffer), 0);
                    memset(buffer, 0, sizeof(buffer));

                    recv(server, buffer, sizeof(buffer), 0);
                    if (buffer[2] == one[0])
                    {
                        cout << "Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                        matches[selected_card_pos[0]] = 1;
                        matches[selected_card_pos[1]] = 1;
                    }
                    else if (buffer[2] == zero[0])
                    {
                        cout << "Not Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                    }
                    memset(buffer, 0, sizeof(buffer));

                    closesocket(server);
                    WSACleanup();
                    cout << "Socket closed." << endl << endl;

                    selected_cards = 0;
                }
            }

            else if ((mouse_x >= square7x && mouse_x <=  square7x + 70) && (mouse_y >= square7y && mouse_y <=  square7y + 70))
            {
                selected_cards++;
                selected_card_pos[selected_cards - 1] = 7;
                cout << selected_card_pos[selected_cards - 1] << endl;

                if (selected_cards == 2)
                {
                    WSADATA WSAData;
                    SOCKET server;
                    SOCKADDR_IN addr;
                    char buffer[200000];

                    WSAStartup(MAKEWORD(2,0), &WSAData);
                    server = socket(AF_INET, SOCK_STREAM, 0);
                    addr.sin_addr.s_addr = inet_addr("192.168.100.108");
                    addr.sin_family = AF_INET;
                    addr.sin_port = htons(5001);
                    connect(server, (SOCKADDR *)&addr, sizeof(addr));

                    for (int i = 0; i <= sizeof(selected_card_pos); i++)
                    {
                        buffer[i] = selected_card_pos[i];
                    }
                    send(server, buffer, sizeof(buffer), 0);
                    memset(buffer, 0, sizeof(buffer));

                    recv(server, buffer, sizeof(buffer), 0);
                    if (buffer[2] == one[0])
                    {
                        cout << "Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                        matches[selected_card_pos[0]] = 1;
                        matches[selected_card_pos[1]] = 1;
                    }
                    else if (buffer[2] == zero[0])
                    {
                        cout << "Not Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                    }
                    memset(buffer, 0, sizeof(buffer));

                    closesocket(server);
                    WSACleanup();
                    cout << "Socket closed." << endl << endl;

                    selected_cards = 0;
                }
            }

            else if ((mouse_x >= square8x && mouse_x <=  square8x + 70) && (mouse_y >= square8y && mouse_y <=  square8y + 70))
            {
                selected_cards++;
                selected_card_pos[selected_cards - 1] = 8;
                cout << selected_card_pos[selected_cards - 1] << endl;

                if (selected_cards == 2)
                {
                    WSADATA WSAData;
                    SOCKET server;
                    SOCKADDR_IN addr;
                    char buffer[200000];

                    WSAStartup(MAKEWORD(2,0), &WSAData);
                    server = socket(AF_INET, SOCK_STREAM, 0);
                    addr.sin_addr.s_addr = inet_addr("192.168.100.108");
                    addr.sin_family = AF_INET;
                    addr.sin_port = htons(5001);
                    connect(server, (SOCKADDR *)&addr, sizeof(addr));

                    for (int i = 0; i <= sizeof(selected_card_pos); i++)
                    {
                        buffer[i] = selected_card_pos[i];
                    }
                    send(server, buffer, sizeof(buffer), 0);
                    memset(buffer, 0, sizeof(buffer));

                    recv(server, buffer, sizeof(buffer), 0);
                    if (buffer[2] == one[0])
                    {
                        cout << "Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                        matches[selected_card_pos[0]] = 1;
                        matches[selected_card_pos[1]] = 1;
                    }
                    else if (buffer[2] == zero[0])
                    {
                        cout << "Not Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                    }
                    memset(buffer, 0, sizeof(buffer));

                    closesocket(server);
                    WSACleanup();
                    cout << "Socket closed." << endl << endl;

                    selected_cards = 0;
                }
            }

            else if ((mouse_x >= square9x && mouse_x <=  square9x + 70) && (mouse_y >= square9y && mouse_y <=  square9y + 70))
            {
                selected_cards++;
                selected_card_pos[selected_cards - 1] = 9;
                cout << selected_card_pos[selected_cards - 1] << endl;

                if (selected_cards == 2)
                {
                    WSADATA WSAData;
                    SOCKET server;
                    SOCKADDR_IN addr;
                    char buffer[200000];

                    WSAStartup(MAKEWORD(2,0), &WSAData);
                    server = socket(AF_INET, SOCK_STREAM, 0);
                    addr.sin_addr.s_addr = inet_addr("192.168.100.108");
                    addr.sin_family = AF_INET;
                    addr.sin_port = htons(5001);
                    connect(server, (SOCKADDR *)&addr, sizeof(addr));

                    for (int i = 0; i <= sizeof(selected_card_pos); i++)
                    {
                        buffer[i] = selected_card_pos[i];
                    }
                    send(server, buffer, sizeof(buffer), 0);
                    memset(buffer, 0, sizeof(buffer));

                    recv(server, buffer, sizeof(buffer), 0);
                    if (buffer[2] == one[0])
                    {
                        cout << "Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                        matches[selected_card_pos[0]] = 1;
                        matches[selected_card_pos[1]] = 1;
                    }
                    else if (buffer[2] == zero[0])
                    {
                        cout << "Not Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                    }
                    memset(buffer, 0, sizeof(buffer));

                    closesocket(server);
                    WSACleanup();
                    cout << "Socket closed." << endl << endl;

                    selected_cards = 0;
                }
            }

            else if ((mouse_x >= square10x && mouse_x <=  square10x + 70) && (mouse_y >= square10y && mouse_y <=  square10y + 70))
            {
                selected_cards++;
                selected_card_pos[selected_cards - 1] = 10;
                cout << selected_card_pos[selected_cards - 1] << endl;

                if (selected_cards == 2)
                {
                    WSADATA WSAData;
                    SOCKET server;
                    SOCKADDR_IN addr;
                    char buffer[200000];

                    WSAStartup(MAKEWORD(2,0), &WSAData);
                    server = socket(AF_INET, SOCK_STREAM, 0);
                    addr.sin_addr.s_addr = inet_addr("192.168.100.108");
                    addr.sin_family = AF_INET;
                    addr.sin_port = htons(5001);
                    connect(server, (SOCKADDR *)&addr, sizeof(addr));

                    for (int i = 0; i <= sizeof(selected_card_pos); i++)
                    {
                        buffer[i] = selected_card_pos[i];
                    }
                    send(server, buffer, sizeof(buffer), 0);
                    memset(buffer, 0, sizeof(buffer));

                    recv(server, buffer, sizeof(buffer), 0);
                    if (buffer[2] == one[0])
                    {
                        cout << "Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                        matches[selected_card_pos[0]] = 1;
                        matches[selected_card_pos[1]] = 1;
                    }
                    else if (buffer[2] == zero[0])
                    {
                        cout << "Not Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                    }
                    memset(buffer, 0, sizeof(buffer));

                    closesocket(server);
                    WSACleanup();
                    cout << "Socket closed." << endl << endl;

                    selected_cards = 0;
                }
            }

            else if ((mouse_x >= square11x && mouse_x <=  square11x + 70) && (mouse_y >= square11y && mouse_y <=  square11y + 70))
            {
                selected_cards++;
                selected_card_pos[selected_cards - 1] = 11;
                cout << selected_card_pos[selected_cards - 1] << endl;

                if (selected_cards == 2)
                {
                    WSADATA WSAData;
                    SOCKET server;
                    SOCKADDR_IN addr;
                    char buffer[200000];

                    WSAStartup(MAKEWORD(2,0), &WSAData);
                    server = socket(AF_INET, SOCK_STREAM, 0);
                    addr.sin_addr.s_addr = inet_addr("192.168.100.108");
                    addr.sin_family = AF_INET;
                    addr.sin_port = htons(5001);
                    connect(server, (SOCKADDR *)&addr, sizeof(addr));

                    for (int i = 0; i <= sizeof(selected_card_pos); i++)
                    {
                        buffer[i] = selected_card_pos[i];
                    }
                    send(server, buffer, sizeof(buffer), 0);
                    memset(buffer, 0, sizeof(buffer));

                    recv(server, buffer, sizeof(buffer), 0);
                    if (buffer[2] == one[0])
                    {
                        cout << "Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                        matches[selected_card_pos[0]] = 1;
                        matches[selected_card_pos[1]] = 1;
                    }
                    else if (buffer[2] == zero[0])
                    {
                        cout << "Not Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                    }
                    memset(buffer, 0, sizeof(buffer));

                    closesocket(server);
                    WSACleanup();
                    cout << "Socket closed." << endl << endl;

                    selected_cards = 0;
                }
            }

            else if ((mouse_x >= square12x && mouse_x <=  square12x + 70) && (mouse_y >= square12y && mouse_y <=  square12y + 70))
            {
                selected_cards++;
                selected_card_pos[selected_cards - 1] = 12;
                cout << selected_card_pos[selected_cards - 1] << endl;

                if (selected_cards == 2)
                {
                    WSADATA WSAData;
                    SOCKET server;
                    SOCKADDR_IN addr;
                    char buffer[200000];

                    WSAStartup(MAKEWORD(2,0), &WSAData);
                    server = socket(AF_INET, SOCK_STREAM, 0);
                    addr.sin_addr.s_addr = inet_addr("192.168.100.108");
                    addr.sin_family = AF_INET;
                    addr.sin_port = htons(5001);
                    connect(server, (SOCKADDR *)&addr, sizeof(addr));

                    for (int i = 0; i <= sizeof(selected_card_pos); i++)
                    {
                        buffer[i] = selected_card_pos[i];
                    }
                    send(server, buffer, sizeof(buffer), 0);
                    memset(buffer, 0, sizeof(buffer));

                    recv(server, buffer, sizeof(buffer), 0);
                    if (buffer[2] == one[0])
                    {
                        cout << "Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                        matches[selected_card_pos[0]] = 1;
                        matches[selected_card_pos[1]] = 1;
                    }
                    else if (buffer[2] == zero[0])
                    {
                        cout << "Not Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                    }
                    memset(buffer, 0, sizeof(buffer));

                    closesocket(server);
                    WSACleanup();
                    cout << "Socket closed." << endl << endl;

                    selected_cards = 0;
                }
            }

            else if ((mouse_x >= square13x && mouse_x <=  square13x + 70) && (mouse_y >= square13y && mouse_y <=  square13y + 70))
            {
                selected_cards++;
                selected_card_pos[selected_cards - 1] = 13;
                cout << selected_card_pos[selected_cards - 1] << endl;

                if (selected_cards == 2)
                {
                    WSADATA WSAData;
                    SOCKET server;
                    SOCKADDR_IN addr;
                    char buffer[200000];

                    WSAStartup(MAKEWORD(2,0), &WSAData);
                    server = socket(AF_INET, SOCK_STREAM, 0);
                    addr.sin_addr.s_addr = inet_addr("192.168.100.108");
                    addr.sin_family = AF_INET;
                    addr.sin_port = htons(5001);
                    connect(server, (SOCKADDR *)&addr, sizeof(addr));

                    for (int i = 0; i <= sizeof(selected_card_pos); i++)
                    {
                        buffer[i] = selected_card_pos[i];
                    }
                    send(server, buffer, sizeof(buffer), 0);
                    memset(buffer, 0, sizeof(buffer));

                    recv(server, buffer, sizeof(buffer), 0);
                    if (buffer[2] == one[0])
                    {
                        cout << "Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                        matches[selected_card_pos[0]] = 1;
                        matches[selected_card_pos[1]] = 1;
                    }
                    else if (buffer[2] == zero[0])
                    {
                        cout << "Not Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                    }
                    memset(buffer, 0, sizeof(buffer));

                    closesocket(server);
                    WSACleanup();
                    cout << "Socket closed." << endl << endl;

                    selected_cards = 0;
                }
            }

            else if ((mouse_x >= square14x && mouse_x <=  square14x + 70) && (mouse_y >= square14y && mouse_y <=  square14y + 70))
            {
                selected_cards++;
                selected_card_pos[selected_cards - 1] = 14;
                cout << selected_card_pos[selected_cards - 1] << endl;

                if (selected_cards == 2)
                {
                    WSADATA WSAData;
                    SOCKET server;
                    SOCKADDR_IN addr;
                    char buffer[200000];

                    WSAStartup(MAKEWORD(2,0), &WSAData);
                    server = socket(AF_INET, SOCK_STREAM, 0);
                    addr.sin_addr.s_addr = inet_addr("192.168.100.108");
                    addr.sin_family = AF_INET;
                    addr.sin_port = htons(5001);
                    connect(server, (SOCKADDR *)&addr, sizeof(addr));

                    for (int i = 0; i <= sizeof(selected_card_pos); i++)
                    {
                        buffer[i] = selected_card_pos[i];
                    }
                    send(server, buffer, sizeof(buffer), 0);
                    memset(buffer, 0, sizeof(buffer));

                    recv(server, buffer, sizeof(buffer), 0);
                    if (buffer[2] == one[0])
                    {
                        cout << "Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                        matches[selected_card_pos[0]] = 1;
                        matches[selected_card_pos[1]] = 1;
                    }
                    else if (buffer[2] == zero[0])
                    {
                        cout << "Not Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                    }
                    memset(buffer, 0, sizeof(buffer));

                    closesocket(server);
                    WSACleanup();
                    cout << "Socket closed." << endl << endl;

                    selected_cards = 0;
                }
            }

            else if ((mouse_x >= square15x && mouse_x <=  square15x + 70) && (mouse_y >= square15y && mouse_y <=  square15y + 70))
            {
                selected_cards++;
                selected_card_pos[selected_cards - 1] = 15;
                cout << selected_card_pos[selected_cards - 1] << endl;

                if (selected_cards == 2)
                {
                    WSADATA WSAData;
                    SOCKET server;
                    SOCKADDR_IN addr;
                    char buffer[200000];

                    WSAStartup(MAKEWORD(2,0), &WSAData);
                    server = socket(AF_INET, SOCK_STREAM, 0);
                    addr.sin_addr.s_addr = inet_addr("192.168.100.108");
                    addr.sin_family = AF_INET;
                    addr.sin_port = htons(5001);
                    connect(server, (SOCKADDR *)&addr, sizeof(addr));

                    for (int i = 0; i <= sizeof(selected_card_pos); i++)
                    {
                        buffer[i] = selected_card_pos[i];
                    }
                    send(server, buffer, sizeof(buffer), 0);
                    memset(buffer, 0, sizeof(buffer));

                    recv(server, buffer, sizeof(buffer), 0);
                    if (buffer[2] == one[0])
                    {
                        cout << "Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                        matches[selected_card_pos[0]] = 1;
                        matches[selected_card_pos[1]] = 1;
                    }
                    else if (buffer[2] == zero[0])
                    {
                        cout << "Not Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                    }
                    memset(buffer, 0, sizeof(buffer));

                    closesocket(server);
                    WSACleanup();
                    cout << "Socket closed." << endl << endl;

                    selected_cards = 0;
                }
            }

            else if ((mouse_x >= square16x && mouse_x <=  square16x + 70) && (mouse_y >= square16y && mouse_y <=  square16y + 70))
            {
                selected_cards++;
                selected_card_pos[selected_cards - 1] = 16;
                cout << selected_card_pos[selected_cards - 1] << endl;

                if (selected_cards == 2)
                {
                    WSADATA WSAData;
                    SOCKET server;
                    SOCKADDR_IN addr;
                    char buffer[200000];

                    WSAStartup(MAKEWORD(2,0), &WSAData);
                    server = socket(AF_INET, SOCK_STREAM, 0);
                    addr.sin_addr.s_addr = inet_addr("192.168.100.108");
                    addr.sin_family = AF_INET;
                    addr.sin_port = htons(5001);
                    connect(server, (SOCKADDR *)&addr, sizeof(addr));

                    for (int i = 0; i <= sizeof(selected_card_pos); i++)
                    {
                        buffer[i] = selected_card_pos[i];
                    }
                    send(server, buffer, sizeof(buffer), 0);
                    memset(buffer, 0, sizeof(buffer));

                    recv(server, buffer, sizeof(buffer), 0);
                    if (buffer[2] == one[0])
                    {
                        cout << "Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                        matches[selected_card_pos[0]] = 1;
                        matches[selected_card_pos[1]] = 1;
                    }
                    else if (buffer[2] == zero[0])
                    {
                        cout << "Not Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                    }
                    memset(buffer, 0, sizeof(buffer));

                    closesocket(server);
                    WSACleanup();
                    cout << "Socket closed." << endl << endl;

                    selected_cards = 0;
                }
            }

            else if ((mouse_x >= square17x && mouse_x <=  square17x + 70) && (mouse_y >= square17y && mouse_y <=  square17y + 70))
            {
                selected_cards++;
                selected_card_pos[selected_cards - 1] = 17;
                cout << selected_card_pos[selected_cards - 1] << endl;

                if (selected_cards == 2)
                {
                    WSADATA WSAData;
                    SOCKET server;
                    SOCKADDR_IN addr;
                    char buffer[200000];

                    WSAStartup(MAKEWORD(2,0), &WSAData);
                    server = socket(AF_INET, SOCK_STREAM, 0);
                    addr.sin_addr.s_addr = inet_addr("192.168.100.108");
                    addr.sin_family = AF_INET;
                    addr.sin_port = htons(5001);
                    connect(server, (SOCKADDR *)&addr, sizeof(addr));

                    for (int i = 0; i <= sizeof(selected_card_pos); i++)
                    {
                        buffer[i] = selected_card_pos[i];
                    }
                    send(server, buffer, sizeof(buffer), 0);
                    memset(buffer, 0, sizeof(buffer));

                    recv(server, buffer, sizeof(buffer), 0);
                    if (buffer[2] == one[0])
                    {
                        cout << "Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                        matches[selected_card_pos[0]] = 1;
                        matches[selected_card_pos[1]] = 1;
                    }
                    else if (buffer[2] == zero[0])
                    {
                        cout << "Not Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                    }
                    memset(buffer, 0, sizeof(buffer));

                    closesocket(server);
                    WSACleanup();
                    cout << "Socket closed." << endl << endl;

                    selected_cards = 0;
                }
            }

            else if ((mouse_x >= square18x && mouse_x <=  square18x + 70) && (mouse_y >= square18y && mouse_y <=  square18y + 70))
            {
                selected_cards++;
                selected_card_pos[selected_cards - 1] = 18;
                cout << selected_card_pos[selected_cards - 1] << endl;

                if (selected_cards == 2)
                {
                    WSADATA WSAData;
                    SOCKET server;
                    SOCKADDR_IN addr;
                    char buffer[200000];

                    WSAStartup(MAKEWORD(2,0), &WSAData);
                    server = socket(AF_INET, SOCK_STREAM, 0);
                    addr.sin_addr.s_addr = inet_addr("192.168.100.108");
                    addr.sin_family = AF_INET;
                    addr.sin_port = htons(5001);
                    connect(server, (SOCKADDR *)&addr, sizeof(addr));

                    for (int i = 0; i <= sizeof(selected_card_pos); i++)
                    {
                        buffer[i] = selected_card_pos[i];
                    }
                    send(server, buffer, sizeof(buffer), 0);
                    memset(buffer, 0, sizeof(buffer));

                    recv(server, buffer, sizeof(buffer), 0);
                    if (buffer[2] == one[0])
                    {
                        cout << "Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                        matches[selected_card_pos[0]] = 1;
                        matches[selected_card_pos[1]] = 1;
                    }
                    else if (buffer[2] == zero[0])
                    {
                        cout << "Not Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                    }
                    memset(buffer, 0, sizeof(buffer));

                    closesocket(server);
                    WSACleanup();
                    cout << "Socket closed." << endl << endl;

                    selected_cards = 0;
                }
            }

            else if ((mouse_x >= square19x && mouse_x <=  square19x + 70) && (mouse_y >= square19y && mouse_y <=  square19y + 70))
            {
                selected_cards++;
                selected_card_pos[selected_cards - 1] = 19;
                cout << selected_card_pos[selected_cards - 1] << endl;

                if (selected_cards == 2)
                {
                    WSADATA WSAData;
                    SOCKET server;
                    SOCKADDR_IN addr;
                    char buffer[200000];

                    WSAStartup(MAKEWORD(2,0), &WSAData);
                    server = socket(AF_INET, SOCK_STREAM, 0);
                    addr.sin_addr.s_addr = inet_addr("192.168.100.108");
                    addr.sin_family = AF_INET;
                    addr.sin_port = htons(5001);
                    connect(server, (SOCKADDR *)&addr, sizeof(addr));

                    for (int i = 0; i <= sizeof(selected_card_pos); i++)
                    {
                        buffer[i] = selected_card_pos[i];
                    }
                    send(server, buffer, sizeof(buffer), 0);
                    memset(buffer, 0, sizeof(buffer));

                    recv(server, buffer, sizeof(buffer), 0);
                    if (buffer[2] == one[0])
                    {
                        cout << "Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                        matches[selected_card_pos[0]] = 1;
                        matches[selected_card_pos[1]] = 1;
                    }
                    else if (buffer[2] == zero[0])
                    {
                        cout << "Not Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                    }
                    memset(buffer, 0, sizeof(buffer));

                    closesocket(server);
                    WSACleanup();
                    cout << "Socket closed." << endl << endl;

                    selected_cards = 0;
                }
            }

            else if ((mouse_x >= square20x && mouse_x <=  square20x + 70) && (mouse_y >= square20y && mouse_y <=  square20y + 70))
            {
                selected_cards++;
                selected_card_pos[selected_cards - 1] = 20;
                cout << selected_card_pos[selected_cards - 1] << endl;

                if (selected_cards == 2)
                {
                    WSADATA WSAData;
                    SOCKET server;
                    SOCKADDR_IN addr;
                    char buffer[200000];

                    WSAStartup(MAKEWORD(2,0), &WSAData);
                    server = socket(AF_INET, SOCK_STREAM, 0);
                    addr.sin_addr.s_addr = inet_addr("192.168.100.108");
                    addr.sin_family = AF_INET;
                    addr.sin_port = htons(5001);
                    connect(server, (SOCKADDR *)&addr, sizeof(addr));

                    for (int i = 0; i <= sizeof(selected_card_pos); i++)
                    {
                        buffer[i] = selected_card_pos[i];
                    }
                    send(server, buffer, sizeof(buffer), 0);
                    memset(buffer, 0, sizeof(buffer));

                    recv(server, buffer, sizeof(buffer), 0);
                    if (buffer[2] == one[0])
                    {
                        cout << "Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                        matches[selected_card_pos[0]] = 1;
                        matches[selected_card_pos[1]] = 1;
                    }
                    else if (buffer[2] == zero[0])
                    {
                        cout << "Not Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                    }
                    memset(buffer, 0, sizeof(buffer));

                    closesocket(server);
                    WSACleanup();
                    cout << "Socket closed." << endl << endl;

                    selected_cards = 0;
                }
            }

            else if ((mouse_x >= square21x && mouse_x <=  square21x + 70) && (mouse_y >= square21y && mouse_y <=  square21y + 70))
            {
                selected_cards++;
                selected_card_pos[selected_cards - 1] = 21;
                cout << selected_card_pos[selected_cards - 1] << endl;

                if (selected_cards == 2)
                {
                    WSADATA WSAData;
                    SOCKET server;
                    SOCKADDR_IN addr;
                    char buffer[200000];

                    WSAStartup(MAKEWORD(2,0), &WSAData);
                    server = socket(AF_INET, SOCK_STREAM, 0);
                    addr.sin_addr.s_addr = inet_addr("192.168.100.108");
                    addr.sin_family = AF_INET;
                    addr.sin_port = htons(5001);
                    connect(server, (SOCKADDR *)&addr, sizeof(addr));

                    for (int i = 0; i <= sizeof(selected_card_pos); i++)
                    {
                        buffer[i] = selected_card_pos[i];
                    }
                    send(server, buffer, sizeof(buffer), 0);
                    memset(buffer, 0, sizeof(buffer));

                    recv(server, buffer, sizeof(buffer), 0);
                    if (buffer[2] == one[0])
                    {
                        cout << "Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                        matches[selected_card_pos[0]] = 1;
                        matches[selected_card_pos[1]] = 1;
                    }
                    else if (buffer[2] == zero[0])
                    {
                        cout << "Not Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                    }
                    memset(buffer, 0, sizeof(buffer));

                    closesocket(server);
                    WSACleanup();
                    cout << "Socket closed." << endl << endl;

                    selected_cards = 0;
                }
            }

            else if ((mouse_x >= square22x && mouse_x <=  square22x + 70) && (mouse_y >= square22y && mouse_y <=  square22y + 70))
            {
                selected_cards++;
                selected_card_pos[selected_cards - 1] = 22;
                cout << selected_card_pos[selected_cards - 1] << endl;

                if (selected_cards == 2)
                {
                    WSADATA WSAData;
                    SOCKET server;
                    SOCKADDR_IN addr;
                    char buffer[200000];

                    WSAStartup(MAKEWORD(2,0), &WSAData);
                    server = socket(AF_INET, SOCK_STREAM, 0);
                    addr.sin_addr.s_addr = inet_addr("192.168.100.108");
                    addr.sin_family = AF_INET;
                    addr.sin_port = htons(5001);
                    connect(server, (SOCKADDR *)&addr, sizeof(addr));

                    for (int i = 0; i <= sizeof(selected_card_pos); i++)
                    {
                        buffer[i] = selected_card_pos[i];
                    }
                    send(server, buffer, sizeof(buffer), 0);
                    memset(buffer, 0, sizeof(buffer));

                    recv(server, buffer, sizeof(buffer), 0);
                    if (buffer[2] == one[0])
                    {
                        cout << "Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                        matches[selected_card_pos[0]] = 1;
                        matches[selected_card_pos[1]] = 1;
                    }
                    else if (buffer[2] == zero[0])
                    {
                        cout << "Not Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                    }
                    memset(buffer, 0, sizeof(buffer));

                    closesocket(server);
                    WSACleanup();
                    cout << "Socket closed." << endl << endl;

                    selected_cards = 0;
                }
            }

            else if ((mouse_x >= square23x && mouse_x <=  square23x + 70) && (mouse_y >= square23y && mouse_y <=  square23y + 70))
            {
                selected_cards++;
                selected_card_pos[selected_cards - 1] = 23;
                cout << selected_card_pos[selected_cards - 1] << endl;

                if (selected_cards == 2)
                {
                    WSADATA WSAData;
                    SOCKET server;
                    SOCKADDR_IN addr;
                    char buffer[200000];

                    WSAStartup(MAKEWORD(2,0), &WSAData);
                    server = socket(AF_INET, SOCK_STREAM, 0);
                    addr.sin_addr.s_addr = inet_addr("192.168.100.108");
                    addr.sin_family = AF_INET;
                    addr.sin_port = htons(5001);
                    connect(server, (SOCKADDR *)&addr, sizeof(addr));

                    for (int i = 0; i <= sizeof(selected_card_pos); i++)
                    {
                        buffer[i] = selected_card_pos[i];
                    }
                    send(server, buffer, sizeof(buffer), 0);
                    memset(buffer, 0, sizeof(buffer));

                    recv(server, buffer, sizeof(buffer), 0);
                    if (buffer[2] == one[0])
                    {
                        cout << "Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                        matches[selected_card_pos[0]] = 1;
                        matches[selected_card_pos[1]] = 1;
                    }
                    else if (buffer[2] == zero[0])
                    {
                        cout << "Not Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                    }
                    memset(buffer, 0, sizeof(buffer));

                    closesocket(server);
                    WSACleanup();
                    cout << "Socket closed." << endl << endl;

                    selected_cards = 0;
                }
            }

            else if ((mouse_x >= square24x && mouse_x <=  square24x + 70) && (mouse_y >= square24y && mouse_y <=  square24y + 70))
            {
                selected_cards++;
                selected_card_pos[selected_cards - 1] = 24;
                cout << selected_card_pos[selected_cards - 1] << endl;

                if (selected_cards == 2)
                {
                    WSADATA WSAData;
                    SOCKET server;
                    SOCKADDR_IN addr;
                    char buffer[200000];

                    WSAStartup(MAKEWORD(2,0), &WSAData);
                    server = socket(AF_INET, SOCK_STREAM, 0);
                    addr.sin_addr.s_addr = inet_addr("192.168.100.108");
                    addr.sin_family = AF_INET;
                    addr.sin_port = htons(5001);
                    connect(server, (SOCKADDR *)&addr, sizeof(addr));

                    for (int i = 0; i <= sizeof(selected_card_pos); i++)
                    {
                        buffer[i] = selected_card_pos[i];
                    }
                    send(server, buffer, sizeof(buffer), 0);
                    memset(buffer, 0, sizeof(buffer));

                    recv(server, buffer, sizeof(buffer), 0);
                    if (buffer[2] == one[0])
                    {
                        cout << "Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                        matches[selected_card_pos[0]] = 1;
                        matches[selected_card_pos[1]] = 1;
                    }
                    else if (buffer[2] == zero[0])
                    {
                        cout << "Not Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                    }
                    memset(buffer, 0, sizeof(buffer));

                    closesocket(server);
                    WSACleanup();
                    cout << "Socket closed." << endl << endl;

                    selected_cards = 0;
                }
            }

            else if ((mouse_x >= square25x && mouse_x <=  square25x + 70) && (mouse_y >= square25y && mouse_y <=  square25y + 70))
            {
                selected_cards++;
                selected_card_pos[selected_cards - 1] = 25;
                cout << selected_card_pos[selected_cards - 1] << endl;

                if (selected_cards == 2)
                {
                    WSADATA WSAData;
                    SOCKET server;
                    SOCKADDR_IN addr;
                    char buffer[200000];

                    WSAStartup(MAKEWORD(2,0), &WSAData);
                    server = socket(AF_INET, SOCK_STREAM, 0);
                    addr.sin_addr.s_addr = inet_addr("192.168.100.108");
                    addr.sin_family = AF_INET;
                    addr.sin_port = htons(5001);
                    connect(server, (SOCKADDR *)&addr, sizeof(addr));

                    for (int i = 0; i <= sizeof(selected_card_pos); i++)
                    {
                        buffer[i] = selected_card_pos[i];
                    }
                    send(server, buffer, sizeof(buffer), 0);
                    memset(buffer, 0, sizeof(buffer));

                    recv(server, buffer, sizeof(buffer), 0);
                    if (buffer[2] == one[0])
                    {
                        cout << "Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                        matches[selected_card_pos[0]] = 1;
                        matches[selected_card_pos[1]] = 1;
                    }
                    else if (buffer[2] == zero[0])
                    {
                        cout << "Not Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                    }
                    memset(buffer, 0, sizeof(buffer));

                    closesocket(server);
                    WSACleanup();
                    cout << "Socket closed." << endl << endl;

                    selected_cards = 0;
                }
            }

            else if ((mouse_x >= square26x && mouse_x <=  square26x + 70) && (mouse_y >= square26y && mouse_y <=  square26y + 70))
            {
                selected_cards++;
                selected_card_pos[selected_cards - 1] = 26;
                cout << selected_card_pos[selected_cards - 1] << endl;

                if (selected_cards == 2)
                {
                    WSADATA WSAData;
                    SOCKET server;
                    SOCKADDR_IN addr;
                    char buffer[200000];

                    WSAStartup(MAKEWORD(2,0), &WSAData);
                    server = socket(AF_INET, SOCK_STREAM, 0);
                    addr.sin_addr.s_addr = inet_addr("192.168.100.108");
                    addr.sin_family = AF_INET;
                    addr.sin_port = htons(5001);
                    connect(server, (SOCKADDR *)&addr, sizeof(addr));

                    for (int i = 0; i <= sizeof(selected_card_pos); i++)
                    {
                        buffer[i] = selected_card_pos[i];
                    }
                    send(server, buffer, sizeof(buffer), 0);
                    memset(buffer, 0, sizeof(buffer));

                    recv(server, buffer, sizeof(buffer), 0);
                    if (buffer[2] == one[0])
                    {
                        cout << "Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                        matches[selected_card_pos[0]] = 1;
                        matches[selected_card_pos[1]] = 1;
                    }
                    else if (buffer[2] == zero[0])
                    {
                        cout << "Not Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                    }
                    memset(buffer, 0, sizeof(buffer));

                    closesocket(server);
                    WSACleanup();
                    cout << "Socket closed." << endl << endl;

                    selected_cards = 0;
                }
            }

            else if ((mouse_x >= square27x && mouse_x <=  square27x + 70) && (mouse_y >= square27y && mouse_y <=  square27y + 70))
            {
                selected_cards++;
                selected_card_pos[selected_cards - 1] = 27;
                cout << selected_card_pos[selected_cards - 1] << endl;

                if (selected_cards == 2)
                {
                    WSADATA WSAData;
                    SOCKET server;
                    SOCKADDR_IN addr;
                    char buffer[200000];

                    WSAStartup(MAKEWORD(2,0), &WSAData);
                    server = socket(AF_INET, SOCK_STREAM, 0);
                    addr.sin_addr.s_addr = inet_addr("192.168.100.108");
                    addr.sin_family = AF_INET;
                    addr.sin_port = htons(5001);
                    connect(server, (SOCKADDR *)&addr, sizeof(addr));

                    for (int i = 0; i <= sizeof(selected_card_pos); i++)
                    {
                        buffer[i] = selected_card_pos[i];
                    }
                    send(server, buffer, sizeof(buffer), 0);
                    memset(buffer, 0, sizeof(buffer));

                    recv(server, buffer, sizeof(buffer), 0);
                    if (buffer[2] == one[0])
                    {
                        cout << "Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                        matches[selected_card_pos[0]] = 1;
                        matches[selected_card_pos[1]] = 1;
                    }
                    else if (buffer[2] == zero[0])
                    {
                        cout << "Not Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                    }
                    memset(buffer, 0, sizeof(buffer));

                    closesocket(server);
                    WSACleanup();
                    cout << "Socket closed." << endl << endl;

                    selected_cards = 0;
                }
            }

            else if ((mouse_x >= square28x && mouse_x <=  square28x + 70) && (mouse_y >= square28y && mouse_y <=  square28y + 70))
            {
                selected_cards++;
                selected_card_pos[selected_cards - 1] = 28;
                cout << selected_card_pos[selected_cards - 1] << endl;

                if (selected_cards == 2)
                {
                    WSADATA WSAData;
                    SOCKET server;
                    SOCKADDR_IN addr;
                    char buffer[200000];

                    WSAStartup(MAKEWORD(2,0), &WSAData);
                    server = socket(AF_INET, SOCK_STREAM, 0);
                    addr.sin_addr.s_addr = inet_addr("192.168.100.108");
                    addr.sin_family = AF_INET;
                    addr.sin_port = htons(5001);
                    connect(server, (SOCKADDR *)&addr, sizeof(addr));

                    for (int i = 0; i <= sizeof(selected_card_pos); i++)
                    {
                        buffer[i] = selected_card_pos[i];
                    }
                    send(server, buffer, sizeof(buffer), 0);
                    memset(buffer, 0, sizeof(buffer));

                    recv(server, buffer, sizeof(buffer), 0);
                    if (buffer[2] == one[0])
                    {
                        cout << "Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                        matches[selected_card_pos[0]] = 1;
                        matches[selected_card_pos[1]] = 1;
                    }
                    else if (buffer[2] == zero[0])
                    {
                        cout << "Not Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                    }
                    memset(buffer, 0, sizeof(buffer));

                    closesocket(server);
                    WSACleanup();
                    cout << "Socket closed." << endl << endl;

                    selected_cards = 0;
                }
            }

            else if ((mouse_x >= square29x && mouse_x <=  square29x + 70) && (mouse_y >= square29y && mouse_y <=  square29y + 70))
            {
                selected_cards++;
                selected_card_pos[selected_cards - 1] = 29;
                cout << selected_card_pos[selected_cards - 1] << endl;

                if (selected_cards == 2)
                {
                    WSADATA WSAData;
                    SOCKET server;
                    SOCKADDR_IN addr;
                    char buffer[200000];

                    WSAStartup(MAKEWORD(2,0), &WSAData);
                    server = socket(AF_INET, SOCK_STREAM, 0);
                    addr.sin_addr.s_addr = inet_addr("192.168.100.108");
                    addr.sin_family = AF_INET;
                    addr.sin_port = htons(5001);
                    connect(server, (SOCKADDR *)&addr, sizeof(addr));

                    for (int i = 0; i <= sizeof(selected_card_pos); i++)
                    {
                        buffer[i] = selected_card_pos[i];
                    }
                    send(server, buffer, sizeof(buffer), 0);
                    memset(buffer, 0, sizeof(buffer));

                    recv(server, buffer, sizeof(buffer), 0);
                    if (buffer[2] == one[0])
                    {
                        cout << "Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                        matches[selected_card_pos[0]] = 1;
                        matches[selected_card_pos[1]] = 1;
                    }
                    else if (buffer[2] == zero[0])
                    {
                        cout << "Not Match" << endl;
                        for(int i = 0; i < 2; i++)
                        {
                            if(buffer[i] == zero[0])
                            {
                                cout << "Green" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Green.jpeg"))
                                {
                                    cout << "Could not load Green Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == one[0])
                            {
                                cout << "Blue" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Blue.jpeg"))
                                {
                                    cout << "Could not load Blue Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == two[0])
                            {
                                cout << "Red" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Red.jpeg"))
                                {
                                    cout << "Could not load Red Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == three[0])
                            {
                                cout << "Yellow" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Yellow.jpeg"))
                                {
                                    cout << "Could not load Yellow Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }

                            if(buffer[i] == four[0])
                            {
                                cout << "Orange" << endl;
                                Texture texture;
                                Sprite image;
                                if (!texture.loadFromFile("Photos//Orange.jpeg"))
                                {
                                    cout << "Could not load Orange Card" << endl;
                                }
                                image.setTexture(texture);
                                float x = cards_list[selected_card_pos[i]].getGlobalBounds().left;
                                float y = cards_list[selected_card_pos[i]].getGlobalBounds().top;
                                image.setPosition(x, y);
                                window.draw(image);
                            }
                            window.display();
                            Sleep(1000);
                        }
                    }
                    memset(buffer, 0, sizeof(buffer));

                    closesocket(server);
                    WSACleanup();
                    cout << "Socket closed." << endl << endl;

                    selected_cards = 0;
                }
            }
            Sleep(500);
        }

        window.clear();
        window.draw(Player1Name);
        window.draw(Player2Name);
        window.draw(title);
        window.draw(square0);
        window.draw(square1);
        window.draw(square2);
        window.draw(square3);
        window.draw(square4);
        window.draw(square5);
        window.draw(square6);
        window.draw(square7);
        window.draw(square8);
        window.draw(square9);
        window.draw(square10);
        window.draw(square11);
        window.draw(square12);
        window.draw(square13);
        window.draw(square14);
        window.draw(square15);
        window.draw(square16);
        window.draw(square17);
        window.draw(square18);
        window.draw(square19);
        window.draw(square20);
        window.draw(square21);
        window.draw(square22);
        window.draw(square23);
        window.draw(square24);
        window.draw(square25);
        window.draw(square26);
        window.draw(square27);
        window.draw(square28);
        window.draw(square29);
        if (matches[0] == 1)
        {
            float x = cards_list[0].getGlobalBounds().left;
            float y = cards_list[0].getGlobalBounds().top;
            imageB.setPosition(x, y);
            window.draw(imageB);
        }
        if (matches[1] == 1)
        {
            float x = cards_list[1].getGlobalBounds().left;
            float y = cards_list[1].getGlobalBounds().top;
            imageB.setPosition(x, y);
            window.draw(imageB);
        }
        if (matches[2] == 1)
        {
            float x = cards_list[2].getGlobalBounds().left;
            float y = cards_list[2].getGlobalBounds().top;
            imageB.setPosition(x, y);
            window.draw(imageB);
        }
        if (matches[3] == 1)
        {
            float x = cards_list[3].getGlobalBounds().left;
            float y = cards_list[3].getGlobalBounds().top;
            imageB.setPosition(x, y);
            window.draw(imageB);
        }
        if (matches[4] == 1)
        {
            float x = cards_list[4].getGlobalBounds().left;
            float y = cards_list[4].getGlobalBounds().top;
            imageB.setPosition(x, y);
            window.draw(imageB);
        }
        if (matches[5] == 1)
        {
            float x = cards_list[5].getGlobalBounds().left;
            float y = cards_list[5].getGlobalBounds().top;
            imageB.setPosition(x, y);
            window.draw(imageB);
        }
        if (matches[6] == 1)
        {
            float x = cards_list[6].getGlobalBounds().left;
            float y = cards_list[6].getGlobalBounds().top;
            imageB.setPosition(x, y);
            window.draw(imageB);
        }
        if (matches[7] == 1)
        {
            float x = cards_list[7].getGlobalBounds().left;
            float y = cards_list[7].getGlobalBounds().top;
            imageB.setPosition(x, y);
            window.draw(imageB);
        }
        if (matches[8] == 1)
        {
            float x = cards_list[8].getGlobalBounds().left;
            float y = cards_list[8].getGlobalBounds().top;
            imageB.setPosition(x, y);
            window.draw(imageB);
        }
        if (matches[9] == 1)
        {
            float x = cards_list[9].getGlobalBounds().left;
            float y = cards_list[9].getGlobalBounds().top;
            imageB.setPosition(x, y);
            window.draw(imageB);
        }
        if (matches[10] == 1)
        {
            float x = cards_list[10].getGlobalBounds().left;
            float y = cards_list[10].getGlobalBounds().top;
            imageB.setPosition(x, y);
            window.draw(imageB);
        }
        if (matches[11] == 1)
        {
            float x = cards_list[11].getGlobalBounds().left;
            float y = cards_list[11].getGlobalBounds().top;
            imageB.setPosition(x, y);
            window.draw(imageB);
        }
        if (matches[12] == 1)
        {
            float x = cards_list[12].getGlobalBounds().left;
            float y = cards_list[12].getGlobalBounds().top;
            imageB.setPosition(x, y);
            window.draw(imageB);
        }
        if (matches[13] == 1)
        {
            float x = cards_list[13].getGlobalBounds().left;
            float y = cards_list[13].getGlobalBounds().top;
            imageB.setPosition(x, y);
            window.draw(imageB);
        }
        if (matches[14] == 1)
        {
            float x = cards_list[14].getGlobalBounds().left;
            float y = cards_list[14].getGlobalBounds().top;
            imageB.setPosition(x, y);
            window.draw(imageB);
        }
        if (matches[15] == 1)
        {
            float x = cards_list[15].getGlobalBounds().left;
            float y = cards_list[15].getGlobalBounds().top;
            imageB.setPosition(x, y);
            window.draw(imageB);
        }
        if (matches[16] == 1)
        {
            float x = cards_list[16].getGlobalBounds().left;
            float y = cards_list[16].getGlobalBounds().top;
            imageB.setPosition(x, y);
            window.draw(imageB);
        }
        if (matches[17] == 1)
        {
            float x = cards_list[17].getGlobalBounds().left;
            float y = cards_list[17].getGlobalBounds().top;
            imageB.setPosition(x, y);
            window.draw(imageB);
        }
        if (matches[18] == 1)
        {
            float x = cards_list[18].getGlobalBounds().left;
            float y = cards_list[18].getGlobalBounds().top;
            imageB.setPosition(x, y);
            window.draw(imageB);
        }
        if (matches[19] == 1)
        {
            float x = cards_list[19].getGlobalBounds().left;
            float y = cards_list[19].getGlobalBounds().top;
            imageB.setPosition(x, y);
            window.draw(imageB);
        }
        if (matches[20] == 1)
        {
            float x = cards_list[20].getGlobalBounds().left;
            float y = cards_list[20].getGlobalBounds().top;
            imageB.setPosition(x, y);
            window.draw(imageB);
        }
        if (matches[21] == 1)
        {
            float x = cards_list[21].getGlobalBounds().left;
            float y = cards_list[21].getGlobalBounds().top;
            imageB.setPosition(x, y);
            window.draw(imageB);
        }
        if (matches[22] == 1)
        {
            float x = cards_list[22].getGlobalBounds().left;
            float y = cards_list[22].getGlobalBounds().top;
            imageB.setPosition(x, y);
            window.draw(imageB);
        }
        if (matches[23] == 1)
        {
            float x = cards_list[23].getGlobalBounds().left;
            float y = cards_list[23].getGlobalBounds().top;
            imageB.setPosition(x, y);
            window.draw(imageB);
        }
        if (matches[24] == 1)
        {
            float x = cards_list[24].getGlobalBounds().left;
            float y = cards_list[24].getGlobalBounds().top;
            imageB.setPosition(x, y);
            window.draw(imageB);
        }
        if (matches[25] == 1)
        {
            float x = cards_list[25].getGlobalBounds().left;
            float y = cards_list[25].getGlobalBounds().top;
            imageB.setPosition(x, y);
            window.draw(imageB);
        }
        if (matches[26] == 1)
        {
            float x = cards_list[26].getGlobalBounds().left;
            float y = cards_list[26].getGlobalBounds().top;
            imageB.setPosition(x, y);
            window.draw(imageB);
        }
        if (matches[27] == 1)
        {
            float x = cards_list[27].getGlobalBounds().left;
            float y = cards_list[27].getGlobalBounds().top;
            imageB.setPosition(x, y);
            window.draw(imageB);
        }
        if (matches[28] == 1)
        {
            float x = cards_list[28].getGlobalBounds().left;
            float y = cards_list[28].getGlobalBounds().top;
            imageB.setPosition(x, y);
            window.draw(imageB);
        }
        if (matches[29] == 1)
        {
            float x = cards_list[29].getGlobalBounds().left;
            float y = cards_list[29].getGlobalBounds().top;
            imageB.setPosition(x, y);
            window.draw(imageB);
        }
        window.display();

        int used_cards = 0;

        for(int i = 0; i < 30; i++)
        {
            if (matches[i] == 1)
            {
                used_cards += 1;
            }
        }

        if (used_cards == 30)
        {
            exit(1);
        }
    }
    return 0;
}