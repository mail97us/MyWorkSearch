#include <iostream>
#include <stdlib.h> //for malloc
#include <fcntl.h>// for Unicode 
#include <io.h>// for setmode in UNICODE
#include <random>//  to generate random number




static int deck54_cards_drawn[14][4] = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},
    {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},
    {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };


class Cards {

public:
    int num_players = 1;
    int pl_score_min = 0, pl_score_max = 0, pl_score = 0;

    int deck54symbols[14][4] = { {65,65,65,65},{75,75,75,75},{81,81,81,81},{74,74,74,74},
        {49,49,49,49},{57,57,57,57},{56,56,56,56},{55,55,55,55},{54,54,54,54},
        {53,53,53,53},{52,52,52,52},{51,51,51,51},{50,50,50,50},{87,87,0,0} };
    int deck54bj_value_max[14][4] = { {11,11,11,11},{4,4,4,4},{3,3,3,3},{2,2,2,2},
        {10,10,10,10},{9,9,9,9},{8,8,8,8},{7,7,7,7},{6,6,6,6},
        {5,5,5,5},{4,4,4,4},{3,3,3,3},{2,2,2,2},{0,0,0,0} };
    int deck54bj_value_min[14][4] = { {1,1,1,1},{4,4,4,4},{3,3,3,3},{2,2,2,2},
        {10,10,10,10},{9,9,9,9},{8,8,8,8},{7,7,7,7},{6,6,6,6},
        {5,5,5,5},{4,4,4,4},{3,3,3,3},{2,2,2,2},{0,0,0,0} };
    int player_cards[14][4] = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},
    {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},
    {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };



public:

    int draw_random_suit()
    {
        std::random_device rd; // obtain a random number from hardware
        std::mt19937 gen(rd()); // seed the generator
        std::uniform_int_distribution<> distr(0, 3); // define the range

        return distr(gen);// generate number
    }
    int draw_random_rank()
    { 
        std::random_device rd; // obtain a random number from hardware
        std::mt19937 gen(rd()); // seed the generator
        std::uniform_int_distribution<> distr(0, 13); // define the range

        return distr(gen);// generate number}
    }

    void message1() { std::cout << " To draw a card type 1. To finish type 0" << "\n"; }



};

int main()
{
    Cards pl1, bank;
    pl1.pl_score_min = 0;
    pl1.pl_score_max = 0;
    bank.pl_score_min = 0;
    bank.pl_score_max = 0;
    int n, i, j;




    pl1.message1();
    scanf_s("%d", &n);

    
    if (n == 1)
    {
        while (n != 0)
        {

            i = pl1.draw_random_rank();
            j = pl1.draw_random_suit();
            if (deck54_cards_drawn[i][j] == 0) {
                deck54_cards_drawn[i][j] = 1;
                pl1.player_cards[i][j] = pl1.deck54symbols[i][j];
                pl1.pl_score_max += pl1.deck54bj_value_max[i][j];
                pl1.pl_score_min += pl1.deck54bj_value_min[i][j];

                printf("%c", pl1.player_cards[i][j]);
                printf("%c", (j + 3));


                std::cout << "\n" << "player 1 Max score is" << pl1.pl_score_max;
                std::cout << "player 1 Min score is" << pl1.pl_score_min << "\n";
                pl1.message1();
                scanf_s("%d", &n);
                if (n == 0) {
                    if (pl1.pl_score_min <= pl1.pl_score_max && pl1.pl_score_max <= 21)  pl1.pl_score = pl1.pl_score_max;
                    else if (pl1.pl_score_min <= 21 && pl1.pl_score_max > 21)pl1.pl_score = pl1.pl_score_min;
                    else pl1.pl_score = pl1.pl_score_min;



                }
            }
        }
    }
    if (pl1.pl_score <= 21) n = 1;
    else std::cout << "Bank won";

    while (n != 0)
    {

        i = bank.draw_random_rank();
        j = bank.draw_random_suit();
        if (deck54_cards_drawn[i][j] == 0) {
            deck54_cards_drawn[i][j] = 1;
            bank.player_cards[i][j] = pl1.deck54symbols[i][j];
            bank.pl_score_max += pl1.deck54bj_value_max[i][j];
            bank.pl_score_min += pl1.deck54bj_value_min[i][j];

            printf("%c", bank.player_cards[i][j]);
            printf("%c", (j + 3));


            std::cout << "\n" << "Bank Max score is" << bank.pl_score_max;
            std::cout << "Bank Min score is" << bank.pl_score_min << "\n";
            if (pl1.pl_score < bank.pl_score_min && bank.pl_score_min < 21) { std::cout << "Bank won!" << bank.pl_score_max << "\n" << bank.pl_score_min << "player Scored" << pl1.pl_score; n = 0; }
            if (pl1.pl_score < bank.pl_score_max && bank.pl_score_max < 21) { std::cout << "Bank wonWoW" << bank.pl_score_max << "\n" << bank.pl_score_min << "player Scored" << pl1.pl_score; n = 0; }
            if (bank.pl_score_max == 21 || bank.pl_score_min == 21)
            {
                bank.pl_score = 21;
                std::cout << "Bank has 21";
                n = 0;
            }


            if (21 < bank.pl_score_max && 21 < bank.pl_score_min) {
                std::cout << "Player won"; n = 0;
            }

        }
    }





  



    return 0;
}
