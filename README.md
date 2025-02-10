# Controle de Servo Motor com PWM no Raspberry Pi Pico

## Descrição

Este projeto controla um servomotor utilizando a GPIO 22 do Raspberry Pi Pico com sinal PWM de 50Hz. O servo motor se move suavemente entre os ângulos de 0 e 180 graus. Além disso, um LED RGB conectado 
à GPIO 12 pisca durante o movimento.

## Requisitos

- Raspberry Pi Pico
- Servomotor compatível com PWM 
- LED RGB
- Resistor de 330Ω para o LED
- Jumpers para conexão

## Conexão

| Componente              | GPIO do Pico |
| ----------------------- | ------------ |
| Servomotor (Sinal)      | GPIO 22      |
| LED RGB (Anodo comum)   | GPIO 12      |
| Alimentação (VCC e GND) | 5V/GND       |

## Instalação

1. Clone este repositório no seu computador:
   ```sh
   git clone https://github.com/seu-usuario/seu-repositorio.git
   ```
2. Compile o código utilizando o SDK do Raspberry Pi Pico.
3. Transfira o arquivo binário para a placa bitdog lab via USB.

## Uso

1. O servo inicia em 180°, depois se move para 90° e 0°, aguardando 5 segundos em cada posição.
2. A rotina principal movimenta o servo entre 0° e 180° de forma suave, alternando o LED RGB durante o movimento.

## Ambiente de Desenvolvimento

- Deve-se utilizar o ambiente de desenvolvimento VS Code em todas as atividades.
- Os códigos devem ser escritos na linguagem C, juntamente com os recursos do Kit de Desenvolvimento de Software Pico SDK.
- O simulador Wokwi deve estar integrado ao ambiente de desenvolvimento VS Code.

## Vídeo Demonstrativo

Para visualizar a execução do projeto, assista ao vídeo disponível no link abaixo:
[Vídeo Demonstrativo](INSIRA_O_LINK_AQUI)

## Licença

Este projeto está sob a licença MIT. Sinta-se livre para modificá-lo e compartilhá-lo.

