#include <stdlib.h>
#include <stdio.h>

#define S 2
#define FG 3
#define TD 6
#define TDFG 7
#define TD2P 8

//Runs through every possible combination of scoring for a given score
void nfl_score_combinations(int target_score) {
    char *scoring_plays[] = {"TD + 2pt", "TD + FG", "TD", "3pt FG", "Safety"};
    int values[] = {8, 7, 6, 3, 2};

    //itterating therough every possible way to score
    for (int td_2pt = 0; td_2pt <= target_score / values[0]; td_2pt++) { 
        for (int td_fg = 0; td_fg <= target_score / values[1]; td_fg++) {
            for (int td = 0; td <= target_score / values[2]; td++) {
                for (int fg = 0; fg <= target_score / values[3]; fg++) {
                    for (int safety = 0; safety <= target_score / values[4]; safety++) {
                        if (td_2pt * values[0] + td_fg * values[1] + td * values[2] + fg * values[3] + safety * values[4] == target_score) {
                            printf("%d %s, %d %s, %d %s, %d %s, %d %s\n", td_2pt, scoring_plays[0], td_fg, scoring_plays[1], td, scoring_plays[2], fg, scoring_plays[3], safety, scoring_plays[4]);
                        }
                    }
                }
            }
        }
    }
}

//Main
int main()
{
    int score = 2;
    
    printf("Enter 0 or 1 to STOP.\n");
    while (score > 1)
    {
        printf("Enter the NFL score: ");

        scanf("%d", &score);

        printf("Possible combinations of scoring plays: \n");
        nfl_score_combinations(score);
        printf("\n");

    }

    return 0;
}