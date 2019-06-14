#include "Ludo.h"
bool isSpriteClicked(const sf::Sprite& spritex, sf::RenderWindow *window) {
    sf::IntRect rect(spritex.getPosition().x, spritex.getPosition().y, spritex.getGlobalBounds().width, spritex.getGlobalBounds().height);
    return (rect.contains(sf::Mouse::getPosition()) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)));
}
Ludo::Ludo() {
    window.create(sf::VideoMode(WIDTH, HEIGHT,BPP), "LUDO!",sf::Style::Fullscreen);window.setVerticalSyncEnabled(true);
    window_puntero=&window;
    texture_back.loadFromFile("img/background.png");background.setTexture(texture_back);
}


void Ludo::Run() {
    sf::Font fuente; fuente.loadFromFile("fonts/titulo.ttf"); sf::Text Anuncio("Ludo!", fuente ,160);Anuncio.setOrigin(Anuncio.getLocalBounds().width/2,0); Anuncio.setPosition(WIDTH/2, 100);Anuncio.setColor(sf::Color::White);
    sf::Text Anuncio2("Turno de jugador\n\t\t rojo!", fuente ,75);Anuncio2.setOrigin(Anuncio.getLocalBounds().width/2,0);Anuncio2.setColor(sf::Color::Red);sf::Text Seleccion("Jugador rojo, presione espacio para \n\t\tlanzar el dado y clickea una ficha", fuente ,40);Seleccion.setOrigin(Anuncio.getLocalBounds().width/2,0);Seleccion.setColor(sf::Color::Red);
    sf::Texture exit_tx;sf::Sprite exit_sp;exit_tx.loadFromFile("img/exit.png");exit_sp.setTexture(exit_tx);exit_sp.setOrigin(exit_sp.getLocalBounds().width/2,0);exit_sp.setPosition(WIDTH-20,0);
    sf::Vector2f targetSize(300.0f,100.0f); sf::Vector2f targetTablero(600.0f,600.0f);
    sf::Sprite Button2;sf::Texture Button2_tx;Button2_tx.loadFromFile("img/2players.png"); Button2.setTexture(Button2_tx);Button2.setScale(targetSize.x/Button2.getGlobalBounds().width,targetSize.y/Button2.getGlobalBounds().height);
    Button2.setPosition(175, 375);
    sf::Sprite Button3;sf::Texture Button3_tx;Button3_tx.loadFromFile("img/3players.png"); Button3.setTexture(Button3_tx);Button3.setScale(targetSize.x/Button3.getGlobalBounds().width,targetSize.y/Button3.getGlobalBounds().height);
    Button3.setPosition(575, 375);
    sf::Sprite Button4;sf::Texture Button4_tx;Button4_tx.loadFromFile("img/4players.png"); Button4.setTexture(Button4_tx);Button4.setScale(targetSize.x/Button4.getGlobalBounds().width,targetSize.y/Button4.getGlobalBounds().height);
    Button4.setPosition(975, 375);
    sf::Sprite dado;dado.setTexture(Button4_tx); sf::Sprite rojo[4];sf::Sprite verde[4];sf::Sprite azul[4];sf::Sprite amarillo[4];
    while (window.isOpen()){
        sf::Event evento;
        while (window.pollEvent(evento)){
            if(juego!= nullptr){
                if(evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Key::Space)
                    juego->Jugar();
                switch (juego->getTurno()){
                    case 1:{
                        for(int i = 0; i < 4; i++){
                        if(isSpriteClicked(rojo[i],window_puntero)){
                            int movimientos=juego->getJugador1()->getMovimimientos();juego->getJugador1()->setMovimimientos(0);
                            if(juego->getJugador1()->getFicha(i)->getEstado()=="c" && movimientos==6){
                                rojo[i].setPosition(juego->getJugador1()->getSalida()->x,juego->getJugador1()->getSalida()->y);
                                juego->getJugador1()->getFicha(i)->setEstado("s");
                                juego->getJugador1()->getFicha(i)->setPosicion(-1);
                                break;}
                            else{
                                if(juego->getJugador1()->getFicha(i)->getEstado()!="c" && juego->getJugador1()->getFicha(i)->getPosicion()!=-2 ){
                                    int posicion=juego->getJugador1()->getFicha(i)->getPosicion(),max=posicion+movimientos;
                                    if (max!=juego->getJugador1()->getFicha2(i)->getPosicion() && max!=juego->getJugador1()->getFicha3(i)->getPosicion()&& max!=juego->getJugador1()->getFicha4(i)->getPosicion()){
                                        for(;posicion<max;posicion++){
                                            rojo[i].move(juego->getJugador1()->getRecorridoJugador()->getRecorrido()[posicion+1].first,juego->getJugador1()->getRecorridoJugador()->getRecorrido()[posicion+1].second);}
                                        juego->getJugador1()->getFicha(i)->aumento_de_posicion(movimientos);
                                        if(movimientos!=6)
                                            juego->AumentoTurno();break;
                                    }
                                    else{
                                        juego->AumentoTurno();break;
                                    }}
                                juego->AumentoTurno();break;
                            }}}
                        break; }

                    case 2:{
                        for(int i = 0; i < 4; i++){
                            if(isSpriteClicked(verde[i],window_puntero)){
                                int movimientos=juego->getJugador2()->getMovimimientos();juego->getJugador2()->setMovimimientos(0);
                                if(juego->getJugador2()->getFicha(i)->getEstado()=="c" && movimientos==6){
                                    verde[i].setPosition(juego->getJugador2()->getSalida()->x,juego->getJugador2()->getSalida()->y);
                                    juego->getJugador2()->getFicha(i)->setEstado("s");
                                    juego->getJugador2()->getFicha(i)->setPosicion(-1);
                                    break;}
                                else{
                                    if(juego->getJugador2()->getFicha(i)->getEstado()!="c" && juego->getJugador2()->getFicha(i)->getPosicion()!=-2 ){
                                        int posicion=juego->getJugador2()->getFicha(i)->getPosicion(),max=posicion+movimientos;
                                        if (max!=juego->getJugador2()->getFicha2(i)->getPosicion() && max!=juego->getJugador2()->getFicha3(i)->getPosicion()&& max!=juego->getJugador2()->getFicha4(i)->getPosicion()){
                                            for(;posicion<max;posicion++){
                                                verde[i].move(juego->getJugador2()->getRecorridoJugador()->getRecorrido()[posicion+1].first,juego->getJugador2()->getRecorridoJugador()->getRecorrido()[posicion+1].second);}
                                            juego->getJugador2()->getFicha(i)->aumento_de_posicion(movimientos);
                                            if(movimientos!=6)
                                                juego->AumentoTurno();break;
                                        }
                                        else{
                                            juego->AumentoTurno();break;
                                        }}
                                    juego->AumentoTurno();break;
                                }}}
                        break; }
                    case 3:{
                        for(int i = 0; i < 4; i++){
                            if(isSpriteClicked(azul[i],window_puntero)){
                                int movimientos=juego->getJugador3()->getMovimimientos();juego->getJugador3()->setMovimimientos(0);
                                if(juego->getJugador3()->getFicha(i)->getEstado()=="c" && movimientos==6){
                                    azul[i].setPosition(juego->getJugador3()->getSalida()->x,juego->getJugador3()->getSalida()->y);
                                    juego->getJugador3()->getFicha(i)->setEstado("s");
                                    juego->getJugador3()->getFicha(i)->setPosicion(-1);
                                    break;}
                                else{
                                    if(juego->getJugador3()->getFicha(i)->getEstado()!="c" && juego->getJugador3()->getFicha(i)->getPosicion()!=-2 ){
                                        int posicion=juego->getJugador3()->getFicha(i)->getPosicion(),max=posicion+movimientos;
                                        if (max!=juego->getJugador3()->getFicha2(i)->getPosicion() && max!=juego->getJugador3()->getFicha3(i)->getPosicion()&& max!=juego->getJugador3()->getFicha4(i)->getPosicion()){
                                            for(;posicion<max;posicion++){
                                                azul[i].move(juego->getJugador3()->getRecorridoJugador()->getRecorrido()[posicion+1].first,juego->getJugador3()->getRecorridoJugador()->getRecorrido()[posicion+1].second);}
                                            juego->getJugador3()->getFicha(i)->aumento_de_posicion(movimientos);
                                            if(movimientos!=6)
                                                juego->AumentoTurno();break;
                                        }
                                        else{
                                            juego->AumentoTurno();break;
                                        }}
                                    juego->AumentoTurno();break;
                                }}}
                        break; }
                    case 4:{
                        for(int i = 0; i < 4; i++){
                            if(isSpriteClicked(amarillo[i],window_puntero)){
                                int movimientos=juego->getJugador4()->getMovimimientos();juego->getJugador4()->setMovimimientos(0);
                                if(juego->getJugador4()->getFicha(i)->getEstado()=="c" && movimientos==6){
                                    amarillo[i].setPosition(juego->getJugador4()->getSalida()->x,juego->getJugador4()->getSalida()->y);
                                    juego->getJugador4()->getFicha(i)->setEstado("s");
                                    juego->getJugador4()->getFicha(i)->setPosicion(-1);
                                    break;}
                                else{
                                    if(juego->getJugador4()->getFicha(i)->getEstado()!="c" && juego->getJugador4()->getFicha(i)->getPosicion()!=-2 ){
                                        int posicion=juego->getJugador4()->getFicha(i)->getPosicion(),max=posicion+movimientos;
                                        if (max!=juego->getJugador4()->getFicha2(i)->getPosicion() && max!=juego->getJugador4()->getFicha3(i)->getPosicion()&& max!=juego->getJugador4()->getFicha4(i)->getPosicion()){
                                            for(;posicion<max;posicion++){
                                                amarillo[i].move(juego->getJugador4()->getRecorridoJugador()->getRecorrido()[posicion+1].first,juego->getJugador4()->getRecorridoJugador()->getRecorrido()[posicion+1].second);}
                                            juego->getJugador4()->getFicha(i)->aumento_de_posicion(movimientos);
                                            if(movimientos!=6)
                                                juego->AumentoTurno();break;
                                        }
                                        else{
                                            juego->AumentoTurno();break;
                                        }}
                                    juego->AumentoTurno();break;
                                }}}
                        break; }

                }
                switch (juego->getTurno()){
                    case 1:{
                        Anuncio2.setColor(sf::Color::Red); Seleccion.setColor(sf::Color::Red);
                        Anuncio2.setString("Turno de jugador\n\t\t rojo!"); Seleccion.setString("Jugador rojo, presione espacio para \n\t\tlanzar el dado y clickea una ficha");break;}
                    case 2:{
                        Anuncio2.setColor(sf::Color::Green);Seleccion.setColor(sf::Color::Black );
                        Anuncio2.setString("Turno de jugador\n\t\t verde!");Seleccion.setString("Jugador verde, presione espacio para \n\t\tlanzar el dado y clickea una ficha");break;}
                    case 3:{
                        Anuncio2.setColor(sf::Color::Blue);Seleccion.setColor(sf::Color::Blue);
                        Anuncio2.setString("Turno de jugador\n\t\t azul!");Seleccion.setString("Jugador azul, presione espacio para \n\t\tlanzar el dado y clickea una ficha");break;}
                    case 4:{
                        Anuncio2.setColor(sf::Color::Yellow);Seleccion.setColor(sf::Color::Black);
                        Anuncio2.setString("Turno de jugador\n\t\t amarillo!");Seleccion.setString("Jugador amarillo, presione espacio para \n\t\tlanzar el dado y clickea una ficha");break;}
                }}
            if(isSpriteClicked(exit_sp,window_puntero)){
                delete juego; window.close();}
            if(juego== nullptr){
                if(isSpriteClicked(Button2,window_puntero)){
                    Button2.move(-10000,0);Button3.move(10000,0);Button4.move(10000,0);Anuncio2.setPosition(WIDTH-200,105);Seleccion.setPosition(WIDTH-270,650);
                    juego=new Juego(2);Anuncio.move(0,-150);
                    for(int i = 0; i<4 ;i++){
                        rojo[i]=juego->getJugador1()->getFicha(i)->getSpriteFicha();rojo[i].setPosition(juego->getJugador1()->getC(i)->x,juego->getJugador1()->getC(i)->y);
                        verde[i]=juego->getJugador2()->getFicha(i)->getSpriteFicha();verde[i].setPosition(juego->getJugador2()->getC(i)->x,juego->getJugador2()->getC(i)->y);
                    }
                }
                if(isSpriteClicked(Button3,window_puntero)){
                    Button2.move(-10000,0);Button3.move(10000,0);Button4.move(10000,0);Anuncio2.setPosition(WIDTH-200,105);Seleccion.setPosition(WIDTH-270,650);
                    juego=new Juego(3);Anuncio.move(0,-150);
                    for(int i = 0; i<4 ;i++){
                        rojo[i]=juego->getJugador1()->getFicha(i)->getSpriteFicha();rojo[i].setPosition(juego->getJugador1()->getC(i)->x,juego->getJugador1()->getC(i)->y);
                        verde[i]=juego->getJugador2()->getFicha(i)->getSpriteFicha();verde[i].setPosition(juego->getJugador2()->getC(i)->x,juego->getJugador2()->getC(i)->y);
                        azul[i]=juego->getJugador3()->getFicha(i)->getSpriteFicha();azul[i].setPosition(juego->getJugador3()->getC(i)->x,juego->getJugador3()->getC(i)->y);
                    }
                }
                if(isSpriteClicked(Button4,window_puntero)){
                    Button2.move(-10000,0);Button3.move(10000,0);Button4.move(10000,0);Anuncio2.setPosition(WIDTH-200,105);Seleccion.setPosition(WIDTH-270,650);
                    juego=new Juego(4);Anuncio.move(0,-150);
                    for(int i = 0; i<4 ;i++){
                        rojo[i]=juego->getJugador1()->getFicha(i)->getSpriteFicha();rojo[i].setPosition(juego->getJugador1()->getC(i)->x,juego->getJugador1()->getC(i)->y);
                        verde[i]=juego->getJugador2()->getFicha(i)->getSpriteFicha();verde[i].setPosition(juego->getJugador2()->getC(i)->x,juego->getJugador2()->getC(i)->y);
                        azul[i]=juego->getJugador3()->getFicha(i)->getSpriteFicha();azul[i].setPosition(juego->getJugador3()->getC(i)->x,juego->getJugador3()->getC(i)->y);
                        amarillo[i]=juego->getJugador4()->getFicha(i)->getSpriteFicha();amarillo[i].setPosition(juego->getJugador4()->getC(i)->x,juego->getJugador4()->getC(i)->y);
                    }
                }}
        }
        window.clear();
        window.draw(background);window.draw(Anuncio);window.draw(exit_sp);
        window.draw(Button2);window.draw(Button3);window.draw(Button4);
        if(juego!= nullptr ){
            dado= juego->getDado()->getDadoSprite();dado.setOrigin(dado.getLocalBounds().width/2,dado.getLocalBounds().height/2);dado.setPosition(WIDTH-100,500);window.draw(dado);
            window.draw(Anuncio2);window.draw(Seleccion);
            auto tablero= juego->getTablero()->getTableroSprite(); tablero.setScale(targetTablero.x/tablero.getGlobalBounds().width,targetTablero.y/tablero.getGlobalBounds().height);tablero.setPosition(160, 153);window.draw(tablero);
            for(int i = 0; i<4; i++){window.draw(rojo[i]);}
            for(int i = 0; i<4; i++){window.draw(verde[i]);}
            if(juego->getNumeroJugadores()>=3){
                for(int i = 0; i<4; i++){window.draw(azul[i]);}}
            if(juego->getNumeroJugadores()==4){
                for(int i = 0; i<4; i++){window.draw(azul[i]);}}}
        window.display();
    }}