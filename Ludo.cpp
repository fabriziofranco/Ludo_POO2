#include "Ludo.h"
bool isSpriteClicked(const sf::Sprite& spritex, sf::RenderWindow *window) {
    sf::IntRect rect(spritex.getPosition().x, spritex.getPosition().y, spritex.getGlobalBounds().width, spritex.getGlobalBounds().height);
    return (rect.contains(sf::Mouse::getPosition()) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)));
}
void MoverFicha(Juego* juego,Jugador* jugador, Ficha* ficha,sf::Sprite sprite_de_ficha){
    int movimientos=jugador->getMovimimientos();
    if(ficha->getEstado()=="c" && movimientos==6){
        sprite_de_ficha.setPosition(jugador->getSalida()->x,jugador->getSalida()->y);
        ficha->setEstado("s");
        ficha->setPosicion(-1);
        juego->AumentoTurno();}
    else{
        if(ficha->getEstado()!="c" && ficha->getPosicion()!=-2 ){
            for(int posicion=ficha->getPosicion(),max=posicion+movimientos;posicion<max;posicion++){
                sprite_de_ficha.move(juego->getJugador1()->getRecorridoJugador()->getRecorrido()[posicion+1].first,juego->getJugador1()->getRecorridoJugador()->getRecorrido()[posicion+1].second);}
            juego->getJugador1()->getFicha1()->aumento_de_posicion(movimientos);
        }juego->AumentoTurno();
    }
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
    sf::Sprite dado;dado.setTexture(Button4_tx); sf::Sprite rojo1;sf::Sprite rojo2;sf::Sprite rojo3;sf::Sprite rojo4;sf::Sprite verde1;sf::Sprite verde2;sf::Sprite verde3;sf::Sprite verde4;sf::Sprite azul1;sf::Sprite azul2;sf::Sprite azul3;sf::Sprite azul4;sf::Sprite amarillo1;sf::Sprite amarillo2;sf::Sprite amarillo3;sf::Sprite amarillo4;
    while (window.isOpen()){
        sf::Event evento;
        while (window.pollEvent(evento)){
            if(juego!= nullptr){
                if(evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Key::Space)
                    juego->Jugar();
                switch (juego->getTurno()){
                    case 1:{
                        if(isSpriteClicked(rojo1,window_puntero)){
                            int movimientos=juego->getJugador1()->getMovimimientos();
                            if(juego->getJugador1()->getFicha1()->getEstado()=="c" && movimientos==6){
                                rojo1.setPosition(juego->getJugador1()->getSalida()->x,juego->getJugador1()->getSalida()->y);
                                juego->getJugador1()->getFicha1()->setEstado("s");
                                juego->getJugador1()->getFicha1()->setPosicion(-1);
                                break;}
                            else{
                                if(juego->getJugador1()->getFicha1()->getEstado()!="c" && juego->getJugador1()->getFicha1()->getPosicion()!=-2 ){
                                    for(int posicion=juego->getJugador1()->getFicha1()->getPosicion(),max=posicion+movimientos;posicion<max;posicion++){
                                        rojo1.move(juego->getJugador1()->getRecorridoJugador()->getRecorrido()[posicion+1].first,juego->getJugador1()->getRecorridoJugador()->getRecorrido()[posicion+1].second);}
                                        juego->getJugador1()->getFicha1()->aumento_de_posicion(movimientos);
                                    }
                                if(movimientos!=6)
                                    juego->AumentoTurno();
                                }
                             break;}
                            if(isSpriteClicked(rojo2,window_puntero)){

                                int movimientos=juego->getJugador1()->getMovimimientos();
                                if(juego->getJugador1()->getFicha2()->getEstado()=="c" && movimientos==6){
                                    rojo2.setPosition(juego->getJugador1()->getSalida()->x,juego->getJugador1()->getSalida()->y);
                                    juego->getJugador1()->getFicha2()->setEstado("s");
                                    juego->getJugador1()->getFicha2()->setPosicion(-1);break;
                                }
                                else{
                                    if(juego->getJugador1()->getFicha2()->getEstado()!="c" && juego->getJugador1()->getFicha2()->getPosicion()!=-2 ){
                                        for(int posicion=juego->getJugador1()->getFicha2()->getPosicion(),max=posicion+movimientos;posicion<max;posicion++){
                                            rojo2.move(juego->getJugador1()->getRecorridoJugador()->getRecorrido()[posicion+1].first,juego->getJugador1()->getRecorridoJugador()->getRecorrido()[posicion+1].second);
                                        }
                                        juego->getJugador1()->getFicha2()->aumento_de_posicion(movimientos);
                                    }
                                    if(movimientos!=6)
                                        juego->AumentoTurno();
                                    break; }
                                }
                            if(isSpriteClicked(rojo3,window_puntero)){

                                int movimientos=juego->getJugador1()->getMovimimientos();
                                if(juego->getJugador1()->getFicha3()->getEstado()=="c" && movimientos==6){
                                    rojo3.setPosition(juego->getJugador1()->getSalida()->x,juego->getJugador1()->getSalida()->y);
                                    juego->getJugador1()->getFicha3()->setEstado("s");
                                    juego->getJugador1()->getFicha3()->setPosicion(-1);
                                    break;
                                }
                                else{
                                    if(juego->getJugador1()->getFicha3()->getEstado()!="c" && juego->getJugador1()->getFicha3()->getPosicion()!=-2 ){
                                        for(int posicion=juego->getJugador1()->getFicha3()->getPosicion(),max=posicion+movimientos;posicion<max;posicion++){
                                            rojo3.move(juego->getJugador1()->getRecorridoJugador()->getRecorrido()[posicion+1].first,juego->getJugador1()->getRecorridoJugador()->getRecorrido()[posicion+1].second);
                                        }
                                        juego->getJugador1()->getFicha3()->aumento_de_posicion(movimientos);
                                    }
                                    if(movimientos!=6)
                                        juego->AumentoTurno();
                                    break;
                                }
                                }
                        if(isSpriteClicked(rojo4,window_puntero)){

                            int movimientos=juego->getJugador1()->getMovimimientos();
                            if(juego->getJugador1()->getFicha4()->getEstado()=="c" && movimientos==6){
                                rojo4.setPosition(juego->getJugador1()->getSalida()->x,juego->getJugador1()->getSalida()->y);
                                juego->getJugador1()->getFicha4()->setEstado("s");
                                juego->getJugador1()->getFicha4()->setPosicion(-1); break;
                            }
                            else{
                                if(juego->getJugador1()->getFicha4()->getEstado()!="c" && juego->getJugador1()->getFicha4()->getPosicion()!=-2 ){
                                    for(int posicion=juego->getJugador1()->getFicha4()->getPosicion(),max=posicion+movimientos;posicion<max;posicion++){
                                        rojo4.move(juego->getJugador1()->getRecorridoJugador()->getRecorrido()[posicion+1].first,juego->getJugador1()->getRecorridoJugador()->getRecorrido()[posicion+1].second);
                                    }
                                    juego->getJugador1()->getFicha4()->aumento_de_posicion(movimientos);
                                }
                                if(movimientos!=6)
                                    juego->AumentoTurno();
                                break;
                            }}
                        break; }

                    case 2:{
                        if(isSpriteClicked(verde1,window_puntero)){
                            int movimientos=juego->getJugador2()->getMovimimientos();
                            if(juego->getJugador2()->getFicha1()->getEstado()=="c" && movimientos==6){
                                verde1.setPosition(juego->getJugador2()->getSalida()->x,juego->getJugador2()->getSalida()->y);
                                juego->getJugador2()->getFicha1()->setEstado("s");
                                juego->getJugador2()->getFicha1()->setPosicion(-1);
                                break;}
                            else{
                                if(juego->getJugador2()->getFicha1()->getEstado()!="c" && juego->getJugador2()->getFicha1()->getPosicion()!=-2 ){
                                    for(int posicion=juego->getJugador2()->getFicha1()->getPosicion(),max=posicion+movimientos;posicion<max;posicion++){
                                        verde1.move(juego->getJugador2()->getRecorridoJugador()->getRecorrido()[posicion+1].first,juego->getJugador2()->getRecorridoJugador()->getRecorrido()[posicion+1].second);}
                                    juego->getJugador2()->getFicha1()->aumento_de_posicion(movimientos);
                                }
                                if(movimientos!=6)
                                    juego->AumentoTurno();
                                break;
                            }
                        }
                        if(isSpriteClicked(verde2,window_puntero)){

                            int movimientos=juego->getJugador2()->getMovimimientos();
                            if(juego->getJugador2()->getFicha2()->getEstado()=="c" && movimientos==6){
                                verde2.setPosition(juego->getJugador2()->getSalida()->x,juego->getJugador2()->getSalida()->y);
                                juego->getJugador2()->getFicha2()->setEstado("s");
                                juego->getJugador2()->getFicha2()->setPosicion(-1);break;
                            }
                            else{
                                if(juego->getJugador2()->getFicha2()->getEstado()!="c" && juego->getJugador2()->getFicha2()->getPosicion()!=-2 ){
                                    for(int posicion=juego->getJugador2()->getFicha2()->getPosicion(),max=posicion+movimientos;posicion<max;posicion++){
                                        verde2.move(juego->getJugador2()->getRecorridoJugador()->getRecorrido()[posicion+1].first,juego->getJugador2()->getRecorridoJugador()->getRecorrido()[posicion+1].second);
                                    }
                                    juego->getJugador2()->getFicha2()->aumento_de_posicion(movimientos);
                                }
                                if(movimientos!=6)
                                    juego->AumentoTurno();
                                break; }
                        }
                        if(isSpriteClicked(verde3,window_puntero)){

                            int movimientos=juego->getJugador2()->getMovimimientos();
                            if(juego->getJugador2()->getFicha3()->getEstado()=="c" && movimientos==6){
                                verde3.setPosition(juego->getJugador2()->getSalida()->x,juego->getJugador2()->getSalida()->y);
                                juego->getJugador2()->getFicha3()->setEstado("s");
                                juego->getJugador2()->getFicha3()->setPosicion(-1);
                                break;
                            }
                            else{
                                if(juego->getJugador2()->getFicha3()->getEstado()!="c" && juego->getJugador2()->getFicha3()->getPosicion()!=-2 ){
                                    for(int posicion=juego->getJugador2()->getFicha3()->getPosicion(),max=posicion+movimientos;posicion<max;posicion++){
                                        verde3.move(juego->getJugador2()->getRecorridoJugador()->getRecorrido()[posicion+1].first,juego->getJugador2()->getRecorridoJugador()->getRecorrido()[posicion+1].second);
                                    }
                                    juego->getJugador2()->getFicha3()->aumento_de_posicion(movimientos);
                                }
                                if(movimientos!=6)
                                    juego->AumentoTurno();
                                break;
                            }
                        }
                        if(isSpriteClicked(verde4,window_puntero)){

                            int movimientos=juego->getJugador2()->getMovimimientos();
                            if(juego->getJugador2()->getFicha4()->getEstado()=="c" && movimientos==6){
                                verde4.setPosition(juego->getJugador2()->getSalida()->x,juego->getJugador2()->getSalida()->y);
                                juego->getJugador2()->getFicha4()->setEstado("s");
                                juego->getJugador2()->getFicha4()->setPosicion(-1); break;
                            }
                            else{
                                if(juego->getJugador2()->getFicha4()->getEstado()!="c" && juego->getJugador2()->getFicha4()->getPosicion()!=-2 ){
                                    for(int posicion=juego->getJugador2()->getFicha4()->getPosicion(),max=posicion+movimientos;posicion<max;posicion++){
                                        verde4.move(juego->getJugador2()->getRecorridoJugador()->getRecorrido()[posicion+1].first,juego->getJugador2()->getRecorridoJugador()->getRecorrido()[posicion+1].second);
                                    }
                                    juego->getJugador2()->getFicha4()->aumento_de_posicion(movimientos);
                                }
                                if(movimientos!=6)
                                    juego->AumentoTurno();
                                break;
                            }}
                        break; }
                    case 3:{
                        if(isSpriteClicked(azul1,window_puntero)){
                            int movimientos=juego->getJugador3()->getMovimimientos();
                            if(juego->getJugador3()->getFicha1()->getEstado()=="c" && movimientos==6){
                                azul1.setPosition(juego->getJugador3()->getSalida()->x,juego->getJugador3()->getSalida()->y);
                                juego->getJugador3()->getFicha1()->setEstado("s");
                                juego->getJugador3()->getFicha1()->setPosicion(-1);
                                break;}
                            else{
                                if(juego->getJugador3()->getFicha1()->getEstado()!="c" && juego->getJugador3()->getFicha1()->getPosicion()!=-2 ){
                                    for(int posicion=juego->getJugador3()->getFicha1()->getPosicion(),max=posicion+movimientos;posicion<max;posicion++){
                                        azul1.move(juego->getJugador3()->getRecorridoJugador()->getRecorrido()[posicion+1].first,juego->getJugador3()->getRecorridoJugador()->getRecorrido()[posicion+1].second);}
                                    juego->getJugador3()->getFicha1()->aumento_de_posicion(movimientos);
                                }
                                if(movimientos!=6)
                                    juego->AumentoTurno();
                                break;
                            }
                        }
                        if(isSpriteClicked(azul2,window_puntero)){

                            int movimientos=juego->getJugador3()->getMovimimientos();
                            if(juego->getJugador3()->getFicha2()->getEstado()=="c" && movimientos==6){
                                azul2.setPosition(juego->getJugador3()->getSalida()->x,juego->getJugador3()->getSalida()->y);
                                juego->getJugador3()->getFicha2()->setEstado("s");
                                juego->getJugador3()->getFicha2()->setPosicion(-1);break;
                            }
                            else{
                                if(juego->getJugador3()->getFicha2()->getEstado()!="c" && juego->getJugador3()->getFicha2()->getPosicion()!=-2 ){
                                    for(int posicion=juego->getJugador3()->getFicha2()->getPosicion(),max=posicion+movimientos;posicion<max;posicion++){
                                        azul2.move(juego->getJugador3()->getRecorridoJugador()->getRecorrido()[posicion+1].first,juego->getJugador3()->getRecorridoJugador()->getRecorrido()[posicion+1].second);
                                    }
                                    juego->getJugador3()->getFicha2()->aumento_de_posicion(movimientos);
                                }
                                if(movimientos!=6)
                                    juego->AumentoTurno();
                                break; }
                        }
                        if(isSpriteClicked(azul3,window_puntero)){

                            int movimientos=juego->getJugador3()->getMovimimientos();
                            if(juego->getJugador3()->getFicha3()->getEstado()=="c" && movimientos==6){
                                azul3.setPosition(juego->getJugador3()->getSalida()->x,juego->getJugador3()->getSalida()->y);
                                juego->getJugador3()->getFicha3()->setEstado("s");
                                juego->getJugador3()->getFicha3()->setPosicion(-1);
                                break;
                            }
                            else{
                                if(juego->getJugador3()->getFicha3()->getEstado()!="c" && juego->getJugador3()->getFicha3()->getPosicion()!=-2 ){
                                    for(int posicion=juego->getJugador3()->getFicha3()->getPosicion(),max=posicion+movimientos;posicion<max;posicion++){
                                        azul3.move(juego->getJugador3()->getRecorridoJugador()->getRecorrido()[posicion+1].first,juego->getJugador3()->getRecorridoJugador()->getRecorrido()[posicion+1].second);
                                    }
                                    juego->getJugador3()->getFicha3()->aumento_de_posicion(movimientos);
                                }
                                if(movimientos!=6)
                                    juego->AumentoTurno();
                                break;
                            }
                        }
                        if(isSpriteClicked(azul4,window_puntero)){

                            int movimientos=juego->getJugador3()->getMovimimientos();
                            if(juego->getJugador3()->getFicha4()->getEstado()=="c" && movimientos==6){
                                azul4.setPosition(juego->getJugador3()->getSalida()->x,juego->getJugador3()->getSalida()->y);
                                juego->getJugador3()->getFicha4()->setEstado("s");
                                juego->getJugador3()->getFicha4()->setPosicion(-1);break;
                            }
                            else{
                                if(juego->getJugador3()->getFicha4()->getEstado()!="c" && juego->getJugador3()->getFicha4()->getPosicion()!=-2 ){
                                    for(int posicion=juego->getJugador3()->getFicha4()->getPosicion(),max=posicion+movimientos;posicion<max;posicion++){
                                        azul4.move(juego->getJugador3()->getRecorridoJugador()->getRecorrido()[posicion+1].first,juego->getJugador3()->getRecorridoJugador()->getRecorrido()[posicion+1].second);
                                    }
                                    juego->getJugador3()->getFicha4()->aumento_de_posicion(movimientos);
                                }
                                if(movimientos!=6)
                                    juego->AumentoTurno();
                                break;
                            }}
                        break; }
                    case 4:{
                        if(isSpriteClicked(amarillo1,window_puntero)){
                            int movimientos=juego->getJugador4()->getMovimimientos();
                            if(juego->getJugador4()->getFicha1()->getEstado()=="c" && movimientos==6){
                                amarillo1.setPosition(juego->getJugador4()->getSalida()->x,juego->getJugador4()->getSalida()->y);
                                juego->getJugador4()->getFicha1()->setEstado("s");
                                juego->getJugador4()->getFicha1()->setPosicion(-1);
                                break;}
                            else{
                                if(juego->getJugador4()->getFicha1()->getEstado()!="c" && juego->getJugador4()->getFicha1()->getPosicion()!=-2 ){
                                    for(int posicion=juego->getJugador4()->getFicha1()->getPosicion(),max=posicion+movimientos;posicion<max;posicion++){
                                        amarillo1.move(juego->getJugador4()->getRecorridoJugador()->getRecorrido()[posicion+1].first,juego->getJugador4()->getRecorridoJugador()->getRecorrido()[posicion+1].second);}
                                    juego->getJugador4()->getFicha1()->aumento_de_posicion(movimientos);
                                }
                                if(movimientos!=6)
                                    juego->AumentoTurno();
                                break;
                            }
                        }
                        if(isSpriteClicked(amarillo2,window_puntero)){

                            int movimientos=juego->getJugador4()->getMovimimientos();
                            if(juego->getJugador4()->getFicha2()->getEstado()=="c" && movimientos==6){
                                amarillo2.setPosition(juego->getJugador4()->getSalida()->x,juego->getJugador4()->getSalida()->y);
                                juego->getJugador4()->getFicha2()->setEstado("s");
                                juego->getJugador4()->getFicha2()->setPosicion(-1);break;
                            }
                            else{
                                if(juego->getJugador4()->getFicha2()->getEstado()!="c" && juego->getJugador4()->getFicha2()->getPosicion()!=-2 ){
                                    for(int posicion=juego->getJugador4()->getFicha2()->getPosicion(),max=posicion+movimientos;posicion<max;posicion++){
                                        amarillo2.move(juego->getJugador4()->getRecorridoJugador()->getRecorrido()[posicion+1].first,juego->getJugador4()->getRecorridoJugador()->getRecorrido()[posicion+1].second);
                                    }
                                    juego->getJugador4()->getFicha2()->aumento_de_posicion(movimientos);
                                }
                                if(movimientos!=6)
                                    juego->AumentoTurno();
                                break; }
                        }
                        if(isSpriteClicked(amarillo3,window_puntero)){

                            int movimientos=juego->getJugador4()->getMovimimientos();
                            if(juego->getJugador4()->getFicha3()->getEstado()=="c" && movimientos==6){
                                amarillo3.setPosition(juego->getJugador4()->getSalida()->x,juego->getJugador4()->getSalida()->y);
                                juego->getJugador4()->getFicha3()->setEstado("s");
                                juego->getJugador4()->getFicha3()->setPosicion(-1);
                                break;
                            }
                            else{
                                if(juego->getJugador4()->getFicha3()->getEstado()!="c" && juego->getJugador4()->getFicha3()->getPosicion()!=-2 ){
                                    for(int posicion=juego->getJugador4()->getFicha3()->getPosicion(),max=posicion+movimientos;posicion<max;posicion++){
                                        amarillo3.move(juego->getJugador4()->getRecorridoJugador()->getRecorrido()[posicion+1].first,juego->getJugador4()->getRecorridoJugador()->getRecorrido()[posicion+1].second);
                                    }
                                    juego->getJugador4()->getFicha3()->aumento_de_posicion(movimientos);
                                }
                                if(movimientos!=6)
                                    juego->AumentoTurno();
                                break;
                            }
                        }
                        if(isSpriteClicked(amarillo4,window_puntero)){

                            int movimientos=juego->getJugador4()->getMovimimientos();
                            if(juego->getJugador4()->getFicha4()->getEstado()=="c" && movimientos==6){
                                amarillo4.setPosition(juego->getJugador4()->getSalida()->x,juego->getJugador4()->getSalida()->y);
                                juego->getJugador4()->getFicha4()->setEstado("s");
                                juego->getJugador4()->getFicha4()->setPosicion(-1);break;
                            }
                            else{
                                if(juego->getJugador4()->getFicha4()->getEstado()!="c" && juego->getJugador4()->getFicha4()->getPosicion()!=-2 ){
                                    for(int posicion=juego->getJugador4()->getFicha4()->getPosicion(),max=posicion+movimientos;posicion<max;posicion++){
                                        amarillo4.move(juego->getJugador4()->getRecorridoJugador()->getRecorrido()[posicion+1].first,juego->getJugador4()->getRecorridoJugador()->getRecorrido()[posicion+1].second);
                                    }
                                    juego->getJugador4()->getFicha4()->aumento_de_posicion(movimientos);
                                }
                                if(movimientos!=6)
                                    juego->AumentoTurno();
                                break;
                            }}
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
                    rojo1=juego->getJugador1()->getFicha1()->getSpriteFicha();rojo1.setPosition(juego->getJugador1()->getC1()->x,juego->getJugador1()->getC1()->y);
                    rojo2=juego->getJugador1()->getFicha2()->getSpriteFicha();rojo2.setPosition(juego->getJugador1()->getC2()->x,juego->getJugador1()->getC2()->y);
                    rojo3=juego->getJugador1()->getFicha3()->getSpriteFicha();rojo3.setPosition(juego->getJugador1()->getC3()->x,juego->getJugador1()->getC3()->y);
                    rojo4=juego->getJugador1()->getFicha4()->getSpriteFicha();rojo4.setPosition(juego->getJugador1()->getC4()->x,juego->getJugador1()->getC4()->y);
                    verde1=juego->getJugador2()->getFicha1()->getSpriteFicha();verde1.setPosition(juego->getJugador2()->getC1()->x,juego->getJugador2()->getC1()->y);
                    verde2=juego->getJugador2()->getFicha2()->getSpriteFicha();verde2.setPosition(juego->getJugador2()->getC2()->x,juego->getJugador2()->getC2()->y);
                    verde3=juego->getJugador2()->getFicha3()->getSpriteFicha();verde3.setPosition(juego->getJugador2()->getC3()->x,juego->getJugador2()->getC3()->y);
                    verde4=juego->getJugador2()->getFicha4()->getSpriteFicha();verde4.setPosition(juego->getJugador2()->getC4()->x,juego->getJugador2()->getC4()->y);
                }
                if(isSpriteClicked(Button3,window_puntero)){
                    Button2.move(-10000,0);Button3.move(10000,0);Button4.move(10000,0);Anuncio2.setPosition(WIDTH-200,105);Seleccion.setPosition(WIDTH-270,650);
                    juego=new Juego(3);Anuncio.move(0,-150);
                    rojo1=juego->getJugador1()->getFicha1()->getSpriteFicha();rojo1.setPosition(juego->getJugador1()->getC1()->x,juego->getJugador1()->getC1()->y);
                    rojo2=juego->getJugador1()->getFicha2()->getSpriteFicha();rojo2.setPosition(juego->getJugador1()->getC2()->x,juego->getJugador1()->getC2()->y);
                    rojo3=juego->getJugador1()->getFicha3()->getSpriteFicha();rojo3.setPosition(juego->getJugador1()->getC3()->x,juego->getJugador1()->getC3()->y);
                    rojo4=juego->getJugador1()->getFicha4()->getSpriteFicha();rojo4.setPosition(juego->getJugador1()->getC4()->x,juego->getJugador1()->getC4()->y);
                    verde1=juego->getJugador2()->getFicha1()->getSpriteFicha();verde1.setPosition(juego->getJugador2()->getC1()->x,juego->getJugador2()->getC1()->y);
                    verde2=juego->getJugador2()->getFicha2()->getSpriteFicha();verde2.setPosition(juego->getJugador2()->getC2()->x,juego->getJugador2()->getC2()->y);
                    verde3=juego->getJugador2()->getFicha3()->getSpriteFicha();verde3.setPosition(juego->getJugador2()->getC3()->x,juego->getJugador2()->getC3()->y);
                    verde4=juego->getJugador2()->getFicha4()->getSpriteFicha();verde4.setPosition(juego->getJugador2()->getC4()->x,juego->getJugador2()->getC4()->y);
                    azul1=juego->getJugador3()->getFicha1()->getSpriteFicha();azul1.setPosition(juego->getJugador3()->getC1()->x,juego->getJugador3()->getC1()->y);
                    azul2=juego->getJugador3()->getFicha2()->getSpriteFicha();azul2.setPosition(juego->getJugador3()->getC2()->x,juego->getJugador3()->getC2()->y);
                    azul3=juego->getJugador3()->getFicha3()->getSpriteFicha();azul3.setPosition(juego->getJugador3()->getC3()->x,juego->getJugador3()->getC3()->y);
                    azul4=juego->getJugador3()->getFicha4()->getSpriteFicha();azul4.setPosition(juego->getJugador3()->getC4()->x,juego->getJugador3()->getC4()->y);
                }
                if(isSpriteClicked(Button4,window_puntero)){
                    Button2.move(-10000,0);Button3.move(10000,0);Button4.move(10000,0);Anuncio2.setPosition(WIDTH-200,105);Seleccion.setPosition(WIDTH-270,650);
                    juego=new Juego(4);Anuncio.move(0,-150);
                    rojo1=juego->getJugador1()->getFicha1()->getSpriteFicha();rojo1.setPosition(juego->getJugador1()->getC1()->x,juego->getJugador1()->getC1()->y);
                    rojo2=juego->getJugador1()->getFicha2()->getSpriteFicha();rojo2.setPosition(juego->getJugador1()->getC2()->x,juego->getJugador1()->getC2()->y);
                    rojo3=juego->getJugador1()->getFicha3()->getSpriteFicha();rojo3.setPosition(juego->getJugador1()->getC3()->x,juego->getJugador1()->getC3()->y);
                    rojo4=juego->getJugador1()->getFicha4()->getSpriteFicha();rojo4.setPosition(juego->getJugador1()->getC4()->x,juego->getJugador1()->getC4()->y);
                    verde1=juego->getJugador2()->getFicha1()->getSpriteFicha();verde1.setPosition(juego->getJugador2()->getC1()->x,juego->getJugador2()->getC1()->y);
                    verde2=juego->getJugador2()->getFicha2()->getSpriteFicha();verde2.setPosition(juego->getJugador2()->getC2()->x,juego->getJugador2()->getC2()->y);
                    verde3=juego->getJugador2()->getFicha3()->getSpriteFicha();verde3.setPosition(juego->getJugador2()->getC3()->x,juego->getJugador2()->getC3()->y);
                    verde4=juego->getJugador2()->getFicha4()->getSpriteFicha();verde4.setPosition(juego->getJugador2()->getC4()->x,juego->getJugador2()->getC4()->y);
                    azul1=juego->getJugador3()->getFicha1()->getSpriteFicha();azul1.setPosition(juego->getJugador3()->getC1()->x,juego->getJugador3()->getC1()->y);
                    azul2=juego->getJugador3()->getFicha2()->getSpriteFicha();azul2.setPosition(juego->getJugador3()->getC2()->x,juego->getJugador3()->getC2()->y);
                    azul3=juego->getJugador3()->getFicha3()->getSpriteFicha();azul3.setPosition(juego->getJugador3()->getC3()->x,juego->getJugador3()->getC3()->y);
                    azul4=juego->getJugador3()->getFicha4()->getSpriteFicha();azul4.setPosition(juego->getJugador3()->getC4()->x,juego->getJugador3()->getC4()->y);
                    amarillo1=juego->getJugador4()->getFicha1()->getSpriteFicha();amarillo1.setPosition(juego->getJugador4()->getC1()->x,juego->getJugador4()->getC1()->y);
                    amarillo2=juego->getJugador4()->getFicha2()->getSpriteFicha();amarillo2.setPosition(juego->getJugador4()->getC2()->x,juego->getJugador4()->getC2()->y);
                    amarillo3=juego->getJugador4()->getFicha3()->getSpriteFicha();amarillo3.setPosition(juego->getJugador4()->getC3()->x,juego->getJugador4()->getC3()->y);
                    amarillo4=juego->getJugador4()->getFicha4()->getSpriteFicha();amarillo4.setPosition(juego->getJugador4()->getC4()->x,juego->getJugador4()->getC4()->y);
                }}
        }
        window.clear();
        window.draw(background);window.draw(Anuncio);window.draw(exit_sp);
        window.draw(Button2);window.draw(Button3);window.draw(Button4);
        if(juego!= nullptr ){
            dado= juego->getDado()->getDadoSprite();dado.setOrigin(dado.getLocalBounds().width/2,dado.getLocalBounds().height/2);dado.setPosition(WIDTH-100,500);window.draw(dado);
            window.draw(Anuncio2);window.draw(Seleccion);
            auto tablero= juego->getTablero()->getTableroSprite(); tablero.setScale(targetTablero.x/tablero.getGlobalBounds().width,targetTablero.y/tablero.getGlobalBounds().height);tablero.setPosition(160, 153);window.draw(tablero);
                window.draw(rojo1);window.draw(rojo2);window.draw(rojo3);window.draw(rojo4);window.draw(verde1);window.draw(verde2);window.draw(verde3);window.draw(verde4);
            if(juego->getNumeroJugadores()==3){
                window.draw(azul1);window.draw(azul2);window.draw(azul3);window.draw(azul4);}
            if(juego->getNumeroJugadores()==4){
                window.draw(azul1);window.draw(azul2);window.draw(azul3);window.draw(azul4);window.draw(amarillo1);window.draw(amarillo2);window.draw(amarillo4);window.draw(amarillo3);}}
        window.display();
}}
