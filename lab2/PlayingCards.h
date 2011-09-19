//
//  PlayingCards.h
//  Lab 2
//
//  COMP 15: Data Structures
//	Fall 2011
//  Tufts University Department of Computer Science
//	Updated by ????
//

#ifndef lab2_PlayingCards_h
#define lab2_PlayingCards_h

#define STANDARD_DECK_SIZE 52

// Class invariant: ????

// The definition for a single playing card
struct Card
{
	// YOU ARE FREE TO REPRESENT A PLAYING CARD HOWEVER YOU WANT
	// ????
};

class PlayingCards
{
public:   
    // Description: Instantiates deck of playing cards
    // Preconditions: ????
    // Postconditions: ????
    PlayingCards();

    // Description: Get playing card at top of deck
    // Preconditions: ????
    // Postconditions: ????    
    Card pop();
    
    // Description: Check if the deck of playing cards is empty
    // Preconditions: ????
    // Postconditions: ????
    bool isEmpty();
    
    // Description: Check if the deck of playing cards is full
    // Preconditions: ????
    // Postconditions: ????
    bool isFull();
    
    // Description: Removes deck of cards from memory
    // Preconditions: ????
    // Postconditions: ????
    ~PlayingCards();
private:
    Card *deck;
    
    // Description: Add a card to the deck; called in shuffle()
    // Preconditions: ????
    // Postconditions: ????
    void push (Card c);
    
    // Description: Shuffles deck of playing cards; called in constructor
    // Preconditions: ????
    // Postconditions: ????
    void shuffle();

    // Anything else?
    // ????
};

#endif
