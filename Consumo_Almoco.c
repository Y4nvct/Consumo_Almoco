#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

int main()
{
  // Configuração para exibir acentos corretamente
  setlocale(LC_ALL, "Portuguese");
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);

  // ===== Declaracao de variaveis =====
  int AlmocoServidos[7]; // Vetor para armazenar almoços por dia
  const char DiasSemana[7][15] = {
      "Segunda-feira", "Terca-feira", "Quarta-feira",
      "Quinta-feira", "Sexta-feira", "Sabado", "Domingo"};

  int TotalAlmoco = 0;     // Total de almoços da semana
  int MediaAlmoco = 0;     // Media de almoços por dia
  int MaiorConsumo = 0;    // Maior consumo de almoços
  int MenorConsumo = 0;    // Menor consumo de almoços
  int DiaMaiorConsumo = 0; // Dia com maior consumo de almoços
  int DiaMenorConsumo = 0; // Dia com menor consumo de almoços
  int i;

  // APRESENTAÇÃO DO SISTEMA DE CONSUMO DE ALMOÇO
  printf("==========================================================\n");
  printf("============== SISTEMA DE CONSUMO DE ALMOCO ==============\n");
  printf("==========================================================\n");
  printf("Sistema Inteligente de Controle de Consumo de Almoco\n");
  printf("Analise completa do Consumo da Semana\n");
  printf("==========================================================\n");

  // ========== ENTRADA DE DADOS ==========
  for (i = 0; i < 7; i++)
  {
    printf("Digite a quantidade de almocos servidos na %s: ", DiasSemana[i]);
    scanf("%d", &AlmocoServidos[i]);

    // ESTRUTURA DE DECISÃO: Validação de Entrada de Dados
    if (AlmocoServidos[i] < 0)
    {
      printf("ERRO: Valor invalido! Digite um numero positivo.\n");
      i--;      // Volta uma posição para repetir a entrada
      continue; // Volta para o inicio do loop
    }

    // ACUMULA TOTAL DE ALMOÇOS PARA CÁLCULO DA MÉDIA
    TotalAlmoco += AlmocoServidos[i];
  }

  printf("Dados registrados com sucesso!\n");

  // ========== PROCESSAMENTO DE DADOS ==========
  printf("Processando Dados...\n\n");

  // CALCULO DA MÉDIA DE ALMOÇOS SEMANAL
  MediaAlmoco = TotalAlmoco / 7;

  // USAR LAÇOS FOR PARA VERIFICAR MAIOR E MENOR CONSUMO

  MaiorConsumo = AlmocoServidos[0];
  MenorConsumo = AlmocoServidos[0];
  DiaMaiorConsumo = 0;
  DiaMenorConsumo = 0;

  // Inicializar com o primeiro valor para comparação correta
  for (i = 1; i < 7; i++)
  {
    // ESTRUTURA DE DECISÃO: encontrar maior consumo
    if (AlmocoServidos[i] > MaiorConsumo)
    {
      MaiorConsumo = AlmocoServidos[i];
      DiaMaiorConsumo = i;
    }

    // ESTRUTURA DE DECISÃO: encontrar menor consumo
    if (AlmocoServidos[i] < MenorConsumo)
    {
      MenorConsumo = AlmocoServidos[i];
      DiaMenorConsumo = i;
    }
  }

  // ========== RELATÓRIO PRINCIPAL ==========
  printf("==========================================================\n");
  printf("============== RELATORIO PRINCIPAL DE CONSUMO ==============\n");
  printf("==========================================================\n");

  // EXIBIR DADOS DO DIA A DIA
  printf("CONSUMO DE ALMOCO POR DIA:\n");
  printf("==========================================================\n");

  // USAR LAÇOS FOR PARA FORMATAR A EXIBIÇÃO!
  for (i = 0; i < 7; i++)
  {
    printf("%-15s | %3d Almocos", DiasSemana[i], AlmocoServidos[i]);

    // ESTRUTURA DE DECISÃO: para destacar dia de pico!
    if (i == DiaMaiorConsumo)
    {
      printf(" - Dia de Pico!");
    }

    // ESTRUTURA DE DECISÃO: para destacar o dia de menor consumo!
    if (i == DiaMenorConsumo)
    {
      printf(" - Menor Consumo!");
    }

    printf("\n");
  }

  printf("==================================================================\n\n");

  // ===== ESTATÍSTICAS (INFO. BÔNUS) =====
  printf("ESTATISTICAS DA SEMANA:\n");
  printf("===============================================\n");
  printf("Total de almocos: %d\n", TotalAlmoco);
  printf("Media diaria: %.1f almocos\n", (float)MediaAlmoco);
  printf("Maior consumo: %d (%s)\n", MaiorConsumo, DiasSemana[DiaMaiorConsumo]);
  printf("Menor consumo: %d (%s)\n", MenorConsumo, DiasSemana[DiaMenorConsumo]);
  printf("Variacao: %d almocos\n", MaiorConsumo - MenorConsumo);
  printf("===============================================\n\n");

  // ====== GRAFICO DO CONSUMO SEMANAL ======

  printf("GRAFICO DE CONSUMO SEMANAL:\n");
  printf("===============================================\n");

  // Calcular escala dinâmica baseada no maior valor
  int escala = MaiorConsumo / 15; // Dividir por 15 para ter barras menores
  if (escala < 1)
    escala = 1; // Escala mínima de 1

  printf("Escala: cada # representa %d almoços\n", escala);
  printf("===============================================\n");

  // LAÇO FOR: Para criar gráfico ASCII melhorado
  for (i = 0; i < 7; i++)
  {
    printf("%-12s | ", DiasSemana[i]);

    // Calcular número de barras proporcionalmente
    int barras = AlmocoServidos[i] / escala;
    if (barras == 0 && AlmocoServidos[i] > 0)
      barras = 1; // Mínimo 1 barra para valores > 0

    // Desenhar barras com caracteres ASCII simples
    for (int j = 0; j < barras; j++)
    {
      printf("#"); // Usar # em vez de caracteres especiais
    }

    // Adicionar espaços para alinhar os números
    int espacos = 20 - barras;
    for (int k = 0; k < espacos; k++)
    {
      printf(" ");
    }

    printf("| %3d almoços", AlmocoServidos[i]);

    // Destacar dias especiais com texto simples
    if (i == DiaMaiorConsumo)
      printf(" [PICO!]");
    else if (i == DiaMenorConsumo)
      printf(" [MENOR]");

    printf("\n");
  }

  printf("===============================================\n");
  printf("Legenda: # = %d almocos | [PICO!] = Maior consumo | [MENOR] = Menor consumo\n", escala);
  printf("\n\n");

  // ========== ANÁLISE DE TENDÊNCIAS (BÔNUS EXTRA) ==========
  printf("ANALISE DE TENDENCIAS:\n");
  printf("===============================================\n");

  // Compara dias úteis vs fim de semana
  int AlmocosUteis = 0, AlmocosFimSemana = 0;

  // LAÇO FOR para somar dias úteis (seg-sex)
  for (i = 0; i < 5; i++)
  {
    AlmocosUteis += AlmocoServidos[i];
  }

  // LAÇO FOR para somar fim de semana (sáb-dom)
  for (i = 5; i < 7; i++)
  {
    AlmocosFimSemana += AlmocoServidos[i];
  }

  float MediaUteis = (float)AlmocosUteis / 5;
  float MediaFimSemana = (float)AlmocosFimSemana / 2;

  printf("Media dias uteis: %.1f almocos\n", MediaUteis);
  printf("Media fim de semana: %.1f almocos\n", MediaFimSemana);

  // ESTRUTURA DE DECISÃO: Análise comparativa
  if (MediaUteis > MediaFimSemana)
  {
    printf("Tendencia: Maior consumo em dias uteis\n");
  }
  else if (MediaFimSemana > MediaUteis)
  {
    printf("Tendencia: Maior consumo no fim de semana\n");
  }
  else
  {
    printf("Tendencia: Consumo equilibrado\n");
  }

  printf("===============================================\n");
  printf("\n\n");

  // ========== RECOMENDAÇÕES (BÔNUS EXTRA) ==========
  printf("RECOMENDACOES:\n");
  printf("===============================================\n");

  // ESTRUTURAS DE DECISÃO para recomendações inteligentes
  if (MediaAlmoco < 50)
  {
    printf("Consumo baixo - Considere estrategias de marketing\n");
  }
  else if (MediaAlmoco > 150)
  {
    printf("Alto consumo - Verifique capacidade de producao\n");
  }
  else
  {
    printf("Consumo dentro da normalidade\n");
  }

  if (MaiorConsumo - MenorConsumo > 100)
  {
    printf("Alta variacao - Planeje melhor os recursos\n");
  }

  printf("Foque no %s para maximizar vendas\n", DiasSemana[DiaMaiorConsumo]);
  printf("===============================================\n");
  printf("\n\n");

  // ========== ENCERRAMENTO ==========
  printf("===============================================\n");
  printf("        RELATORIO CONCLUIDO           \n");
  printf("===============================================\n");
  printf("Obrigado por usar o Almocometo Pro!\n");
  printf("Dados analisados com sucesso!\n");
  printf("===============================================\n");

  return 0;
}
