#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    for(int i=0; i<candidate_count; i++)
    {
        //printf("%d iteration\n",i);
        if(strcmp(name,candidates[i].name))
        {
            //printf("working\n");
            continue;
        }
        else
        {
            candidates[i].votes++;
            return true;
        }
    }
return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    int draw_count=0;
    int draw[9];
    int temp=0;
    int tempvote=0;

    for(int i=0; i<1; i++)
    {
        tempvote=candidates[i].votes;
        temp=i;
        for(int j=i+1; j<candidate_count; j++)
        {
            if(tempvote<candidates[j].votes)
            {
                //printf("\t");
                //printf("i vote =%d i+1 vote=%d and temp is %d now being assigned to i=%d\n",candidates[i].votes,candidates[i+1].votes,temp,i);
                temp=j;
                tempvote=candidates[j].votes;
            }
            else if(tempvote==candidates[j].votes)
            {
                draw[draw_count]=temp;
                draw_count++;
                draw[draw_count]=j;
            }
                //printf("i vote =%d i+1 vote=%d and temp is %d now being assigned to i+1=%d\n",candidates[i].votes,candidates[i+1].votes,temp,i+1);


        }

        //}
    }
    if(draw_count!=0)
    {
        for(int i=0; i<draw_count+1; i++)
        {
            printf("%s ",candidates[draw[i]].name);
        }
    }

    else
    {
        printf("%s\n",candidates[temp].name);
    }

    return;
}

