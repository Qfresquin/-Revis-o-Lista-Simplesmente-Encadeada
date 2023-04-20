#include<stdio.h>

struct No {
    int valor;
    No *prox;
};

struct Lista {
    No *cabeca, *cauda;
    int n;

    Lista() {
        cabeca = cauda = NULL;
        n = 0;
    }

    bool vazia() { // O(1)
        return (cabeca == NULL);
    }
    
    bool existeValor (int v){
     	
    	if (!vazia()) {
    		No *aux = cabeca;
            while (aux->prox != NULL) {
        		aux = aux->prox;
                if (aux->valor == v) return true;
                }
                
		}
		return false;
	}
    void inserirInicio(int v) { // O(1)
        No *novo = new No();
        novo->valor = v;
        if (vazia()) {
            novo->prox = NULL;
            cabeca = novo;
            cauda = novo;
        } else {
            novo->prox = cabeca;
            cabeca = novo;
        }
        n++;
    }

    void inserirFinal(int v) { // O(1)
        No *novo = new No();
        novo->valor = v;
        if (vazia()) {
            novo->prox = NULL;
            cabeca = novo;
            cauda = novo;
        } else {
            novo->prox = NULL;
            cauda->prox = novo;
            cauda = novo;
        }
        n++;
    }

    void imprimir() { // O(n)
        /*for (No *aux = cabeca; aux != NULL; aux = aux->prox) */
        No *aux = cabeca;
        while (aux != NULL) {
            printf("%d\n", aux->valor);
            aux = aux->prox;
        }
    }

    int tamanho() { // O(1)
        return n;
    }
    


    void removerInicio() { // O(1)
        if (!vazia()) {
            if (tamanho() == 1) {
                No *aux = cabeca;
                cabeca = NULL;
                cauda = NULL;
                delete(aux);
            } else {
                No *aux = cabeca;
                cabeca = cabeca->prox;
                delete(aux);
            }
            n--;
        }
    }

    void removerFinal() { // O(n)
        if (!vazia()) {
            if (tamanho() == 1) {
                No *aux = cabeca;
                cabeca = NULL;
                cauda = NULL;
                delete(aux);
            } else {
                No *penultimo = cabeca;
                while (penultimo->prox != cauda) {
                    penultimo = penultimo->prox;
                }
                delete(cauda);
                cauda = penultimo;
                cauda->prox = NULL;
            }
            n--;
        }
    }
    
    void removerNValores(int v) { // O(n*v)
    	while (v != 0) {
		removerFinal();	
		v--;
		}
	}
	
	void removerSegundoElemento(){
		if (!vazia()) {
			if (tamanho() == 1);
			else if (tamanho() == 2) removerFinal();
			else{
				No *aux = cabeca->prox;
				cabeca->prox = aux->prox;
				delete(aux);
				n--;
				
			}
		}
	}
	
	void inserirTamanho(){
		inserirFinal(tamanho());
	}
	
	void imprimirMenorqueN(int v){
		No *aux = cabeca;
        while (aux != NULL) {
            if (v >= aux->valor)printf("%d\n", aux->valor);
            aux = aux->prox;
        }
	}
	
	void inserirPenultimo(int v) { // O(n)
        if (!vazia()) {
            if (tamanho() == 1);
            else {
                No *penultimo = cabeca;
                while (penultimo->prox != cauda) {
                    penultimo = penultimo->prox;
                }
                No *novo = new No();
        		novo->valor = v;
                penultimo->prox = novo;
                novo->prox = cauda;
                n++;
            }  
        }
    }
    
  void removerPosicao(int v) {
    if (!vazia()) {
        if (v == 1) removerInicio();
        else if (v == tamanho()) removerFinal();
        else if (v < tamanho()) {
            No *aux = cabeca;
            No *aux2 = NULL;
            for (int i = 0; i < v -2; i++) {
                aux = aux->prox;
            }
            aux2 = aux->prox;
            aux->prox = aux2->prox;
            delete aux2;
            n--;
        }
    }
}

	void removerRecorrencias (int v) {
		if(existeValor(v)){
			No *aux = cabeca;
			int posicao = 1;

    		 while (aux != NULL){
    			if (aux->valor == v){
        			aux = aux->prox;
					removerPosicao(posicao);
    			} else {
				aux = aux->prox;
  				posicao++;} 
 	   			
			}
		}
	}
	
	void inserirSeNExistir (int v){
		if(!existeValor(v)) inserirFinal(v);
	}
    

};

int main() {

    Lista l;
    l.inserirFinal(5);
    l.inserirFinal(4);
    l.inserirFinal(3);
    l.inserirFinal(2);
    l.inserirFinal(7);
    l.inserirFinal(1);
    l.inserirFinal(0);
    l.inserirFinal(2);
    l.inserirInicio(5);
    l.inserirFinal(6);
	l.inserirFinal(5);
    l.inserirFinal(4);
    l.inserirFinal(5);
    

	l.removerRecorrencias(5);
	l.inserirFinal(5);
	l.inserirFinal(4);
	l.inserirSeNExistir(5);

    l.imprimir();



	

    return 0;
}
