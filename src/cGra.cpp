#include "cGra.h"

using namespace std;

cGra::cGra(cPlansza &aPlansza, cGracz &aGracz, cGraczAI *aGraczAITrudny, cGraczAI *aGraczAIRandom) : mPlansza (aPlansza), mGracz (aGracz)
{
    cout << "Konstruktor gry" << endl;
    mGraczAITrudny = aGraczAITrudny;
    mGraczAIRandom = aGraczAIRandom;
    wynikGracza = 0;
    wynikAI = 0;
    //ctor
}

cGra::~cGra()
{
    cout << "Destruktor gry" << endl;
    //dtor
}

void cGra::graj()
{
    sf::RenderWindow okno(sf::VideoMode(1000, 600), "Kolko-krzyzyk");
    float szerokoscOkna = 1000;
    float wysokoscOkna = 600;
    unsigned int szerokoscPola = 200;
    bool blad;

    //Linie do planszy
    sf::RectangleShape liniaPozioma(sf::Vector2f(600.f, 4.f)), liniaPionowa(sf::Vector2f(600.f, 4.f));
    liniaPozioma.setFillColor(sf::Color(0.f, 0.f, 0.f));
    liniaPionowa = liniaPozioma;
    liniaPionowa.rotate(90.f);

    //Kolko
    sf::CircleShape kolko(81.f);
    kolko.setOutlineThickness(9.f);
    kolko.setOutlineColor(sf::Color(0.f, 0.f, 0.f));

    //Krzyzyk
    sf::VertexArray krzyzykLinia1(sf::Quads, 4);

    krzyzykLinia1[0].position = sf::Vector2f(16.f, 10.f);
    krzyzykLinia1[1].position = sf::Vector2f(190.f, 184.f);
    krzyzykLinia1[2].position = sf::Vector2f(184.f, 190.f);
    krzyzykLinia1[3].position = sf::Vector2f(10.f, 16.f);

    krzyzykLinia1[0].color = sf::Color::Black;
    krzyzykLinia1[1].color = sf::Color::Black;
    krzyzykLinia1[2].color = sf::Color::Black;
    krzyzykLinia1[3].color = sf::Color::Black;

    sf::VertexArray krzyzykLinia2(sf::Quads, 4);
    krzyzykLinia2 = krzyzykLinia1;
    krzyzykLinia2[0].position = sf::Vector2f(190.f, 16.f);
    krzyzykLinia2[1].position = sf::Vector2f(16.f, 190.f);
    krzyzykLinia2[2].position = sf::Vector2f(10.f, 184.f);
    krzyzykLinia2[3].position = sf::Vector2f(184.f, 10.f);

    bool AITrudnyAktywny=false;

    //Font
    sf::Font font;
    if(!font.loadFromFile("OpenSans-Regular.ttf")) cout << "Nie wczytalo fontu" << endl;

    //Tekst
    sf::Text tekstWynik, tekstPrzycisk1, tekstPrzycisk2, tekstStatus;
    tekstWynik.setFont(font);
    tekstWynik.setString("Gracz " + to_string(wynikGracza) + " : " + to_string(wynikAI) + " AI");
    tekstWynik.setCharacterSize(24);
    tekstWynik.setFillColor(sf::Color(0.f, 0.f, 0.f));
    tekstWynik.setPosition(sf::Vector2f(740.f, 50.f));

    tekstPrzycisk1.setFont(font);
    tekstPrzycisk1.setString("AI random");
    tekstPrzycisk1.setCharacterSize(18);
    tekstPrzycisk1.setFillColor(sf::Color(0.f, 0.f, 0.f));
    tekstPrzycisk1.setPosition(sf::Vector2f(700.f, 100.f));

    tekstPrzycisk2.setFont(font);
    tekstPrzycisk2.setString("AI trudny");
    tekstPrzycisk2.setCharacterSize(18);
    tekstPrzycisk2.setFillColor(sf::Color(0.f, 0.f, 0.f));
    tekstPrzycisk2.setPosition(sf::Vector2f(850.f, 100.f));

    tekstStatus.setFont(font);
    tekstStatus.setCharacterSize(24);
    tekstStatus.setFillColor(sf::Color(0.f, 0.f, 0.f));
    tekstStatus.setPosition(sf::Vector2f(670.f, 200.f));

    //Przyciski
    sf::RectangleShape przycisk1(sf::Vector2f(12.f, 12.f)), przycisk2(sf::Vector2f(12.f, 12.f));
    przycisk1.setPosition(sf::Vector2f(680.f, 105.f));
    przycisk1.setOutlineThickness(2.f);
    przycisk1.setOutlineColor(sf::Color(0.f, 0.f, 0.f));
    przycisk1.setFillColor(sf::Color(0.f, 0.f, 0.f));

    przycisk2 = przycisk1;
    przycisk2.setPosition(sf::Vector2f(830.f, 105.f));
    przycisk2.setFillColor(sf::Color(255.f, 255.f, 255.f));

    while(okno.isOpen())
    {
        sf::Event zdarzenie;
        while(okno.pollEvent(zdarzenie))
        {
            switch(zdarzenie.type)
            {
                case sf::Event::Closed:
                    okno.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if(zdarzenie.mouseButton.button == sf::Mouse::Left)
                    {
                        for(unsigned int i=0; i<3; i++)
                        {
                            for(unsigned int j=0; j<3; j++)
                            {
                                if((zdarzenie.mouseButton.x > i*szerokoscPola*(szerokoscOkna/1000) && zdarzenie.mouseButton.y > j*szerokoscPola*(wysokoscOkna/600)) &&
                                   (zdarzenie.mouseButton.x < (i+1)*szerokoscPola*(szerokoscOkna/1000) && zdarzenie.mouseButton.y < (j+1)*szerokoscPola*(wysokoscOkna/600)))
                                {
                                    blad = mGracz.obslugaBledow(j, i);
                                    if(blad==true)
                                    {
                                        stringstream komunikat;
                                        komunikat << mGracz;
                                        tekstStatus.setString(komunikat.str());
                                    }
                                    mGracz.wprowadz(j, i);
                                    if(mPlansza.status()==1)
                                    {
                                        tekstStatus.setString("Wygral gracz!");
                                        wynikGracza++;
                                        tekstWynik.setString("Gracz " + to_string(wynikGracza) + " : " + to_string(wynikAI) + " AI");
                                        mPlansza = mPlansza;
                                        blad=true;
                                    }
                                    if(mPlansza.status()==3)
                                    {
                                        tekstStatus.setString("Remis!");
                                        mPlansza = mPlansza;
                                    }
                                    else
                                    {
                                        if(blad==false)
                                        {
                                            if(AITrudnyAktywny==true) mGraczAITrudny->wprowadz();
                                            else mGraczAIRandom->wprowadz();

                                            if(mPlansza.status()==2)
                                            {
                                                tekstStatus.setString("Wygral AI!");
                                                wynikAI++;
                                                tekstWynik.setString("Gracz " + to_string(wynikGracza) + " : " + to_string(wynikAI) + " AI");
                                                mPlansza = mPlansza;
                                            }
                                        }
                                    }
                                }
                            }
                            //Wybor AI
                            if((zdarzenie.mouseButton.x > 678*(szerokoscOkna/1000) && zdarzenie.mouseButton.y > 103*(wysokoscOkna/600)) &&
                               (zdarzenie.mouseButton.x < 788*(szerokoscOkna/1000) && zdarzenie.mouseButton.y < 119*(wysokoscOkna/600)))
                            {
                                przycisk1.setFillColor(sf::Color(0.f, 0.f, 0.f));
                                przycisk2.setFillColor(sf::Color(255.f, 255.f, 255.f));
                                if(AITrudnyAktywny==true)
                                {
                                    mPlansza = mPlansza;
                                    AITrudnyAktywny=false;
                                }
                            }
                            if((zdarzenie.mouseButton.x > 828*(szerokoscOkna/1000) && zdarzenie.mouseButton.y > 103*(wysokoscOkna/600)) &&
                               (zdarzenie.mouseButton.x < 930*(szerokoscOkna/1000) && zdarzenie.mouseButton.y < 119*(wysokoscOkna/600)))
                            {
                                przycisk2.setFillColor(sf::Color(0.f, 0.f, 0.f));
                                przycisk1.setFillColor(sf::Color(255.f, 255.f, 255.f));
                                if(AITrudnyAktywny==false)
                                {
                                    mPlansza = mPlansza;
                                    AITrudnyAktywny=true;
                                }
                            }
                        }
                    }
                    break;
                case sf::Event::Resized:
                    szerokoscOkna = zdarzenie.size.width;
                    wysokoscOkna = zdarzenie.size.height;
                    break;
            }
        }

        okno.clear(sf::Color::White);

        for(unsigned int i=0; i<3; i++)
        {
            for(unsigned int j=0; j<3; j++)
            {
                if(mPlansza.mPlansza[j][i]=='O')
                {
                    kolko.setPosition(i*szerokoscPola+18, j*szerokoscPola+18);
                    okno.draw(kolko);
                }

                if(mPlansza.mPlansza[j][i]=='X')
                {
                    krzyzykLinia1[0].position = sf::Vector2f(i*szerokoscPola + 16.f, j*szerokoscPola + 10.f);
                    krzyzykLinia1[1].position = sf::Vector2f(i*szerokoscPola + 190.f, j*szerokoscPola + 184.f);
                    krzyzykLinia1[2].position = sf::Vector2f(i*szerokoscPola + 184.f, j*szerokoscPola + 190.f);
                    krzyzykLinia1[3].position = sf::Vector2f(i*szerokoscPola + 10.f, j*szerokoscPola + 16.f);
                    okno.draw(krzyzykLinia1);
                    krzyzykLinia2[0].position = sf::Vector2f(i*szerokoscPola + 190.f, j*szerokoscPola + 16.f);
                    krzyzykLinia2[1].position = sf::Vector2f(i*szerokoscPola + 16.f, j*szerokoscPola + 190.f);
                    krzyzykLinia2[2].position = sf::Vector2f(i*szerokoscPola + 10.f, j*szerokoscPola + 184.f);
                    krzyzykLinia2[3].position = sf::Vector2f(i*szerokoscPola + 184.f, j*szerokoscPola + 10.f);
                    okno.draw(krzyzykLinia2);
                }
            }
        }

        //Render granic pol
        liniaPozioma.setPosition(0.f, 198.f);
        okno.draw(liniaPozioma);
        liniaPozioma.setPosition(0.f, 398.f);
        okno.draw(liniaPozioma);
        liniaPionowa.setPosition(202.f, 0.f);
        okno.draw(liniaPionowa);
        liniaPionowa.setPosition(402.f, 0.f);
        okno.draw(liniaPionowa);

        okno.draw(tekstWynik);

        okno.draw(przycisk1);
        okno.draw(tekstPrzycisk1);

        okno.draw(przycisk2);
        okno.draw(tekstPrzycisk2);

        okno.draw(tekstStatus);

        okno.display();
    }
}
