#include <iostream>
using std::string;
using namespace std;

class i_cadastro{
    virtual void aposentadoria()=0;
};

class cadastro
{
protected:
    string Nome;
    string Cpf;
    int Idade;
public:
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
        Idade = Idade;
    }
    int getIdade()
    {
        return Idade;
    }
    void mostrar_dados()
    {
        std::cout<<"Nome-"<<Nome<<std::endl;
        std::cout<<"Cpf-"<<Cpf<<std::endl;
        std::cout<<"Idade-"<<Idade<<std::endl;
    }
    void aposentadoria(){
        if (Idade>65)
            std::cout<<"Voce pode se aposentar"<<std::endl;
        else
            std::cout<<"Voce nao tem idade para se aposentar"<<std::endl;
    };
    virtual void atividade(){
        std::cout<<Nome<<"está trabalhando"<<std::endl;
    }
/*
    cadastro(string nome, string empresa, int idade){
        Nome=nome;
        Empresa=empresa;
        Idade=idade;
    };*/

};
class professor:public cadastro{
    string disciplina;
public:
    void setdp(string dp){
        disciplina=dp;
    };
    void atividade(){
    std::cout<<Nome<<"está ensinando"<<disciplina<<std::endl;
    }
};

class aluno:public cadastro{
    string serie;
public:
    void setserie(string sr){
        serie=sr;
        };
    void atividade(){
    std::cout<<Nome<<"esta estudando"<<std::endl;
    }
};

int main(){
    int p=0;
    professor prof[4];
    aluno al[29];
    prof[1].setdp("matematica");

    char ch;

        while(ch!=5){
        string strdata;
        int intdata;
        std::cout<<"Sistema Escola"<<std::endl;
        std::cout<<"1-realizar matricula"<<std::endl;
        std::cout<<"2-consultar matricula"<<std::endl;
        std::cout<<"3-editar ou apagar matricula"<<std::endl;
        std::cout<<"4-checar turmas"<<std::endl;
        std::cout<<"5-sair"<<std::endl;
        std::cin>>ch;


        switch(ch){

            case'1':
                std::cout<<"1-professor"<<std::endl;
                std::cout<<"2-aluno"<<std::endl;
                std::cin>>ch;

                if(ch=='1'){
                    std::cout<<"Digite o nome"<<std::endl;
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

                    std::cout<<"cadastro realizado com sucesso, n° da matricula:"<<p<<std::endl;
                    p++;
                }

            case'2':
                std::cout<<"Digite n° da matricula"<<std::endl;


            };
    };
return 0;
};
