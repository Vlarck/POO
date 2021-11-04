#include <iostream>
#include<string.h>
using std::string;
using namespace std;

class i_cadastro{
    virtual void status()=0;
};

class cadastro:i_cadastro
{
protected:
    string Nome;
    string Cpf;
    int Idade;
public://metodos
    void setNome(string nome)
    {
        Nome = nome;
    }
    string getNome()
    {
        return Nome;
    }
    void setCpf(string cpf)
    {
        Cpf = cpf;
    }
    string getCpf()
    {
        return Cpf;
    }
    void setIdade(int idade)
    {
        Idade = idade;
    }
    int getIdade()
    {
        return Idade;
    }
    void mostrarDados()
    {
        std::cout<<"Nome-"<<Nome<<std::endl;
        std::cout<<"Cpf-"<<Cpf<<std::endl;
        std::cout<<"Idade-"<<Idade<<std::endl;
    }

    virtual void status(){
        std::cout<<Nome<<"Usuario cadastrado"<<std::endl;
    };

};

class professor:public cadastro{//herança
    string disciplina;
public:
    void setdp(string dp){
    disciplina=dp;
    };
    void status(){
    std::cout<<Nome<<" esta ensinando "<<disciplina<<std::endl;
    };
};

class aluno:public cadastro{//herança
    string serie;
public:
    void setserie(string sr){
        serie=sr;
        };
    void status(){
    std::cout<<Nome<<" esta matriculado no "<<serie<<std::endl;
    };
};


int main(){
    professor prof[4];//objeto
    aluno al[29];//objeto
    char ch;
    int p=0;
    int a=0;

        while(1){
        string strdata;
        int intdata;
        std::cout<<"Sistema Escola\n"<<std::endl;
        std::cout<<"1-realizar matricula"<<std::endl;
        std::cout<<"2-consultar matricula"<<std::endl;
        std::cout<<"3-apagar matricula"<<std::endl;
        std::cout<<"4-sair"<<std::endl;
        std::cin>>ch;


        switch(ch){
            int j;
            case'1':
                std::cout<<"\n1-professor"<<std::endl;
                std::cout<<"2-aluno"<<std::endl;
                std::cin>>j;

                if(j==1){
                    std::cout<<"\nDigite o nome"<<std::endl;
                    std::cin>>strdata;
                    prof[p].setNome(strdata);

                    std::cout<<"Digite a idade"<<std::endl;
                    std::cin>>intdata;
                    prof[p].setIdade(intdata);

                    std::cout<<"Digite cpf"<<std::endl;
                    std::cin>>strdata;
                    prof[p].setCpf(strdata);

                    std::cout<<"Digite a disciplina"<<std::endl;
                    std::cin>>strdata;
                    prof[p].setdp(strdata);

                    std::cout<<"\ncadastro realizado com sucesso, n° da matricula:"<<p<<"\n"<<std::endl;
                    p++;
                    ch=0;
                    break;
                };
                if(j==2){
                    std::cout<<"Digite o nome"<<std::endl;
                    std::cin>>strdata;
                    al[p].setNome(strdata);

                    std::cout<<"Digite a idade"<<std::endl;
                    std::cin>>intdata;
                    al[p].setIdade(intdata);

                    std::cout<<"Digite cpf"<<std::endl;
                    std::cin>>strdata;
                    al[p].setCpf(strdata);

                    std::cout<<"Digite a serie"<<std::endl;
                    std::cin>>strdata;
                    al[p].setserie(strdata);

                    std::cout<<"cadastro realizado com sucesso, n da matricula: "<<a<<std::endl;
                    a++;
                    ch=0;
                    break;
                };

            case'2':
                std::cout<<"\n1-professor"<<std::endl;
                std::cout<<"2-aluno"<<std::endl;
                std::cin>>ch;

                if(ch=='1'){
                    std::cout<<"Digite n° da matricula"<<std::endl;
                    std::cin>>intdata;
                    prof[intdata].mostrarDados();
                    prof[intdata].status();
                    break;
                    };

                if(ch=='2'){
                    std::cout<<"Digite n° da matricula"<<std::endl;
                    std::cin>>intdata;
                    al[intdata].mostrarDados();
                    al[intdata].status();
                    break;
                    };
            case'3':
                std::cout<<"1-professor"<<std::endl;
                std::cout<<"2-aluno"<<std::endl;
                std::cin>>ch;

                if(ch=='1'){
                    int c;
                    std::cout<<"Digite n° da matricula"<<std::endl;
                    std::cin>>intdata;
                    prof[intdata].mostrarDados();
                    std::cout<<"confirmar?\n1-sim\n2-nao"<<std::endl;
                    std::cin>>c;
                    if(c==1){
                        prof[intdata].setCpf("-");
                        prof[intdata].setdp("-");
                        prof[intdata].setNome("-");
                        prof[intdata].setIdade(0);
                        std::cout<<"Removida com sucesso\n"<<std::endl;
                        break;
                    }if(c==2){
                        break;
                    };

                };
                if(ch=='2'){
                    int c;
                    std::cout<<"Digite n° da matricula"<<std::endl;
                    std::cin>>intdata;
                    al[intdata].mostrarDados();
                    std::cout<<"confirmar?\n1-sim\n2-nao"<<std::endl;
                    std::cin>>c;
                    if(c==1){
                        al[intdata].setCpf("Removida");
                        al[intdata].setserie("Removida");
                        al[intdata].setNome("Removida");
                        al[intdata].setIdade(0);
                        std::cout<<"Removida com sucesso\n"<<std::endl;
                        break;
                    }if(c==2){
                        break;
                    };
                };
            case'4':
                std::cout<<"Obrigado, volte sempre\n"<<std::endl;
                exit(0);
                break;


            };
    };
return 0;
};
