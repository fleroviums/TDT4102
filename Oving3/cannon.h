double acclY();
double velY(double initVelocityY, double time);

double posX(double initPosition, double initVelocity, double time);
double posY(double initPosition, double initVelocity, double time);

void printTime(double time);

double flightTime(double initVelocityY);


// Ber brukeren om en vinkel
double getUserInputTheta();
//Ber brukeren om en absoluttfart
double getUserInputAbsVelocity();
// Konverterer fra grader til radianer
double degToRad(double deg);
// Returnerer henholdsvis farten i x-, og y-retning, gitt en vinkel
// theta og en absoluttfart absVelocity.
double getVelocityX(double theta, double absVelocity);
double getVelocityY(double theta, double absVelocity);
// Dekomponerer farten gitt av absVelocity, i x- og y-komponentene
// gitt vinkelen theta. Det første elementet i vectoren skal være
//x-komponenten, og det andre elementet skal være y-komponenten.
// "Vector" i funksjonsnavnet er vektor-begrepet i geometri
vector<double> getVelocityVector(double theta, double absVelocity);