//
// Created by clock on 07/03/21.
//

#include "box.h"

Forma* box(float x,float y,float z,int div){
    Forma *f = new Forma();
    for (int i = 0; i < div; ++i) {
        for (int j = 0; j < div; ++j) {
            //@TODO FALTAM VERIFICAR AS TEXTURE POINTS
            //Front Face
            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)i,y/2.0f-(y/(float)div)*(float)j,z/2.0f));
            f->insereNormal(new Ponto(0,0,1));
            f->insereTextura(new Ponto(1-((x/(float)div)*(float)i)/x,1-((y/(float)div)*(float)j/y),0));

            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i+1),y/2.0f-(y/(float)div)*(float)(j+1),z/2.0f));
            f->insereNormal(new Ponto(0,0,1));
            f->insereTextura(new Ponto(1-((x/(float)div)*(float)(i+1))/x,1-((y/(float)div)*(float)(j+1))/y,0));

            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i),y/2.0f-(y/(float)div)*(float)(j+1),z/2.0f));
            f->insereNormal(new Ponto(0,0,1));
            f->insereTextura(new Ponto(1-((x/(float)div)*(float)(i))/x,1-((y/(float)div))/y*(float)(j+1),0));


            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i),y/2.0f-(y/(float)div)*(float)(j),z/2.0f));
            f->insereNormal(new Ponto(0,0,1));
            f->insereTextura(new Ponto(1-((x/(float)div)*(float)(i))/x,1-((y/(float)div)*(float)(j))/y,0));

            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i+1),y/2.0f-(y/(float)div)*(float)(j),z/2.0f));
            f->insereNormal(new Ponto(0,0,1));
            f->insereTextura(new Ponto(1-((x/(float)div)*(float)(i+1))/x,1-((y/(float)div)*(float)(j))/y,0));

            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i+1),y/2.0f-(y/(float)div)*(float)(j+1),z/2.0f));
            f->insereNormal(new Ponto(0,0,1));
            f->insereTextura(new Ponto(1-((x/(float)div)*(float)(i+1))/x,1-((y/(float)div)*(float)(j+1))/y,0));

            //Back Face
            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)i,y/2.0f-(y/(float)div)*(float)j,-z/2.0f));
            f->insereNormal(new Ponto(0,0,-1));
            f->insereTextura(new Ponto((x/(float)div)*(float)i/x,1-(y/(float)div)*(float)j/y,0));

            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i),y/2.0f-(y/(float)div)*(float)(j+1),-z/2.0f));
            f->insereNormal(new Ponto(0,0,-1));
            f->insereTextura(new Ponto((x/(float)div)*(float)(i)/x,1-(y/(float)div)*(float)(j+1)/y,0));

            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i+1),y/2.0f-(y/(float)div)*(float)(j+1),-z/2.0f));
            f->insereNormal(new Ponto(0,0,-1));
            f->insereTextura(new Ponto((x/(float)div)*(float)(i+1)/x,1-(y/(float)div)*(float)(j+1)/y,0));


            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i),y/2.0f-(y/(float)div)*(float)(j),-z/2.0f));
            f->insereNormal(new Ponto(0,0,-1));
            f->insereTextura(new Ponto((x/(float)div)*(float)(i)/x,1-(y/(float)div)*(float)(j)/y,0));

            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i+1),y/2.0f-(y/(float)div)*(float)(j+1),-z/2.0f));
            f->insereNormal(new Ponto(0,0,-1));
            f->insereTextura(new Ponto((x/(float)div)*(float)(i+1)/x,1-(y/(float)div)*(float)(j+1)/y,0));

            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i+1),y/2.0f-(y/(float)div)*(float)(j),-z/2.0f));
            f->insereNormal(new Ponto(0,0,-1));
            f->insereTextura(new Ponto((x/(float)div)*(float)(i+1)/x,1-(y/(float)div)*(float)(j)/y,0));

            //Right Face
            f->inserePonto(new Ponto(x/2.0f,y/2.0f-(y/(float) div)*(float)(j),z/2.0f-(z/(float) div)*(float)(i)));
            f->insereNormal(new Ponto(1,0,0));
            f->insereTextura(new Ponto((z/(float) div)*(float)(i)/z,1-(y/(float) div)*(float)(j)/y,0));

            f->inserePonto(new Ponto(x/2.0f,y/2.0f-(y/(float) div)*(float)(j+1),z/2.0f-(z/(float) div)*(float)(i)));
            f->insereNormal(new Ponto(1,0,0));
            f->insereTextura(new Ponto((z/(float) div)*(float)(i)/z,1-(y/(float) div)*(float)(j+1)/y,0));

            f->inserePonto(new Ponto(x/2.0f,y/2.0f-(y/(float) div)*(float)(j+1),z/2.0f-(z/(float) div)*(float)(i+1)));
            f->insereNormal(new Ponto(1,0,0));
            f->insereTextura(new Ponto((z/(float) div)*(float)(i+1)/z,1-(y/(float) div)*(float)(j+1)/y,0));


            f->inserePonto(new Ponto(x/2.0f,y/2.0f-(y/(float) div)*(float)(j),z/2.0f-(z/(float) div)*(float)(i)));
            f->insereNormal(new Ponto(1,0,0));
            f->insereTextura(new Ponto((z/(float) div)*(float)(i)/z,1-(y/(float) div)*(float)(j)/y,0));

            f->inserePonto(new Ponto(x/2.0f,y/2.0f-(y/(float) div)*(float)(j+1),z/2.0f-(z/(float) div)*(float)(i+1)));
            f->insereNormal(new Ponto(1,0,0));
            f->insereTextura(new Ponto((z/(float) div)*(float)(i+1)/z,1-(y/(float) div)*(float)(j+1)/y,0));

            f->inserePonto(new Ponto(x/2.0f,y/2.0f-(y/(float) div)*(float)(j),z/2.0f-(z/(float) div)*(float)(i+1)));
            f->insereNormal(new Ponto(1,0,0));
            f->insereTextura(new Ponto((z/(float) div)*(float)(i+1)/z,1-(y/(float) div)*(float)(j)/y,0));


            //Left Face
            f->inserePonto(new Ponto(-x/2.0f,y/2.0f-(y/(float)div)*(float)(j),z/2.0f-(z/(float) div)*(float)(i)));
            f->insereNormal(new Ponto(-1,0,0));
            f->insereTextura(new Ponto(1-(z/(float) div)*(float)(i)/z,1-(y/(float)div)*(float)(j)/y,0));

            f->inserePonto(new Ponto(-x/2.0f,y/2.0f-(y/(float) div)*(float)(j+1),z/2.0f-(z/(float) div)*(float)(i+1)));
            f->insereNormal(new Ponto(-1,0,0));
            f->insereTextura(new Ponto(1-(z/(float) div)*(float)(i+1)/z,1-(y/(float) div)*(float)(j+1)/y,0));

            f->inserePonto(new Ponto(-x/2.0f,y/2.0f-(y/(float) div)*(float)(j+1),z/2.0f-(z/(float) div)*(float)(i)));
            f->insereNormal(new Ponto(-1,0,0));
            f->insereTextura(new Ponto(1-(z/(float) div)*(float)(i)/z,1-(y/(float) div)*(float)(j+1)/y,0));


            f->inserePonto(new Ponto(-x/2.0f,y/2.0f-(y/(float) div)*(float)(j),z/2.0f-(z/(float) div)*(float)(i)));
            f->insereNormal(new Ponto(-1,0,0));
            f->insereTextura(new Ponto(1-(z/(float) div)*(float)(i)/z,1-(y/(float)div)*(float)(j)/y,0));

            f->inserePonto(new Ponto(-x/2.0f,y/2.0f-(y/(float) div)*(float)(j),z/2.0f-(z/(float) div)*(float)(i+1)));
            f->insereNormal(new Ponto(-1,0,0));
            f->insereTextura(new Ponto(1-(z/(float) div)*(float)(i+1)/z,1-(y/(float)div)*(float)(j)/y,0));

            f->inserePonto(new Ponto(-x/2.0f,y/2.0f-(y/(float) div)*(float)(j+1),z/2.0f-(z/(float) div)*(float)(i+1)));
            f->insereNormal(new Ponto(-1,0,0));
            f->insereTextura(new Ponto(1-(z/(float) div)*(float)(i+1)/z,1-(y/(float)div)*(float)(j+1)/y,0));

            //Top Face
            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i),y/2.0f,z/2.0f-(z/(float) div)*(float)(j+1)));
            f->insereNormal(new Ponto(0,1,0));
            f->insereTextura(new Ponto(1-(x/(float)div)*(float)(i)/x,(z/(float) div)*(float)(j+1)/z,0));

            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i+1),y/2.0f,z/2.0f-(z/(float) div)*(float)(j)));
            f->insereNormal(new Ponto(0,1,0));
            f->insereTextura(new Ponto(1-(x/(float)div)*(float)(i+1)/x,(z/(float) div)*(float)(j)/z,0));

            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i),y/2.0f,z/2.0f-(z/(float) div)*(float)(j)));
            f->insereNormal(new Ponto(0,1,0));
            f->insereTextura(new Ponto(1-(x/(float)div)*(float)(i)/x,(z/(float) div)*(float)(j)/z,0));


            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i),y/2.0f,z/2.0f-(z/(float) div)*(float)(j+1)));
            f->insereNormal(new Ponto(0,1,0));
            f->insereTextura(new Ponto(1-(x/(float)div)*(float)(i)/x,(z/(float) div)*(float)(j+1)/z,0));

            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i+1),y/2.0f,z/2.0f-(z/(float) div)*(float)(j+1)));
            f->insereNormal(new Ponto(0,1,0));
            f->insereTextura(new Ponto(1-(x/(float)div)*(float)(i+1)/x,(z/(float) div)*(float)(j+1)/z,0));

            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i+1),y/2.0f,z/2.0f-(z/(float) div)*(float)(j)));
            f->insereNormal(new Ponto(0,1,0));
            f->insereTextura(new Ponto(1-(x/(float)div)*(float)(i+1)/x,(z/(float) div)*(float)(j)/z,0));

            //Down Face
            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i),-y/2.0f,z/2.0f-(z/(float) div)*(float)(j+1)));
            f->insereNormal(new Ponto(0,-1,0));
            f->insereTextura(new Ponto((x/(float)div)*(float)(i)/x,(z/(float) div)*(float)(j+1)/z,0));

            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i),-y/2.0f,z/2.0f-(z/(float) div)*(float)(j)));
            f->insereNormal(new Ponto(0,-1,0));
            f->insereTextura(new Ponto((x/(float)div)*(float)(i)/x,(z/(float) div)*(float)(j)/z,0));

            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i+1),-y/2.0f,z/2.0f-(z/(float) div)*(float)(j)));
            f->insereNormal(new Ponto(0,-1,0));
            f->insereTextura(new Ponto((x/(float)div)*(float)(i+1)/x,(z/(float) div)*(float)(j)/z,0));


            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i),-y/2.0f,z/2.0f-(z/(float) div)*(float)(j+1)));
            f->insereNormal(new Ponto(0,-1,0));
            f->insereTextura(new Ponto((x/(float)div)*(float)(i)/x,(z/(float) div)*(float)(j+1)/z,0));

            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i+1),-y/2.0f,z/2.0f-(z/(float) div)*(float)(j)));
            f->insereNormal(new Ponto(0,-1,0));
            f->insereTextura(new Ponto((x/(float)div)*(float)(i+1)/x,(z/(float) div)*(float)(j)/z,0));

            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i+1),-y/2.0f,z/2.0f-(z/(float) div)*(float)(j+1)));
            f->insereNormal(new Ponto(0,-1,0));
            f->insereTextura(new Ponto((x/(float)div)*(float)(i+1)/x,(z/(float) div)*(float)(j+1)/z,0));

        }
    }

    return f;

}