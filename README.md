📟 Projeto RTC com Controle de LED – Arduino + DS1302
📌 Descrição

Este projeto educacional tem como objetivo demonstrar a integração entre um módulo de relógio em tempo real (RTC DS1302) e um microcontrolador Arduino, permitindo o controle de um LED com registro de data e hora.

A aplicação combina conceitos de sistemas embarcados, leitura de sensores, controle de atuadores e comunicação serial, sendo ideal para alunos em fase inicial/intermediária no aprendizado de programação e eletrônica.

🎯 Objetivo Educacional
Compreender o funcionamento de um RTC (Relógio em Tempo Real)
Trabalhar com manipulação de data e hora
Implementar leitura de entradas digitais (botão)
Controlar saídas digitais (LED)
Utilizar comunicação serial para interação com o sistema
Aplicar lógica de programação em sistemas embarcados
⚙️ Funcionalidades
⏰ Leitura de data e hora em tempo real
💡 Controle de LED via botão físico
🔁 Alternância de estado do LED (liga/desliga)
🖥️ Controle do LED via comandos no monitor serial
🕒 Registro de eventos com data e hora
🔧 Atualização manual da data e hora via serial
🛠️ Tecnologias e Componentes
Arduino (Uno, Nano, etc.)
Módulo RTC DS1302
LED
Botão (push button)
Resistores
Linguagem C++ (Arduino IDE)
🔌 Ligações (Hardware)
Componente	Pino Arduino
RTC CLK	5
RTC DAT	6
RTC RST	7
LED	2
Botão	4
💻 Como Funciona

O sistema realiza a leitura contínua da data e hora através do módulo RTC.

🔘 Botão físico
Ao pressionar o botão:
O LED alterna entre ligado/desligado
Uma mensagem é exibida no monitor serial com data e hora do evento
⌨️ Comandos via Serial

O usuário pode interagir com o sistema pelo monitor serial:

Comando	Função
ligar	Liga o LED
desligar	Desliga o LED
atualiza AAAA MM DD HH MM SS	Atualiza data e hora

📌 Exemplo:

atualiza 2025 12 02 16 30 00
🔄 Atualização Inicial do RTC

No código existe um bloco para configuração inicial da data/hora:

rtc.setDateTime(&dt);

⚠️ Importante:

Execute apenas uma vez para configurar o relógio
Depois, comente essa parte para evitar sobrescrever a hora a cada reset
📊 Exemplo de Saída no Serial
Led Ligado! 02/12/2025 16:30:10
Led Desligado! 02/12/2025 16:30:15
Hora atualizada! 02/12/2025 16:31:00
📚 Aplicações
Projetos de automação
Sistemas de registro de eventos (log)
Controle de dispositivos baseado em tempo
Ensino de IoT e sistemas embarcados
🎓 Contexto Educacional

Este projeto foi desenvolvido como uma atividade prática para alunos de cursos técnicos (como Desenvolvimento de Sistemas e áreas correlatas), com foco no aprendizado aplicado de eletrônica e programação.

A proposta é estimular o raciocínio lógico, a integração entre hardware e software e a resolução de problemas reais.

🚀 Possíveis Melhorias
Integração com display LCD/OLED
Controle automático baseado em horários
Registro em cartão SD
Integração com IoT (Wi-Fi / ESP32)
