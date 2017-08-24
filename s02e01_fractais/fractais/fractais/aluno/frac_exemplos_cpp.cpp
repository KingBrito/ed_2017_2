#include <lib/pen.h>

void tree(Pen &p, int dist){
    //ponto de parada
    if(dist < 5)
        return;
    //acao
    p.setColor(255, 255, 255);
    p.walk(dist);
    //chamada recursiva
    p.right(20);
    tree(p, dist - 12);
    p.left(40);
    tree(p, dist - 12);
    p.right(20);
    p.setColor(0, 255, 0);
    p.walk(-dist);
}

void fractal(){
    Pen p(800, 600);
    //coloca o pincel na posicao x 300 y 500
    p.setXY(400, 600);
    p.setThickness(2);

    //faz o pincel apontar pra direita
    p.setHeading(90);
    //se speed = 0 entao ele faz o mais rapido possivel
    //se foi a partir de 1 ele controla a velocidade
    p.setSpeed(5);
    tree(p, 100);
    //espera clicar no botao de fechar
    p.wait();
}

int main(){
    fractal();
    return 0;
}
