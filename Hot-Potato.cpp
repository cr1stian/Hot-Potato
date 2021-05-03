#include <iostream>
#include <string>

#define p(x) std::cout << #x << " " << x << std::endl;


class Player{
private:
	std::string name; // Player's Name

public:
	Player(); // Default Constructor
	~Player(); // Deconstructor Object
	void SetName(std::string newName); // Sets name with given parameter
	std::string GetName(); // Returns name as String

};

class Node{
private:
	Node* nPlayer; // Pointer to next Node
	Player playerData; // Player Object Data

public:
	Node(); // Default Constructor
	Node(const Node& oldNode); // Copy Constructor
	//Node& operator=(const Node* rhNode); // Copy Assignment Operator
	~Node(); // Deconstructor
	void SetNext(Node* nextNode); // Sets the last Node's pointer to the NewNode
	Node* GetNext(); // Returns pointer to the next object

	void SetPlayerName(const std::string name); // Sets Player's name
	std::string GetPlayerName(); // Returns player name
};

class Game{
private:
	Node* hPointer; // Pointer to Head Node
	Node* tPointer; // Pointer to Tail Node
	int numPasses; // Record of number of Passes allowed
	int numPlayers; // Record of number of Players allowed

public:
	Game(); // Default Constructor
	~Game(); // Deconstructor
	void AskForNumbers(); // Asks user for N Players and X Passes
	void AddPlayer(); // Adds a new player to list
	void RemovePlayerAfter(Node curPlayer); // Removes player after CurPlayer in List

	std::string PrintInfo(){ return "Players: " + std::to_string(numPlayers) + " Passes: " + std::to_string(numPasses); }

};

int main(){
	


	Node thisPlayer, secPlayer;
	thisPlayer.SetPlayerName("Cristian");
	secPlayer.SetPlayerName("Sam");

	Node* playerOne, * playerTwo;
	playerOne = &thisPlayer;
	playerTwo = &secPlayer;

	Node headNode;
	headNode.SetNext(playerOne);
	playerOne->SetNext(&secPlayer);

	std::cout << headNode.GetNext()->GetPlayerName() << "\n";

	Game firstGame;
	firstGame.AskForNumbers();



	/* At a point where Program crashes after running the below statement
	
		Looking at the console log, We notice AskForNumbers() runs smoothly and accordingly
		as well as the PrintInfo() below

		The console log shows our values being grabbed and stored correctly 
		BUUUUUT only see the destructor messages from objects Game & Sam 

		No message saying Cristian Destoryed

		this might be the object going out of bound and throwing our error in Visual Studio

	*/


	std::cout << "\n" + firstGame.PrintInfo();


}

// ********************
/********* Player *********/
// ********************

// Des: Default Construcor Initializes Object with a blank name
// Pre: Memory must be allocated for Object
// Pos: Initialized Object with blank name
Player::Player(){
	this->name = "";
}

// Des: Deconstructor displays name when object is destroyed
// Pre: Object must have been created
// Pos: Displayed String comfirming object is destroyed
Player::~Player(){
	std::cout << this->name + " Object Destroyed\n";
}

// Des: Take given string and sets as object's name
// Pre: Memeroy must be allocated for object
// Pos: Assigns Player's name to newName
void Player::SetName(std::string newName){
	name = newName; // ***************** Could Use a capitalize function here
}

// Des: Return's Player's name as a string
// Pre: Memory must be allocated for object
// Pos: Returns name as string
std::string Player::GetName(){
	return name;
}

// ********************
/********* Node *********/
// ********************

// Des: Default Constructor Initializes Object with nPlayer to nullptr
// Pre: Memory must be allocated for Object
// Pos: Initializes object with nPlayer to nullptr
Node::Node(){
	nPlayer = nullptr;
}

// Des: Deconstructor to ensure memory restored to heap
// Pre: Object must exist
// Pos: Memory taken from dynamically created object returned to heap
Node::~Node(){
	delete nPlayer;
}

// Des: Copy Constuctor for implicitly defined copying
// Pre: Memory must be allocated for Object
// Pos: Assigns values copied from old object to newly created object
Node::Node(const Node& oldNode){
	nPlayer = oldNode.nPlayer;
	playerData = oldNode.playerData;
}


Node& Node::operator=(const Node* rhNode){
	nPlayer = rhNode->nPlayer;
	playerData = rhNode->playerData;
	return *this;
}



// Des: Copy Assignment Operator for implicitly copying values over
// Pre: Left hand object must exist
// Pos: Left hand object is assigned right hand object's valyes



// Des: Set's object's Pointer to the next node
// Pre: The object being pointed to must exist
// Pos: Addess of next node is store on nPlayer
void Node::SetNext(Node* nextNode){
	nPlayer = nextNode;
}


// Des: Set's the Player's name in Node object, calls SetName in Player Object
// Pre: Memory must be allocated for the object
// Pos: Set's the Node's Player object's name
void Node::SetPlayerName(const std::string name){
	playerData.SetName(name);
}


// Des: Returns Player name from Node object
// Pre: Object must exist
// Pos: Returns Player name as a string
std::string Node::GetPlayerName(){
	return playerData.GetName();
}


// Des: Returns pointer to next Node
// Pre: Obect must be allocated
// Pos: Returns pointer to next Node
Node* Node::GetNext(){
	return nPlayer;
}

// ********************
/* Game */
// ********************


// Des: Default constructor initializing object's pointers to nullptr
// Pre: Memory must be allocated for object
// Pos: nullptr assigned to pointers
Game::Game(){
	hPointer = nullptr;
	tPointer = nullptr;
	numPasses = -1;
	numPlayers = -1;
}


// Des: Decontructor to free memory 
// Pre: Memory must be allocated
// Pos: Console log of Object Destruction
Game::~Game(){
	std::cout << "Game Object Destroyed\n";
}


// Des: Asks Players for number of Players and Passes
// Pre: Memory must be allocated for object
// Pos: N and X numbers applied to numPlayers & numPasses respectively
void Game::AskForNumbers(){
	int passes(-1), players(-1);
	std::string askPlayers = "How Many Number of Players?\n";
	std::string askPasses = "How Many Number of Passes?\n";

	std::cout << askPlayers;
	std::cin >> players;
	std::cout << askPasses;
	std::cin >> passes;

	p(players); // DEBUG********************
	p(passes);	// DEBUG********************

	while(std::cin.fail() || (players < 0 || passes < 0) ){
		std::cout << "Error with given values\nTry Again\n";
		std::cin.clear();
		std::cin.ignore();

		std::cout << askPlayers;
		std::cin >> players;
		std::cout << askPasses;
		std::cin >> askPasses;
	}

	numPlayers = players;
	numPasses = passes;
}

// Des: Adds new Player object to linked list
// Pre: Memory must be allocated
// Pos: Adds next node to list
void Game::AddPlayer(){


	/* TODO: Consider where to put the catch for the try catch here
			
					I create the objects dynamically here in a try
			1. I catch the error here and handle accordingly
			2. I catch the error in the scope of where I call this function [ Main ]

			Regardless I have to use the number of players reqeuest != 
				I should throw an error and restart?
	 */
}