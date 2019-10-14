Meu Projeto  final da disciplina de SE, consiste no aprimoramento o bebedeouro dos pets criados na tarefa 3.
Esta empreitada terá como carater principal a automação da realimentação de água por meio de sensores de nível e válvulas solenoides para acionamento da bomba de água via WIFI.

Funcionamento:
O reservatorio é utilizado por dois gatos, e é acionado por proximidade dos animais, que quando próximos ao sensor ultrasonico, o sistema aciona a bomba de água liberando a água para os gatos e acionando o sinalizador acústico. O projeto conta com um sitema de temperatura da agua através de um sensor analógico LM35 que exibe sua leitura de temperatura em um display OLED.
A realimentação do reservatório se dará por comunicação sem fio via 802.11 onde um arduino uno e um esp 8266 estará na torneira e  será comandado pelo ardunio mestre que esta junto ao reservatório quando o sensor de nível detectar nível baixo dentro do reservatótio.

Motivação:
O re-abastecimento d bebedeouro é feito manualmente a cada três dias. 
No caso do não re-abastecimento do reservatório a bomba de água trabalha a seco o que pode ocasionar a queima da mesma.

Componentes empregados:
2 Arduinos Uno
2 Modulos esp8266
1 Valvula Solenoide de 12 Volts
1 sinalizador acústico
1 sensor de nivel de água
1 bomba de agua de 110v
1 sensor ultaronico 
1 circuito chaveador de 127Volts AC construido via mosfet.
1 sinalisador acustico
1 sensor de fluxo de 
1 Transistor BC 557
1 sensor  de temperatura LM35
1 display Oled

Paralelamente surigiu a necessidade do controle do fluxo e controle do nivel de agua de um Tanquinho ao qual o preenchimento do reservatorio é de forma manual.

Funcionamento:
O tanquinho será abastecido automaticamente e acionado pelo app Blink e será comandado via Web através do ESP8266, conecatdo á um arduíno Nano.

Motivação:
O abastecimento do tanquinho é feito manualmente pela empregada, que as vezes esquece o mesmo ligado e causando muito desperdício de água. O fato é que o abastecimento do tanquinho é feito p

Componentes empregados:
1 Arduino  Nano
1 Modulos esp8266
1 Valvula Solenoide de 12 Volts
1 Dsplay Oled
1 sinalisador acustico
1 Dsiplay 16x2
1 regulador  AN7805
