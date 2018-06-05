#include "Interface.h"
//Realiza a busca do código no arquivo e transfere para um vetor
//como a memória tem um limite de 50 posições o vetor é limitado em 51 posições
//a ultima posição é preenchida com um % que é a ordem de parada usada na leitura do vetor
void LerArquivo()
{
    //abrir arquivo em modo de leitura
    ifstream A;
    A.open("Codigo.txt");
    //testar a abertura do arquivo
    if(!A)
    {
        cout<<"Erro ao abrir arquivo!!";
//		exit(-1);
    }
    //salvar cada linha do arquivo no vetor de strings
    else
    {
        int i=0;
        while(!A.eof())
        {
            getline(A,Arquivo[i]);
            i++;
        }
        //ordem de parada utilizada na transferencia para a memória
        Arquivo[i-1]="%";
    }

    //fechar o arquivo
    A.close();
}
//essa função transfere o conteúdo atual da memória, tanto em binário quanto em decimal
// para um arquivo chamado Memoria.txt
void GuardarMemoriaArquivo()
{
    //abrir arquivo em modo de escrita
    ofstream A;
    A.open("Memoria.txt");
    //testar a abertura do arquivo
    if(!A)
    {
        cout<<"Erro ao abrir arquivo!!";
//		exit(-1);
    }
    //salvar cada linha do arquivo no vetor de strings
    else
    {
        A<<"\n\t      M E M O R I A (binaria) \n";

        A<<"--------------------------------------------\n| END.\t | CONTEUDO                        |"<<endl;
        A<<"--------------------------------------------"<<endl;
        int v[16];
        for(int i=0; i<50; i++)
        {
            GetMEM(i,0,16,v);
            A<<"| "<<i<<"\t |";
            for(int x=0; x<16; x++) A<<" "<<v[x];
            A<<" |\n--------------------------------------------"<<endl;
        }
        A<<"\n\t      M E M O R I A (decimal) \n";
        A<<"--------------------------------------------\n| END.\t | OPCODE    | CONTEUDO            |"<<endl;
        A<<"--------------------------------------------"<<endl;
        for(int i=0; i<50; i++)
        {
            int a,b,op[4],v[12];
            GetMEM(i,0,4,op);
            GetMEM(i,4,16,v);
            a=Conv_Bin_Dec_IR(op,a,4);
            b=Conv_Bin_Dec(v,b,12);
            A<<"| "<<i<<"\t |  "<<a<<"\t     | "<<b<<"\t          ";
            A<<" |\n--------------------------------------------"<<endl;
        }
    }
}
//Essa função faz o salvamento de memória, cada um dos códigos contidos no vetor
//que contem o código é lido e interpretado
//em seguido uma função realiza a construção da matriz de memória
void SalvarMem()
{
    int x=-1, c=0, d=0, op[4], v[12];
    char Comando[25], dado[25];
    do
    {
        x++;
        if(Arquivo[x]=="%") break;
        int i=0;
        do
        {
            Comando[i]=Arquivo[x][i];
            i++;
        }
        while(Arquivo[x][i]!=' ' && i<Arquivo[x].size());
        Comando[i]='\0';
        int y=0;

        do
        {
            dado[y]=Arquivo[x][i];
            y++;
            i++;
        }
        while(i<=Arquivo[x].size());

        d=atoi(dado);
        Conv_Dec_Bin(d,v,12);

        int flag=0;
        //interpretação de comandos
        if(strcmp(Comando,"LOAD")==0) c=1;
        else if(strcmp(Comando,"STOR")==0) c=2;
        else if(strcmp(Comando,"ADD")==0) c=3;
        else if(strcmp(Comando,"SUB")==0) c=4;
        else if(strcmp(Comando,"MUL")==0) c=5;
        else if(strcmp(Comando,"DIV")==0) c=6;
        else if(strcmp(Comando,"MOD")==0) c=7;
        else if(strcmp(Comando,"OR")==0) c=8;
        else if(strcmp(Comando,"AND")==0) c=9;
        else if(strcmp(Comando,"JUMP")==0) c=10;
        else if(strcmp(Comando,"JUMPZ")==0) c=11;
        else if(strcmp(Comando,"JUMPN")==0) c=12;
        else if(strcmp(Comando,"JUMPP")==0) c=13;
        else if(strcmp(Comando,"INC")==0) c=14;
        else if(strcmp(Comando,"END")==0) c=15;
        else
        {
            c=atoi(Comando);
            flag=-1;
        }
        //construção da matriz de memória
        if(flag==0)
        {
            Conv_Dec_Bin(c,op,4);
            SetMEM(4,16,x,v);
            SetMEM(0,4,x,op);

        }
        else
        {
            SetMEM(4,16,c,v);
        }

    }
    while(Arquivo[x]!="%");
}
//mostra a memória, o usuário tem a opção de mostrá-la em binário ou decimal
void MostrarMemoria(int tipo)
{
    cout<<"\n\t      M E M O R I A \n";
    if(tipo==1)
    {
        cout<<"--------------------------------------------\n| END.\t | CONTEUDO                        |"<<endl;
        cout<<"--------------------------------------------"<<endl;
        int v[16];
        for(int i=0; i<50; i++)
        {
            GetMEM(i,0,16,v);
            cout<<"| "<<i<<"\t |";
            for(int x=0; x<16; x++) cout<<" "<<v[x];
            cout<<" |\n--------------------------------------------"<<endl;
        }
    }
    else
    {
        cout<<"--------------------------------------------\n| END.\t | OPCODE    | CONTEUDO            |"<<endl;
        cout<<"--------------------------------------------"<<endl;
        for(int i=0; i<50; i++)
        {
            int a,b,op[4],v[12];
            GetMEM(i,0,4,op);
            GetMEM(i,4,16,v);
            a=Conv_Bin_Dec_IR(op,a,4);
            b=Conv_Bin_Dec(v,b,12);
            cout<<"| "<<i<<"\t |  "<<a<<"\t     | "<<b<<"\t          ";
            cout<<" |\n--------------------------------------------"<<endl;
        }
    }

}
//inicia a execução do programa contido na matriz de memória
int IniciarExec()
{
    //inicializa um corpo de vetores que receberão os registradores e irão exibí-los em tempo real
    int ir[16], mar[12], mbr[12], ac[12], pc;
    //realiza a verificação do pc
    pc=GetPC();
    //utiliza o pc para setar o IR
    SetIR(pc);
    //Guarda o OPCODE atual na variável d, a condição de parada do programa é achar o opcode do comando END
    int d=GetOPCODE();
    while(d!=15)
    {

        InterpretarLinha(d);
        //realiza o processo de interpretação do comando do opcode
        GetIR(0,16,ir);
        GetMAR(mar);
        GetMBR(mbr);
        GetAC(ac);
        cout<<"| "<<pc<<"\t| ";
        for(int i=0; i<16; i++) cout<<ir[i];
        cout<<" | ";
        for(int i=0; i<12; i++) cout<<mar[i];
        cout<<" | ";
        for(int i=0; i<12; i++) cout<< mbr[i];
        cout<<" | ";
        for(int i=0; i<12; i++) cout<<ac[i];
        cout<<" | "<<endl;
        cout<<"-------------------------------------------------------------------------"<<endl;
        //refaz a execução com a próxima linha de memória
        IniciarExec();

    }
    //indica a finalização do programa, não serão mais executadas instruções
    cout<<"--> PROGRAMA FINALIZADO, TECLE ALGO PARA VOLTAR AO MENU <--"<<endl;
    //o programa realiza parada com o pause no windows e o read -p no linux
    #ifdef _WIN32
    system("pause");
    system("cls");
    #else
    system("read -p \"Pressione enter para sair\" saindo");
    system("clear");
    #endif // _WIN32
    //retorna ao menu após finalizar a execução do programa
    Menu();
    return 0;

}

//inicia a interpretação do OPCODE
void InterpretarLinha(int E)
{
    int op[4],a;
    //MAR recebe o endereço e MBR o valor deste endereço que o MAR contem
    SetMAR();
    SetMBR();
    //o opcode é salvo na variável a
    a=GetOPCODE();

    //inicia a interpretação do OPCODE
    switch(a)
    {
    case 1:
        Load();
        break;
    case 2:
        Store();
        break;
    case 3:
        ADD();
        break;
    case 4:
        SUB();
        break;
    case 5:
        MUL();
        break;
    case 6:
        DIV();
        break;
    case 7:
        MOD();
        break;
    case 8:
        OR();
        break;
    case 9:
        AND();
        break;
    case 10:
        JUMP();
        break;
    case 11:
        JUMPZ();
        break;
    case 12:
        JUMPN();
        break;
    case 13:
        JUMPP();
        break;
    case 14:
        INC();
        break;
    }
}

//função de interface de menu de usuário
int Menu()
{
    int valor;
    cout<<" \n\n---> SIMULADOR DE PROCESSADOR ASSEMBLY <---"<<endl<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"| 1\t| Mostrar conteudo da memoria (binario);\t\t|"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"| 2\t| Mostrar conteudo da memoria (decimal);\t\t|"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"| 3\t| Mostrar conteudo de posicao especifica da memoria;\t|"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"| 4\t| Iniciar/Continuar execucao do programa;\t\t|"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"| 5\t| Guardar a memoria no arquivo;          \t\t|"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"| 0\t| Sair;\t\t\t\t\t\t\t|"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"\n --> Escolha: ";
    cin>>valor;
    switch(valor)
    {
    case 1:
        MostrarMemoria(1);
        cout<<"(!) APERTE QUALQUER TECLA PARA VOLTAR AO MENU (!)"<<endl;
        //o programa realiza parada com o pause no windows e o read -p no linux
        #ifdef _WIN32
        system("pause");
        system("cls");
        #else
        system("read -p \"Pressione enter para sair\" saindo");
        system("clear");
        #endif // _WIN32
        Menu();
        break;
    case 2:
        MostrarMemoria(2);
        cout<<"(!) APERTE QUALQUER TECLA PARA VOLTAR AO MENU (!)"<<endl;
        #ifdef _WIN32
        system("pause");
        system("cls");
        #else
        system("read -p \"Pressione enter para sair\" saindo");
        system("clear");
        #endif // _WIN32
        Menu();
        break;
    case 3:
        cout<<"\n --> Digite a posicao desejada em decimal: ";
        cin>>valor;
        int v[12], op[4],a,b;
        GetMEM(valor,0,4,op);
        GetMEM(valor,4,16,v);
        a=Conv_Bin_Dec_IR(op,a,4);
        b=Conv_Bin_Dec(v,b,12);
        cout<<"------------------------------------------------------------------------"<<endl;
        cout<<"| POS.  | OPCODE - BIN  | OPCODE - DEC| CONTEUDO - BIN |CONTEUDO - DEC |"<<endl;
        cout<<"------------------------------------------------------------------------"<<endl;
        cout<<"| "<<valor<<"\t|";
        for(int i=0; i<4; i++) cout<<op[i];
        cout<<"\t        | "<<a<<"\t      |";
        for(int i=0; i<12; i++) cout<<v[i];
        cout<<"    | "<<b<<"\t       |"<<endl;
        cout<<"------------------------------------------------------------------------"<<endl;
        cout<<"(!) PRESSIONE ENTER PARA VOLTAR AO MENU (!)"<<endl;
        #ifdef _WIN32
        system("pause");
        system("cls");
        #else
        system("read -p \"Pressione enter para sair\" saindo");
        system("clear");
        #endif // _WIN32
        Menu();
        break;

    case 4:
        cout<<" \n\n---> PROGRAMA EM EXECUCAO (M para voltar ao menu) <---"<<endl<<endl;
        cout<<"-------------------------------------------------------------------------"<<endl;
        cout<<"| PC\t| IR               | MAR          | MBR          | AC           |"<<endl;
        cout<<"-------------------------------------------------------------------------"<<endl;
        IniciarExec();
        break;
    case 5:
        GuardarMemoriaArquivo();
        cout<<"\nMemoria salva em arquivo!!\n\n"<<endl;
        #ifdef _WIN32
        system("pause");
        system("cls");
        #else
        system("read -p \"Pressione enter para sair\" saindo");
        system("clear");
        #endif // _WIN32
        Menu();
        break;
    case 0:
        exit(-1);
    default:
        cout<<"\n\n (!)  ESCOLHA INVALIDA, TENTE NOVAMENTE  (!) "<<endl<<endl;
        cout<<"(!) APERTE QUALQUER TECLA PARA VOLTAR AO MENU (!)"<<endl;
        #ifdef _WIN32
        system("pause");
        system("cls");
        #else
        system("read -p \"Pressione enter para sair\" saindo");
        system("clear");
        #endif // _WIN32
        Menu();
    }
    cout<<endl<<endl;
}
