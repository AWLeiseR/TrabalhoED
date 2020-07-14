#include<math.h>

/*calcula a distancia euclidiana entre os pontoos (x1,y1) e (x2,y2)*/
double distancia (double x1, double y1, double x2, double y2){
    double dx = x2 - x1;
    double dy = y2 - y1;

    double dist = sqrt(dx*dx + dy * dy);
    return dist;
}

double max(double n1,double n2){
    if(n1>n2)
        return n1;
    else
        return n2;
}

double min(double n1,double n2){
    if(n1<n2)
        return n1;
    else
        return n2;
}
int collision(double recX,double recY,double recW,double recH,double cX,double cY,double cR){
    double deltaX;
    double deltaY;
    
    deltaX=cX-max(recX,min(cX,recX+recW));
    deltaY=cY-max(recY,min(cY,recY+recH));
    if((deltaX*deltaX+deltaY*deltaY)<=(cR*cR))
        return 1;
    else
        return 0;
}

int sobreposicao(Formas forma1,Formas forma2, FILE *arq3){
    //res(resultado),dis(distancia),raios(soma dos raios ou so o raio)
    int res,dis,raios;
    double w,h;
    char cor[]="red";
    //verifica se as duas formas sao circulos
    if(forma1.tipo=='c'&&forma2.tipo=='c'){
        //calcula a distancia entre os rcentros
        dis=distancia(forma1.cx,forma1.cy,forma2.cx,forma2.cy);
        //soma so raios
        raios=forma1.r+forma2.r;
        //verifica se a distancia é menos ou igual ao soma dos raios
        if(dis<=raios)
            res=1;
        else
            res=0;

        w=max(forma1.cx,forma2.cx)-min(forma1.cx,forma2.cx)+forma1.r+forma2.r;
            
        h=max(forma1.cy,forma2.cy)-min(forma1.cy,forma2.cy)+forma1.r+forma2.r;
        criaRetangulodash(min(forma1.cx,forma2.cx)-max(forma1.r,forma2.r),min(forma1.cy,forma2.cy)-max(forma1.r,forma2.r),w,h,cor,arq3,res);
            
    //verifica se as formas sao um retangulo e um circulo
    }else if(forma1.tipo=='r'&&forma2.tipo=='c'){
        res=collision(forma1.cx,forma1.cy,forma1.w,forma1.h,forma2.cx,forma2.cy,forma2.r);
        w=max(forma1.cx+forma1.w,forma2.cx+forma2.r)-min(forma1.cx,forma2.cx-forma2.r);    
       h=max(forma1.cy+forma1.h,forma2.cy+forma2.r)-min(forma1.cy,forma2.cy-forma2.r);
        criaRetangulodash(min(forma1.cx,forma2.cx-forma2.r),min(forma1.cy,forma2.cy-forma2.r),w,h,cor,arq3,res);
    //verifica se as formas sao um circulo e um retangulo    
    }else if(forma1.tipo=='c'&&forma2.tipo=='r'){
        res=collision(forma2.cx,forma2.cy,forma2.w,forma2.h,forma1.cx,forma1.cy,forma1.r);
        w=max(forma2.cx+forma2.w,forma1.cx+forma1.r)-min(forma2.cx,forma1.cx-forma1.r);    
        h=max(forma2.cy+forma2.h,forma1.cy+forma1.r)-min(forma2.cy,forma1.cy-forma1.r);
        criaRetangulodash(min(forma2.cx,forma1.cx-forma1.r),min(forma2.cy,forma1.cy-forma1.r),w,h,cor,arq3,res);
    //verifica se as duas formas sao retangulos
    }else if(forma1.tipo=='r'&&forma2.tipo=='r'){
        if(forma1.cx<forma2.cx+forma2.w && forma1.cx+forma1.w>forma2.cx && forma1.cy<forma2.cy+forma2.h && forma1.cy+forma1.h>forma2.cy)
          res=1;
         w=max(forma1.cx+forma1.w,forma2.cx+forma2.w)-min(forma1.cx,forma2.cx);   
       h=max(forma1.cy+forma1.h,forma2.cy+forma2.h)-min(forma1.cy,forma2.cy);
       criaRetangulodash(min(forma1.cx,forma2.cx),min(forma1.cy,forma2.cy),w,h,cor,arq3,res);
          
    }

    return res;
}
