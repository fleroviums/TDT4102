class Cheese{
    private:
        string name;
        bool hasHoles;
        bool isBrown;
    public:
        Cheese(string cheeseName,
        bool cheseHasHoles, bool cheseIsbrwon)){
            this->name = cheeseName;
            this->cheeseHasHoles = hasHoles;
            this->isBrown = cheeseIsBrown;
        }
};

class BrownCheese : public Cheese{
    public:
        BrownCheese(string cheeseName) : Cheese(cheeseName, false, true);
}