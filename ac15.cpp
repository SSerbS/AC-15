#include <bits/stdc++.h>
using namespace std;
#define FOR(n) for(int i = 0; i < n; i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vb = vector<bool>;

void print(ofstream& arq, const string& s){
    cout << s << '\n';

    if(arq.is_open()){
        arq << s << '\n';
    }
}

int main(){
    cout << "Digite o nome e o bloco na mesma linha: ";
    string nome; getline(cin, nome);
    ofstream arq("C:/Users/playe/Documents/AC15_" + nome + ".txt", ios::app);
    
    set<int> v = {1,4,5,6,7,8,9,11,12,14,17,19,20,23,24,25,27,28,31,34,35,38,39,41,42,43,47,
    48,49,55,56,59,60,62,67,68,70,73,75,76,77,79,80,82,83,85,86,89,90,91,92,93,97,100,101,106,107,109,112,115,116,117,118,120};

    
    cout << "Digite as 120 respostas:\n";
    vector<char> respostas(120);
    int foiate = 1;
    // 1. Apenas coleta as respostas (com a lógica de voltar funcionando perfeitamente)
    for(;foiate <= 120; foiate++){
        print(arq, (string)"Preenchendo agora a pergunta " + to_string(foiate) + ". Responda 'v', aperte 'o' (branco), ou aperte 'f' (fim). Aperte '0' para corrigir o anterior.");
        char x; cin >> x;
        if(x == 'f'){print(arq, "Parou em " + to_string(foiate)); break;}
        if(x != 'v' && x != 'o') { 
            foiate -= 2; // Volta a pergunta
            if(foiate <= -1) foiate = 0; // Evita que o índice vá a 0 (vai a +1 na próxima iteração)
            continue; 
        }
        respostas[foiate-1] = x;
        print(arq, (string)"Pergunta " + to_string(foiate) + " respondeu " + x);
    }
    foiate--;

    int acertos{0};
    // 2. Processa as pontuações DEPOIS de coletar tudo
    for(int i = 0; i < foiate; i++){
        char x = respostas[i];
        
        if(x == 'v' && v.find(i+1) != v.end()) acertos++;
        else if(x == 'o' && v.find(i+1) == v.end()) acertos++;
    }
    print(arq, "\n=== RESULTADOS PARA: " + nome + "===\n");
    print(arq,"Questões Examinadas: " + to_string(foiate) + '\n');
    print(arq, "Acertos: " + to_string(acertos) + '\n');
    print(arq, "Pontos = Acertos - Erros: " + to_string(acertos - (foiate-acertos)) + '\n');
    print(arq, "\nProcessamento concluido.\n");
    arq.close();
    return 0;
}