#include "Points.h"

Points::Points() = default;

// Euclidean Distance
Double calculate_distance(Point &a, Point &b) {
    return sqrt(
        pow((a.get_x()-b.get_x()),2) +
        pow((a.get_y()-b.get_y()), 2)
        );
}

Points::Points(int number): number_of_points(number) {
    // 1 PARTICULA
    /*for(int i = 0; i < number_of_particles; i++)
        particles.emplace_back(0,0,1,1,30,0.5);*/

    // 10 PARTICULAS
    /* particles = {{0,0,1,1,30,0.5},
                 {800,600,1,1,30,0.5},
                 {100,0,1,1,30,0.5},
                 {300,600,1,1,30,0.5},
                 {0,400,1,1,30,0.5},
                 {0,600,1,1,30,0.5},
                 {200,100,1,1,30,0.5},
                 {200,400,1,1,30,0.5},
                 {500,500,1,1,30,0.5},
                 {500,100,1,1,30,0.5}};*/

    /// GENERADORA DE PARTICULAS
    // random_device rd;
    // mt19937 generator(rd());
    // uniform_real_distribution<double> distribution(-3,3);

    // int column = 0, row = 25;
    /*
    for(int i = 0; i < number_of_particles; i++) {
        //if (i% row == 0)
        //    column += 20;
        //particles.emplace_back(i%row * 1000/row, column, distribution(generator),distribution(generator),2, 1);
        uniform_real_distribution<double> distribution1(0,500);
        uniform_real_distribution<double> distribution2(0,900);
        particles.emplace_back(distribution1(generator), distribution2(generator), distribution(generator),distribution(generator),2, 1);
    }
    */
}

void Points::add(Point p) {
    points.push_back(p);
}

//DIBUJO DE CADA PARTICULA
void Points::draw(sf::RenderWindow* window) {
    for (auto &p : points){
        sf::CircleShape shape(2);
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(p.get_x(), p.get_y());
        window->draw(shape);
    }
}

vector<Point> Points::get_points() {
    return points;
}
