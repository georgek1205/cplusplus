//Initializing a Sequence of Cards for UNO
#include<iostream>
#include<cstring>
using namespace std;
class Card
{
    public:
    //ì??ì?±ì??
    Card() : color(NULL), value(0), number(0){}
    //ê¸°ë³¸ ì??ì?±ì??
    Card(const char* b, int v, int num)
    {
        this->color = new char[strlen(b) + 1];
        strcpy(this->color, b);
         
        this->value = v;
         
        this->number = num;
    }
    //ë³µì?¬ ì??ì?±ì??
    Card(const Card& r)
    {
        this->color = new char[strlen(r.color) + 1];
        strcpy(this->color, r.color);
         
        this->value = r.value;
        this->number = r.number;
    }
    //ì??ë©¸ì??(ë³µì?¬ì??ì?±ì??ì?? í?¬ì?¸í?° ë?¤ì?´ ë°©ì§?)
    ~Card()
    {
        if(color != NULL)
            delete [] color;
    }
    //sets
    void setColor(const char* n)
    {
        if(this->color != NULL)
            delete [] this->color;
        this->color = new char[strlen(n) + 1];
        strcpy(this->color, n);
    }
    void setValue(int v)
    {
        value = v;
    }
    void setNum(int num)
    {
        number = num;
    }
    //gets
    char* getColor() const
    {
        return color;
    }
    int getVal() const
    {
        return value;
    }
    int getNum() const
    {
        return number;
    }
    //member
    private:
    char* color;
    int value;
    int number;
};
// Add your code here.
// You need to implement these access functions and the default constructor in
//order to complete the class definition of Card.
// color is an pointer to color array, while num is an pointer to number array
 
 
void printSequence(Card* cardSeq);
 
void initSequence(Card* cardSeq, char colorName[][10], int* color, int* num)
{
    //seed1
    if(*color == 1)
    {
        cardSeq[0].setColor(colorName[1]);
        cardSeq[0].setNum(num[8]);
         
        cardSeq[1].setColor(colorName[2]);
        cardSeq[1].setNum(num[4]);
         
        cardSeq[2].setColor(colorName[1]);
        cardSeq[2].setNum(num[1]);
         
        cardSeq[3].setColor(colorName[2]);
        cardSeq[3].setNum(num[0]);
         
        cardSeq[4].setColor(colorName[2]);
        cardSeq[4].setNum(num[2]);
         
        cardSeq[5].setColor(colorName[1]);
        cardSeq[5].setNum(num[2]);
    }
     
    //seed2
    else if(*color == 2)
    {
        cardSeq[0].setColor(colorName[1]);
        cardSeq[0].setNum(num[2]);
         
        cardSeq[1].setColor(colorName[2]);
        cardSeq[1].setNum(num[2]);
         
        cardSeq[2].setColor(colorName[0]);
        cardSeq[2].setNum(num[3]);
         
        cardSeq[3].setColor(colorName[2]);
        cardSeq[3].setNum(num[7]);
         
        cardSeq[4].setColor(colorName[1]);
        cardSeq[4].setNum(num[1]);
         
        cardSeq[5].setColor(colorName[1]);
        cardSeq[5].setNum(num[1]);
    }
    //seed3
    else if(*color == 3)
    {
        cardSeq[0].setColor(colorName[0]);
        cardSeq[0].setNum(num[5]);
         
        cardSeq[1].setColor(colorName[2]);
        cardSeq[1].setNum(num[1]);
         
        cardSeq[2].setColor(colorName[3]);
        cardSeq[2].setNum(num[6]);
         
        cardSeq[3].setColor(colorName[2]);
        cardSeq[3].setNum(num[4]);
         
        cardSeq[4].setColor(colorName[1]);
        cardSeq[4].setNum(num[0]);
         
        cardSeq[5].setColor(colorName[1]);
        cardSeq[5].setNum(num[0]);
    }
     
    //seed4
    else if(*color == 4)
    {
        cardSeq[0].setColor(colorName[3]);
        cardSeq[0].setNum(num[8]);
         
        cardSeq[1].setColor(colorName[3]);
        cardSeq[1].setNum(num[8]);
         
        cardSeq[2].setColor(colorName[1]);
        cardSeq[2].setNum(num[0]);
         
        cardSeq[3].setColor(colorName[3]);
        cardSeq[3].setNum(num[2]);
         
        cardSeq[4].setColor(colorName[0]);
        cardSeq[4].setNum(num[8]);
         
        cardSeq[5].setColor(colorName[1]);
        cardSeq[5].setNum(num[8]);
    }
    //seed 5
    else if(*color == 5)
    {
        cardSeq[0].setColor(colorName[2]);
        cardSeq[0].setNum(num[1]);
         
        cardSeq[1].setColor(colorName[3]);
        cardSeq[1].setNum(num[5]);
         
        cardSeq[2].setColor(colorName[0]);
        cardSeq[2].setNum(num[2]);
         
        cardSeq[3].setColor(colorName[3]);
        cardSeq[3].setNum(num[0]);
         
        cardSeq[4].setColor(colorName[0]);
        cardSeq[4].setNum(num[6]);
         
        cardSeq[5].setColor(colorName[2]);
        cardSeq[5].setNum(num[7]);
    }
    //seed 6
    else if(*color == 6)
    {
        cardSeq[0].setColor(colorName[2]);
        cardSeq[0].setNum(num[4]);
         
        cardSeq[1].setColor(colorName[3]);
        cardSeq[1].setNum(num[4]);
         
        cardSeq[2].setColor(colorName[2]);
        cardSeq[2].setNum(num[6]);
         
        cardSeq[3].setColor(colorName[0]);
        cardSeq[3].setNum(num[7]);
         
        cardSeq[4].setColor(colorName[0]);
        cardSeq[4].setNum(num[5]);
         
        cardSeq[5].setColor(colorName[2]);
        cardSeq[5].setNum(num[6]);
    }
    //seed 7
    else if(*color == 7)
    {
        cardSeq[0].setColor(colorName[1]);
        cardSeq[0].setNum(num[7]);
         
        cardSeq[1].setColor(colorName[3]);
        cardSeq[1].setNum(num[2]);
         
        cardSeq[2].setColor(colorName[1]);
        cardSeq[2].setNum(num[0]);
         
        cardSeq[3].setColor(colorName[0]);
        cardSeq[3].setNum(num[4]);
         
        cardSeq[4].setColor(colorName[3]);
        cardSeq[4].setNum(num[4]);
         
        cardSeq[5].setColor(colorName[2]);
        cardSeq[5].setNum(num[5]);
    }
    //seed 8
    else if(*color == 8)
    {
        cardSeq[0].setColor(colorName[0]);
        cardSeq[0].setNum(num[0]);
         
        cardSeq[1].setColor(colorName[3]);
        cardSeq[1].setNum(num[8]);
         
        cardSeq[2].setColor(colorName[3]);
        cardSeq[2].setNum(num[3]);
         
        cardSeq[3].setColor(colorName[1]);
        cardSeq[3].setNum(num[2]);
         
        cardSeq[4].setColor(colorName[3]);
        cardSeq[4].setNum(num[2]);
         
        cardSeq[5].setColor(colorName[2]);
        cardSeq[5].setNum(num[4]);
    }
    //seed 9
    else if(*color == 9)
    {
        cardSeq[0].setColor(colorName[0]);
        cardSeq[0].setNum(num[4]);
         
        cardSeq[1].setColor(colorName[3]);
        cardSeq[1].setNum(num[6]);
         
        cardSeq[2].setColor(colorName[2]);
        cardSeq[2].setNum(num[5]);
         
        cardSeq[3].setColor(colorName[1]);
        cardSeq[3].setNum(num[0]);
         
        cardSeq[4].setColor(colorName[2]);
        cardSeq[4].setNum(num[1]);
         
        cardSeq[5].setColor(colorName[2]);
        cardSeq[5].setNum(num[3]);
    }
    //seed10
    else if(*color == 10)
    {
        cardSeq[0].setColor(colorName[3]);
        cardSeq[0].setNum(num[6]);
         
        cardSeq[1].setColor(colorName[0]);
        cardSeq[1].setNum(num[5]);
         
        cardSeq[2].setColor(colorName[1]);
        cardSeq[2].setNum(num[8]);
         
        cardSeq[3].setColor(colorName[2]);
        cardSeq[3].setNum(num[6]);
         
        cardSeq[4].setColor(colorName[2]);
        cardSeq[4].setNum(num[0]);
         
        cardSeq[5].setColor(colorName[2]);
        cardSeq[5].setNum(num[2]);
    }
    //seed11
    else if(*color == 11)
    {
        cardSeq[0].setColor(colorName[2]);
        cardSeq[0].setNum(num[0]);
         
        cardSeq[1].setColor(colorName[0]);
        cardSeq[1].setNum(num[3]);
         
        cardSeq[2].setColor(colorName[3]);
        cardSeq[2].setNum(num[2]);
         
        cardSeq[3].setColor(colorName[2]);
        cardSeq[3].setNum(num[4]);
         
        cardSeq[4].setColor(colorName[2]);
        cardSeq[4].setNum(num[7]);
         
        cardSeq[5].setColor(colorName[2]);
        cardSeq[5].setNum(num[1]);
    }
    //seed 12
    else if(*color == 12)
    {
        cardSeq[0].setColor(colorName[1]);
        cardSeq[0].setNum(num[3]);
         
        cardSeq[1].setColor(colorName[0]);
        cardSeq[1].setNum(num[0]);
         
        cardSeq[2].setColor(colorName[2]);
        cardSeq[2].setNum(num[5]);
         
        cardSeq[3].setColor(colorName[3]);
        cardSeq[3].setNum(num[1]);
         
        cardSeq[4].setColor(colorName[1]);
        cardSeq[4].setNum(num[6]);
         
        cardSeq[5].setColor(colorName[2]);
        cardSeq[5].setNum(num[0]);
    }
    //seed 13
    else if(*color == 13)
    {
        cardSeq[0].setColor(colorName[1]);
        cardSeq[0].setNum(num[5]);
         
        cardSeq[1].setColor(colorName[0]);
        cardSeq[1].setNum(num[8]);
         
        cardSeq[2].setColor(colorName[0]);
        cardSeq[2].setNum(num[7]);
         
        cardSeq[3].setColor(colorName[3]);
        cardSeq[3].setNum(num[8]);
         
        cardSeq[4].setColor(colorName[1]);
        cardSeq[4].setNum(num[5]);
         
        cardSeq[5].setColor(colorName[2]);
        cardSeq[5].setNum(num[8]);
    }
    //seed 14
    else if(*color == 14)
    {
        cardSeq[0].setColor(colorName[0]);
        cardSeq[0].setNum(num[8]);
         
        cardSeq[1].setColor(colorName[0]);
        cardSeq[1].setNum(num[6]);
         
        cardSeq[2].setColor(colorName[3]);
        cardSeq[2].setNum(num[2]);
         
        cardSeq[3].setColor(colorName[3]);
        cardSeq[3].setNum(num[5]);
         
        cardSeq[4].setColor(colorName[0]);
        cardSeq[4].setNum(num[4]);
         
        cardSeq[5].setColor(colorName[2]);
        cardSeq[5].setNum(num[7]);
    }
     
    //seed 15
    else if(*color == 15)
    {
        cardSeq[0].setColor(colorName[3]);
        cardSeq[0].setNum(num[2]);
         
        cardSeq[1].setColor(colorName[0]);
        cardSeq[1].setNum(num[4]);
         
        cardSeq[2].setColor(colorName[1]);
        cardSeq[2].setNum(num[5]);
         
        cardSeq[3].setColor(colorName[0]);
        cardSeq[3].setNum(num[3]);
         
        cardSeq[4].setColor(colorName[0]);
        cardSeq[4].setNum(num[3]);
         
        cardSeq[5].setColor(colorName[3]);
        cardSeq[5].setNum(num[6]);
    }
    //seed 16
    else if(*color == 16)
    {
        cardSeq[0].setColor(colorName[2]);
        cardSeq[0].setNum(num[5]);
         
        cardSeq[1].setColor(colorName[1]);
        cardSeq[1].setNum(num[2]);
         
        cardSeq[2].setColor(colorName[0]);
        cardSeq[2].setNum(num[8]);
         
        cardSeq[3].setColor(colorName[0]);
        cardSeq[3].setNum(num[1]);
         
        cardSeq[4].setColor(colorName[3]);
        cardSeq[4].setNum(num[1]);
         
        cardSeq[5].setColor(colorName[3]);
        cardSeq[5].setNum(num[5]);
    }
    //seed 17
    else if(*color == 17)
    {
        cardSeq[0].setColor(colorName[2]);
        cardSeq[0].setNum(num[7]);
         
        cardSeq[1].setColor(colorName[1]);
        cardSeq[1].setNum(num[0]);
         
        cardSeq[2].setColor(colorName[3]);
        cardSeq[2].setNum(num[1]);
         
        cardSeq[3].setColor(colorName[1]);
        cardSeq[3].setNum(num[8]);
         
        cardSeq[4].setColor(colorName[3]);
        cardSeq[4].setNum(num[0]);
         
        cardSeq[5].setColor(colorName[3]);
        cardSeq[5].setNum(num[4]);
    }
    //seed 18
    else if(*color == 18)
    {
        cardSeq[0].setColor(colorName[1]);
        cardSeq[0].setNum(num[1]);
         
        cardSeq[1].setColor(colorName[1]);
        cardSeq[1].setNum(num[7]);
         
        cardSeq[2].setColor(colorName[1]);
        cardSeq[2].setNum(num[4]);
         
        cardSeq[3].setColor(colorName[1]);
        cardSeq[3].setNum(num[5]);
         
        cardSeq[4].setColor(colorName[3]);
        cardSeq[4].setNum(num[8]);
         
        cardSeq[5].setColor(colorName[3]);
        cardSeq[5].setNum(num[3]);
    }
    //seed 19
    else if(*color == 19)
    {
        cardSeq[0].setColor(colorName[0]);
        cardSeq[0].setNum(num[4]);
         
        cardSeq[1].setColor(colorName[1]);
        cardSeq[1].setNum(num[6]);
         
        cardSeq[2].setColor(colorName[0]);
        cardSeq[2].setNum(num[7]);
         
        cardSeq[3].setColor(colorName[2]);
        cardSeq[3].setNum(num[3]);
         
        cardSeq[4].setColor(colorName[2]);
        cardSeq[4].setNum(num[7]);
         
        cardSeq[5].setColor(colorName[3]);
        cardSeq[5].setNum(num[2]);
    }
    //seed 20
    else if(*color == 20)
    {
        cardSeq[0].setColor(colorName[3]);
        cardSeq[0].setNum(num[6]);
         
        cardSeq[1].setColor(colorName[1]);
        cardSeq[1].setNum(num[3]);
         
        cardSeq[2].setColor(colorName[2]);
        cardSeq[2].setNum(num[0]);
         
        cardSeq[3].setColor(colorName[2]);
        cardSeq[3].setNum(num[1]);
         
        cardSeq[4].setColor(colorName[2]);
        cardSeq[4].setNum(num[6]);
         
        cardSeq[5].setColor(colorName[3]);
        cardSeq[5].setNum(num[1]);
    }
     
    for(int i = 0; i < 6; i++)
    {
        if(strcmp(cardSeq[i].getColor(),colorName[0]) == 0)
            cardSeq[i].setValue(1);
        else if(strcmp(cardSeq[i].getColor(),colorName[1]) == 0)
            cardSeq[i].setValue(2);
        else if(strcmp(cardSeq[i].getColor(),colorName[2]) == 0)
            cardSeq[i].setValue(3);
        else if(strcmp(cardSeq[i].getColor(),colorName[3]) == 0)
            cardSeq[i].setValue(4);
    }
}
 
void printSequence(Card* cardSeq)
{
    for(int i = 0; i < 6;i++)
    {
        cout << cardSeq[i].getColor() << cardSeq[i].getNum() << " ";
    }
    cout << endl;
}
 
int main()
{
    // Add your code here.
    Card cardSeq[6];
    char colorName[][10] = {"Red", "Yellow", "Blue", "Green"};
    int color[1];
    int num[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "Enter the seed for random number generation: ";
    cin >> color[0];
     
    initSequence(cardSeq, colorName, color, num);
     
    printSequence(cardSeq);
    return 0;
}
