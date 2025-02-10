#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define PWM_GPIO 22       // Pino de saída PWM
#define PWM_FREQ 50       // Frequência desejada (50Hz)
#define SYSTEM_CLOCK 125000000 // Clock base do Raspberry Pi Pico
#define TOP_VALUE 65535   // Resolução de 16 bits
#define STEP_US 5         // Incremento de ciclo ativo
#define DELAY_MS 10       // Atraso entre incrementos para suavizar o movimento
#define PULSE_MIN 500     // Pulso para 0 graus
#define PULSE_MID 1470    // Pulso para 90 graus
#define PULSE_MAX 2400    // Pulso para 180 graus

void setup_pwm(uint16_t pulse_width_us) {
    gpio_set_function(PWM_GPIO, GPIO_FUNC_PWM); // Configura GPIO como saída PWM

    uint slice_num = pwm_gpio_to_slice_num(PWM_GPIO); // Obtém o slice do PWM

    float divisor = (float) SYSTEM_CLOCK / (PWM_FREQ * TOP_VALUE); // Calcula o divisor

    pwm_set_clkdiv(slice_num, divisor); // Define o divisor de clock
    pwm_set_wrap(slice_num, TOP_VALUE); // Define o valor máximo do contador
    pwm_set_chan_level(slice_num, PWM_CHAN_A, (TOP_VALUE * pulse_width_us) / 20000); // Define ciclo ativo

    pwm_set_enabled(slice_num, true); // Habilita o PWM
}

void move_servo_smoothly(uint16_t start, uint16_t end) {
    if (start < end) {
        for (uint16_t pulse = start; pulse <= end; pulse += STEP_US) {
            setup_pwm(pulse);
            sleep_ms(DELAY_MS);
        }
    } else {
        for (uint16_t pulse = start; pulse >= end; pulse -= STEP_US) {
            setup_pwm(pulse);
            sleep_ms(DELAY_MS);
        }
    }
}

int main() {
    stdio_init_all();
    
    setup_pwm(PULSE_MAX); // Define posição inicial em 180 graus
    sleep_ms(5000); // Aguarda 5 segundos
    
    setup_pwm(PULSE_MID); // Define posição intermediária em 90 graus
    sleep_ms(5000); // Aguarda 5 segundos
    
    setup_pwm(PULSE_MIN); // Define posição final em 0 graus
    sleep_ms(5000); // Aguarda 5 segundos
    
    while (1) {
        move_servo_smoothly(PULSE_MIN, PULSE_MAX); // Move suavemente de 0 para 180 graus
        sleep_ms(1000);
        move_servo_smoothly(PULSE_MAX, PULSE_MIN); // Move suavemente de 180 para 0 graus
        sleep_ms(1000);
    }
}
