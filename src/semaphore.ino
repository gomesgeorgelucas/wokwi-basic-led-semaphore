#define TEMPO_VERDE 3000    // ms
#define TEMPO_AMARELO 1000  // ms
#define TEMPO_VERMELHO 3000 // ms

#define LED_VEICULO_VERDE 25
#define LED_VEICULO_AMARELO 33
#define LED_VEICULO_VERMELHO 32

#define LED_PEDESTRE_VERDE 27
#define LED_PEDESTRE_VERMELHO 26

const int LED_VEICULO_VERDE_ON = 1;
const int LED_VEICULO_VERDE_OFF = 2;
const int LED_VEICULO_AMARELO_ON = 3;
const int LED_VEICULO_AMARELO_OFF = 4;
const int LED_VEICULO_VERMELHO_ON = 5;
const int LED_VEICULO_VERMELHO_OFF = 6;

int state = LED_VEICULO_VERDE_ON;

void setup()
{
    pinMode(LED_VEICULO_VERDE, OUTPUT);
    pinMode(LED_VEICULO_AMARELO, OUTPUT);
    pinMode(LED_VEICULO_VERMELHO, OUTPUT);
    pinMode(LED_PEDESTRE_VERDE, OUTPUT);
    pinMode(LED_PEDESTRE_VERMELHO, OUTPUT);

    digitalWrite(LED_VEICULO_VERDE, LOW);
    digitalWrite(LED_VEICULO_AMARELO, LOW);
    digitalWrite(LED_VEICULO_VERMELHO, LOW);
    digitalWrite(LED_PEDESTRE_VERMELHO, LOW);
    digitalWrite(LED_PEDESTRE_VERDE, LOW);

    Serial.begin(9600);
    Serial.println("Semaphore init");
}

void loop()
{
    switch (state)
    {
    case LED_VEICULO_VERDE_ON:
        digitalWrite(LED_VEICULO_VERDE, HIGH);
        digitalWrite(LED_PEDESTRE_VERMELHO, HIGH);
        delay(TEMPO_VERDE);
        state = LED_VEICULO_VERDE_OFF;
        break;

    case LED_VEICULO_VERDE_OFF:
        digitalWrite(LED_VEICULO_VERDE, LOW);
        state = LED_VEICULO_AMARELO_ON;
        break;

    case LED_VEICULO_AMARELO_ON:
        digitalWrite(LED_VEICULO_AMARELO, HIGH);
        delay(TEMPO_AMARELO);
        state = LED_VEICULO_AMARELO_OFF;
        break;

    case LED_VEICULO_AMARELO_OFF:
        digitalWrite(LED_VEICULO_AMARELO, LOW);
        digitalWrite(LED_PEDESTRE_VERMELHO, LOW);
        state = LED_VEICULO_VERMELHO_ON;
        break;

    case LED_VEICULO_VERMELHO_ON:
        digitalWrite(LED_VEICULO_VERMELHO, HIGH);
        digitalWrite(LED_PEDESTRE_VERDE, HIGH);
        delay(TEMPO_VERMELHO);
        state = LED_VEICULO_VERMELHO_OFF;
        break;

    case LED_VEICULO_VERMELHO_OFF:
        digitalWrite(LED_VEICULO_VERMELHO, LOW);
        digitalWrite(LED_PEDESTRE_VERDE, LOW);
        state = LED_VEICULO_VERDE_ON;
        break;

    default:
        break;
    } // switch
} // loop
