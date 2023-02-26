#include "std_lib_facilities.h"
#include "header.h"
#include "AnimationWindow.h"

//Oppgave 1
int main()
{
    int n;
    cout << "Velg funksjon:\n0) Skriv inn og print ut heltall" << endl;
    cout << "1) Skriv inn og print ut heltall" << endl;
    cout << "2) Summere to heltall" << endl;
    cout << "3) Sjekker om tall mellom 0 og 15 er odde" << endl;
    cout << "4) Gjor sekunder om til timer, minutt og sekund." << endl;
    cout << "5) Beregn summen av et bestemt antall heltall" << endl;
    cout << "6) Beregner summen av tall du skriver inn" << endl;
    cout << "7) Skriv inn og print ut desimaltall" << endl;
    cout << "8) Konverter belop fra NOK til Euro" << endl;
    cout << "9) Print ut gangetabell" << endl;
    cout << "10) Los kvadratiske ligninger" << endl;
    cout << "11) Pythagoras" << endl;
    cout << "12) Saldoberegning" << endl;
    cout << "13) Avslutt" << endl;
    cout << "Angi valg (0-13):" << endl;
    cin >> n;
    switch (n)
    {
        case 0:
        {
            inputAndPrintInteger();
            break;
        }  
        case 1: 
        {
            int number = inputInteger();
            cout << "Du skrev: " << number << endl;
            break;
        } 
        case 2:
        {
            inputIntegersAndPrintSum();
            break;
        }
        case 3:
        {
            for (int i = 0; i < 16; ++i)
            {
                cout << i << " er " << (isOdd(i)? "odde": "partall") << endl;
            }
            break;
        }
        case 4:
        {
            int number = inputInteger();
            printHumanReadableTime(number);
            break;
        }
        case 5:
        {
            int n;
            cout << "Hvor mange heltall vil du summere?: " << endl;
            cin >> n;
            int sum = sumOfMultipleInts(n);
            cout << "Summen av tallene dine er " << sum << endl;
            break;
        }
        case 6:
        {
            int sum = sumOfInfiniteInts();
            cout << "Summen din er " << sum << endl;
            break;
        }
        case 7:
        {
            double number = inputDouble();
            cout << "Du skrev: " << number << endl;
            break;
        }
        case 8:
        {
            pair<double,double> money = NOKtoEuro();
            cout << ceil(money.second*100.0)/100.0 << " er " << ceil(money.first*100.0)/100.0 << " euro." << endl;
            break;
        }
        case 9:
        {
            gangetabell();
            break;
        }         
        case 10:
        {
            solveQuadraticEquation();
            break;
        }   
        case 11:
        {
            pythagoras();
            break;
        }
        case 12:
        {
            vector<int> vec = calculateBalance(5000, 3, 10);
            printBalance(vec);
            break;
        }
        case 13:
        {
            break;
        }
        default:
        {
            break;
        }
    }
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i =0; i < v.size(); i++)
    {
        cout << v.at(i) << endl;
    }
    return 0;
}
void inputAndPrintInteger()
{
    int tall;
    cout << "Skriv inn et tall: " << endl;
    cin >> tall;
    cout << "Du skrev: " << tall << endl;
}
int inputInteger()
{
    int n;
    cout << "Skriv inn et tall: " << endl;
    cin >> n;
    return n;
}
void inputIntegersAndPrintSum()
{
    int a = inputInteger();
    int b = inputInteger();
    cout << "Summen av tallene: " << a + b << endl;
}
/*Oppgave 1e: Jeg valgte å bruke inputInteger fordi jeg trengte 
at funksjonen jeg kaller på returnerer en verdi jeg kan lagre i 
en variabel.
*/
bool isOdd(int n)
{
    return (n%2);
}
void printHumanReadableTime(int sekunder)
{
    int timer = sekunder / 3600;
    int minutter = (sekunder%3600)/60;
    int rest = sekunder - timer*3600 - minutter*60;
    cout << sekunder << " sekunder er " << timer << " timer, " << minutter << " minutter og " << rest << " sekunder." << endl;
}
//Oppgave 2
int sumOfMultipleInts(int n)
{
    int sum=0;
    for (int i = 0; i < n; ++i)
    {
        int number = inputInteger();
        sum += number;
    }
    return sum;
}
int sumOfInfiniteInts()
{
    cout << "Ved aa skrive tallet 0 vil du stoppe summeringen." << endl;
    int sum = inputInteger();
    int number = 1;
    while (number != 0)
    {
        number = inputInteger();
        sum += number;
    }
    return sum;
}
/*Oppgave 2c: I deloppgave a valgte jeg en for-løkke fordi jeg visste 
 hvor mange element som skulle summeres. I deloppgave b valgte jeg en 
 while-løkke da det var ukjent hvor mange tall brukeren skulle skrive 
 inn før hun skrev tallet 0.*/
double inputDouble()
{
    double n;
    cout << "Skriv inn et tall: " << endl;
    cin >> n;
    return double(n);
}
pair<double,double> NOKtoEuro()
{
    double valuta = 0.093;
    double nok = inputDouble();
    if (nok < 0)
    {
        cout << "Du skrev inn et negativt tall. Vennligst skriv inn et positivt tall:" << endl;
        cin >> nok;
    }
    double euro = nok * valuta;
    pair<double, double> penger {euro, nok};
    return penger; 
}
/*
Oppgave f: Man bør bruke inputDouble framfor inputInteger fordi 
inputet skal ganges med en double og vi ønsker å returnere svaret 
som en double. Jeg valgte returtype pair fordi jeg ville utfordre
meg selv og bruke både inputet fra brukeren (nok) og verdien for 
euro i en streng i case 8.
*/
void gangetabell()
{
    int felt = 4;
    int height;
    int width;
    cout << "Enter height:" << endl;
    cin >> height;
    cout << "Enter width:" << endl;
    cin >> width;

    for (int i = 1; i < height+1; ++i)
    {
        for(int j = 1; j < width+1; ++j)
        {
            cout << setw(felt) << i*j;
        }
        cout << "\n" << endl;
    }
}
//Oppgave 3:
double discriminant(double a, double b, double c)
{
    double disc = pow(b, 2) - 4*a*c;
    return disc;
}
void printRealRoots(double a, double b, double c)
{
    double disc = discriminant(a, b, c);
    if (disc < 0.0)
    {
        cout << "There are no real roots" << endl;
    }
    else if (disc == 0.)
    {
        double x_pluss = (-b)/(2*a);
        cout << "There is only one real root: " << x_pluss << endl;
    }
    else if (disc > 0.0)
    {
        double x_minus = (-b - sqrt(disc))/(2*a);
        double x_pluss = (-b + sqrt(disc))/(2*a);
        cout << "The two real roots are " << x_minus << " and " << x_pluss << endl;
    }
}
void solveQuadraticEquation()
{
    double a;
    double b;
    double c;
    cout << "Skriv inn koeffisienten til x^2:" << endl;
    cin >> a;
    cout << "Skriv inn koeffisienten til x:" << endl;
    cin >> b;
    cout << "Skriv inn konstanten:" << endl;
    cin >> c;
    printRealRoots(a, b, c);
}
//Oppgave 4
void pythagoras()
{
    int w = 1000;
    int h = 1000;
    AnimationWindow win{100,100, w, h, "Pythagoras"};
    win.draw_triangle(Point{300, 500}, Point{500, 500}, Point{300, 300}, Color::red);
    win.draw_quad(Point{500,500}, Point{700,300}, Point{500,100}, Point{300,300}, Color::orange);
    win.draw_quad(Point{300,500}, Point{500,500}, Point{500,700}, Point{300,700}, Color::yellow);
    win.draw_quad(Point{300,300}, Point{300,500}, Point{100,500}, Point{100,300}, Color::green);
    win.wait_for_close();
}
//Oppgave 5
vector<int> calculateBalance(int innskudd, int rente, int aar)
{
    vector<int> balance(aar+1);
    for (int Aar = 0; Aar < aar+1; Aar++)
    {
        double saldo = static_cast<double>(innskudd) * pow((1 + rente/100.), Aar);
        balance[Aar] = static_cast<int>(saldo);
    }
    return balance;
}
void printBalance(vector<int> vec)
{
    int antall = size(vec);
    cout << "Aar" << "\t\t" << "Saldo" << endl;
    for (int i=0; i< antall; i++)
    {
        cout << i << "\t\t" << vec[i] << endl;
    }
}

/*
Oppgave 5c: Vektoren i seg selv har ingen en visuell representasjon
og må skrives ut elementvis for at det skal gi logisk mening.
*/
/*
Oppgave 5d: For-løkken startet på 0 og avsluttet på 9 (da dette er 
størrelsen til vektoren). Det betyr at den kjører 10 ganger som vil
føre til at på den tiende loopen går den out of range på vektoren
fordi det ikke finnes et tiende element. Dette problemet fikset jeg
ved å fjerne =-tegnet der det sto 'i <= '
*/
