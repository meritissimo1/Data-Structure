#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	float				n;
	struct s_node	*proximo;
}t_node;

typedef struct s_lista
{
	struct s_node	*primeiro;
	int				tamanho;
}t_lista;

void	inicializar(t_lista *lista)
{
	lista->tamanho = 0;
	lista->primeiro = NULL;
}

int	tamanho(t_lista *lista)
{
	if (lista)
	{
		printf("\nTamanho: %d", lista->tamanho);
		return lista->tamanho;
	}
	return (0);	
}

void	imprimir(t_lista *lista)
{
	t_node	*aux;

	if (lista->tamanho >= 0)
	{
		aux = lista->primeiro;
		printf("\nLista: ");
		while(aux)
		{
			printf("%.2f ", aux->n);
			aux = aux->proximo;
		}
	}	
}

void	inserir_ordenado(t_lista *lista, float num)
{
	t_node	*novo;
	t_node	*aux;

	novo = (t_node *)malloc(sizeof(t_node));
	if (novo)
	{
		novo->n = num;
		if (lista->primeiro == NULL)
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

void	reinicializar(t_lista *lista)
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

void	finalizar(t_lista *lista)
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
	free(lista);
	exit(0);
}

void	remove_elemento_x(t_lista *lista, float num)
{
	t_node	*aux;
	t_node	*remover;

	remover = NULL;
	if (lista->primeiro)
	{
		if(lista->primeiro->n == num)
		{
			aux = lista->primeiro;
			aux = aux->proximo;
			free(lista->primeiro);
			lista->primeiro = aux;
			lista->tamanho -= 1;
		}
		else
		{
			aux = lista->primeiro;
			while ( aux->proximo && aux->proximo->n != num)
				aux = aux->proximo;
			if (aux->proximo)
			{
				remover = aux->proximo;	
				aux->proximo = remover->proximo;
				lista->tamanho -= 1;
				free(remover);
			}		
		}
	}
}

void	remove_posicao_p(t_lista *lista, int posicao)
{
	int		i;
	t_node	*aux;
	t_node	*remover;	

	i = 2;
	remover = NULL;
	if (lista->primeiro || (posicao < lista->tamanho && posicao > 0))
	{
		if (posicao == 1)
		{
			aux = lista->primeiro;
			aux = aux->proximo;
			free(lista->primeiro);
			lista->primeiro = aux;
			lista->tamanho -= 1;
		}
		else
		{
			aux = lista->primeiro;
			while (aux->proximo && i < posicao)
			{
				i++;
				aux = aux->proximo;
			}				
			if (aux->proximo)
			{
				remover = aux->proximo;	
				aux->proximo = remover->proximo;
				lista->tamanho -= 1;
				free(remover);
			}
		}	
	}
}

int	busca_elemento_x(t_lista *lista, float num)
{
	t_node	*aux;

	if (lista->primeiro)
	{
		aux = lista->primeiro;
		while (aux && aux->n != num)
			aux = aux->proximo;
		if (aux)
			return (1);
		else
			return (0);
	}
	else
		return 0;
}

float	busca_posicao_p(t_lista *lista, int posicao)
{
	int		i;
	t_node	*aux;

	i = 1;
	if (lista->primeiro || (posicao < lista->tamanho && posicao > 0))
	{
		aux = lista->primeiro;
		while (aux && i < posicao)
		{
			aux = aux->proximo;
			i++;
		}			
		if (aux)
		{
			printf("\n%.2f\n", aux->n);
			return (aux->n);	
		}			
		else
			return (0);		
	}
	else
		return (0);	
}

int	main(void)
{
	t_lista		*lista;
	int			opcao;
	float		valor;

	printf("\n\t1 - Start\n\t2 - Sair\n");
	scanf("%d", &opcao);
	if (opcao ==  1)
	{
		lista = (t_lista *)malloc(sizeof(t_lista));
		inicializar(lista);
		while(42)
		{
			printf("\n\t1 - Imprimir\n\t2 - Inserir Ordenado\n\t"
			"3 - Remove Elemento 'x'\n\t4 - Remove Posicao 'p'\n\t5 - Busca Elemento 'x'\n\t"
			"6 - Busca Posicao 'p'\n\t7 - Tamanho\n\t8 - Restart\n\t9 - Finalizar\n");
			scanf("%d", &opcao);
			if (opcao >= 0 && opcao <= 42)
			{
				if (opcao == 42)
				{
					printf("Created by Marcelo 'Meritissimo' the answer to life the universe and everything.\n");
				}
				else if (opcao == 2)
				{
					printf("Digite um valor: ");
					scanf("%f", &valor);
					inserir_ordenado(lista, valor);
				}
				else if (opcao == 1)
					imprimir(lista);
				else if (opcao == 7)
					tamanho(lista);
				else if (opcao == 8)
					reinicializar(lista);
				else if (opcao == 9)
					finalizar(lista);
				else if (opcao == 3)
				{
					printf("Digite um valor: ");
					scanf("%f", &valor);
					remove_elemento_x(lista, valor);
				}
				else if (opcao == 4)
				{
					printf("Digite um valor: ");
					scanf("%f", &valor);
					remove_posicao_p(lista, valor);
				}
				else if (opcao == 5)
				{
					printf("Digite um valor: ");
					scanf("%f", &valor);
					busca_elemento_x(lista, valor);
				}
				else if (opcao == 6)
				{
					printf("Digite um valor: ");
					scanf("%f", &valor);
					busca_posicao_p(lista, valor);
				}
			}
			else
				printf("Opcao Invalida");
		}
		free(lista);
	}
	else
		return (0);
	return (0);
}