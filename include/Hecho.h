#ifndef HECHO_H
#define HECHO_H
#include <string>

class Hecho {
    private:
        std::string id;
        float fc;

    public:
        Hecho() {}
        Hecho(std::string id, float fc);
        ~Hecho();

        std::string getID();
        float getFC();

};

#endif // HECHO_H
