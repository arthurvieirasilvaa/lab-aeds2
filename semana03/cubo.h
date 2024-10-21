struct Cubo {
    double lado;
};

// Recebe o valor do lado como parâmeto e retorna um Cubo com a sua variável já inicializada:
Cubo* inicializa_cubo(double);

double retorna_lados(Cubo); // recebe um Cubo como parâmetro e retorna o valor dos seus lados.

double calcular_area(Cubo); // recebe um Cubo como parâmetro e retorna o valor da sua área.

double calcular_volume(Cubo); // recebe um Cubo como parâmetro e retorna o valor do seu volume.