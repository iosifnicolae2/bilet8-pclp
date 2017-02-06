#include<stdio.h>
#include<math.h>
#define PI 3.14

struct cerc{
    int x,y;
    float raza;
};
struct punct{
    int x,y;};

void citire(cerc &c){
    printf("Introduceti valori pentru cerc:\n");
    printf("\nx= ");
    scanf("%d",&c.x);
    printf("\ny=");
    scanf("%d", &c.y);
    printf("raza= ");
    scanf("%f", &c.raza);
}
void afisare(cerc &c){
    printf("Coordonatele punctului sunt (%d,%d) si raza este %f .",c.x,c.y,c.raza);}

int aria(cerc &c){
    int a;
    a=PI*c.raza*c.raza;
    return a;}
int distanta(cerc c1,cerc c2){
    double d;
    d=sqrt(double(c2.x-c1.x)*(c2.x-c1.x)+(c2.y-c1.y)*(c2.y-c1.y));
    return d;
}
int verific(cerc c,punct p){
    int a;
    a=(p.x-c.x)*(p.x-c.x)+(p.y-c.y)*(p.y-c.y);
    if(a<=c.raza*c.raza)
        return 1;
        else
            return 0;

}
int maimare(cerc &a, cerc &b)
{
    if(aria(a)>aria(b)){

        return aria(a);
    }
        else{

        return aria(b);
    }

}
int main(){
    punct p;
    int i,j,n;
    printf("Introduceti dimensiunea tabloului:");
    scanf("%d",&n);
    cerc *tab=new cerc[n];

    for(i=0;i<n;i++){
        citire(tab[i]);}

    for(i=0;i<n;i++){
        afisare(tab[i]);}

/*
 * Ce ai scris tu aici e corect daca iti cere aria maxima, dar tie iti cere cercul maxim.*/

    float max;
    cerc c_max;
    max=aria(tab[0]);
    for(i=1; i<n; i++)
    {
        if(max<aria(tab[i])){
            c_max = tab[i];
            //sau ai fi putut salva indicele i, ceea ce ar fi fost mai eficient..
            max=aria(tab[i]);
        }
    }
    printf("Cercul maxim este: ");
    afisare(c_max);
    printf("\nMax:%f", max);

    printf("\nCititi coordonatle punctului p:\n");
    printf("x="); scanf("%d", &p.x);
    printf("y="); scanf("%d", &p.y);
    for(i=0;i<n;i++)
        if(verific(tab[i],p)){
            printf("Cercul %d include punctul introdus.\n");
        }

    //if(verific(tab[i],p)
    for(i=0; i<n; i++){
        printf("%d", distanta(tab[i], tab[i+1]));
    }
  //  getch();
    return 0;
}