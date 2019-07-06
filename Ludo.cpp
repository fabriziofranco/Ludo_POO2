#include "Ludo.h"
bool isSpriteClicked(const sf::Sprite& spritex, sf::RenderWindow *window) {
    sf::IntRect rect(spritex.getPosition().x, spritex.getPosition().y, spritex.getGlobalBounds().width, spritex.getGlobalBounds().height);
    return (rect.contains(sf::Mouse::getPosition()) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)));
}
Ludo::Ludo() {
    window.create(sf::VideoMode(WIDTH, HEIGHT,BPP), "LUDO!",sf::Style::Fullscreen);window.setVerticalSyncEnabled(true);
    window_puntero=&window;window.setFramerateLimit(60);
    texture_back.loadFromFile("img/background.png");background.setTexture(texture_back);
    permiso = 1;
    bloqueo_3_6 = 0;
}


void Ludo::Run() {
    sf::Font fuente; fuente.loadFromFile("fonts/titulo.ttf"); sf::Text Anuncio("Ludo!", fuente ,160);Anuncio.setOrigin(Anuncio.getLocalBounds().width/2,0); Anuncio.setPosition(WIDTH/2, 100);Anuncio.setColor(sf::Color::White);
    sf::Text Puntos_1("Rojo :", fuente ,60);Puntos_1.setOrigin(Puntos_1.getLocalBounds().width/4,0); Puntos_1.setPosition(WIDTH-530, 250);Puntos_1.setColor(sf::Color::Black);
    sf::Text Puntos_2("Verde :", fuente ,60);Puntos_2.setOrigin(Puntos_2.getLocalBounds().width/4,0); Puntos_2.setPosition(WIDTH-530, 350);Puntos_2.setColor(sf::Color::Black);
    sf::Text Puntos_3("Azul :", fuente ,60);Puntos_3.setOrigin(Puntos_3.getLocalBounds().width/4,0); Puntos_3.setPosition(WIDTH-530, 450);Puntos_3.setColor(sf::Color::Black);
    sf::Text Puntos_4("Amarillo :", fuente ,60);Puntos_4.setOrigin(Puntos_4.getLocalBounds().width/4,0); Puntos_4.setPosition(WIDTH-530, 550);Puntos_4.setColor(sf::Color::Black);
    sf::Text Anuncio2("Turno de jugador\n\t\t rojo!", fuente ,75);Anuncio2.setOrigin(Anuncio.getLocalBounds().width/2,0);Anuncio2.setColor(sf::Color::Red);sf::Text Seleccion("Jugador rojo, presione espacio para \n\t\tlanzar el dado y clickea una ficha", fuente ,40);Seleccion.setOrigin(Anuncio.getLocalBounds().width/2,0);Seleccion.setColor(sf::Color::Red);
    sf::Texture Tabla_tx;sf::Sprite Tabla_sp;Tabla_tx.loadFromFile("img/Tabla_de_puntaje.png");Tabla_tx.setSmooth(true);Tabla_sp.setTexture(Tabla_tx);Tabla_sp.setOrigin(Tabla_sp.getLocalBounds().width/4,0);Tabla_sp.setPosition(WIDTH-500,250);Tabla_sp.setScale(sf::Vector2f(0.4f, 0.545f));
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
                if(evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Key::Space){
                    if(permiso == 1 && bloqueo_3_6 < 3){
                        juego->Jugar();
                        permiso = 0;
                    }
                }
                switch (juego->getTurno()){
                    case 1:{
                        for(int i = 0; i < 4; i++){
                            if(isSpriteClicked(rojo[i],window_puntero)){
                                int movimientos=juego->getJugador1()->getMovimimientos();juego->getJugador1()->setMovimimientos(0);
                                if(movimientos == 6){bloqueo_3_6++;}else{bloqueo_3_6 = 0;}
                                if(juego->getJugador1()->getFicha(i)->getEstado() == "f"){
                                    juego->AumentoTurno();
                                    permiso = 1;
                                    break;
                                } else if(juego->getJugador1()->getFicha(i)->getEstado()=="c" && movimientos==6){
                                    rojo[i].setPosition(juego->getJugador1()->getSalida()->x,juego->getJugador1()->getSalida()->y);
                                    juego->getJugador1()->getFicha(i)->setEstado("s");
                                    juego->getJugador1()->getFicha(i)->setPosicion(-1);
                                    permiso = 1;
                                    break;}
                                else{
                                    if(juego->getJugador1()->getFicha(i)->getEstado()!="c" && juego->getJugador1()->getFicha(i)->getPosicion()!=-2 ){
                                        int posicion=juego->getJugador1()->getFicha(i)->getPosicion(),max=posicion+movimientos,retroceso=max-55;
                                        if ((max!=juego->getJugador1()->getFicha2(i)->getPosicion() && max!=juego->getJugador1()->getFicha3(i)->getPosicion()&& max!=juego->getJugador1()->getFicha4(i)->getPosicion()) || max == 55){
                                            if(max > 55){max = 55-retroceso;}
                                            if(max > posicion){
                                                for(;posicion<max;posicion++){
                                                    rojo[i].move(juego->getJugador1()->getRecorridoJugador()->getRecorrido()[posicion+1].first,juego->getJugador1()->getRecorridoJugador()->getRecorrido()[posicion+1].second);
                                                }
                                                juego->getJugador1()->getFicha(i)->setPosicion(posicion);
                                            }
                                            if(max < posicion){
                                                for(;posicion>max;posicion--){
                                                    rojo[i].move(-1*juego->getJugador1()->getRecorridoJugador()->getRecorrido()[posicion-1].first,-1*juego->getJugador1()->getRecorridoJugador()->getRecorrido()[posicion-1].second);
                                                }
                                                juego->getJugador1()->getFicha(i)->setPosicion(posicion);
                                            }
                                            juego->getJugador1()->getFicha(i)->setEstado("n");
                                            for(int j = 0; j < 4; j++){
                                                if((rojo[i].getPosition() == verde[j].getPosition()) && juego->getJugador2()->getFicha(j)->getEstado() == "n"){
                                                    juego->getJugador2()->getFicha(j)->setEstado("c");
                                                    juego->getJugador2()->getFicha(j)->setPosicion(-2);
                                                    verde[j].setPosition(juego->getJugador2()->getC(j)->x,juego->getJugador2()->getC(j)->y);
                                                }
                                                if(juego->getNumeroJugadores() >= 3){
                                                    if((rojo[i].getPosition() == azul[j].getPosition()) && juego->getJugador3()->getFicha(j)->getEstado() == "n"){
                                                        juego->getJugador3()->getFicha(j)->setEstado("c");
                                                        juego->getJugador3()->getFicha(j)->setPosicion(-2);
                                                        azul[j].setPosition(juego->getJugador3()->getC(j)->x,juego->getJugador3()->getC(j)->y);
                                                    }
                                                }
                                                if(juego->getNumeroJugadores() >= 4){
                                                    if(rojo[i].getPosition() == amarillo[j].getPosition() && juego->getJugador4()->getFicha(j)->getEstado() == "n"){
                                                        juego->getJugador4()->getFicha(j)->setEstado("c");
                                                        juego->getJugador4()->getFicha(j)->setPosicion(-2);
                                                        amarillo[j].setPosition(juego->getJugador4()->getC(j)->x,juego->getJugador4()->getC(j)->y);
                                                    }
                                                }
                                            }
                                            if(juego->getJugador1()->getFicha(i)->getPosicion() == 55){
                                                juego->getJugador1()->getFicha(i)->setEstado("f");
                                                juego->getJugador1()->aumento_puntos();
                                                int puntos = juego->getJugador1()->getPuntos();
                                                switch (puntos){
                                                    case 1:
                                                        Puntos_1.setString("Rojo : I");break;
                                                    case 2:
                                                        Puntos_1.setString("Rojo : II");break;
                                                    case 3:
                                                        Puntos_1.setString("Rojo : III");break;
                                                    case 4:
                                                        Puntos_1.setString("Rojo : IV");break;
                                                }
                                            }
                                            if(movimientos!=6)
                                                juego->AumentoTurno();permiso = 1;break;
                                        } else {
                                            juego->AumentoTurno();permiso = 1;break;
                                        }
                                    }
                                    juego->AumentoTurno();permiso = 1;break;
                                }}}
                        break; }

                    case 2:{
                        for(int i = 0; i < 4; i++){
                            if(isSpriteClicked(verde[i],window_puntero)){
                                int movimientos=juego->getJugador2()->getMovimimientos();juego->getJugador2()->setMovimimientos(0);
                                if(movimientos == 6){bloqueo_3_6++;}else{bloqueo_3_6 = 0;}
                                if(juego->getJugador2()->getFicha(i)->getEstado() == "f"){
                                    juego->AumentoTurno();permiso = 1;break;
                                } else if(juego->getJugador2()->getFicha(i)->getEstado()=="c" && movimientos==6){
                                    verde[i].setPosition(juego->getJugador2()->getSalida()->x,juego->getJugador2()->getSalida()->y);
                                    juego->getJugador2()->getFicha(i)->setEstado("s");
                                    juego->getJugador2()->getFicha(i)->setPosicion(-1);
                                    permiso = 1;
                                    break;}
                                else{
                                    if(juego->getJugador2()->getFicha(i)->getEstado()!="c" && juego->getJugador2()->getFicha(i)->getPosicion()!=-2 ){
                                        int posicion=juego->getJugador2()->getFicha(i)->getPosicion(),max=posicion+movimientos,retroceso=max-55;
                                        if ((max!=juego->getJugador2()->getFicha2(i)->getPosicion() && max!=juego->getJugador2()->getFicha3(i)->getPosicion()&& max!=juego->getJugador2()->getFicha4(i)->getPosicion()) || max == 55){
                                            if(max > 55){max = 55-retroceso;}
                                            if(max > posicion){
                                                for(;posicion<max;posicion++){
                                                    verde[i].move(juego->getJugador2()->getRecorridoJugador()->getRecorrido()[posicion+1].first,juego->getJugador2()->getRecorridoJugador()->getRecorrido()[posicion+1].second);
                                                }
                                                juego->getJugador2()->getFicha(i)->setPosicion(posicion);
                                            }
                                            if(max < posicion){
                                                for(;posicion>max;posicion--){
                                                    verde[i].move(-1*juego->getJugador2()->getRecorridoJugador()->getRecorrido()[posicion-1].first,-1*juego->getJugador2()->getRecorridoJugador()->getRecorrido()[posicion-1].second);
                                                }
                                                juego->getJugador2()->getFicha(i)->setPosicion(posicion);
                                            }
                                            juego->getJugador2()->getFicha(i)->setEstado("n");
                                            for(int j = 0; j < 4; j++){
                                                if(verde[i].getPosition() == rojo[j].getPosition() && juego->getJugador1()->getFicha(j)->getEstado() == "n"){
                                                    juego->getJugador1()->getFicha(j)->setEstado("c");
                                                    juego->getJugador1()->getFicha(j)->setPosicion(-2);
                                                    rojo[j].setPosition(juego->getJugador1()->getC(j)->x,juego->getJugador1()->getC(j)->y);
                                                }
                                                if(juego->getNumeroJugadores() >= 3){
                                                    if((verde[i].getPosition() == azul[j].getPosition()) && juego->getJugador3()->getFicha(j)->getEstado() == "n"){
                                                        juego->getJugador3()->getFicha(j)->setEstado("c");
                                                        juego->getJugador3()->getFicha(j)->setPosicion(-2);
                                                        azul[j].setPosition(juego->getJugador3()->getC(j)->x,juego->getJugador3()->getC(j)->y);
                                                    }
                                                }
                                                if(juego->getNumeroJugadores() >= 4){
                                                    if((verde[i].getPosition() == amarillo[j].getPosition()) && juego->getJugador4()->getFicha(j)->getEstado() == "n"){
                                                        juego->getJugador4()->getFicha(j)->setEstado("c");
                                                        juego->getJugador4()->getFicha(j)->setPosicion(-2);
                                                        amarillo[j].setPosition(juego->getJugador4()->getC(j)->x,juego->getJugador4()->getC(j)->y);
                                                    }
                                                }
                                            }
                                            if(juego->getJugador2()->getFicha(i)->getPosicion() >= 55){
                                                juego->getJugador1()->getFicha(i)->setEstado("f");
                                                juego->getJugador2()->aumento_puntos();
                                                int puntos = juego->getJugador2()->getPuntos();
                                                switch (puntos){
                                                    case 1:
                                                        Puntos_2.setString("Verde : I");break;
                                                    case 2:
                                                        Puntos_2.setString("Verde : II");break;
                                                    case 3:
                                                        Puntos_2.setString("Verde : III");break;
                                                    case 4:
                                                        Puntos_2.setString("Verde : IV");break;
                                                }
                                            }
                                            if(movimientos!=6)
                                                juego->AumentoTurno();permiso = 1;break;
                                        }
                                        else{
                                            juego->AumentoTurno();permiso = 1;break;
                                        }}
                                    juego->AumentoTurno();permiso = 1;break;
                                }}}
                        break; }
                    case 3:{
                        for(int i = 0; i < 4; i++){
                            if(isSpriteClicked(azul[i],window_puntero)){
                                int movimientos=juego->getJugador3()->getMovimimientos();juego->getJugador3()->setMovimimientos(0);
                                if(movimientos == 6){bloqueo_3_6++;}else{bloqueo_3_6 = 0;}
                                if(juego->getJugador3()->getFicha(i)->getEstado() == "f"){
                                    juego->AumentoTurno();permiso = 1;break;
                                } else if(juego->getJugador3()->getFicha(i)->getEstado()=="c" && movimientos==6){
                                    azul[i].setPosition(juego->getJugador3()->getSalida()->x,juego->getJugador3()->getSalida()->y);
                                    juego->getJugador3()->getFicha(i)->setEstado("s");
                                    juego->getJugador3()->getFicha(i)->setPosicion(-1);
                                    permiso = 1;
                                    break;}
                                else{
                                    if(juego->getJugador3()->getFicha(i)->getEstado()!="c" && juego->getJugador3()->getFicha(i)->getPosicion()!=-2 ){
                                        int posicion=juego->getJugador3()->getFicha(i)->getPosicion(),max=posicion+movimientos,retroceso=max-55;
                                        if ((max!=juego->getJugador3()->getFicha2(i)->getPosicion() && max!=juego->getJugador3()->getFicha3(i)->getPosicion()&& max!=juego->getJugador3()->getFicha4(i)->getPosicion()) || max == 55){
                                            if(max > 55){max = 55-retroceso;}
                                            if(max > posicion){
                                                for(;posicion<max;posicion++){
                                                    azul[i].move(juego->getJugador3()->getRecorridoJugador()->getRecorrido()[posicion+1].first,juego->getJugador3()->getRecorridoJugador()->getRecorrido()[posicion+1].second);
                                                }
                                                juego->getJugador3()->getFicha(i)->setPosicion(posicion);
                                            }
                                            if(max < posicion){
                                                for(;posicion>max;posicion--){
                                                    azul[i].move(-1*juego->getJugador3()->getRecorridoJugador()->getRecorrido()[posicion-1].first,-1*juego->getJugador3()->getRecorridoJugador()->getRecorrido()[posicion-1].second);
                                                }
                                                juego->getJugador3()->getFicha(i)->setPosicion(posicion);
                                            }
                                            juego->getJugador3()->getFicha(i)->setEstado("n");
                                            for(int j = 0; j < 4; j++){
                                                if(azul[i].getPosition() == rojo[j].getPosition() && juego->getJugador1()->getFicha(j)->getEstado() == "n"){
                                                    juego->getJugador1()->getFicha(j)->setEstado("c");
                                                    juego->getJugador1()->getFicha(j)->setPosicion(-2);
                                                    rojo[j].setPosition(juego->getJugador1()->getC(j)->x,juego->getJugador1()->getC(j)->y);
                                                }
                                                if(azul[i].getPosition() == verde[j].getPosition() && juego->getJugador2()->getFicha(j)->getEstado() == "n" ){
                                                    juego->getJugador2()->getFicha(j)->setEstado("c");
                                                    juego->getJugador2()->getFicha(j)->setPosicion(-2);
                                                    verde[j].setPosition(juego->getJugador2()->getC(j)->x,juego->getJugador2()->getC(j)->y);
                                                }
                                                if(juego->getNumeroJugadores() >= 4){
                                                    if(azul[i].getPosition() == amarillo[j].getPosition() && juego->getJugador4()->getFicha(j)->getEstado() == "n"){
                                                        juego->getJugador4()->getFicha(j)->setEstado("c");
                                                        juego->getJugador4()->getFicha(j)->setPosicion(-2);
                                                        amarillo[j].setPosition(juego->getJugador4()->getC(j)->x,juego->getJugador4()->getC(j)->y);
                                                    }
                                                }
                                            }
                                            if(juego->getJugador3()->getFicha(i)->getPosicion() >= 55){
                                                juego->getJugador1()->getFicha(i)->setEstado("f");
                                                juego->getJugador3()->aumento_puntos();
                                                int puntos = juego->getJugador3()->getPuntos();
                                                switch (puntos){
                                                    case 1:
                                                        Puntos_3.setString("Azul : I");break;
                                                    case 2:
                                                        Puntos_3.setString("Azul : II");break;
                                                    case 3:
                                                        Puntos_3.setString("Azul : III");break;
                                                    case 4:
                                                        Puntos_3.setString("Azul : IV");break;
                                                }
                                            }
                                            if(movimientos!=6)
                                                juego->AumentoTurno();permiso = 1;break;
                                        }
                                        else{
                                            juego->AumentoTurno();permiso = 1;break;
                                        }}
                                    juego->AumentoTurno();permiso = 1;break;
                                }}}
                        break; }
                    case 4:{
                        for(int i = 0; i < 4; i++){
                            if(isSpriteClicked(amarillo[i],window_puntero)){
                                int movimientos=juego->getJugador4()->getMovimimientos();juego->getJugador4()->setMovimimientos(0);
                                if(movimientos == 6){bloqueo_3_6++;}else{bloqueo_3_6 = 0;}
                                if(juego->getJugador4()->getFicha(i)->getEstado() == "f"){
                                    juego->AumentoTurno();permiso = 1;break;
                                } else if(juego->getJugador4()->getFicha(i)->getEstado()=="c" && movimientos==6){
                                    amarillo[i].setPosition(juego->getJugador4()->getSalida()->x,juego->getJugador4()->getSalida()->y);
                                    juego->getJugador4()->getFicha(i)->setEstado("s");
                                    juego->getJugador4()->getFicha(i)->setPosicion(-1);
                                    permiso = 1;
                                    break;}
                                else{
                                    if(juego->getJugador4()->getFicha(i)->getEstado()!="c" && juego->getJugador4()->getFicha(i)->getPosicion()!=-2 ){
                                        int posicion=juego->getJugador4()->getFicha(i)->getPosicion(),max=posicion+movimientos,retroceso=max-55;
                                        if ((max!=juego->getJugador4()->getFicha2(i)->getPosicion() && max!=juego->getJugador4()->getFicha3(i)->getPosicion()&& max!=juego->getJugador4()->getFicha4(i)->getPosicion()) || max == 55){
                                            if(max > 55){max = 55-retroceso;}
                                            if(max > posicion){
                                                for(;posicion<max;posicion++){
                                                    amarillo[i].move(juego->getJugador4()->getRecorridoJugador()->getRecorrido()[posicion+1].first,juego->getJugador4()->getRecorridoJugador()->getRecorrido()[posicion+1].second);
                                                }
                                                juego->getJugador4()->getFicha(i)->setPosicion(posicion);
                                            }
                                            if(max < posicion){
                                                for(;posicion>max;posicion--){
                                                    amarillo[i].move(-1*juego->getJugador4()->getRecorridoJugador()->getRecorrido()[posicion-1].first,-1*juego->getJugador4()->getRecorridoJugador()->getRecorrido()[posicion-1].second);
                                                }
                                                juego->getJugador4()->getFicha(i)->setPosicion(posicion);
                                            }
                                            juego->getJugador4()->getFicha(i)->setEstado("n");
                                            for(int j = 0; j < 4; j++){
                                                if(amarillo[i].getPosition() == rojo[j].getPosition() && juego->getJugador1()->getFicha(j)->getEstado() == "n"){
                                                    juego->getJugador1()->getFicha(j)->setEstado("c");
                                                    juego->getJugador1()->getFicha(j)->setPosicion(-2);
                                                    rojo[j].setPosition(juego->getJugador1()->getC(j)->x,juego->getJugador1()->getC(j)->y);
                                                }
                                                if(amarillo[i].getPosition() == verde[j].getPosition() && juego->getJugador2()->getFicha(j)->getEstado() == "n"){
                                                    juego->getJugador2()->getFicha(j)->setEstado("c");
                                                    juego->getJugador2()->getFicha(j)->setPosicion(-2);
                                                    verde[j].setPosition(juego->getJugador2()->getC(j)->x,juego->getJugador2()->getC(j)->y);
                                                }
                                                if(juego->getNumeroJugadores() >= 3){
                                                    if(amarillo[i].getPosition() == azul[j].getPosition() && juego->getJugador3()->getFicha(j)->getEstado() == "n"){
                                                        juego->getJugador3()->getFicha(j)->setEstado("c");
                                                        juego->getJugador3()->getFicha(j)->setPosicion(-2);
                                                        azul[j].setPosition(juego->getJugador3()->getC(j)->x,juego->getJugador3()->getC(j)->y);
                                                    }
                                                }
                                            }
                                            if(juego->getJugador4()->getFicha(i)->getPosicion() >= 55){
                                                juego->getJugador1()->getFicha(i)->setEstado("f");
                                                juego->getJugador4()->aumento_puntos();
                                                int puntos = juego->getJugador4()->getPuntos();
                                                switch (puntos){
                                                    case 1:
                                                        Puntos_4.setString("Amarillo : I");break;
                                                    case 2:
                                                        Puntos_4.setString("Amarillo : II");break;
                                                    case 3:
                                                        Puntos_4.setString("Amarillo : III");break;
                                                    case 4:
                                                        Puntos_4.setString("Amarillo : IV");break;
                                                }
                                            }
                                            if(movimientos!=6)
                                                juego->AumentoTurno();permiso = 1;break;
                                        }
                                        else{
                                            juego->AumentoTurno();permiso = 1;break;
                                        }}
                                    juego->AumentoTurno();permiso = 1;break;
                                }}}
                        break; }

                }
                                switch (juego->getNumeroJugadores()){
                    case 2:
                        if(juego->getJugador1()->getPuntos()==4)
                            Anuncio.setString("Gana rojo!");
                        else if(juego->getJugador2()->getPuntos()==4){
                            Anuncio.setString("Gana verde!");
                        }
                        break;
                    case 3:
                        if(juego->getJugador1()->getPuntos()==4)
                            Anuncio.setString("Gana rojo!");
                        else if(juego->getJugador2()->getPuntos()==4){
                            Anuncio.setString("Gana verde!");
                        }
                        else if(juego->getJugador3()->getPuntos()==4){
                            Anuncio.setString("Gana azul!");
                        }
                        break;
                    case 4:
                        if(juego->getJugador1()->getPuntos()==4)
                            Anuncio.setString("Gana rojo!");
                        else if(juego->getJugador2()->getPuntos()==4){
                            Anuncio.setString("Gana verde!");
                        }
                        else if(juego->getJugador3()->getPuntos()==4){
                            Anuncio.setString("Gana azul!");
                        }
                        else if(juego->getJugador4()->getPuntos()==4){
                            Anuncio.setString("Gana amarillo!");
                        }
                        break;

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
            window.draw(Anuncio2);window.draw(Tabla_sp);window.draw(Seleccion);window.draw(Puntos_1);window.draw(Puntos_2);window.draw(Puntos_3);window.draw(Puntos_4);
            auto tablero= juego->getTablero()->getTableroSprite(); tablero.setScale(targetTablero.x/tablero.getGlobalBounds().width,targetTablero.y/tablero.getGlobalBounds().height);tablero.setPosition(160, 153);window.draw(tablero);
            for(int i = 0; i<4; i++){window.draw(rojo[i]);}
            for(int i = 0; i<4; i++){window.draw(verde[i]);}
            if(juego->getNumeroJugadores()>=3){
                for(int i = 0; i<4; i++){window.draw(azul[i]);}}
            if(juego->getNumeroJugadores()==4){
                for(int i = 0; i<4; i++){window.draw(amarillo[i]);}}}
        window.display();
    }}
