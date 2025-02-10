#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define PWM_GPIO 22       // Pino de saída PWM
#define PWM_FREQ 50       // Frequência desejada (50Hz)
#define SYSTEM_CLOCK 125000000 // Clock base do Raspberry Pi Pico
#define TOP_VALUE 65535   // Resolução de 16 bits

void setup_pwm() {
    gpio_set_function(PWM_GPIO, GPIO_FUNC_PWM); // Configura GPIO como saída PWM

    uint slice_num = pwm_gpio_to_slice_num(PWM_GPIO); // Obtém o slice do PWM

    float divisor = (float) SYSTEM_CLOCK / (PWM_FREQ * TOP_VALUE); // Calcula o divisor

    pwm_set_clkdiv(slice_num, divisor); // Define o divisor de clock
    pwm_set_wrap(slice_num, TOP_VALUE); // Define o valor máximo do contador
    pwm_set_chan_level(slice_num, PWM_CHAN_A, (TOP_VALUE * 2400) / 20000); // Define ciclo ativo de 2.400µs (0,12%)

    pwm_set_enabled(slice_num, true); // Habilita o PWM
}

int main() {
    stdio_init_all();
    setup_pwm();

    sleep_ms(5000); // Aguarda 5 segundos na posição de 180 graus
    
    while (1) {
        sleep_ms(1000); // Mantém o loop
    }
}
