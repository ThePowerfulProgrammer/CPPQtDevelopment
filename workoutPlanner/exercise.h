#ifndef EXERCISE_H
#define EXERCISE_H
#include <QString>

class exercise
{
public:
    exercise();
    exercise(QString name,QString description,int sets,int reps, int rpe ,float workingWeight, float rest, float max);

    // Copy constructor
    exercise(const exercise& other);

    QString getName();
    void setName(QString s);

    QString getDescription();
    void setDescription(QString d);

    float getMax();
    void setMax(float m);

    float getWorkingWeight();
    void setWorkingWeight(float ww);

    float getRest();
    void setRest(float r);

    int getId();
    void setID(int i);


    int getRPE();
    void setRPE(int rpe);

    int getSets();
    void setSets(int s);

    int getReps();
    void setReps(int r);

    QString toString() const;
    // PC: returns a QString repr of our class instance


private:
    QString name;
    QString description;
    static int id; // consider it a means to get a PK
    int unique_id;
    int RPE;
    int sets;
    int reps;
    float max;
    float workingWeight;
    float rest;

};

#endif // EXERCISE_H
