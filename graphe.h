#ifndef GRAPHE_H
#define GRAPHE_H
#include <vector>
#include "sommet.h"
#include "arc.h"



class Graphe
{
private:
    std::vector<Sommet*> vectSommet_;
    std::vector<Arc*> vectArc_;
    QVector<QVector<int> > matrAsso_;
    int isDragging_;

    std::vector<int> alpha_;
    std::vector<int> beta_;
public:
    Graphe();
    ~Graphe();


    int loadMatrice();
    int loadAlphaBeta();

    void compute(QGraphicsScene* scene);
    void moveSommet(double x, double y);
    void addSommet(double x, double y, double radius, QColor color);
    void addArc(Sommet* origin, Sommet* destination, float width, float cost, QColor color);
    QVector<int>* getSuccDirect(Sommet *s);
    QVector<int>* getPredDirect(Sommet* s);

    std::vector<Sommet*> getVectSommet() const {return vectSommet_;}
    std::vector<Arc*> getVectArc() const {return vectArc_;}
    QVector<QVector<int> > getMatrAsso() const {return matrAsso_;}
    int getIsDragging() const {return isDragging_;}
    std::vector<int> getAlpha() const {return alpha_;}
    std::vector<int> getBeta() const {return beta_;}

    void setMatrAsso(QVector<QVector<int> > matrAsso){matrAsso_ = matrAsso;}
    void setIsDragging(int i){isDragging_ = i;}
};

std::vector<Sommet *> readSommet(const char* name);
QVector<QVector<int> > readMatrice(const char* name);
std::vector<int> readVector(const char* name);
#endif // GRAPHE_H
