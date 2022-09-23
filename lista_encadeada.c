#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	float				n;
	struct s_node	*proximo;
}t_node;

typedef struct s_inicio
{
	struct s_node	*primeiro;
	int				tamanho;
}t_inicio;

void	inicializar(t_inicio *lista)
{
	lista->tamanho = 0;
	lista->primeiro = NULL;
}

int	tamanho(t_inicio *lista)
{
	printf("\nTamanho: %d", lista->tamanho);
	return lista->tamanho;
}

void	imprimir(t_inicio *lista)
{
	t_node	*aux;

	aux = lista->primeiro;
	printf("\nLista: ");
	while(aux)
	{
		printf("%.2f ", aux->n);
		aux = aux->proximo;
	}
}

void	inserir_ordenado(t_inicio *lista, float num)
{
	t_node	*novo;
	t_node	*aux;

	novo = (t_node *)malloc(sizeof(t_node));
	aux = (t_node *)malloc(sizeof(t_node));
	if (novo)
	{
		novo->n = num;
		if (lista->primeiro ==  NULL)
		{
			novo->proximo = NULL;
			lista->primeiro = novo;
		}
		else if (novo->n < lista->primeiro->n)
		{
			novo->proximo = lista->primeiro;
			lista->primeiro = novo;
		}
		else
		{
			aux = lista->primeiro;
			while (aux->proximo && novo->n > aux->proximo->n)
				aux = aux->proximo;
			novo->proximo = aux->proximo;
			aux->proximo = novo;
		}
		lista->tamanho += 1;
	}
	else
		printf("Erro durante alocacao");
}

void	reinicializar(t_inicio *lista)
{
	int		i;
	t_node	*aux;

	i = 0;
	aux = lista->primeiro;
	while (i < lista->tamanho)
	{
		aux = lista->primeiro->proximo;
		free(lista->primeiro);
		lista->primeiro = aux;
		i++;
	}
	free(lista->primeiro);
	lista->tamanho = 0;
}

void	finalizar(t_inicio *lista)
{
	int		i;
	t_node	*aux;

	i = 0;
	aux = lista->primeiro;
	while (i < lista->tamanho)
	{
		aux = lista->primeiro->proximo;
		free(lista->primeiro);
		lista->primeiro = aux;
		i++;
	}
	free(lista->primeiro);
	exit(0);

}

int	main(void)
{
	t_inicio	*lista;
	int			opcao;
	float		valor;

	lista = (t_inicio *)malloc(sizeof(t_inicio));
	inicializar(lista);
	while(42)
	{
		printf("\n\t0 - Sair\n\t1 - Inserir Ordenado\n\t2 - Imprimir\n\t3 - Tamanho\n\t4 - Restart\n");
		scanf("%d", &opcao);
		if (opcao >= 0)
		{
			if (opcao == 1)
			{
				printf("Digite um valor: ");
				scanf("%f", &valor);
				inserir_ordenado(lista, valor);
			}
			else if (opcao == 2)
				imprimir(lista);
			else if (opcao == 3)
				tamanho(lista);
			else if (opcao == 4)
				reinicializar(lista);
			else if (opcao == 0)
				finalizar(lista);
		}
		else
			printf("Opcao Invalida");
	}

	return (0);
}