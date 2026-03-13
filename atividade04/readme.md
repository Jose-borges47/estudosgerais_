 1. Diferenças de visibilidade/tempo de vida: - Variáveis globais permanecem disponíveis durante
 toda a execução do programa, acessíveis de qualquer função/método. - Variáveis locais só
 existem dentro da função onde foram declaradas, sendo criadas quando a função é chamada e
 destruídas ao final. - Parâmetros funcionam como variáveis locais inicializadas no momento da
 chamada. 
 2. Problemas potenciais do uso de globais em sistemas reais: - Dificultam manutenção e
 depuração. - Aumentam risco de modificações indesejadas. - Podem gerar falhas de segurança se
 informações sensíveis (como senha) ficarem expostas globalmente. 
 3. Solução preferida em
 produção: - As versões com variáveis locais/parâmetros, pois são mais seguras, encapsuladas e
 facilitam manutenção e testes.