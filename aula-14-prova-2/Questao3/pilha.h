typedef struct _caixa {
	int identificador;
	char destino[50];
	float peso;
} caixa;

void push(caixa c);
caixa pop();
void imprimir();
int verificarCheia();
int verificarVazia();
void inicializar();
void imprimirCaixa(caixa c);
caixa lerCaixa();
