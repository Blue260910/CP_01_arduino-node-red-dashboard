# FIAP - ENGENHARIA DE SOFTWARE - 3ESPW
## CP1 - Physical Computing IoT and IoB - 14/03/2025

### Grupo

André Lambert - RM 99148

Felipe Cortez - RM99750

Julia Lins - RM98690

Luís Barreto - RM99210

Victor Aranda - RM99667

# CP_01_arduino-node-red-dashboard
Um projeto que integra o Arduino com Node-RED para controlar e monitorar sensores via Dashboard.

# Arduino + Node-RED Dashboard

Este é um projeto que integra um **Arduino** com **Node-RED**, controlando e monitorando sensores via uma interface gráfica de **Dashboard**. O projeto permite a leitura de sensores de temperatura, umidade, e luminosidade, com controle de um servo motor via Node-RED.


![image](https://github.com/user-attachments/assets/7ea4784c-fc16-4eed-8adc-0e81c3231e07)
![image](https://github.com/user-attachments/assets/6c7277fa-4981-425d-9ceb-89a66668ba7d)


## Componentes Utilizados

- **Arduino**:
  - Sensor TMP (para temperatura).
  - Sensor LDR (para luminosidade).
  - Potenciômetro (para controle manual do servo motor).
  - Servo Motor.
  ![Componentes - Arduino](https://github.com/user-attachments/assets/b3e0a301-d34f-45e1-9a6d-60eed0078d59)
  ![image](https://github.com/user-attachments/assets/6f53099c-3e03-4062-b6be-080a92f2d0f1)

  
- **Node-RED**:
  - Dashboard para exibir valores de sensores.
  - Controle de servo motor via botões na interface gráfica.

## Estrutura do Projeto

- **arduino/**: Contém o código do Arduino (`codigo_arduino.ino`).
- **node-red/**: Contém o fluxo do Node-RED (`fluxo_node_red.json`).
- **README.md**: Este arquivo com as instruções.

## Como Utilizar

### 1. Preparação do Arduino

1. Conecte os sensores TMP, LDR e o potenciômetro ao seu Arduino.
2. Conecte o servo motor ao pino digital de controle.
3. Carregue o código `codigo_arduino.ino` no seu Arduino utilizando a IDE do Arduino.

### 2. Preparação do Node-RED

1. Instale o Node-RED e configure os nós de Dashboard.
2. Importe o fluxo do Node-RED a partir de `fluxo_node_red.json`.
3. Inicie o Node-RED e abra o Dashboard no navegador.
4. Os dados de sensores serão exibidos no Dashboard e você poderá controlar o servo motor através dos botões.

### 3. Testando o Sistema

- Acesse o Dashboard do Node-RED em `http://localhost:1880/ui`.
- Veja os valores dos sensores em tempo real.
- Use os botões para controlar o servo motor em diferentes ângulos.

## Licença

Este projeto é licenciado sob a [MIT License](LICENSE).
