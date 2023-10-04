#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<iostream>
#include<ctime>
#include<Windows.h>
#include<SFML/Audio.hpp>
#include<sstream>
#include<ctime>
using namespace sf;
using namespace std;
int playersnum, lvl = 1;
float x1 = 0, x2 = 0, x3 = 0, x4 = 0, delay = 0.2;
int y = 0, yy = 0, yyy = 0, yyyy = 0;
int move1 = 0, move2 = 0, move3 = 0, move4 = 0;
float const g = 0;
float s = 1.2;
bool endd = 0;

RenderWindow window(VideoMode(1920, 1080), "kitty cat");
//
struct flag {
    bool keytoken = 0;
    int numplayer = 0;
    bool button1_pressed = false;
    bool button2_pressed = false;
    bool atright[10] = {};
    bool buttons[4] = { 0,0,0,0 };
    int bigwall_check = 0;;
    bool key_check = false;
    bool donefourlvl3 = false;
    bool done = false;

};
//
struct player
{
    Texture texture;
    Sprite sprite;
    int movespeed = 0;
    bool right = 1;
    FloatRect rect;
    float movex = 0, movey = 0;
    bool onground = false;;

    void update(float time, int r, int l) {
        rect.left += movex * time;
        rect.top += movey * time;
        if (rect.left > r) {
            rect.left = r;
        }
        if (rect.left <= l) {
            rect.left = l;
        }


        if (!onground)
        {
            movey += (0.002 * time);
        }
        onground = false;
        sprite.setPosition(rect.left, rect.top);
        movex = 0;

    }
};
//players functions
void playertext(player(&x)[4], int n);
void player1move(player& s);
void player2move(player& s);
void player3move(player& s);
void player4move(player& s);
void drawplayer(player x[], int i);
void coll_between_players(player a[], int n);

struct objects1 {
    Texture texture, texture1, texture2, texture3, wall, wall1, keyy, button, button1, buttonright, button1right, buttonleft, button1left, backgroundd, door, door1;
    Sprite box[20], box1[20], box2[60], box3[30], bigwall[10], smallwall1[10], key, openbutton[10], closedbutton[10], background[5], doorclosed, dooropen
        , openbuttonright[5], closedbuttonright[5], openbuttonleft[5], closedbuttonleft[5];
};
struct objects2 {
    Texture texture, texture1, texture2, texture3, wall, wall1, keyy, button, button1, buttonright, button1right, buttonleft, button1left, backgroundd, door, door1;
    Sprite box[20], box1[20], box2[70], box3[30], bigwall[20], smallwall1[20], key, openbutton[10], closedbutton[10], background[5], doorclosed, dooropen
        , openbuttonright[5], closedbuttonright[5], openbuttonleft[5], closedbuttonleft[5];
};
struct objects3 {
    Texture texture, texture1, texture2, texture3, wall, wall1, keyy, button, button1, buttonright, button1right, buttonleft, button1left, backgroundd, door, door1;
    Sprite box[20], box1[20], box2[60], box3[30], bigwall[10], smallwall1[10], key, openbutton[10], closedbutton[10], background[5], doorclosed, dooropen
        , openbuttonright[5], closedbuttonright[5], openbuttonleft[5], closedbuttonleft[5];
};
//two player functions////////////////////////////////
//lvl 1 functions 
//////////////////////////////////////////////
void cam(CircleShape c, View v);
void small_walls(player a[], objects1& b); //
void ground(player a[], objects1& b);      //
void walls(player a[], objects1& b);       //
void walls_movement(objects1& b);          //
void two_players_lvl1_gameplay();          //
//void key(player a[], objects1& b, flag& f);//
void box_3(player a[], objects1& b);       //
/////////////////////////////////////////////
void loadtext1(objects1& a);          //
void loadtext2(objects2& a);          //
void loadtext3(objects3& a);          //
void setSprite1(objects1& box);       //  
void setSprite2(objects2& box);       //
void setSprite3(objects3& box);       //
void twoplayerlvl1(objects1& w);      //
void twoplayerlvl1draw(objects1& w);  //
void twoplayerlvl2(objects2& w);      //
void twoplayerlvl2draw(objects2& w);  //
void twoplayerlvl3(objects3& w);      //
void twoplayerlvl3draw(objects3& w);  //
////////////////////////////////////////
//three player functions
///////////////////////////////////////
void threesetSprite1(objects1& a);//////
void threesetSprite2(objects2& a);//////
void three_players_lvl2_gameplay();//////
void threesetSprite3(objects2& a);//////
void threeplayerlvl1(objects1& a);//////
void three_players_lvl1_gameplay();
void threeplayerlvl2(objects2& a);//////
void threeplayerlvl3(objects2& a);//////
void threeplayerlvl1draw(objects1& a);//
void threeplayerlvl2draw(objects2& a);//
void threeplayerlvl3draw(objects2& a);//
///////////////////////////////////////
//////////////////////////////////
void key1(player a[], objects1& b, flag& f, int n);
void key2(player a[], objects2& b, flag& f, int n);
void key3(player a[], objects3& b, flag& f, int n);
/////////////////////////////
void fourplayerlvl3(objects3& a);
void foursetSprite3(objects3& a);
void fourplayerlvl3draw(objects3& a);
void fourplayerlvl3gameplay();
//////////////////////////////
void ground1(player a[], objects1& b, int n, int x);
void ground2(player a[], objects2& b, int n, int x);
void ground3(player a[], objects3& b, int n, int x);
/////////////////////////////////
void box_31(player a[], objects1& b);
void box_32(player a[], objects2& b, int players);
void box_33(player a[], objects3& b, int players);
void long_walls1(player a[], objects1& b);
void long_walls2(player a[], objects2& b, int n);
void long_walls3(player a[], objects3& b);
///////////////////////////////////////////
void small_walls1(player a[], objects1& b, int players, int objects);
void small_walls2(player a[], objects2& b, int players, int objects);
void small_walls3(player a[], objects3& b, int players, int objects);
//////////////////////
void button_threeplayers(player a[], objects2& b, flag& f);
void rest(player a[], int n);
void threeplayerslvl2gameplay();
void button_fourplayers_lvl3(player a[], objects3& b, flag& f);
void threeplayerlvl3gameplay();
void walls_movement_threeplayer(objects2& b, flag& flag);
SoundBuffer jumpsound, key;

int main() {

    Music music;
    music.openFromFile("sounds/Hateno Village (The Legend of Zelda_ Breath of the Wild OST).wav");
    music.setVolume(50);
    music.setLoop(true);
    music.play();
    cin >> lvl;
    while (true) {
        if (lvl == 2) {
            two_players_lvl1_gameplay();
        }
        else if (lvl == 3) {
            while (true) {
                if (endd) {
                    break;
                }
                threeplayerslvl2gameplay();
            }
        }
        else if (lvl == 4) {
            while (true) {
                if (endd == true) {
                    break;
                }
                fourplayerlvl3gameplay();
            }
        }
        else break;

    }
}

void key1(player a[], objects1& b, flag& f, int n) {

    for (int i = 0; i < n; i++) {
        if (f.keytoken == true) {
            continue;
        }
        if (b.key.getGlobalBounds().intersects(a[i].sprite.getGlobalBounds())) {
            f.keytoken = true;
            f.numplayer = i;
        }
    }
    if (f.keytoken == true) {
        b.key.setPosition(a[f.numplayer].sprite.getPosition().x, a[f.numplayer].sprite.getPosition().y);
    }

}

void key2(player a[], objects2& b, flag& f, int n) {

    for (int i = 0; i < n; i++) {
        if (f.keytoken == true) {
            continue;
        }
        if (b.key.getGlobalBounds().intersects(a[i].sprite.getGlobalBounds())) {
            f.keytoken = true;
            f.numplayer = i;
        }
    }
    if (f.keytoken == true) {
        b.key.setPosition(a[f.numplayer].sprite.getPosition().x, a[f.numplayer].sprite.getPosition().y);
    }

}

void key3(player a[], objects3& b, flag& f, int n) {

    for (int i = 0; i < n; i++) {
        if (f.keytoken == true) {
            continue;
        }
        if (b.key.getGlobalBounds().intersects(a[i].sprite.getGlobalBounds())) {
            f.keytoken = true;
            f.numplayer = i;
        }
    }
    if (f.keytoken == true) {
        b.key.setPosition(a[f.numplayer].sprite.getPosition().x, a[f.numplayer].sprite.getPosition().y);
    }

}
//GAMEPLAY//
void two_players_lvl1_gameplay() {
    window.setFramerateLimit(60);
    objects1 w1;

    player players[4];
    flag f;
    playertext(players, 2);

    loadtext1(w1);
    setSprite1(w1);
    twoplayerlvl1(w1);




    players[0].rect.left = 100;
    players[0].rect.top = 800;
    players[1].rect.left = 100;
    players[1].rect.top = 500;
    Clock clock;
    while (window.isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 650;
        Event event;
        if (time > 20) {
            time = 20;
        }
        while (window.pollEvent(event)) {

            if (event.type == Event::Closed) {
                window.close();

            }

        }





        /*f.keytoken==true &&*/
        if (w1.key.getGlobalBounds().intersects(w1.doorclosed.getGlobalBounds())) {
            w1.doorclosed.setTexture(w1.door1);
            lvl++;

        }
        if (players[0].sprite.getGlobalBounds().intersects(w1.openbutton[0].getGlobalBounds()) || players[1].sprite.getGlobalBounds().intersects(w1.openbutton[0].getGlobalBounds()))
        {
            w1.openbutton[0].setTexture(w1.button1);
            f.button1_pressed = true;
            f.button2_pressed = false;
            w1.openbutton[1].setTexture(w1.button);
        }

        if (players[0].sprite.getGlobalBounds().intersects(w1.openbutton[1].getGlobalBounds()) || players[1].sprite.getGlobalBounds().intersects(w1.openbutton[1].getGlobalBounds()))
        {
            if (players[0].rect.left + 60 >= w1.openbutton[1].getPosition().x)
            {
                w1.openbutton[1].setTexture(w1.button1);
                f.button1_pressed = false;
                f.button2_pressed = true;
                w1.openbutton[0].setTexture(w1.button);
            }
        }

        if (f.button1_pressed)
        {
            if (w1.bigwall[1].getPosition().y != 630) {
                w1.bigwall[1].move(0, -5);
            }
            for (int i = 0; i < 4; i++)
            {
                w1.box3[i].move(5, 0);
                if (w1.box3[i].getPosition().x >= 1385 - (i * 62))
                {
                    w1.box3[i].move(-5, 0);
                }
            }

            for (int i = 4; i < 8; i++)
            {
                w1.box3[i].move(-5, 0);
                if (w1.box3[i].getPosition().x <= 1385 - (i * 62))
                {
                    w1.box3[i].move(+5, 0);

                }
            }
        }

        if (f.button2_pressed == false && f.button1_pressed == true)
        {
            w1.bigwall[5].move(0, +5);
            if (w1.bigwall[5].getPosition().y >= 850)
            {
                w1.bigwall[5].move(0, -5);
            }
        }

        if (f.button2_pressed == true && f.button1_pressed == false)
        {
            if (w1.bigwall[1].getPosition().y != 0) {
                w1.bigwall[1].move(0, 5);
            }
            w1.bigwall[5].move(0, -5);
            if (w1.bigwall[5].getPosition().y <= 585)
            {
                w1.bigwall[5].move(0, +5);
            }
        }

        if (w1.bigwall[1].getPosition().x == 500) {
            f.atright[0] = true;
        }
        else if (w1.bigwall[1].getPosition().x == 0) {
            f.atright[0] = false;
        }

        if (f.atright[0] == false) {
            w1.bigwall[1].move(5, 0);

        }
        else {
            w1.bigwall[1].move(-5, 0);


        }

        if (w1.bigwall[3].getPosition().x == 450) {
            f.atright[1] = true;
        }
        else if (w1.bigwall[3].getPosition().x == 100) {
            f.atright[1] = false;
        }

        if (f.atright[1] == true) {
            w1.bigwall[3].move(-5, 0);

        }
        else {
            w1.bigwall[3].move(5, 0);


        }
        coll_between_players(players, 2);
        if (players[0].sprite.getGlobalBounds().intersects(w1.doorclosed.getGlobalBounds()) && players[1].sprite.getGlobalBounds().intersects(w1.doorclosed.getGlobalBounds())) {

            break;
        }

        key1(players, w1, f, 2);
        small_walls(players, w1);
        walls(players, w1);
        ground(players, w1);
        box_3(players, w1);
        walls_movement(w1);

        player1move(players[0]);
        player2move(players[1]);
        players[0].update(time, 1800, -20);
        players[1].update(time, 1800, -20);








        window.clear();

        twoplayerlvl1draw(w1);

        drawplayer(players, 2);
        window.display();
    }
}


void threeplayerslvl2gameplay()
{
    window.setFramerateLimit(60);
    objects2 w2;
    float veiww = 1920 / 2;
    player players[4];
    flag f;
    playertext(players, 3);

    loadtext2(w2);
    threesetSprite2(w2);
    threeplayerlvl2(w2);
    threeplayerlvl2draw(w2);

    CircleShape c(50);
    c.setPosition(1920 / 2, 1080 / 2);
    View view(FloatRect(0, 0, 1920, 1080));
    Clock clock;
    players[0].rect.top = 400;
    players[1].rect.top = 400;
    players[2].rect.top = 400;
    players[0].rect.left = 0;
    players[1].rect.left = 75;
    players[2].rect.left = 150;

    while (window.isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 650;
        Event event;
        if (time > 20) {
            time = 20;
        }
        view.setCenter(players[0].sprite.getPosition());
        window.setView(view);

        while (window.pollEvent(event)) {

            if (event.type == Event::Closed) {
                window.close();

            }

        }
        view.setCenter(c.getPosition());
        c.setPosition(veiww, 1080 / 2);
        veiww += 1;
        window.setView(view);
        rest(players, 3);
        key2(players, w2, f, 3);

        small_walls2(players, w2, 3, 6);
        //for (int i = 0; i < 3; i++) {
        if (players[0].sprite.getPosition().x >= c.getPosition().x + 1000 || players[0].sprite.getPosition().x <= c.getPosition().x - 1100.1f
            || players[0].sprite.getPosition().x >= c.getPosition().x + 1000 || players[0].sprite.getPosition().x <= c.getPosition().x - 1100.1f
            || players[1].sprite.getPosition().x >= c.getPosition().x + 1000 || players[1].sprite.getPosition().x <= c.getPosition().x - 1100.1f
            || players[2].sprite.getPosition().x >= c.getPosition().x + 1000 || players[2].sprite.getPosition().x <= c.getPosition().x - 1100.1f) {
            break;

        }
        //}
        if (w2.key.getGlobalBounds().intersects(w2.doorclosed.getGlobalBounds())) {
            w2.doorclosed.setTexture(w2.door1);
            w2.key.setScale(0, 0);
            f.done = true;

        }
        if (f.done == true) {
            if (players[0].sprite.getGlobalBounds().intersects(w2.doorclosed.getGlobalBounds()) && players[1].sprite.getGlobalBounds().intersects(w2.doorclosed.getGlobalBounds()) && players[2].sprite.getGlobalBounds().intersects(w2.doorclosed.getGlobalBounds())) {
                endd = true;
                break;
            }
        }

        box_32(players, w2, 3);
        button_threeplayers(players, w2, f);

        long_walls2(players, w2, 10);
        ground2(players, w2, 70, 3);
        player1move(players[0]);
        player2move(players[1]);
        player3move(players[2]);
        player4move(players[3]);
        players[0].update(time, 4900, -20);
        players[1].update(time, 4900, -20);
        players[2].update(time, 4900, -20);
        coll_between_players(players, 3);


        window.clear();

        threeplayerlvl2draw(w2);

        drawplayer(players, 3);
        window.display();
    }
}

void threeplayerlvl3gameplay()
{
    window.setFramerateLimit(60);
    objects2 w2;

    player players[4];
    flag f;
    playertext(players, 3);

    loadtext2(w2);
    threesetSprite3(w2);
    threeplayerlvl3(w2);


    CircleShape player(50);
    player.setPosition(1920 / 2, 1080 / 2);
    View view(FloatRect(0, 0, 1920, 1080));
    Clock clock;
    while (window.isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 650;
        Event event;
        if (time > 20) {
            time = 20;
        }
        view.setCenter(player.getPosition());
        window.setView(view);
        if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
            player.move(4, 0);
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
            player.move(-4, 0);
        }
        while (window.pollEvent(event)) {

            if (event.type == Event::Closed) {
                window.close();

            }

        }

        /* small_walls_threeplayers(players, w3);
         walls_threeplayers(players, w3);
         ground_threeplayers(players, w3);*/
        box_32(players, w2, 3);
        long_walls2(players, w2, 10);
        /*button_threeplayers_lvl3(players, w3, f);*/

        ground2(players, w2, 40, 3);

        coll_between_players(players, 3);
        player1move(players[0]);
        player2move(players[1]);
        player3move(players[2]);

        players[0].update(time, 3400, -20);
        players[1].update(time, 3400, -20);
        players[2].update(time, 3400, -20);
        window.clear();

        threeplayerlvl3draw(w2);

        drawplayer(players, 3);
        window.display();
    }

}
//
void button_threeplayers(player a[], objects2& b, flag& f)
{
    for (int j = 0; j < 3; j++)
    {
        if (a[0].sprite.getGlobalBounds().intersects(b.openbutton[j].getGlobalBounds()) || a[1].sprite.getGlobalBounds().intersects(b.openbutton[j].getGlobalBounds()) || a[2].sprite.getGlobalBounds().intersects(b.openbutton[j].getGlobalBounds()))
        {
            if (a[0].rect.left + 71.5f >= b.openbutton[j].getPosition().x || a[0].rect.left + 72 >= b.openbutton[j].getPosition().x || a[1].rect.left + 71.5 <= b.openbutton[j].getPosition().x || a[1].rect.left + 72 <= b.openbutton[j].getPosition().x || a[2].rect.left + 71.5 <= b.openbutton[j].getPosition().x || a[2].rect.left + 72 <= b.openbutton[j].getPosition().x || a[3].rect.left + 71.5 <= b.openbutton[j].getPosition().x || a[3].rect.left + 72 <= b.openbutton[j].getPosition().x)
                b.openbutton[j].setTexture(b.button1);
            f.buttons[j] = true;
        }
        else
        {

            b.openbutton[j].setTexture(b.button);
            f.buttons[j] = false;



        }
    }
    /*f.buttons[0] = true;
    f.buttons[1] = true;
    f.buttons[2] = true;*/
    if (f.buttons[0] == true)
    {
        if (b.smallwall1[1].getPosition().y >= 0) {
            b.smallwall1[1].move(0, -2);
        }


    }
    else {
        if (b.smallwall1[1].getPosition().y <= 340) {
            b.smallwall1[1].move(0, 2);
        }
    }
    if (f.buttons[1] == true)
    {
        if (b.smallwall1[2].getPosition().y >= -50)
        {
            b.smallwall1[2].move(0, -2);
        }

    }
    else {
        if (b.smallwall1[2].getPosition().y <= 240) {

            b.smallwall1[2].move(0, 2);
        }

    }

    if (f.buttons[2] == true)
    {
        if (b.smallwall1[3].getPosition().y <= -150)
        {
            b.smallwall1[3].move(0, -2);
        }



    }
    for (int j = 3; j < 6; j++)
    {
        if (a[0].sprite.getGlobalBounds().intersects(b.openbutton[j].getGlobalBounds()) || a[1].sprite.getGlobalBounds().intersects(b.openbutton[j].getGlobalBounds()) || a[2].sprite.getGlobalBounds().intersects(b.openbutton[j].getGlobalBounds()))
        {
            if (a[0].rect.left - 10 >= b.openbutton[j].getPosition().x || a[0].rect.left - 10.5 >= b.openbutton[j].getPosition().x || a[1].rect.left + 71.5 <= b.openbutton[j].getPosition().x || a[1].rect.left + 72 <= b.openbutton[j].getPosition().x || a[2].rect.left + 71.5 <= b.openbutton[j].getPosition().x || a[2].rect.left + 72 <= b.openbutton[j].getPosition().x || a[3].rect.left + 71.5 <= b.openbutton[j].getPosition().x || a[3].rect.left + 72 <= b.openbutton[j].getPosition().x)
                b.openbutton[j].setTexture(b.button1);
            f.buttons[j] = true;
        }
        else
        {

            b.openbutton[j].setTexture(b.button);
            f.buttons[j] = false;



        }
    }

    if (f.buttons[3] == true)
    {
        if (b.smallwall1[4].getPosition().y >= -500) {
            b.smallwall1[4].move(0, -2);
        }


    }
    else {
        if (b.smallwall1[4].getPosition().y <= 120) {
            b.smallwall1[4].move(0, 2);
        }
    }
    if (f.buttons[4] == true)
    {
        if (b.smallwall1[5].getPosition().y >= -500)
        {
            b.smallwall1[5].move(0, -2);
        }

    }
    else {
        if (b.smallwall1[5].getPosition().y <= 120) {

            b.smallwall1[5].move(0, 2);
        }

    }
    if (f.buttons[5] == true)
    {
        if (b.smallwall1[0].getPosition().y >= -500)
        {
            b.smallwall1[0].move(0, -2);
        }

    }
    else {
        if (b.smallwall1[0].getPosition().y <= 120) {

            b.smallwall1[0].move(0, 2);
        }

    }


}
//
//void walls_movement_threeplayer(objects2& b, flag& flag)
//{
//    if (b.bigwall[3].getPosition().y == 660) {
//        flag.atright[0] = true;
//    }
//    else if (b.bigwall[3].getPosition().y == 230) {
//        flag.atright[0] = false;
//    }
//
//    if (flag.atright[0] == false) {
//        b.bigwall[3].move(0, 5);
//
//    }
//    else
//    {
//        b.bigwall[3].move(0, -5);
//
//    }
//}

//


void fourplayerlvl3gameplay()
{
    window.setFramerateLimit(60);
    objects3 w3;
    float veiww = 1920 / 2;
    player players[4];
    flag f;
    playertext(players, 4);

    loadtext3(w3);
    foursetSprite3(w3);
    fourplayerlvl3(w3);
    fourplayerlvl3draw(w3);
    for (int i = 0; i < 4; i++) {
        players[i].rect.left = 75 * i;
        players[i].rect.top = 300;
    }
    CircleShape c(50);
    c.setPosition(960, 540);
    View view(FloatRect(0, 0, 1920, 1080));
    Clock clock;
    while (window.isOpen()) {
        float t1 = clock.getElapsedTime().asMicroseconds();

        clock.restart();
        t1 /= 650;

        Event event;
        if (t1 > 20) {
            t1 = 20;
        }



        view.setCenter(c.getPosition());
        c.setPosition(veiww, 1080 / 2);
        veiww += 0.5;
        window.setView(view);

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();

            }
        }
        if (w3.key.getGlobalBounds().intersects(w3.dooropen.getGlobalBounds())) {
            w3.doorclosed.setTexture(w3.door1);
            w3.key.setScale(0, 0);

        }
        if (players[0].sprite.getPosition().x >= c.getPosition().x + 1000 || players[0].sprite.getPosition().x <= c.getPosition().x - 1100.1f
            || players[0].sprite.getPosition().x >= c.getPosition().x + 1000 || players[0].sprite.getPosition().x <= c.getPosition().x - 1100.1f
            || players[1].sprite.getPosition().x >= c.getPosition().x + 1000 || players[1].sprite.getPosition().x <= c.getPosition().x - 1100.1f
            || players[2].sprite.getPosition().x >= c.getPosition().x + 1000 || players[2].sprite.getPosition().x <= c.getPosition().x - 1100.1f
            || players[3].sprite.getPosition().x >= c.getPosition().x + 1000 || players[3].sprite.getPosition().x <= c.getPosition().x - 1100.1f) {
            break;

        }
        //}
        if (w3.key.getGlobalBounds().intersects(w3.doorclosed.getGlobalBounds())) {
            w3.doorclosed.setTexture(w3.door1);
            w3.key.setScale(0, 0);
            f.done = true;

        }
        if (f.done == true) {
            if (players[0].sprite.getGlobalBounds().intersects(w3.doorclosed.getGlobalBounds()) && players[1].sprite.getGlobalBounds().intersects(w3.doorclosed.getGlobalBounds()) && players[2].sprite.getGlobalBounds().intersects(w3.doorclosed.getGlobalBounds()) && players[3].sprite.getGlobalBounds().intersects(w3.doorclosed.getGlobalBounds())) {
                endd = true;
                break;
            }
        }
        coll_between_players(players, 4);
        small_walls3(players, w3, 4, 4);
        long_walls3(players, w3);
        ground3(players, w3, 4, 60);
        box_33(players, w3, 4);
        player1move(players[0]);
        player2move(players[1]);
        player3move(players[2]);
        player4move(players[3]);

        players[0].update(t1, 7300, -20);
        players[1].update(t1, 7300, -20);
        players[2].update(t1, 7300, -20);
        players[3].update(t1, 7300, -20);
        button_fourplayers_lvl3(players, w3, f);
        rest(players, 4);
        key3(players, w3, f, 4);
        window.clear();
        fourplayerlvl3draw(w3);
        drawplayer(players, 4);
        window.display();
    }
}
void rest(player a[], int n) {
    for (int i = 0; i < n; i++) {

        if (a[i].sprite.getPosition().y >= 1100) {
            a[i].rect.top = 200;


        }

    }
}
//camera
void cam(CircleShape c, View v) {
    float f = 1920 / 2;
    v.setCenter(c.getPosition());
    c.setPosition(f, 540);
    f += 2;

}


//coll
void small_walls1(player a[], objects1& b, int players, int objects) {
    for (int i = 0; i < objects; i++) {

        for (int j = 0; j < players; j++) {
            if (a[j].sprite.getGlobalBounds().intersects(b.smallwall1[i].getGlobalBounds()))
            {
                if ((a[j].rect.left + 71.5 <= b.smallwall1[i].getPosition().x) || (a[j].rect.left + 72 <= b.smallwall1[i].getPosition().x))
                {
                    a[j].rect.left = b.smallwall1[i].getPosition().x - 110;
                }

                else if ((a[j].rect.left - 50 >= b.smallwall1[i].getPosition().x) || (a[j].rect.left - 50.5 >= b.smallwall1[i].getPosition().x))
                {
                    a[j].rect.left = b.smallwall1[i].getPosition().x + 60;

                }

                else
                {
                    a[j].movey = 0;
                    a[j].rect.top = b.smallwall1[i].getPosition().y - 110;
                    a[j].onground = true;
                }
            }
        }
    }
}

void small_walls2(player a[], objects2& b, int players, int objects) {
    for (int i = 0; i < objects; i++) {

        for (int j = 0; j < players; j++) {
            if (a[j].sprite.getGlobalBounds().intersects(b.smallwall1[i].getGlobalBounds()))
            {
                if ((a[j].rect.left + 71.5 <= b.smallwall1[i].getPosition().x) || (a[j].rect.left + 72 <= b.smallwall1[i].getPosition().x))
                {
                    a[j].rect.left = b.smallwall1[i].getPosition().x - 110;
                }

                else if ((a[j].rect.left - 50 >= b.smallwall1[i].getPosition().x) || (a[j].rect.left - 50.5 >= b.smallwall1[i].getPosition().x))
                {
                    a[j].rect.left = b.smallwall1[i].getPosition().x + 60;

                }

                else
                {
                    a[j].movey = 0;
                    a[j].onground = true;
                    if (a[j].rect.top > b.bigwall[i].getPosition().y + 100)
                    {

                        a[j].onground = false;
                    }
                    else {
                        a[j].rect.top = b.smallwall1[i].getPosition().y - 110;
                        a[j].onground = true;
                    }
                }
            }
        }
    }
}

void small_walls3(player a[], objects3& b, int players, int objects) {
    for (int i = 0; i < objects; i++) {

        for (int j = 0; j < players; j++) {
            if (a[j].sprite.getGlobalBounds().intersects(b.smallwall1[i].getGlobalBounds()))
            {
                if ((a[j].rect.left + 71.5 <= b.smallwall1[i].getPosition().x) || (a[j].rect.left + 72 <= b.smallwall1[i].getPosition().x))
                {
                    a[j].rect.left = b.smallwall1[i].getPosition().x - 110;
                }

                else if ((a[j].rect.left - 50 >= b.smallwall1[i].getPosition().x) || (a[j].rect.left - 50.5 >= b.smallwall1[i].getPosition().x))
                {
                    a[j].rect.left = b.smallwall1[i].getPosition().x + 60;

                }

                else
                {
                    a[j].movey = 0;
                    a[j].rect.top = b.smallwall1[i].getPosition().y - 110;
                    a[j].onground = true;
                }
            }
        }
    }
}

void ground1(player a[], objects1& b, int n, int x) {
    for (int j = 0; j < x; j++) {

        for (int i = 0; i < n; i++) {

            if (a[j].sprite.getGlobalBounds().intersects(b.box2[i].getGlobalBounds())) {

                a[j].movey = 0;

                a[j].onground = 1;

                a[j].rect.top = b.box2[i].getPosition().y - 110;

                a[j].onground = true;


            }
        }
    }
}

void ground2(player a[], objects2& b, int n, int x) {
    for (int j = 0; j < x; j++) {

        for (int i = 0; i < n; i++) {

            if (a[j].sprite.getGlobalBounds().intersects(b.box2[i].getGlobalBounds())) {

                a[j].movey = 0;

                a[j].onground = 1;

                a[j].rect.top = b.box2[i].getPosition().y - 110;

                a[j].onground = true;


            }
        }
    }
}

void ground3(player a[], objects3& b, int n, int x) {
    for (int j = 0; j < n; j++) {

        for (int i = 0; i < x; i++) {

            if (a[j].sprite.getGlobalBounds().intersects(b.box2[i].getGlobalBounds())) {

                a[j].movey = 0;

                a[j].onground = 1;

                a[j].rect.top = b.box2[i].getPosition().y - 110;

                a[j].onground = true;


            }
        }
    }
}

void box_31(player a[], objects1& b)
{
    for (int i = 0; i < 8; i++) {

        for (int j = 0; j < 2; j++) {
            if (a[j].sprite.getGlobalBounds().intersects(b.box3[i].getGlobalBounds())) {

                if ((a[j].rect.left + 71.5 <= b.box3[i].getPosition().x) || (a[j].rect.left + 72 <= b.box3[i].getPosition().x)) {
                    a[j].rect.left = b.box3[i].getPosition().x - 110;

                }

                else
                {
                    a[j].movey = 0;
                    a[j].onground = true;
                    if (a[j].rect.top >= b.box3[i].getPosition().y && a[j].rect.left <= b.box3[i].getPosition().x + 63)
                    {
                        a[j].rect.top = b.box3[i].getPosition().y + 59;
                        a[j].onground = false;
                    }
                    else
                    {
                        a[j].rect.top = b.box3[i].getPosition().y - 109.5f;
                        a[j].onground = true;
                    }
                }

            }
        }
    }
}

void box_32(player a[], objects2& b, int players)
{
    for (int i = 0; i < 28; i++) {

        for (int j = 0; j < players; j++) {
            if (a[j].sprite.getGlobalBounds().intersects(b.box3[i].getGlobalBounds())) {

                if ((a[j].rect.left + 71.5 <= b.box3[i].getPosition().x) || (a[j].rect.left + 72 <= b.box3[i].getPosition().x)) {
                    a[j].rect.left = b.box3[i].getPosition().x - 110;

                }



                else if ((a[j].rect.left - 50 >= b.box3[i].getPosition().x) || (a[j].rect.left - 50.5 >= b.box3[i].getPosition().x))
                {
                    a[j].rect.left = b.box3[i].getPosition().x + 60;

                }
                else
                {
                    a[j].movey = 0;
                    a[j].onground = true;
                    if (a[j].rect.top >= b.box3[i].getPosition().y && a[j].rect.left <= b.box3[i].getPosition().x + 63)
                    {
                        a[j].rect.top = b.box3[i].getPosition().y + 62;
                        a[j].onground = false;
                    }
                    else
                    {
                        a[j].rect.top = b.box3[i].getPosition().y - 109.5f;
                        a[j].onground = true;
                    }
                }

            }
        }
    }
}

void box_33(player a[], objects3& b, int players)
{
    for (int i = 0; i < 28; i++) {

        for (int j = 0; j < players; j++) {
            if (a[j].sprite.getGlobalBounds().intersects(b.box3[i].getGlobalBounds())) {

                if ((a[j].rect.left + 71.5 <= b.box3[i].getPosition().x) || (a[j].rect.left + 72 <= b.box3[i].getPosition().x)) {
                    a[j].rect.left = b.box3[i].getPosition().x - 110;

                }



                else if ((a[j].rect.left - 50 >= b.box3[i].getPosition().x) || (a[j].rect.left - 50.5 >= b.box3[i].getPosition().x))
                {
                    a[j].rect.left = b.box3[i].getPosition().x + 60;

                }
                else
                {
                    a[j].movey = 0;
                    a[j].onground = true;
                    if (a[j].rect.top >= b.box3[i].getPosition().y && a[j].rect.left <= b.box3[i].getPosition().x + 63)
                    {
                        a[j].rect.top = b.box3[i].getPosition().y + 62;
                        a[j].onground = false;
                    }
                    else
                    {
                        a[j].rect.top = b.box3[i].getPosition().y - 109.5f;
                        a[j].onground = true;
                    }
                }

            }
        }
    }
}

void long_walls1(player a[], objects1& b) {
    for (int i = 0; i < 8; i++) {

        for (int j = 0; j < 4; j++) {
            if (a[j].sprite.getGlobalBounds().intersects(b.bigwall[i].getGlobalBounds())) {

                if ((a[j].rect.left + 71.5 <= b.bigwall[i].getPosition().x) || (a[j].rect.left + 72 <= b.bigwall[i].getPosition().x)) {
                    a[j].rect.left = b.bigwall[i].getPosition().x - 110;

                }

                else if (a[j].rect.left >= b.bigwall[i].getPosition().x + 285 || a[j].rect.left >= b.bigwall[i].getPosition().x + 285.5) {
                    a[j].rect.left = b.bigwall[i].getPosition().x + 345;


                }
                else
                {
                    a[j].movey = 0;
                    a[j].onground = true;
                    if (a[j].rect.top >= b.bigwall[i].getPosition().y)
                    {
                        a[j].rect.top = b.bigwall[i].getPosition().y + 59;
                        a[j].onground = false;
                    }
                    else
                    {
                        a[j].rect.top = b.bigwall[i].getPosition().y - 109.5f;
                        a[j].onground = true;
                    }
                }

            }
        }
    }
}

void long_walls2(player a[], objects2& b, int n) {
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < 4; j++) {
            if (a[j].sprite.getGlobalBounds().intersects(b.bigwall[i].getGlobalBounds())) {

                if ((a[j].rect.left + 71.5 <= b.bigwall[i].getPosition().x) || (a[j].rect.left + 72 <= b.bigwall[i].getPosition().x)) {
                    a[j].rect.left = b.bigwall[i].getPosition().x - 110;

                }

                else if (a[j].rect.left >= b.bigwall[i].getPosition().x + 285 || a[j].rect.left >= b.bigwall[i].getPosition().x + 285.5) {
                    a[j].rect.left = b.bigwall[i].getPosition().x + 345;


                }
                else
                {
                    a[j].movey = 0;
                    a[j].onground = true;
                    if (a[j].rect.top >= b.bigwall[i].getPosition().y)
                    {
                        a[j].rect.top = b.bigwall[i].getPosition().y + 59;
                        a[j].onground = false;
                    }
                    else
                    {
                        a[j].rect.top = b.bigwall[i].getPosition().y - 109.5f;
                        a[j].onground = true;
                    }
                }

            }
        }
    }
}


void long_walls3(player a[], objects3& b) {
    for (int i = 0; i < 8; i++) {

        for (int j = 0; j < 4; j++) {
            if (a[j].sprite.getGlobalBounds().intersects(b.bigwall[i].getGlobalBounds())) {

                if ((a[j].rect.left + 71.5 <= b.bigwall[i].getPosition().x) || (a[j].rect.left + 72 <= b.bigwall[i].getPosition().x)) {
                    a[j].rect.left = b.bigwall[i].getPosition().x - 110;

                }

                else if (a[j].rect.left >= b.bigwall[i].getPosition().x + 285 || a[j].rect.left >= b.bigwall[i].getPosition().x + 285.5) {
                    a[j].rect.left = b.bigwall[i].getPosition().x + 345;


                }
                else
                {
                    a[j].movey = 0;
                    a[j].onground = true;
                    if (a[j].rect.top >= b.bigwall[i].getPosition().y)
                    {
                        a[j].rect.top = b.bigwall[i].getPosition().y + 59;
                        a[j].onground = false;
                    }
                    else
                    {
                        a[j].rect.top = b.bigwall[i].getPosition().y - 109.5f;
                        a[j].onground = true;
                    }
                }

            }
        }
    }
}


//buttons
void button_fourplayers_lvl3(player a[], objects3& b, flag& f)
{
    /*  for (int i = 0; i < 3; i++)
      {
          for (int j = 0; j < 3; j++)
          {

              if (b.box[i].getGlobalBounds().intersects(b.openbutton[j].getGlobalBounds()))
              {
                  b.openbutton[j].setTexture(b.button1);
                  f.buttons[i] = true;
              }
              else
              {
                  b.openbutton[j].setTexture(b.button);
                 f.buttons[i] =false;
              }
          }
      } */
      /* f.buttons[0] = true;
         f.buttons[1] = true;
         f.buttons[2] = true;*/
    if (a[0].sprite.getGlobalBounds().intersects(b.openbutton[0].getGlobalBounds()) || a[1].sprite.getGlobalBounds().intersects(b.openbutton[0].getGlobalBounds()) || a[2].sprite.getGlobalBounds().intersects(b.openbutton[0].getGlobalBounds()) || a[3].sprite.getGlobalBounds().intersects(b.openbutton[0].getGlobalBounds())) {

        b.openbutton[0].setTexture(b.button1);
        f.buttons[0] = true;
    }
    else {
        b.openbutton[0].setTexture(b.button);
        f.buttons[0] = false;
    }


    ////////////////////////////////unknown ?? removed nested loop ?????????//////////////
    for (int j = 1; j < 5; j++)
    {
        if (a[0].sprite.getGlobalBounds().intersects(b.openbutton[j].getGlobalBounds()) || a[1].sprite.getGlobalBounds().intersects(b.openbutton[j].getGlobalBounds()) || a[2].sprite.getGlobalBounds().intersects(b.openbutton[j].getGlobalBounds()) || a[3].sprite.getGlobalBounds().intersects(b.openbutton[j].getGlobalBounds()))
        {
            if (a[0].rect.left - 10 >= b.openbutton[j].getPosition().x || a[0].rect.left - 10.5 >= b.openbutton[j].getPosition().x || a[1].rect.left + 71.5 <= b.openbutton[j].getPosition().x || a[1].rect.left + 72 <= b.openbutton[j].getPosition().x || a[2].rect.left + 71.5 <= b.openbutton[j].getPosition().x || a[2].rect.left + 72 <= b.openbutton[j].getPosition().x || a[3].rect.left + 71.5 <= b.openbutton[j].getPosition().x || a[3].rect.left + 72 <= b.openbutton[j].getPosition().x)
                b.openbutton[j].setTexture(b.button1);
            f.buttons[j] = true;
        }
        else if (f.buttons[1] == false || f.buttons[2] == false || f.buttons[3] == false || f.buttons[4] == false)
        {
            b.openbutton[j].setTexture(b.button);
            f.buttons[1] = false;
            f.buttons[2] = false;
            f.buttons[3] = false;
            f.buttons[4] = false;
        }
    }

    //first three walls in the start of the gameplay

    if (f.buttons[0] == true)
    {
        b.smallwall1[0].move(0, -2);

        if (b.smallwall1[0].getPosition().y <= 300)
        {
            b.smallwall1[0].move(0, 2);
        }
    }
    else
    {
        if (b.smallwall1[0].getPosition().y == 535)
        {

        }
        else
        {
            if (b.smallwall1[0].getPosition().y >= 535)
            {
                b.smallwall1[0].move(0, -2);
            }
            else
            {
                b.smallwall1[0].move(0, 2);
            }
        }
    }

    /*f.buttons[1] = true; f.buttons[2] = true; f.buttons[3] = true;*/
    if (f.buttons[1] == true && f.buttons[2] == true && f.buttons[3] == true && f.buttons[4] == true)
    {
        f.bigwall_check = f.bigwall_check + 1;
    }
    if (f.bigwall_check >= 1)
    {
        if (b.bigwall[1].getPosition().x == 3000) {
            f.atright[0] = true;
        }
        else if (b.bigwall[1].getPosition().x == 2600) {
            f.atright[0] = false;
        }

        if (f.atright[0] == false)
        {
            b.bigwall[1].move(5, 0);

        }
        else {
            b.bigwall[1].move(-5, 0);
        }
    }
    for (int j = 5; j < 9; j++)
    {
        if (a[0].sprite.getGlobalBounds().intersects(b.openbutton[j].getGlobalBounds()) || a[1].sprite.getGlobalBounds().intersects(b.openbutton[j].getGlobalBounds()) || a[2].sprite.getGlobalBounds().intersects(b.openbutton[j].getGlobalBounds()) || a[3].sprite.getGlobalBounds().intersects(b.openbutton[j].getGlobalBounds()))
        {
            if (a[0].rect.left - 10 >= b.openbutton[j].getPosition().x || a[0].rect.left - 10.5 >= b.openbutton[j].getPosition().x || a[1].rect.left + 71.5 <= b.openbutton[j].getPosition().x || a[1].rect.left + 72 <= b.openbutton[j].getPosition().x || a[2].rect.left + 71.5 <= b.openbutton[j].getPosition().x || a[2].rect.left + 72 <= b.openbutton[j].getPosition().x || a[3].rect.left + 71.5 <= b.openbutton[j].getPosition().x || a[3].rect.left + 72 <= b.openbutton[j].getPosition().x)
                b.openbutton[j].setTexture(b.button1);
            f.buttons[j] = true;
        }
        else if (f.buttons[5] == false || f.buttons[6] == false || f.buttons[7] == false || f.buttons[8] == false)
        {
            b.openbutton[j].setTexture(b.button);
            f.buttons[1] = false;
            f.buttons[2] = false;
            f.buttons[3] = false;
            f.buttons[4] = false;
        }
    }
    /*f.buttons[5] = true; f.buttons[6] = true; f.buttons[7] = true;*/
    if (f.buttons[5] == true && f.buttons[6] == true && f.buttons[7] == true && f.buttons[8] == true)
    {
        f.key_check = true;
    }

    if (f.key_check)
    {
        b.box3[11].move(0, 5);
        b.key.move(0, 5);
        if (b.box3[11].getPosition().y == 440)
        {
            b.box3[11].move(0, -5);
            b.key.move(0, -5);
        }
    }
}

//two players lvl1
void loadtext1(objects1& a) {
    a.texture.loadFromFile("assets/box.jpg");
    a.texture1.loadFromFile("assets/box1.png");
    a.texture2.loadFromFile("assets/box2.png");
    a.texture3.loadFromFile("assets/box3.png");
    a.wall.loadFromFile("assets/wall.jpg");
    a.wall1.loadFromFile("assets/smallwall.jpg");
    a.keyy.loadFromFile("assets/key.png");
    a.button.loadFromFile("assets/button.png");
    a.button1.loadFromFile("assets/button2.png");
    a.backgroundd.loadFromFile("assets/background.jpg");
    a.door.loadFromFile("assets/exitdoor.png");
    a.door1.loadFromFile("assets/dooropen.png");
    a.button1right.loadFromFile("assets/button2left.png");
    a.button1right.loadFromFile("assets/button2right.png");
    a.buttonright.loadFromFile("assets/buttonright.png");
    a.buttonleft.loadFromFile("assets/buttonleft.png");
}

void setSprite1(objects1& a) {
    for (int i = 0; i < 50; i++) {
        a.box[i].setTexture(a.texture);
        a.box[i].setScale(0.7, 0.7);
    }
    for (int i = 0; i < 20; i++) {
        a.box1[i].setTexture(a.texture1);
        a.box1[i].setScale(0.7, 0.7);
    }
    for (int i = 0; i < 25; i++) {
        a.box2[i].setTexture(a.texture2);
        a.box2[i].setScale(0.5, 0.5);
    }
    for (int i = 0; i < 8; i++) {
        a.box3[i].setTexture(a.texture3);
        a.box3[i].setScale(0.28, 0.28);
    }
    for (int i = 0; i < 8; i++) {
        a.bigwall[i].setTexture(a.wall);
        a.bigwall[i].setScale(0.112f, 0.28f);
    }
    for (int i = 0; i < 2; i++) {
        a.smallwall1[i].setTexture(a.wall1);
        a.smallwall1[i].setScale(0.28, 0.84);
    }
    for (int i = 0; i < 2; i++) {
        a.openbutton[i].setTexture(a.button);
        a.closedbutton[i].setTexture(a.button1);
        a.openbutton[i].setScale(0.42, 0.42);
        a.closedbutton[i].setScale(0.42, 0.42);
    }
    for (int i = 0; i < 2; i++) {
        a.openbuttonright[i].setTexture(a.buttonright);
        a.openbuttonleft[i].setTexture(a.buttonleft);
        a.closedbuttonright[i].setTexture(a.button1right);
        a.closedbuttonleft[i].setTexture(a.button1left);
        a.openbuttonright[i].setScale(0.42, 0.42);
        a.closedbuttonright[i].setScale(0.42, 0.42);
        a.openbuttonleft[i].setScale(0.42, 0.42);
        a.closedbuttonleft[i].setScale(0.42, 0.42);
    }
    a.key.setTexture(a.keyy);
    a.key.setScale(0.28f, 0.28f);
    a.doorclosed.setTexture(a.door);
    a.doorclosed.setScale(0.56f, 0.56f);
    a.dooropen.setTexture(a.door1);
    a.dooropen.setScale(0.56f, 0.56f);
    a.background[0].setTexture(a.backgroundd);
    a.background[1].setTexture(a.backgroundd);
    a.background[0].setScale(1.5f, 1.7f);
    a.background[1].setScale(1.5f, 1.7f);
    a.background[1].setScale(1.5f, 1.7f);
}

void setSprite2(objects2& box)
{
}

void twoplayerlvl1(objects1& a) {

    a.smallwall1[0].setPosition(1445, 444);
    a.smallwall1[1].setPosition(725, 444);
    for (int i = 0; i < 25; i++) {

        a.box2[i].setPosition(170.05 * 0.5 * i, 960);
    }


    a.doorclosed.setPosition(1715, 645);

    for (int i = 0; i < 8; i++) {
        a.box3[i].setPosition(1140, 450 + (i * 61.6f));

    }
    //a.bigwall[0].setPosition(140, 790);
    a.bigwall[1].setPosition(400, 1300);
    a.bigwall[2].setPosition(400, 5000);
    a.bigwall[3].setPosition(400, 8200);
    a.bigwall[4].setPosition(1515, 390);
    a.bigwall[5].setPosition(1510, 585);
    a.bigwall[6].setPosition(1720, 585);
    a.bigwall[7].setPosition(1720, 850);


    a.openbutton[0].setPosition(850, 930);
    a.openbutton[1].setPosition(1838, 555);
    a.key.setPosition(735, 350);
}

void twoplayerlvl1draw(objects1& a) {
    window.draw(a.background[0]);
    window.draw(a.doorclosed);

    window.draw(a.openbutton[0]);
    window.draw(a.openbutton[1]);
    window.draw(a.key);
    window.draw(a.smallwall1[0]);
    window.draw(a.smallwall1[1]);

    for (int i = 0; i < 8; i++) {
        window.draw(a.box3[i]);
    }
    for (int i = 0; i < 25; i++) {


        window.draw(a.box2[i]);
    }
    for (int i = 0; i < 8; i++) {
        if (i == 0) {
            continue;
        }
        window.draw(a.bigwall[i]);
    }
}

void small_walls(player a[], objects1& b) {
    for (int i = 0; i < 8; i++) {

        for (int j = 0; j < 2; j++) {
            if (a[j].sprite.getGlobalBounds().intersects(b.smallwall1[i].getGlobalBounds()))
            {
                if ((a[j].rect.left + 71.5 <= b.smallwall1[i].getPosition().x) || (a[j].rect.left + 72 <= b.smallwall1[i].getPosition().x))
                {
                    a[j].rect.left = b.smallwall1[i].getPosition().x - 110;
                }

                else if ((a[j].rect.left - 50 >= b.smallwall1[i].getPosition().x) || (a[j].rect.left - 50.5 >= b.smallwall1[i].getPosition().x))
                {
                    a[j].rect.left = b.smallwall1[i].getPosition().x + 60;

                }


                else
                {
                    a[j].movey = 0;
                    a[j].onground = true;
                    /*if (a[j].rect.top >= b.bigwall[i].getPosition().y)
                    {
                        a[j].rect.top = b.bigwall[i].getPosition().y + 1100;
                        a[j].onground = false;
                    }*/
                    /*else {*/
                    a[j].rect.top = b.smallwall1[i].getPosition().y - 110;
                    a[j].onground = true;
                    //}

                }
            }
        }
    }



}

void box_3(player a[], objects1& b)
{
    for (int i = 0; i < 8; i++) {

        for (int j = 0; j < 3; j++) {
            if (a[j].sprite.getGlobalBounds().intersects(b.box3[i].getGlobalBounds())) {

                if ((a[j].rect.left + 71.5 <= b.box3[i].getPosition().x) || (a[j].rect.left + 72 <= b.box3[i].getPosition().x)) {
                    a[j].rect.left = b.box3[i].getPosition().x - 110;

                }

                else
                {
                    a[j].movey = 0;
                    a[j].onground = true;
                    if (a[j].rect.top >= b.box3[i].getPosition().y && a[j].rect.left <= b.box3[i].getPosition().x + 63)
                    {
                        a[j].rect.top = b.box3[i].getPosition().y + 59;
                        a[j].onground = false;
                    }
                    else
                    {
                        a[j].rect.top = b.box3[i].getPosition().y - 109.5f;
                        a[j].onground = true;
                    }
                }

            }
        }
    }
}


void ground(player a[], objects1& b) {
    for (int j = 0; j < 4; j++) {

        for (int i = 0; i < 50; i++) {

            if (a[j].sprite.getGlobalBounds().intersects(b.box2[i].getGlobalBounds())) {

                a[j].movey = 0;

                a[j].onground = 1;

                a[j].rect.top = b.box2[i].getPosition().y - 110;

                a[j].onground = true;


            }
        }
    }
}


void walls(player a[], objects1& b) {
    for (int i = 0; i < 8; i++) {

        for (int j = 0; j < 2; j++) {
            if (a[j].sprite.getGlobalBounds().intersects(b.bigwall[i].getGlobalBounds())) {

                if ((a[j].rect.left + 71.5 <= b.bigwall[i].getPosition().x) || (a[j].rect.left + 72 <= b.bigwall[i].getPosition().x)) {
                    a[j].rect.left = b.bigwall[i].getPosition().x - 110;

                }

                else if (a[j].rect.left >= b.bigwall[i].getPosition().x + 150 || a[j].rect.left >= b.bigwall[i].getPosition().x + 155) {
                    a[j].rect.left = b.bigwall[i].getPosition().x + 185;


                }
                else
                {


                    if (a[j].rect.top >= b.bigwall[i].getPosition().y)
                    {
                        a[j].rect.top = b.bigwall[i].getPosition().y + 59;
                        a[j].onground = false;
                    }
                    else
                    {
                        a[j].rect.top = b.bigwall[i].getPosition().y - 109.5f;
                        a[j].movey = 0;
                        a[j].onground = true;
                    }
                }

            }
        }
    }
}

void walls_movement(objects1& b)
{
    /*
    if (b.bigwall[1].getPosition().x >= 750)
    {
        b.bigwall[1].move(-5, 0);
    }
    else
    {
        if (b.bigwall[1].getPosition().x <= 100)
        {
            b.bigwall[1].move(+5, 0);
        }

    }*/
}



//two players lvl2
void loadtext2(objects2& a) {
    a.texture.loadFromFile("assets/box_pur.png");
    a.texture1.loadFromFile("assets/box1_pur.png");
    a.texture2.loadFromFile("assets/box2_pur.png");
    a.texture3.loadFromFile("assets/box3_pur.png");
    a.wall.loadFromFile("assets/wall_pur.png");
    a.wall1.loadFromFile("assets/small_wall_pur.png");
    a.keyy.loadFromFile("assets/key.png");
    a.button.loadFromFile("assets/button.png");
    a.button1.loadFromFile("assets/button2.png");
    a.backgroundd.loadFromFile("assets/background_pur.png");
    a.door.loadFromFile("assets/exitdoor_pur.png");
    a.door1.loadFromFile("assets/door open pur.png");
    a.button1right.loadFromFile("assets/button2left.png");
    a.button1right.loadFromFile("assets/button2right.png");
    a.buttonright.loadFromFile("assets/buttonright.png");
    a.buttonleft.loadFromFile("assets/buttonleft.png");
}

void sdddetSprite2(objects2& a) {
    for (int i = 0; i < 50; i++) {
        a.box[i].setTexture(a.texture);
        a.box[i].setScale(0.5, 0.5);
    }
    for (int i = 0; i < 20; i++) {
        a.box1[i].setTexture(a.texture1);
        a.box1[i].setScale(0.7, 0.7);
    }
    for (int i = 0; i < 22; i++) {
        a.box2[i].setTexture(a.texture2);
        a.box2[i].setScale(0.5, 0.5);
    }
    for (int i = 0; i < 2; i++) {
        a.box3[i].setTexture(a.texture3);
        a.box3[i].setScale(0.28, 0.28);

    }

    for (int i = 0; i < 4; i++) {
        a.bigwall[i].setTexture(a.wall);
        a.bigwall[i].setScale(0.28, 0.28);
    }
    for (int i = 0; i < 10; i++) {
        a.smallwall1[i].setTexture(a.wall1);
    }
    for (int i = 0; i < 2; i++) {
        a.openbutton[i].setTexture(a.button);
        a.closedbutton[i].setTexture(a.button1);
        a.openbutton[i].setScale(0.42, 0.42);
        a.closedbutton[i].setScale(0.42, 0.42);
    }
    for (int i = 0; i < 2; i++) {
        a.openbuttonright[i].setTexture(a.buttonright);
        a.openbuttonleft[i].setTexture(a.buttonleft);
        a.closedbuttonright[i].setTexture(a.button1right);
        a.closedbuttonleft[i].setTexture(a.button1left);
        a.openbuttonright[i].setScale(0.42, 0.42);
        a.closedbuttonright[i].setScale(0.42, 0.42);
        a.openbuttonleft[i].setScale(0.42, 0.42);
        a.closedbuttonleft[i].setScale(0.42, 0.42);
    }
    a.key.setTexture(a.keyy);
    a.key.setScale(0.28, 0.28);
    a.doorclosed.setTexture(a.door);
    a.doorclosed.setScale(0.28, 0.28);
    a.dooropen.setTexture(a.door1);
    a.dooropen.setScale(0.56, 0.56);
    a.background[0].setTexture(a.backgroundd);
    a.background[1].setTexture(a.backgroundd);
    a.background[0].setScale(1.5, 1.65);
    a.background[1].setScale(1.5, 1.65);
}

void twoplayerlvl2(objects2& a) {
    for (int i = 0; i < 19; i++) {
        if ((i == 3) || (i == 4) || (i == 5)) {
            continue;
        }
        a.box2[i].setPosition(236 * 0.5 * i, 935);
    }
    a.doorclosed.setPosition(1450, 162);
    a.box[0].setPosition(500, 656);
    a.box[1].setPosition(1000, 536);
    a.bigwall[0].setPosition(300, 740);
    a.bigwall[1].setPosition(190, 400);
    a.bigwall[2].setPosition(900, 620);
    a.bigwall[3].setPosition(1120, 280);
    a.openbutton[0].setPosition(950, 890);
    a.key.setPosition(200, 340);
}

void twoplayerlvl2draw(objects2& a) {
    window.draw(a.background[0]);
    window.draw(a.doorclosed);
    window.draw(a.openbutton[0]);
    window.draw(a.key);
    for (int i = 0; i < 2; i++) {
        window.draw(a.box[i]);
    }
    for (int i = 0; i < 19; i++) {

        if ((i == 3) || (i == 4) || (i == 5)) {
            continue;
        }
        window.draw(a.box2[i]);
    }
    for (int i = 0; i < 4; i++) {
        window.draw(a.bigwall[i]);
    }
}


//two players lvl3
void loadtext3(objects3& a) {

    a.texture.loadFromFile("assets/box_blu.png");
    a.texture1.loadFromFile("assets/box1_blu.png");
    a.texture2.loadFromFile("assets/box2_blu.png");
    a.texture3.loadFromFile("assets/box3_blu.png");
    a.wall.loadFromFile("assets/wall_blu.png");
    a.wall1.loadFromFile("assets/small_wall_blu.png");
    a.keyy.loadFromFile("assets/key.png");
    a.button.loadFromFile("assets/button.png");
    a.button1.loadFromFile("assets/button2.png");
    a.backgroundd.loadFromFile("assets/background_blu.png");
    a.door.loadFromFile("assets/exitdoor_blu.png");
    a.door1.loadFromFile("assets/door open blue.png");
    a.button1right.loadFromFile("assets/button2left.png");
    a.button1right.loadFromFile("assets/button2right.png");
    a.buttonright.loadFromFile("assets/buttonright.png");
    a.buttonleft.loadFromFile("assets/buttonleft.png");

}

void setSprite3(objects3& a) {
    for (int i = 0; i < 20; i++) {
        a.box[i].setTexture(a.texture);
        a.box[i].setScale(0.5, 0.5);
    }
    for (int i = 0; i < 20; i++) {
        a.box1[i].setTexture(a.texture1);
        a.box1[i].setScale(0.5, 0.5);
    }
    for (int i = 0; i < 50; i++) {
        a.box2[i].setTexture(a.texture2);
        a.box2[i].setScale(0.5, 0.5);
    }
    for (int i = 0; i < 2; i++) {
        a.box3[i].setTexture(a.texture3);
        a.box3[i].setScale(0.3, 0.3);
    }

    for (int i = 0; i < 4; i++) {
        a.bigwall[i].setTexture(a.wall);
        a.bigwall[i].setScale(0.2, 0.2);
    }
    for (int i = 0; i < 10; i++) {
        a.smallwall1[i].setTexture(a.wall1);
    }
    for (int i = 0; i < 2; i++) {
        a.openbutton[i].setTexture(a.button);
        a.closedbutton[i].setTexture(a.button1);
        a.openbutton[i].setScale(0.3, 0.3);
        a.closedbutton[i].setScale(0.3, 0.3);
    }
    for (int i = 0; i < 2; i++) {
        a.openbuttonright[i].setTexture(a.buttonright);
        a.openbuttonleft[i].setTexture(a.buttonleft);
        a.closedbuttonright[i].setTexture(a.button1right);
        a.closedbuttonleft[i].setTexture(a.button1left);
        a.openbuttonright[i].setScale(0.3, 0.3);
        a.closedbuttonright[i].setScale(0.3, 0.3);
        a.openbuttonleft[i].setScale(0.3, 0.3);
        a.closedbuttonleft[i].setScale(0.3, 0.3);
    }
    a.key.setTexture(a.keyy);
    a.key.setScale(0.35f, 0.35f);
    a.doorclosed.setTexture(a.door);
    a.doorclosed.setScale(0.4f, 0.4f);
    a.dooropen.setTexture(a.door1);
    a.dooropen.setScale(0.4f, 0.4f);
    a.background[0].setTexture(a.backgroundd);
    a.background[1].setTexture(a.backgroundd);
    a.background[0].setScale(1.5, 1.7);
    a.background[1].setScale(1.5, 1.7);
}

void twoplayerlvl3(objects3& w) {
    for (int i = 0; i < 25; i++) {
        w.box2[i].setPosition(170.05 * 0.5 * i, 960);
    }

    w.bigwall[0].setPosition(1585, 920);
    w.bigwall[1].setPosition(800, 570);
    w.bigwall[2].setPosition(250, 720);
    w.bigwall[3].setPosition(1270, 400);
    w.openbutton[0].setPosition(1300, 370);
    w.openbutton[1].setPosition(800, 935);
    w.doorclosed.setPosition(1430, 233);
    w.box3[0].setPosition(420, 656);
    w.openbuttonright[0].setPosition(1882.7f, 650);
    w.key.setPosition(960, 460);
}

void twoplayerlvl3draw(objects3& a) {
    window.draw(a.background[0]);
    window.draw(a.doorclosed);
    window.draw(a.openbuttonright[0]);
    window.draw(a.key);
    for (int i = 0; i < 8; i++) {
        window.draw(a.box3[i]);
    }
    for (int i = 0; i < 25; i++) {
        window.draw(a.box2[i]);


    }
    for (int i = 0; i < 4; i++) {
        window.draw(a.bigwall[i]);

    }
    for (int i = 0; i < 3; i++) {
        window.draw(a.openbutton[i]);
    }

}


//three players lvl1
void threesetSprite1(objects1& a) {
    for (int i = 0; i < 50; i++) {
        a.box[i].setTexture(a.texture);
        a.box[i].setScale(0.5, 0.5);
    }
    for (int i = 0; i < 20; i++) {
        a.box1[i].setTexture(a.texture1);
        a.box1[i].setScale(0.7, 0.7);
    }
    for (int i = 0; i < 48; i++) {
        a.box2[i].setTexture(a.texture2);
        a.box2[i].setScale(0.5, 0.5);
    }
    for (int i = 0; i < 8; i++) {
        a.box3[i].setTexture(a.texture3);
        a.box3[i].setScale(0.28, 0.28);
    }
    for (int i = 0; i < 8; i++) {
        a.bigwall[i].setTexture(a.wall);
        a.bigwall[i].setScale(0.112f, 0.28f);
    }
    for (int i = 0; i < 2; i++) {
        a.smallwall1[i].setTexture(a.wall1);
        a.smallwall1[i].setScale(0.28f, 0.84f);
    }
    for (int i = 0; i < 2; i++) {
        a.openbutton[i].setTexture(a.button);
        a.closedbutton[i].setTexture(a.button1);
        a.openbutton[i].setScale(0.42, 0.42);
        a.closedbutton[i].setScale(0.42, 0.42);
    }
    for (int i = 0; i < 2; i++) {
        a.openbuttonright[i].setTexture(a.buttonright);
        a.openbuttonleft[i].setTexture(a.buttonleft);
        a.closedbuttonright[i].setTexture(a.button1right);
        a.closedbuttonleft[i].setTexture(a.button1left);
        a.openbuttonright[i].setScale(0.42, 0.42);
        a.closedbuttonright[i].setScale(0.42, 0.42);
        a.openbuttonleft[i].setScale(0.42, 0.42);
        a.closedbuttonleft[i].setScale(0.42, 0.42);
    }
    a.key.setTexture(a.keyy);
    a.key.setScale(0.28f, 0.28f);
    a.doorclosed.setTexture(a.door);
    a.doorclosed.setScale(0.56f, 0.56f);
    a.dooropen.setTexture(a.door1);
    a.dooropen.setScale(0.56f, 0.56f);
    a.background[0].setTexture(a.backgroundd);
    a.background[1].setTexture(a.backgroundd);
    a.background[2].setTexture(a.backgroundd);
    a.background[0].setScale(1.5f, 1.7f);
    a.background[1].setScale(1.5f, 1.7f);
    a.background[1].setScale(1.5f, 1.7f);
    a.background[2].setScale(1.5f, 1.7f);
    a.background[3].setTexture(a.backgroundd);
    a.background[4].setTexture(a.backgroundd);
    a.background[3].setScale(1.5f, 1.7f);
    a.background[4].setScale(1.5f, 1.7f);
}

void threeplayerlvl1(objects1& a) {
    for (int i = 0; i < 48; i++) {
        if ((i == 0) || (i == 1) || (i == 2) || (i == 3) || (i == 4) || (i == 5) || (i == 10) || (i == 11) || (i == 12) || (i == 45) || (i == 46) || (i == 47) || (i == 48)) {
            continue;
        }
        a.box2[i].setPosition(171 * 0.5 * i, 935);
    }
    a.background[0].setPosition(0, 0);
    a.background[1].setPosition(1920, 0);
    a.background[2].setPosition(1920 * 2, 0);
    a.background[3].setPosition(-1920, 0);
    a.background[4].setPosition(1920 * 3, 0);

    a.key.setPosition(880, 505);

    a.box3[0].setPosition(420, 585);
    a.box3[1].setPosition(570, 585);
    a.box3[2].setPosition(720, 585);
    a.box3[3].setPosition(1140, 800);
    a.box3[4].setPosition(1240, 680);
    a.box3[5].setPosition(1340, 560);

    a.box3[6].setPosition(4720, 300);
    a.box3[7].setPosition(4870, 300);
    a.box3[8].setPosition(5020, 300);
    a.box3[9].setPosition(5170, 300);

    a.smallwall1[0].setPosition(870, 585);
    a.smallwall1[1].setPosition(3450, 585);
    a.smallwall1[2].setPosition(3600, 585);
    a.smallwall1[3].setPosition(3750, 585);

    a.bigwall[0].setPosition(0, 585);
    a.bigwall[1].setPosition(1490, 560);
    a.bigwall[2].setPosition(1792, 560);
    a.bigwall[3].setPosition(4000, 890);
    a.bigwall[4].setPosition(4302, 300);
    a.bigwall[5].setPosition(5320, 300);

    a.openbutton[0].setPosition(2200, 895);
    a.openbutton[1].setPosition(2450, 895);
    a.openbutton[2].setPosition(2700, 895);

    a.doorclosed.setPosition(5500, 180);

    a.box[0].setPosition(2000, 490);
    a.box[1].setPosition(2950, 864);
    a.box[2].setPosition(3200, 864);

}

void threeplayerlvl1draw(objects1& a) {
    for (int i = 0; i < 5; i++) {
        window.draw(a.background[i]);
    }

    for (int i = 0; i < 10; i++) {
        window.draw(a.box3[i]);
    }
    for (int i = 0; i < 48; i++) {
        if ((i == 0) || (i == 1) || (i == 2) || (i == 3) || (i == 4) || (i == 5) || (i == 10) || (i == 11) || (i == 12) || (i == 45) || (i == 46) || (i == 47) || (i == 48)) {
            continue;
        }
        window.draw(a.box2[i]);
    }
    for (int i = 0; i < 4; i++) {
        window.draw(a.smallwall1[i]);
    }
    for (int i = 0; i < 3; i++) {
        window.draw(a.openbutton[i]);
    }
    for (int i = 0; i < 6; i++) {
        window.draw(a.bigwall[i]);
    }
    for (int i = 0; i < 3; i++) {
        window.draw(a.box[i]);
    }
    window.draw(a.doorclosed);
    window.draw(a.key);
}


// three players lvl2
void threeplayerlvl2(objects2& a)
{
    for (int i = 0; i < 40; i++) {
        if ((i == 39) || (i == 38) || (i == 37) || (i == 36) || (i == 35) || (i == 34) || (i == 33) || (i == 32) || (i == 31)) {

            a.box2[i].setPosition(-170.05 * 0.5 * i, 960);

        }
        a.box2[i].setPosition(170.05 * 0.5 * i, 960);
    }

    a.background[1].setPosition(1920, 0);
    a.background[2].setPosition(3840, 0);

    a.key.setPosition(1915, 260);

    a.box3[0].setPosition(2300, 540);
    a.box3[1].setPosition(2100, 440);
    a.box3[2].setPosition(1900, 340);

    a.smallwall1[1].setPosition(540, 344);
    a.smallwall1[2].setPosition(890, 244);
    a.smallwall1[3].setPosition(1500, -200);
    a.smallwall1[0].setPosition(4100, 200);
    a.smallwall1[4].setPosition(4200, 200);
    a.smallwall1[5].setPosition(4300, 200);


    a.bigwall[0].setPosition(0, 640);
    a.bigwall[1].setPosition(500, 740);
    a.bigwall[2].setPosition(850, 640);
    a.bigwall[4].setPosition(-2500, 740);
    a.bigwall[5].setPosition(2802, 740);
    a.bigwall[6].setPosition(3049, 590);
    a.bigwall[7].setPosition(3502, 590);
    a.bigwall[8].setPosition(4055, 590);
    a.bigwall[3].setPosition(-4008, 590);
    a.bigwall[9].setPosition(4461, 590);

    a.openbutton[0].setPosition(600, 920);
    a.openbutton[1].setPosition(950, 920);
    a.openbutton[2].setPosition(1050, 600);
    a.openbutton[3].setPosition(3250, 555);
    a.openbutton[4].setPosition(3500, 555);
    a.openbutton[5].setPosition(3750, 555);

    a.doorclosed.setPosition(4500, 350);


}

void threesetSprite2(objects2& a)
{
    for (int i = 0; i < 32; i++) {
        a.box2[i].setTexture(a.texture2);
        a.box2[i].setScale(0.5, 0.5);
    }
    for (int i = 0; i < 3; i++) {
        a.box3[i].setTexture(a.texture3);
        a.box3[i].setScale(0.28, 0.28);
    }
    for (int i = 0; i < 10; i++) {
        a.bigwall[i].setTexture(a.wall);
        a.bigwall[i].setScale(0.21f, 0.21f);
    }
    for (int i = 0; i < 10; i++) {

        a.smallwall1[i].setTexture(a.wall1);
        a.smallwall1[i].setScale(0.28f, 0.64f);
    }
    for (int i = 0; i < 6; i++) {
        a.openbutton[i].setTexture(a.button);
        a.closedbutton[i].setTexture(a.button1);
        a.openbutton[i].setScale(0.42, 0.42);
        a.closedbutton[i].setScale(0.42, 0.42);
    }
    for (int i = 0; i < 2; i++) {
        a.openbuttonright[i].setTexture(a.buttonright);
        a.openbuttonleft[i].setTexture(a.buttonleft);
        a.closedbuttonright[i].setTexture(a.button1right);
        a.closedbuttonleft[i].setTexture(a.button1left);
        a.openbuttonright[i].setScale(0.42, 0.42);
        a.closedbuttonright[i].setScale(0.42, 0.42);
        a.openbuttonleft[i].setScale(0.42, 0.42);
        a.closedbuttonleft[i].setScale(0.42, 0.42);
    }
    a.smallwall1[3].setTexture(a.wall1);
    a.smallwall1[3].setScale(0.28f, 2);
    a.key.setTexture(a.keyy);
    a.key.setScale(0.28f, 0.28f);
    a.doorclosed.setTexture(a.door);
    a.doorclosed.setScale(0.56f, 0.56f);
    a.dooropen.setTexture(a.door1);
    a.dooropen.setScale(0.215f, 0.215f);
    a.background[0].setTexture(a.backgroundd);
    a.background[1].setTexture(a.backgroundd);
    a.background[2].setTexture(a.backgroundd);
    a.background[0].setScale(1.5f, 1.7f);
    a.background[1].setScale(1.5f, 1.7f);
    a.background[1].setScale(1.5f, 1.7f);
    a.background[2].setScale(1.5f, 1.7f);
    a.background[3].setTexture(a.backgroundd);
    a.background[4].setTexture(a.backgroundd);
    a.background[3].setScale(1.5f, 1.7f);
    a.background[4].setScale(1.5f, 1.7f);
}

void threeplayerlvl2draw(objects2& a)
{
    for (int i = 0; i < 3; i++) {
        window.draw(a.background[i]);
    }
    for (int i = 0; i < 3; i++) {
        window.draw(a.box3[i]);
    }
    for (int i = 0; i < 32; i++) {

        window.draw(a.box2[i]);
    }
    for (int i = 0; i < 6; i++) {
        window.draw(a.smallwall1[i]);
    }
    for (int i = 0; i < 6; i++) {
        window.draw(a.openbutton[i]);
    }
    for (int i = 0; i < 10; i++) {
        window.draw(a.bigwall[i]);
    }

    window.draw(a.doorclosed);
    window.draw(a.key);

}

//void key_threeplayers(player a[], objects2& b, flag& f);
//
//void button_threeplayers(objects2& b, flag& f);



// three players lvl3
void threeplayerlvl3(objects2& a) {
    for (int i = 0; i < 40; i++) {
        if ((i == 39) || (i == 38) || (i == 37) || (i == 36) || (i == 35) || (i == 34) || (i == 33) || (i == 32) || (i == 31)) {
            a.box2[i].setPosition(-17110 * 0.5 * i, 690);
        }
        a.box2[i].setPosition(171 * 0.5 * i, 960);
    }



    a.background[1].setPosition(1280 * s, 0);
    a.background[2].setPosition(2560 * s, 0);

    a.key.setPosition(1095 * s, 390 * s);

    a.box3[0].setPosition(1290 * s, 440 * s);
    a.box3[1].setPosition(1190 * s, 440 * s);
    a.box3[2].setPosition(1090 * s, 440 * s);

    a.smallwall1[1].setPosition(463 * s, 357 * s);
    a.smallwall1[2].setPosition(653 * s, 307 * s);
    a.smallwall1[3].setPosition(900 * s, 505 * s);
    a.smallwall1[0].setPosition(2200 * s, 277 * s);
    a.smallwall1[4].setPosition(2245 * s, 277 * s);
    a.smallwall1[5].setPosition(2290 * s, 277 * s);

    a.openbuttonright[0].setPosition(1230 * s, 440 * s);

    a.bigwall[0].setPosition(0, 440 * s);
    a.bigwall[1].setPosition(433 * s, 540 * s);
    a.bigwall[2].setPosition(620 * s, 490 * s);
    a.bigwall[3].setPosition(2268 * s, 460 * s);
    a.bigwall[4].setPosition(1433 * s, 560 * s);
    a.bigwall[5].setPosition(1600 * s, 560 * s);
    a.bigwall[6].setPosition(1767 * s, 460 * s);
    //a.bigwall[7].setPosition(1934 * s, 460 * s);
    a.bigwall[8].setPosition(2101 * s, 460 * s);
    // a.bigwall[9].setPosition(2435 * s, 460 * s);

    a.openbutton[0].setPosition(500 * s, 667 * s);
    a.openbutton[1].setPosition(600 * s, 667 * s);
    a.openbutton[2].setPosition(730 * s, 467 * s);
    a.openbutton[3].setPosition(1840 * s, 437 * s);
    a.openbutton[4].setPosition(1950 * s, 437 * s);
    a.openbutton[5].setPosition(2060 * s, 437 * s);

    a.doorclosed.setPosition(2485 * s, 375 * s);

    a.box[0].setPosition(1100 * s, 640 * s);
    a.box[1].setPosition(1550 * s, 510 * s);
}
void threesetSprite3(objects2& a) {
    for (int i = 0; i < 40; i++) {
        a.box2[i].setTexture(a.texture2);
        a.box2[i].setScale(0.5, 0.5);
    }
    for (int i = 0; i < 6; i++) {
        a.smallwall1[i].setTexture(a.wall1);
        a.smallwall1[i].setScale(0.28f, 0.64f);
    }
    for (int i = 0; i < 3; i++) {
        a.background[i].setTexture(a.backgroundd);
        a.background[i].setScale(1.5f, 1.65f);
    }
    for (int i = 0; i < 10; i++) {
        a.bigwall[i].setTexture(a.wall);
        a.bigwall[i].setScale(0.21f, 0.21f);
    }
    for (int i = 0; i < 3; i++) {
        a.box3[i].setTexture(a.texture3);
        a.box3[i].setScale(0.28f, 0.28f);

    }
    for (int i = 0; i < 6; i++) {
        a.openbutton[i].setTexture(a.button);
        a.openbutton[i].setScale(0.42f, 0.42f);
    }
    for (int i = 0; i < 2; i++) {
        a.box[i].setTexture(a.texture);
        a.box[i].setScale(0.42f, 0.42f);
    }
    a.openbuttonright[0].setTexture(a.buttonright);
    a.openbuttonright[0].setScale(0.42f, 0.42f);

    a.key.setTexture(a.keyy);
    a.key.setScale(0.28f, 0.28f);

    a.doorclosed.setTexture(a.door);
    a.doorclosed.setScale(0.56f, 0.56f);
    a.dooropen.setTexture(a.door1);
    a.dooropen.setScale(0.56f, 0.56f);

}

//void button_threeplayers_lvl3(objects3& b, flag& f);

void threeplayerlvl3draw(objects2& a) {
    for (int i = 0; i < 3; i++) {
        window.draw(a.background[i]);
    }
    for (int i = 0; i < 3; i++) {
        window.draw(a.box3[i]);
    }
    for (int i = 0; i < 40; i++) {
        if ((i == 39) || (i == 38) || (i == 37) || (i == 36) || (i == 35) || (i == 34) || (i == 33) || (i == 32) || (i == 31)) {
            continue;
        }
        window.draw(a.box2[i]);
    }
    for (int i = 0; i < 6; i++) {
        window.draw(a.smallwall1[i]);
    }
    for (int i = 0; i < 6; i++) {
        window.draw(a.openbutton[i]);
    }
    for (int i = 0; i < 10; i++) {
        window.draw(a.bigwall[i]);
    }
    for (int i = 0; i < 2; i++) {
        window.draw(a.box[i]);
    }
    window.draw(a.doorclosed);
    window.draw(a.key);


}
// four players lvl1
// four players lvl2
// four players lvl3
void fourplayerlvl3(objects3& a)
{

    int j = 16, l = 55, m = 0;

    for (int i = 0; i < 60; i++) {
        if (i == j) {
            if (j < 46)
                j += 1;
            a.box2[i].setPosition(-5000 * 0.5 * i, 935);
            continue;
        }
        if (i == l) {
            if (l < 60)
                l += 1;
            a.box2[i].setPosition(-5000 * 0.5 * i, 935);
            continue;
        }
        if (i == m) {
            if (m < 3)
                m += 1;
            a.box2[i].setPosition(-5000 * 0.5 * i, 935);
            continue;
        }
        a.box2[i].setPosition(239 * 0.5 * i, 935);
    }

    a.background[1].setPosition(1920, 0);
    a.background[2].setPosition(3840, 0);
    a.background[3].setPosition(5760, 0);
    a.background[4].setPosition(7680, 0);

    a.box3[0].setPosition(2000, 780);
    a.box3[1].setPosition(2150, 680);
    a.box3[2].setPosition(2300, 580);
    a.box3[3].setPosition(2450, 480);

    a.box3[9].setPosition(3500, 440);
    a.box3[10].setPosition(4000, 440);
    a.box3[11].setPosition(4500, 140);
    a.box3[12].setPosition(5000, 440);
    a.box3[13].setPosition(5500, 440);

    a.box3[14].setPosition(3750, 590);
    a.box3[15].setPosition(4250, 590);
    a.box3[16].setPosition(4750, 590);
    a.box3[17].setPosition(5250, 590);

    a.box3[18].setPosition(3500, 740);
    a.box3[19].setPosition(4000, 740);
    a.box3[20].setPosition(4500, 740);
    a.box3[21].setPosition(5000, 740);
    a.box3[22].setPosition(5500, 740);

    a.box3[23].setPosition(3750, 890);
    a.box3[24].setPosition(4250, 890);
    a.box3[25].setPosition(4750, 890);
    a.box3[26].setPosition(5250, 890);

    a.box3[4].setPosition(-1000, 935);
    a.box3[5].setPosition(-1000, 835);
    a.box3[6].setPosition(6650, 835);
    a.box3[7].setPosition(6850, 670);
    a.box3[8].setPosition(6650, 535);
    a.box3[27].setPosition(-1000, 435);

    a.smallwall1[0].setPosition(1000, 535);

    a.bigwall[0].setPosition(0, 600);
    a.bigwall[1].setPosition(3000, 440);
    a.bigwall[2].setPosition(7000, 435);


    a.openbutton[0].setPosition(1195, 900);

    a.openbutton[1].setPosition(1995, 745);
    a.openbutton[2].setPosition(2145, 645);
    a.openbutton[3].setPosition(2295, 545);
    a.openbutton[4].setPosition(2445, 445);

    a.openbutton[5].setPosition(3745, 855);
    a.openbutton[6].setPosition(4245, 855);
    a.openbutton[7].setPosition(4745, 855);
    a.openbutton[8].setPosition(5245, 855);


    a.doorclosed.setPosition(7070, 197);

    a.key.setPosition(4505, 70);
}
void foursetSprite3(objects3& a)
{
    for (int i = 0; i < 60; i++) {
        a.box2[i].setTexture(a.texture2);
        a.box2[i].setScale(0.7, 0.7);
    }
    for (int i = 0; i < 1; i++) {
        a.smallwall1[i].setTexture(a.wall1);
        a.smallwall1[i].setScale(0.28, 0.64);
    }
    for (int i = 0; i < 5; i++) {
        a.background[i].setTexture(a.backgroundd);
        a.background[i].setScale(1.5, 1.65);
    }
    for (int i = 0; i < 3; i++) {
        a.bigwall[i].setTexture(a.wall);
        a.bigwall[i].setScale(0.21, 0.21);
    }
    for (int i = 0; i < 28; i++) {
        a.box3[i].setTexture(a.texture3);
        a.box3[i].setScale(0.28, 0.28);

    }
    for (int i = 0; i < 9; i++) {
        a.openbutton[i].setTexture(a.button);
        a.openbutton[i].setScale(0.42, 0.42);
    }
    /* for (int i = 0; i < 0; i++) {
         a.box[i].setTexture(a.texture);
         a.box[i].setScale(0.42, 0.42);
     }*/
    a.openbuttonright[0].setTexture(a.buttonright);
    a.openbuttonright[0].setScale(0.42, 0.42);

    a.key.setTexture(a.keyy);
    a.key.setScale(0.28, 0.28);

    a.doorclosed.setTexture(a.door);
    a.doorclosed.setScale(0.56f, 0.56f);
    a.dooropen.setTexture(a.door1);
    a.dooropen.setScale(0.56f, 0.56f);

}

void fourplayerlvl3draw(objects3& a)
{
    for (int i = 0; i < 5; i++) {
        window.draw(a.background[i]);
    }
    int j = 16, l = 55, m = 0;

    for (int i = 0; i < 60; i++) {
        if (i == j) {
            if (j < 46)
                j += 1;
            continue;
        }
        if (i == l) {
            if (l < 60)
                l += 1;
            continue;
        }
        if (i == m) {
            if (m < 3)
                m += 1;
            continue;
        }

        window.draw(a.box2[i]);
    }
    for (int i = 0; i < 1; i++) {
        window.draw(a.smallwall1[i]);
    }
    for (int i = 0; i < 9; i++) {
        window.draw(a.openbutton[i]);
    }
    for (int i = 0; i < 3; i++) {
        window.draw(a.bigwall[i]);
    }
    /*for (int i = 0; i < 0; i++) {
        window.draw(a.box[i]);
    }*/
    for (int i = 0; i < 28; i++) {
        if (i == 4 || i == 5 || i == 27) {
            continue;
        }
        window.draw(a.box3[i]);
    }

    window.draw(a.doorclosed);
    window.draw(a.key);

}



//players
void playertext(player(&x)[4], int n) {
    x[0].texture.loadFromFile("players/red.png");
    x[1].texture.loadFromFile("players/blue.png");
    x[0].sprite.setTexture(x[0].texture);
    x[1].sprite.setTexture(x[1].texture);
    x[0].sprite.setScale(0.8, 0.8);
    x[1].sprite.setScale(0.8, 0.8);
    if (n == 3 || n == 4) {
        x[2].texture.loadFromFile("players/yellow.png");
        x[2].sprite.setTexture(x[2].texture);
        x[2].sprite.setScale(0.8, 0.8);
    }
    if (n == 4) {
        x[3].texture.loadFromFile("players/green.png");
        x[3].sprite.setTexture(x[3].texture);
        x[3].sprite.setScale(0.8, 0.8);
    }






    for (int i = 0; i < n; i++) {
        x[i].sprite.setTextureRect(IntRect(0, 0, 142.22, 141.75));
    }
}

void player1move(player& s) {

    if ((Keyboard::isKeyPressed(Keyboard::Key::Up)) && (Keyboard::isKeyPressed(Keyboard::Key::Right))) {

        if (s.onground) {
            s.movey = -1;
            x1 = 0;
            s.onground = false;
        }
        s.right = 1;
        s.movex = 0.3;
        y = 2;
        if (x1 <= 3.4) {


            x1 += delay;
        }
        s.sprite.setTextureRect(IntRect((short int)x1 * 142.22f, 141.75f * y, 142.22f, 141.75f));

    }

    else if (Keyboard::isKeyPressed(Keyboard::Key::Up) && Keyboard::isKeyPressed(Keyboard::Key::Left)) {

        if (s.onground) {
            s.movey = -1;
            x1 = 0;
            s.onground = false;
        }
        s.right = 0;
        s.movex = -0.3;
        y = 2;
        if (x1 < 3.4) {


            x1 += delay;
        }
        s.sprite.setTextureRect(IntRect((short int)x1 * 142.22f + 142.22f, 141.75f * y, -142.22f, 141.75f));

    }

    else if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {
        if (s.onground) {
            s.movey = -1;
            x1 = 0;
            s.onground = false;
        }

        y = 2;
        if (x1 <= 3.4) {


            x1 += delay;
        }
        s.sprite.setTextureRect(IntRect((short int)x1 * 142.22f, 141.75f * y, 142.22f, 141.75f));

    }

    else if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
        s.movex = 0.3;
        // s.sprite.move(s.movex, 0);
        s.right = 1;
        x1 += 0.2;
        y = 1;
        s.sprite.setTextureRect(IntRect((short int)x1 * 142.22f, 141.75f * y, 142.22f, 141.75f));
        if (x1 >= 8.8) {
            x1 = 0;

        }
    }

    else if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
        s.movex = -0.3;
        // s.sprite.move(s.movex, 0);
        s.right = 0;
        x1 += 0.2;
        y = 1;
        s.sprite.setTextureRect(IntRect((short int)x1 * 142.22f + 142.22f, 141.75f * y, -142.22f, 141.75f));
        if (x1 >= 8.8) {
            x1 = 0;

        }
    }

    else {

        if (s.right) {
            x1 += delay;
            y = 0;
            s.sprite.setTextureRect(IntRect((short int)x1 * 142.22f, 141.75f * y, 142.22f, 141.75f));
            if (x1 >= 7.8) {
                x1 = 0;
            }
        }
        else {

            x1 += delay;
            y = 0;
            s.sprite.setTextureRect(IntRect((short int)x1 * 142.22f + 142.22f, 141.75f * y, -142.22f, 141.75f));
            if (x1 >= 7.8) {
                x1 = 0;
            }
        }
    }

}

void player2move(player& s) {

    if ((Keyboard::isKeyPressed(Keyboard::Key::W)) && (Keyboard::isKeyPressed(Keyboard::Key::D))) {
        if (s.onground) {
            s.movey = -1;
            x2 = 0;
            s.onground = false;
        }
        s.right = 1;
        s.movex = 0.3;
        yy = 2;
        if (x2 <= 3.4) {
            x2 += delay;
        }
        s.sprite.setTextureRect(IntRect((short int)x2 * 142.22f, 141.75f * yy, 142.22f, 141.75f));

    }

    else if (Keyboard::isKeyPressed(Keyboard::Key::W) && Keyboard::isKeyPressed(Keyboard::Key::A)) {

        if (s.onground) {
            s.movey = -1;
            x2 = 0;
            s.onground = false;
        }
        s.right = 0;
        s.movex = -0.3;
        yy = 2;
        if (x2 <= 3.4) {


            x2 += delay;
        }
        s.sprite.setTextureRect(IntRect((short int)x2 * 142.22f + 142.22f, 141.75f * yy, -142.22f, 141.75f));

    }

    else if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
        if (s.onground) {
            s.movey = -1;
            x2 = 0;
            s.onground = false;
        }

        yy = 2;
        if (x2 <= 3.4) {


            x2 += delay;
        }
        s.sprite.setTextureRect(IntRect((short int)x2 * 142.22f, 141.75f * yy, 142.22f, 141.75f));

    }

    else if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
        s.movex = 0.3;
        // s.sprite.move(s.movex, 0);
        s.right = 1;
        x2 += 0.2;
        yy = 1;
        s.sprite.setTextureRect(IntRect((short int)x2 * 142.22f, 141.75f * yy, 142.22f, 141.75f));
        if (x2 >= 8.8) {
            x2 = 0;

        }
    }

    else if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
        s.movex = -0.3;
        // s.sprite.move(s.movex, 0);
        s.right = 0;
        x2 += 0.2;
        yy = 1;
        s.sprite.setTextureRect(IntRect((short int)x2 * 142.22f + 142.22f, 141.75f * yy, -142.22f, 141.75f));
        if (x2 >= 8.8) {
            x2 = 0;

        }
    }

    else {

        if (s.right) {
            x2 += delay;
            yy = 0;
            s.sprite.setTextureRect(IntRect((short int)x2 * 142.22f, 141.75f * yy, 142.22f, 141.75f));
            if (x2 >= 7.8) {
                x2 = 0;
            }
        }
        else {

            x2 += delay;
            yy = 0;
            s.sprite.setTextureRect(IntRect((short int)x2 * 142.22f + 142.22f, 141.75f * yy, -142.22f, 141.75f));
            if (x2 >= 7.8) {
                x2 = 0;
            }
        }
    }
}

void player3move(player& s) {
    if ((Keyboard::isKeyPressed(Keyboard::Key::I)) && (Keyboard::isKeyPressed(Keyboard::Key::L))) {
        if (s.onground) {
            s.movey = -1;
            x3 = 0;
            s.onground = false;
        }
        s.right = 1;
        s.movex = 0.3;
        yyy = 2;
        if (x3 <= 3.4) {


            x3 += delay;
        }
        s.sprite.setTextureRect(IntRect((short int)x3 * 142.22f, 141.75f * yyy, 142.22f, 141.75f));

    }

    else if (Keyboard::isKeyPressed(Keyboard::Key::I) && Keyboard::isKeyPressed(Keyboard::Key::J)) {

        if (s.onground) {
            s.movey = -1;
            x3 = 0;
            s.onground = false;
        }
        s.right = 0;
        s.movex = -0.3;
        yyy = 2;
        if (x3 < 3.4) {


            x3 += delay;
        }
        s.sprite.setTextureRect(IntRect((short int)x3 * 142.22f + 142.22f, 141.75f * yyy, -142.22f, 141.75f));

    }

    else if (Keyboard::isKeyPressed(Keyboard::Key::I)) {
        if (s.onground) {
            s.movey = -1;
            x3 = 0;
            s.onground = false;
        }

        yyy = 2;
        if (x3 <= 3.4) {


            x3 += delay;
        }
        s.sprite.setTextureRect(IntRect((short int)x3 * 142.22f, 141.75f * yyy, 142.22f, 141.75f));

    }

    else if (Keyboard::isKeyPressed(Keyboard::Key::L)) {
        s.movex = 0.3;
        // s.sprite.move(s.movex, 0);
        s.right = 1;
        x3 += 0.2;
        yyy = 1;
        s.sprite.setTextureRect(IntRect((short int)x3 * 142.22f, 141.75f * yyy, 142.22f, 141.75f));
        if (x3 >= 8.8) {
            x3 = 0;

        }
    }

    else if (Keyboard::isKeyPressed(Keyboard::Key::J)) {
        s.movex = -0.3;
        // s.sprite.move(s.movex, 0);
        s.right = 0;
        x3 += 0.2;
        yyy = 1;
        s.sprite.setTextureRect(IntRect((short int)x3 * 142.22f + 142.22f, 141.75f * yyy, -142.22f, 141.75f));
        if (x3 >= 8.8) {
            x3 = 0;

        }
    }

    else {

        if (s.right) {
            x3 += delay;
            yyy = 0;
            s.sprite.setTextureRect(IntRect((short int)x3 * 142.22f, 141.75f * yyy, 142.22f, 141.75f));
            if (x3 >= 7.8) {
                x3 = 0;
            }
        }
        else {

            x3 += delay;
            yyy = 0;
            s.sprite.setTextureRect(IntRect((short int)x3 * 142.22f + 142.22f, 141.75f * yyy, -142.22f, 141.75f));
            if (x3 >= 7.8) {
                x3 = 0;
            }
        }
    }




}

void player4move(player& s) {
    if ((Keyboard::isKeyPressed(Keyboard::Key::Num8)) && (Keyboard::isKeyPressed(Keyboard::Key::Num6))) {
        if (s.onground) {
            s.movey = -1;
            x4 = 0;
            s.onground = false;
        }
        s.right = 1;
        s.movex = 0.3;
        yyyy = 2;
        if (x4 <= 3.4) {


            x4 += delay;
        }
        s.sprite.setTextureRect(IntRect((short int)x4 * 142.22f, 141.75f * yyyy, 142.22f, 141.75f));

    }

    else if (Keyboard::isKeyPressed(Keyboard::Key::Num8) && Keyboard::isKeyPressed(Keyboard::Key::Num4)) {

        if (s.onground) {
            s.movey = -1;
            x4 = 0;
            s.onground = false;
        }
        s.right = 0;
        s.movex = -0.3;
        yyyy = 2;
        if (x4 < 3.4) {


            x4 += delay;
        }
        s.sprite.setTextureRect(IntRect((short int)x4 * 142.22f + 142.22f, 141.75f * yyyy, -142.22f, 141.75f));

    }

    else if (Keyboard::isKeyPressed(Keyboard::Key::Num8)) {
        if (s.onground) {
            s.movey = -1;
            x4 = 0;
            s.onground = false;
        }

        yyyy = 2;
        if (x4 < 3.4) {


            x4 += delay;
        }
        s.sprite.setTextureRect(IntRect((short int)x4 * 142.22f, 141.75f * yyyy, 142.22f, 141.75f));

    }

    else if (Keyboard::isKeyPressed(Keyboard::Key::Num6)) {
        s.movex = 0.3;
        // s.sprite.move(s.movex, 0);
        s.right = 1;
        x4 += 0.2;
        yyyy = 1;
        s.sprite.setTextureRect(IntRect((short int)x4 * 142.22f, 141.75f * yyyy, 142.22f, 141.75f));
        if (x4 >= 8.8) {
            x4 = 0;

        }
    }

    else if (Keyboard::isKeyPressed(Keyboard::Key::Num4)) {
        s.movex = -0.3;
        // s.sprite.move(s.movex, 0);
        s.right = 0;
        x4 += 0.2;
        yyyy = 1;
        s.sprite.setTextureRect(IntRect((short int)x4 * 142.22f + 142.22f, 141.75f * yyyy, -142.22f, 141.75f));
        if (x4 >= 8.8) {
            x4 = 0;

        }
    }

    else {

        if (s.right) {
            x4 += delay;
            yyyy = 0;
            s.sprite.setTextureRect(IntRect((short int)x4 * 142.22f, 141.75f * yyyy, 142.22f, 141.75f));
            if (x4 >= 7.8) {
                x4 = 0;
            }
        }
        else {

            x4 += delay;
            yyyy = 0;
            s.sprite.setTextureRect(IntRect((short int)x4 * 142.22f + 142.22f, 141.75f * yyyy, -142.22f, 141.75f));
            if (x4 >= 7.8) {
                x4 = 0;
            }
        }
    }

}

void coll_between_players(player a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[j].sprite.getGlobalBounds().intersects(a[i].sprite.getGlobalBounds())) {

                if (a[i].sprite.getPosition().y > a[j].sprite.getPosition().y) {




                    a[j].rect.top = a[i].sprite.getPosition().y - 105;
                    a[j].movey = 0;
                    a[j].onground = true;
                }

            }
        }
    }
}

void drawplayer(player x[], int i) {
    for (int k = 0; k < i; k++) {
        window.draw(x[k].sprite);
    }
}