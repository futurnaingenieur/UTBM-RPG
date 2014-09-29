#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

using namespace std;

void drawMap(sf::RenderWindow*app,bool matrix[6][6], char* level, sf::RectangleShape *boba, bool firstime)
{
    char a;
    sf::RectangleShape r;
    r.setSize(sf::Vector2f(100,100));
    sf::Texture texture_wall;
    sf::Texture texture_floor;
    sf::Texture texture_bed;
    texture_wall.loadFromFile("mur.jpg");
    texture_floor.loadFromFile("sol.jpg");
    texture_bed.loadFromFile("bed.jpg");

    //If first==true then it means that the heroe swich of room so we need to place the heroe in the good location respecting to the room.
    if(level == "Room2.txt" && firstime)
    boba->setPosition(sf::Vector2f(0,100));
    if(level == "Room1.txt" && firstime)
    boba->setPosition(sf::Vector2f(500,100));


    ifstream flux(level);
    if(flux)
    {

    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            flux.get(a);
            //cout<<a;
            if(a=='0'){
                r.setTexture(&texture_wall);
                matrix[j][i]=false;
            }
            else if(a=='1'){
                r.setTexture(&texture_floor);
                matrix[j][i]=true;
            }
            else if(a=='2'){
                r.setTexture(&texture_bed);
                matrix[j][i]=false;
            }
            r.setPosition(sf::Vector2f(j*100,i*100));
            app->draw(r);
        }
        //cout<<endl;
        flux.get(a);
    }

    }
    else
     cout<< "problem";
}





///----------------------------------------------------------



int main()
{
    sf::RenderWindow app(sf::VideoMode(600,600,32),"TEST");

    app.setFramerateLimit(60);

    sf::Event event;

    bool matrix[6][6];
    char* level="Room1.txt";
    sf::Texture t_boba;
    t_boba.loadFromFile("nournourR.png");
    sf::RectangleShape boba;
    boba.setSize(sf::Vector2f(100,100));
    boba.setTexture(&t_boba);
    boba.setPosition(sf::Vector2f(100,100));

    int x_bobaL=(boba.getPosition().x)/100,
    x_bobaR=((boba.getPosition().x)+100)/100,
    y_bobaT=(boba.getPosition().y)/100,
    y_bobaB=((boba.getPosition().y)+100)/100;

    sf::Texture t_dredre;
    t_dredre.loadFromFile("dredre2.png");
    sf::RectangleShape dredre;
    dredre.setSize(sf::Vector2f(100,100));
    dredre.setTexture(&t_dredre);
    dredre.setPosition(sf::Vector2f(400,100));

    while(app.isOpen())
    {
        app.clear();
        drawMap(&app,matrix,level, &boba, false);
        app.draw(boba);

        while(app.pollEvent(event))
        {
            switch(event.type)
            {
            case sf::Event::Closed:
                app.close();
                break;
            case sf::Event::KeyPressed:
                cout<<x_bobaL<<" "<<y_bobaT<<endl;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                        t_boba.loadFromFile("nournourL.png");
                        if((int)boba.getPosition().y%100==0){
                            if(((int)boba.getPosition().x%100==0 && matrix[x_bobaL-1][y_bobaT]) || (int)boba.getPosition().x%100!=0 )
                            {
                                boba.move(sf::Vector2f(-10,0));
                            }
                            else if( x_bobaL-1<0)
                                boba.move(sf::Vector2f(-10,0));
                        }
                        else{
                            if(((int)boba.getPosition().x%100==0 && matrix [x_bobaL-1][y_bobaT] && matrix[x_bobaL-1][y_bobaB])||((int)boba.getPosition().x%100!=0))
                            {
                                boba.move(sf::Vector2f(-10,0));
                            }
                        }
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    t_boba.loadFromFile("nournourR.png");
                    if((int)boba.getPosition().y%100==0){
                            if(((int)boba.getPosition().x%100==0 && matrix[x_bobaR][y_bobaT]) || (int)boba.getPosition().x%100!=0 )
                            {
                                boba.move(sf::Vector2f(10,0));
                            }
                        }
                        else{
                            if(((int)boba.getPosition().x%100==0 && matrix [x_bobaR][y_bobaT] && matrix[x_bobaL+1][y_bobaB])||((int)boba.getPosition().x%100!=0))
                            {
                                boba.move(sf::Vector2f(10,0));
                            }
                        }
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    if((int)boba.getPosition().x%100==0){
                            if(((int)boba.getPosition().y%100==0 && matrix[x_bobaL][y_bobaT-1]) || (int)boba.getPosition().y%100!=0 )
                            {
                                boba.move(sf::Vector2f(0,-10));
                            }
                        }
                        else{
                            if(((int)boba.getPosition().y%100==0 && matrix [x_bobaL][y_bobaT-1] && matrix[x_bobaR][y_bobaT-1])||((int)boba.getPosition().y%100!=0))
                            {
                                boba.move(sf::Vector2f(0,-10));
                            }
                        }
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    if((int)boba.getPosition().x%100==0){
                            if(((int)boba.getPosition().y%100==0 && matrix[x_bobaL][y_bobaB]) || (int)boba.getPosition().y%100!=0 )
                            {
                                boba.move(sf::Vector2f(0,10));
                            }
                        }
                        else{
                            if(((int)boba.getPosition().y%100==0 && matrix [x_bobaL][y_bobaB] && matrix[x_bobaR][y_bobaB])||((int)boba.getPosition().y%100!=0))
                            {
                                boba.move(sf::Vector2f(0,10));
                            }
                        }
                }
                break;
            default:
                break;
            }
            x_bobaL=(boba.getPosition().x)/100;
            x_bobaR=((boba.getPosition().x)+100)/100;
            y_bobaT=(boba.getPosition().y)/100;
            y_bobaB=((boba.getPosition().y)+100)/100;
            if(x_bobaL>5){
                    //that's the case when the heroe cross the gate on the top right of the room1
                level="Room2.txt";
                drawMap(&app,matrix,level, &boba, true);
            }
            if(x_bobaL<0){
                //that's the case when the heroe cross the gate on the top left of the room2
                level="Room1.txt";
                drawMap(&app,matrix,level, &boba , true);
            }
        }
        dredre.setPosition(sf::Vector2f(400,100));
        app.draw(dredre);
        app.display();
    }

    return 0;
}
