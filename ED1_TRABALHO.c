#include<stdio.h>   //Bibliotecas básicas
#include<stdlib.h>
 
#define MAX 50      //Definição para auxiliar na alteração caso seja necessário
 
//Definição da pilha dos vertices e seus elementos necessários
typedef struct{
    int topo; //Variável para o topo da pilha
    int vertices[MAX];//Variável para os vertices do inicio
    int vertices2[MAX];//Variável para os vertices do final
    int arestas[MAX];//Variável para o valor dos caminhos(arestas)
    int caminhos[MAX];//Caminho percorrido
    int topocaminho;//Topo para o caminho percorrido
}Pilha;

 
//Função que cria e aloca memória para a pilha, fazendo com que o topo vá para -1 para conseguir o funcionamento
//desejado ao somar
Pilha* criar(int *check){
    Pilha* p;
    p = (Pilha*) malloc(sizeof(Pilha));//Alocamento de memória para a pilha
    if(p == NULL) *check = 0;//Confirmação de que a pilha não está vazia
    else{
        p->topo=-1;//Atribuição de valor ao topo para começar a empilhar elementos
        *check = 1;//Variável que confirma o sucesso da função, que nem a DeuCerto dos exemplos da aula
    }
    return p;//Retorno da pilha p
}
 
//Função que limpa os dados da pilha, "destrói" a pilha
void destruir(Pilha *p){
    if(p != NULL) free(p);
}
 
//Função que checa se a pilha esta vazia utilizando a variável topo
int vazia(Pilha *p){
    if(p->topo == -1) return 1;
    else return 0;
}
 
//Função que checa se a pilha esta vazia utilizando da variável topo e do valor MAX
int cheia(Pilha *p){
    if(p->topo == MAX-1) return 1; //-1 devido ao topo começar em -1
    else return 0;
}
 
//Função para empilhar os elementos
int empilhar(Pilha *p, int vertices, int vertices2, int arestas){
    if (cheia(p) == 1)//Checa se a pilha está cheia, e se estiver cheia não empilha elementos
        return 0;
    else {
        p->topo = p->topo + 1;//Avanço do topo da pilha pela adição de um elemento
        p->vertices[p->topo] = vertices;//Atribuição do valor desejado à pilha
        p->vertices2[p->topo] = vertices2;
        p->arestas[p->topo] = arestas;

        return 1;
    }
}
 
//Função que desempilha os elementos
int desempilhar(Pilha *p, int *vertices, int *vertices2, int *arestas){
    if (vazia(p) == 1)//Não desempilha caso a pilha esteja vazia
        return 0;
    else {
        *vertices = p->vertices[p->topo];
        *vertices2 = p->vertices2[p->topo];
        *arestas = p->arestas[p->topo];
        p->topo = p->topo - 1;//Remove o topo atual e retrocede uma posição
        return 1;
    }
}
 
//Função que gera o grafo de acordo com o modelo da questão
int gerargrafo(Pilha *p){
    int vertices, vertices2, arestas;
    scanf("%d %d %d", &vertices, &vertices2, &arestas);
    empilhar(p,vertices,vertices2,arestas);
    //desempilhar(p,&vertices,&vertices2,&arestas);
    //printf("Voce digitou : %d %d %d\n",vertices, vertices2, arestas);

    if(vazia(p) == 1){//pilha está vazia, então houve erro ao gravar dados
        return 0;
    }
    else return 1;//Função funcionou corretamente
}

int buscagrafo(Pilha *p, int inicial, int final){
    //Fazer uma matriz, colocar elemento final e inicial(uma matriz cada), empilhar todos, criar um vetor para arestas
    //checar vetor inicial e vetor final, caso algum seja o desejado, parar de desempilhar e gravar os dados,
    //fazer isso até acabar o programa
    int vertices, vertices2, arestas;
    int verticeProcurado;
    int arestasSoma = 0;
    p->topocaminho = 0;
    while(1){
        desempilhar(p,&vertices,&vertices2,&arestas);

        if(vertices>vertices2){
            int temp;
            temp = vertices;
            vertices = vertices2;
            vertices2 = temp;
        }

        if(vertices2 == final){
            arestasSoma = arestasSoma + arestas; //Soma dos caminhos
            /**p->caminhos[p->topocaminho] = vertices2;//Criação do caminho percorrido de trás para frente
            p->topocaminho = p->topocaminho + 1;
            p->caminhos[p->topocaminho] = vertices;
            p->topocaminho = p->topocaminho + 1;**/
            verticeProcurado = vertices;
        }

        if(vertices2 == verticeProcurado){
            arestasSoma = arestasSoma + arestas; //Soma dos caminhos
            /**p->caminhos[p->topocaminho] = vertices2;//Criação do caminho percorrido de trás para frente
            p->topocaminho = p->topocaminho + 1;
            p->caminhos[p->topocaminho] = vertices;
            p->topocaminho = p->topocaminho + 1;**/
            verticeProcurado = vertices;
        }

        if(inicial == vertices){
            arestasSoma = arestasSoma + arestas; //Soma dos caminhos
            /**p->caminhos[p->topocaminho] = vertices2;//Criação do caminho percorrido de trás para frente
            p->topocaminho = p->topocaminho + 1;
            p->caminhos[p->topocaminho] = vertices;
            p->topocaminho = p->topocaminho + 1;**/
            printf("%d",arestasSoma);
            return 1;
        }

        else{printf("-1\n");return 0;}//Retorno da impossibilidade de criar um caminho
    }
}
 
//Função main
int main()
{
    Pilha *p;
    int DeuCerto;
    int c;
    int teste;
    int vertices, vertices2, arestas;
    int destinoInicial, destinoFinal;
 
    p = criar(&DeuCerto);
    if (DeuCerto == 0) {
        printf("Erro!!");
        exit(1);
    }
    printf("Digite o numero de vertices: ");
    scanf("%d", &vertices);
    printf("Digite o numero de arestas: ");
    scanf("%d", &arestas);
 
    for(int i = 0; i<arestas; i++){
    gerargrafo(p);
    }

    for(int i = 0; i<arestas; i++){
    printf("caminho %d = %d %d %d\n", i+1, p->vertices[i], p->vertices2[i], p->arestas[i]);
    }

    printf("Digite o destino inicial e final no formato ""Di DF"": ");
    scanf("%d %d", &destinoInicial, &destinoFinal);
    buscagrafo(p, destinoInicial, destinoFinal);

    if (cheia(p) == 1) printf("Pilha cheia\n");
 
    destruir(p);
 
    return 0;
}
/**a partir de um vértice inicial (origem), insira todos os vértices vizinhos em uma
pilha. Em seguida, pegue (remova) o vértice do topo da pilha e repita o processo, ou seja,
insira os vizinhos desse vértice na pilha. Esse algoritmo de busca segue até que o alvo (ou
seja, o vértice destino) seja encontrado ou até que a pilha esteja vazia.**/
 
