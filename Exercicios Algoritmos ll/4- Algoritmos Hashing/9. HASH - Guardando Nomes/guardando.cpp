#include <iostream>
#include <cstring>

using namespace std;

//Struct
struct dado{
	char info[50]; //informaÃ§Ã£o
	int k; //chave
	int status; //0: cÃ©lula vazia, 1: cÃ©lula ocupada, 2: chave removida
};

//FunÃ§Ãµes
int h1(int h, int m); //hash1
int h2(int h, int m); //hash2
int dhash(int h, int i, int m); //double hash
int hash_insert(dado t[], int m, char k[]); //inserÃ§Ã£o de valores
int hash_search(dado t[], int m, char k[]); //procura de valores
int hash_remove(dado t[], int m, char k[]); //remoÃ§Ã£o de valores
int hash_key(char k[]); //calcula o valor da chave

int main(){
	dado t[100]; //tabela hash
	int m; //tamanho da tabela
	int i; //contador
	char k[50]; //informaÃ§Ã£o que serÃ¡ inserida
	char op[10]; //opÃ§Ã£o do usuÃ¡rio
	int fim = 0; //o programa nÃ£o irÃ¡ finalizar
	int result; //posiÃ§Ã£o na tabela
	
	//Lendo o tamanho da tabela
	cin >> m;
	
	//Inicializando a tabela
	for(i = 0; i < m; i++){
		strcpy(t[i].info,"vazio");
		t[i].k = -1; //coloca -1 em toda a tabela hash
		t[i].status = 0; //define todas as celulas como vazias no inÃ­cio
	}
	
	cin.ignore(); //para permitir o input de frases
	
	//Inserir a opÃ§Ã£o desejada
	do {
		//LÃª a opÃ§Ã£o do usuÃ¡rio
		cin.getline(op,10); //recebe a informaÃ§Ã£o
		
		//Adicionar informaÃ§Ãµes na tabela
		if(strcmp(op,"1") == 0){
			cin.getline(k,50);
			hash_insert(t, m, k); //chama a funÃ§Ã£o de inserir infos 
		}
		
		//Pesquisar informaÃ§Ãµes na tabela
		else if(strcmp(op,"2") == 0){
		    cin.getline(k,50);
	        result = hash_search(t, m, k);
	        if(result == -1){
				cout << k << " nao encontrado" << endl;
			}
			else {
				cout << k << " encontrado na posicao " << result << endl;
			}
		}
		
		//Remover informaÃ§Ãµes da tabela
		else if(strcmp(op,"3") == 0){
		    cin.getline(k,50);
	        hash_remove(t, m, k);
		}
		
		//Mostrar valores da tabela
		else if(strcmp(op,"4") == 0){
		    for(i = 0; i < m; i++){
		        cout << t[i].info << endl;
	        }
		}
		
		//Finaliza o programa
		else if(strcmp(op,"5") == 0){
			fim = 1;
		}
		
		//Caso a opÃ§Ã£o nÃ£o seja vÃ¡lida
		else{
			cout << endl;
		}
		
	}while(fim == 0);
	
	return 0;
}

//Inserir infos na tabela
int hash_insert(dado t[], int m, char k[]){
	int i = 0; //tentativas
	int j; //recebe a posiÃ§Ã£o da chave
	int h; //recebe o valor da chave
	h = hash_key(k); //chama a funÃ§Ã£o que calcula a chave
	do{
		j = dhash(h, i, m); //calcula a posiÃ§Ã£o na tabela hash
		if (t[j].status != 1){ //se a cÃ©lula estÃ¡ vazia
			strcpy(t[j].info,k); //coloca a info na tabela
			t[j].k = h; //coloca a chave na tabela
			t[j].status = 1; //define a cÃ©lula como ocupada
			return j; //finaliza o loop
		}
	    else
	    	i = i+1; //aumenta o valor da tentativa
	}while(i != m);
	return -1; //a tabela estÃ¡ cheia
}

//Procurar infos na tabela
int hash_search(dado t[], int m, char k[]) {
	int j; //posiÃ§Ã£o na tabela
	int i = 0; //tentativas
	int h; //chave
	h = hash_key(k);
	do {
		j = dhash(h, i, m);
		if(t[j].k == h) {
			return j; //retorna a posiÃ§Ã£o caso ache o valor
		}
		i++;
	} while (t[j].status != 0 && i < m);
	return -1; //retorna -1 caso nÃ£o ache
}

//Remover valor
int hash_remove(dado t[], int m, char k[]) {
	int j; //posiÃ§Ã£o na tabela
	j = hash_search(t, m, k);
	if(j != -1) {
		t[j].status = 2; //cÃ©lula com status de chave removida
		t[j].k = -1; //cÃ©lula vazia
		strcpy(t[j].info,"vazio"); //esvazia a cÃ¡lula
		return 0; //remoÃ§Ã£o feita
	}
	else {
		return -1; //a chave nÃ£o estÃ¡ na tabela
	}
}

//Double Hash
int dhash(int h, int i, int m){
	int hash1; //resultado de hash1
	int hash2; //resultado de hash2
	int result; //resultado de dhash
	hash1 = h1(h, m); //chama a funÃ§Ã£o hash1
	hash2 = h2(h, m); //chama a funÃ§Ã£o hash2
	result = (((hash1) + i*(hash2)) % m); //cÃ¡lculo de posiÃ§Ã£o
	return result; //retorna o resultado
}

//Hash1
int h1(int h, int m){
	int hash1; //resultado de hash1
	hash1 = (h % m); //cÃ¡lculo de posiÃ§Ã£o
	//caso o resultado seja positivo
	if(hash1 >= 0) {
		return hash1;
	}
	//caso o resultado seja negativo
	else {
		hash1 = hash1 + m;
		return hash1;
	}
}

//Hash2
int h2(int h, int m){
	int hash2; //resultado de hash1
	hash2 = 1 + (h % (m - 1)); //cÃ¡lculo de posiÃ§Ã£o
	//caso o resultado seja positivo
	if(hash2 >= 0) {
		return hash2;
	}
	//caso o resultado seja negativo
	else {
		hash2 = hash2 + m;
		return hash2;
	}
}

//Gerador de chaves
int hash_key(char k[]){
	int tam = 0; //comprimento de nome
	int i; //contador
	int h = 0; //chave
	tam = strlen(k);
	for(i = 0; i < tam; i++){
		h += int(k[i]);
		//basicamente converte cada char para o valor ascii
	}
	return h;
}