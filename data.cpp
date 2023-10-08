#include <iostream>


class Data{

    private:
        int dia;
        int mes;
        int ano;

        
    public:
        Data(int dia, int mes, int ano){
            if (dia <=0 || dia > 31) dia = 1;

            // this->dia = (dia <=0 || dia > 31 ? 1 : dia );
            this->dia = dia;
            this->mes = mes;
            this->ano = ano;   
        }
        
        void imprime(){
            printf("%d/%d/%d\n", this->dia, this->mes, this->ano);
        }

        int getDia(){
            return this->dia;
        }

        void setDia(int dia){
            if (dia <=0 || dia > 31) return;

            this->dia = dia;
        }

        int getMes(){
            return this->mes;
        }

        void setMes(int mes){

            this->mes = mes;
        }

        int getAno(){
            return this->ano;
        }
        
        void setAno(int ano){
            this->ano = ano;
        }

};

void Data::imprime(){
    printf("%d/%d/%d\n", this->dia, this->mes, this->ano);
}


int main(){

    Data d1(15,9,2023);
    
    d1.imprime();

    d1.setDia(-10);
    d1.setMes(12);
    d1.setAno(2022);

    printf("%d/%d/%d\n", d1.getDia(), d1.getMes(), d1.getAno());
    d1.imprime();
    
    Data d2(1,1,2023);
    d2.imprime();

    
    

   

}